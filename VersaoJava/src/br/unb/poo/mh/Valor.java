package br.unb.poo.mh;

public abstract class Valor implements Expressao {
 
	@Override
	public Valor avaliar() {
		return this;
	}
}
