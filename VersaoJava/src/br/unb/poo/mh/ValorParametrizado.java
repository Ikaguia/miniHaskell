package br.unb.poo.mh;

public abstract class ValorParametrizado<T> extends Valor {

	private T valor;
	
	public ValorParametrizado(T valor) {
		this.valor = valor;
	}
	
	public T getValor() {
		return valor;
	}
	
	@Override
	public boolean equals(Object other) {
		if(other instanceof ValorParametrizado) {
			return valor.equals(((ValorParametrizado)other).getValor());
		}
		return false;
	}
}
