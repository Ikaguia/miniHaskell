package br.unb.poo.mh;

import java.util.List;

public class DeclaracaoFuncao {

	private String nome;
	/*
	 * Na presenca de tipos, os argumentos formais 
	 * devem ser "anotados" com os respectivos tipos. 
	 * A verificacao de tipos da aplicacao de funcoes 
	 * deve checar se os argumentos atuais (que sao expressoes) 
	 * sao bem tipados em relacao aos argumentos formais. 
	 */
	private List<String> args;
	private Expressao corpo;
	
	public DeclaracaoFuncao(String nome, List<String> args, Expressao corpo) {
		this.nome = nome;
		this.args = args;
		this.corpo = corpo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public List<String> getArgs() {
		return args;
	}

	public void setArgs(List<String> args) {
		this.args = args;
	}

	public Expressao getCorpo() {
		return corpo;
	}

	public void setCorpo(Expressao corpo) {
		this.corpo = corpo;
	}
}
