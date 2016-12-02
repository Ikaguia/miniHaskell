package br.unb.poo.mh;

import java.util.HashMap;
import java.util.Stack;

/*
 * Classe utilitaria para permitir overloading. 
 * Com o uso dessa classe, podemos ter funcoes 
 * na linguagem MiniHaskell com mesmo nome mas 
 * aridades diferente. 
 */
class AssinaturaDeFuncao {
	private String nome;
	private int aridade;
	
	public AssinaturaDeFuncao(String nome, int aridade) {
		this.nome = nome;
		this.aridade = aridade; 
	}
	
	public AssinaturaDeFuncao(DeclaracaoFuncao dec) {
		this(dec.getNome(), dec.getArgs().size());
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getAridade() {
		return aridade;
	}
	
	/*
	 * Necessaria a implementacao do metodo hashCode para 
	 * fazer com que o "get" de um hash map funcione. A 
	 * falta desse metodo originou o "bug" que ocorreu 
	 * no final da aula do dia 10/11/2016. 
	 * 
	 * @see java.lang.Object#hashCode()
	 */
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + aridade;
		result = prime * result + ((nome == null) ? 0 : nome.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		return (obj instanceof AssinaturaDeFuncao) &&
				((AssinaturaDeFuncao)obj).nome.equals(nome) &&
				((AssinaturaDeFuncao)obj).aridade == aridade;
	}
	
	
}

/**
 * Ambiente de execucao. Representa uma 
 * area de memoria que eh populada a cada 
 * chamada de funcao, associando os argumentos 
 * formais da declaracao de uma funcao com os 
 * parametros (expressoes) passados na chamada 
 * de uma funcao. 
 * 
 * @author rbonifacio
 *
 */
public class Ambiente {
	private HashMap<AssinaturaDeFuncao, DeclaracaoFuncao> funcoes;
	
	private Stack<HashMap<String, Expressao>> pilhaExecucao;
	
	/* a classe ambiente eh um singleton */
	private static Ambiente instance;
	
	private Ambiente() {
		pilhaExecucao = new Stack<>();
		funcoes = new HashMap<>();
	}
	
	public static Ambiente instance() {
		if(instance == null) {
			instance = new Ambiente();
		}
		return instance;
	}

	/**
	 * Declara uma funcao no ambiente de execucao.
	 * @param decl Declaracao de funcao. 
	 */
	public void declaraFuncao(DeclaracaoFuncao decl) {
		funcoes.put(new AssinaturaDeFuncao(decl), decl);
	}
	
	/**
	 * Obtem uma declaracao de funcao no ambiente de execucao.
	 * @param nome da funcao
	 * @param aridade da funcao
	 * @return Declaracao de funcao com dado nome / aridade.
	 * 
	 * @throws RuntimeException, caso a funcao nao tenha sido declarada.
	 */
	public DeclaracaoFuncao getDeclaracaoFuncao(String nome, int aridade) {
		DeclaracaoFuncao dec = funcoes.get(new AssinaturaDeFuncao(nome, aridade));
	
		if(dec == null) {
			throw new RuntimeException("Funcao " + nome + " nao definida");
		}
		return dec;
	}
	
	/**
	 * Adiciona uma nova tabela (vazia) entre ids e 
	 * expressoes no topo da pilha. Esse metodo eh 
	 * particularmente util quando uma funcao eh chamada.
	 */
	public void empilha() {
		pilhaExecucao.push(new HashMap<>());
	}
	
	/**
	 * Remove uma associacao entre nomes e expressoes 
	 * do topo da pilha. Util quando ocorre o retorno 
	 * de uma funcao. 
	 */
	public void desempilha() {
		if(!pilhaExecucao.isEmpty()) {
			pilhaExecucao.pop();
		}
	}

	/**
	 * Associa um identificador a uma expressao 
	 * na tabela que esta no topo da pilha. 
	 * 
	 * @param id identificador da variavel ou argumento
	 * @param exp expressao associada ao identificador
	 */
	public void associaExpressao(String id, Expressao exp) {
		if(pilhaExecucao.isEmpty()) {
			empilha();
		}
		HashMap<String, Expressao> tabelaAtual = pilhaExecucao.peek();
		tabelaAtual.put(id, exp);
	}
	
	/**
	 * Obtem o valor da expressao associado a um identificador 
	 * na tabela que esta no topo da pilha. 
	 * @param id identificador da variavel
	 * @return expressao associada
	 * @throws RuntimeException quando a variavel nao foi associada
	 */
	public Expressao getExpressao(String id) {
		Expressao exp = null;
		if(!pilhaExecucao.isEmpty()) {
			exp = pilhaExecucao.peek().get(id);
		}
		if(exp == null) {
			throw new RuntimeException("Variavel nao declarada");
		}
		return exp;
	}
}
