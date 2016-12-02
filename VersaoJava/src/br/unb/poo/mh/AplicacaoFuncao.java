package br.unb.poo.mh;

import java.util.List;

/**
 * Corresponde a uma expressao do tipo 
 * aplicacao de funcao. 
 * 
 * @author rbonifacio
 */
public class AplicacaoFuncao implements Expressao {
	
	String nome;
	List<Expressao> parametros;

	public AplicacaoFuncao(String nome, List<Expressao> parametros) {
		this.nome = nome;
		this.parametros = parametros;
	}

	@Override
	public Valor avaliar() {
		DeclaracaoFuncao dec = Ambiente.instance().
				getDeclaracaoFuncao(nome, parametros.size());
		
		Ambiente.instance().empilha();
		
		for(int i = 0; i < dec.getArgs().size(); i++) {
			String arg = dec.getArgs().get(i);
			Expressao pmt = parametros.get(i);
			
			Ambiente.instance().associaExpressao(arg, pmt);
		}
		Valor res = dec.getCorpo().avaliar();
		Ambiente.instance().desempilha();
		
		return res;
	}

	@Override
	public Tipo tipo() {
		return Tipo.Error;
	}

	@Override
	public void aceitar(Visitor v) {
		v.visitar(this);
		
	}
	
	
	

}
