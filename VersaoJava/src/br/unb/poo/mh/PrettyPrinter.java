package br.unb.poo.mh;

public class PrettyPrinter implements Visitor{

	@Override
	public void visitar(ValorInteiro exp) {
		System.out.print(exp.getValor());
	}

	@Override
	public void visitar(ValorBooleano exp) {
		System.out.print(exp.getValor());
	}
	
	@Override
	public void visitar(ExpressaoBooleana exp) {
		System.out.print("(");
		exp.expEsquerda.aceitar(this);
		switch(exp.t){
			case AND:
				System.out.print(" and ");
			case OR:
				System.out.print(" or ");
		}
		exp.expDireita.aceitar(this);
		System.out.print(")");
	}
	
	@Override
	public void visitar(ExpressaoDivisao exp) {
		System.out.print("(");
		exp.expEsquerda.aceitar(this);
		System.out.print("/");
		exp.expDireita.aceitar(this);
		System.out.print(")");
	}

	@Override
	public void visitar(ExpressaoSoma exp) {
		System.out.print("(");
		exp.expEsquerda.aceitar(this);
		System.out.print("+");
		exp.expDireita.aceitar(this);
		System.out.print(")");
	}

	@Override
	public void visitar(Multiplicacao exp) {
		System.out.print("(");
		exp.expEsquerda.aceitar(this);
		System.out.print("*");
		exp.expDireita.aceitar(this);
		System.out.print(")");
	}

	@Override
	public void visitar(IfThenElse exp) {
		System.out.print("if( ");
		exp.condicao.aceitar(this);
		System.out.println(")");
		
		System.out.print("then ");
		exp.clausulaThen.aceitar(this);
		
		System.out.println("else " );
		exp.clausulaElse.aceitar(this);
	}

	@Override
	public void visitar(AplicacaoFuncao exp) {
		System.out.print(exp.nome);
		System.out.print("(");
		int i = 0;
		while(i < exp.parametros.size() - 1) {
			exp.parametros.get(i++).aceitar(this);
			System.out.print(",");
		}
		if(i == exp.parametros.size() - 1) {
			exp.parametros.get(i++).aceitar(this);
		}
		System.out.println(")");
	}

	@Override
	public void visitar(Identificador exp) {
		System.out.println(exp.id);
	}

	@Override
	public void visitar(ExpressaoSubtracao exp) {
		System.out.print("(");
		exp.expEsquerda.aceitar(this);
		System.out.print("-");
		exp.expDireita.aceitar(this);
		System.out.print(")");
	}

}
