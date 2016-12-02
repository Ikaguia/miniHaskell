package br.unb.cic.poo.mh;

import org.junit.BeforeClass;
import org.junit.Test;

import br.unb.poo.mh.Expressao;
import br.unb.poo.mh.ExpressaoBooleana;
import br.unb.poo.mh.ExpressaoSoma;
import br.unb.poo.mh.IfThenElse;
import br.unb.poo.mh.TipoExpressaoBooleana;
import br.unb.poo.mh.ValorBooleano;
import br.unb.poo.mh.ValorInteiro;
import org.junit.Assert;

public class TesteIfThenElse {
	
	@BeforeClass
	public static void SuiteSetUp(){
		System.out.println("==Teste de Expressões IfThenElse==");
	}
	
	@Test
	public void IfThenElseSimples(){
		//ValorBooleano vtrue = new ValorBooleano(true);
		ValorBooleano vfalse = new ValorBooleano(false);
		
		Expressao soma = new ExpressaoSoma(new ValorInteiro(2), new ValorInteiro(201));
		
		Expressao ifthen1 = new IfThenElse(new ExpressaoBooleana(vfalse, vfalse, TipoExpressaoBooleana.OR), null, soma);
		
		Assert.assertEquals(new ValorInteiro(203), ifthen1.avaliar()); 
	}
}
