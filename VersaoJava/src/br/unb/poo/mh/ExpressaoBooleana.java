package br.unb.poo.mh;

public class ExpressaoBooleana extends ExpressaoBinaria {
	
	TipoExpressaoBooleana t;
	
	public ExpressaoBooleana (Expressao expDireita, Expressao expEsquerda, TipoExpressaoBooleana t){
		super(expEsquerda, expDireita);
		this.t = t;
	}

	@Override
	public Valor avaliar() {
		ValorBooleano ve = (ValorBooleano)expEsquerda.avaliar();
		ValorBooleano vd = (ValorBooleano)expDireita.avaliar();
		
		ValorBooleano resultado;
		
		switch(t){
			case AND:
				resultado = new ValorBooleano( ve.getValor() && vd.getValor() ); break;
			case OR:
				resultado = new ValorBooleano( ve.getValor() || vd.getValor() ); break;
			default:
				resultado = null;
		}
		
		return resultado;
	}

	@Override
	public Tipo tipo() {
		return (expEsquerda.tipo() == Tipo.Booleano && expDireita.tipo() == Tipo.Booleano)
				? Tipo.Booleano : Tipo.Error;
	}

	@Override
	public void aceitar(Visitor v) {
		v.visitar(this);
	}
	
}
