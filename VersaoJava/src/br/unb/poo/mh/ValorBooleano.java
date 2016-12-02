package br.unb.poo.mh;

public class ValorBooleano extends ValorParametrizado<Boolean>{

	public ValorBooleano(Boolean valor) {
		super(valor);
	}

	@Override
	public Tipo tipo() {
		return Tipo.Booleano;
	}

	@Override
	public void aceitar(Visitor v) {
		v.visitar(this);
	}

}
