package br.unb.cic.poo.mh;

import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

import br.unb.poo.mh.Expressao;
import br.unb.poo.mh.ExpressaoBooleana;
import br.unb.poo.mh.ExpressaoDivisao;
import br.unb.poo.mh.ExpressaoSoma;
import br.unb.poo.mh.ExpressaoSubtracao;
import br.unb.poo.mh.Multiplicacao;
import br.unb.poo.mh.PrettyPrinter;
import br.unb.poo.mh.Tipo;
import br.unb.poo.mh.TipoExpressaoBooleana;
import br.unb.poo.mh.ValorBooleano;
import br.unb.poo.mh.ValorInteiro;

public class TesteExpressaoBinaria {
	private ValorInteiro v5 = new ValorInteiro(5);
	private ValorInteiro v10 = new ValorInteiro(10);
	ValorInteiro v15 = new ValorInteiro(15);
	
	@BeforeClass
	public static void SuiteSetUp(){
		System.out.println("==Teste de Expressões Isoladas==");
	}
	
	
	/*Operação soma*/
	private Expressao soma = new ExpressaoSoma(v5, v10);
	
	@Test
	public void testeSomaSimples() {
		Assert.assertEquals(v15, soma.avaliar());
		Assert.assertEquals(Tipo.Inteiro, soma.tipo());
	}
	
	@Test
	public void testeSomaComplexa() {
		ValorInteiro v25 = new ValorInteiro(25);
		Expressao soma2 = new ExpressaoSoma(v10, soma);
		Assert.assertEquals(v25, soma2.avaliar());
	}
	
	
	/*Operação subtração*/
	
	@Test
	public void testeSubtracaoSimples() {
		Assert.assertEquals(new ValorInteiro(-5), new ExpressaoSubtracao(v10, v5).avaliar());
	}
	
	
	/*Operação multiplicação*/
	@Test
	public void testeExpressaoOk() {
		Expressao m = new Multiplicacao(v10, new ExpressaoSoma(v10, v5));
		
		Assert.assertEquals(new ValorInteiro(150), m.avaliar());
	}
	
	@Test
	public void testeExpressaoNok() {
		ValorBooleano vtrue = new ValorBooleano(true);
		
		Expressao m = new Multiplicacao(v10, new ExpressaoSoma(v10, vtrue));
		
		//m.avaliar();
	}
	
	/*Operação divisão*/
	PrettyPrinter pp = new PrettyPrinter();
	@Test
	public void testeDivisaoSimples() {
		System.out.println("-Divisão-");
		Expressao div = new ExpressaoDivisao(v5, v10);
		Assert.assertEquals(new ValorInteiro(2), div.avaliar());
		div.aceitar(pp);
	}
	
	
	/*Operacao booleana (and, or)*/
	private ValorBooleano vtrue = new ValorBooleano(true);
	private ValorBooleano vfalse = new ValorBooleano(false);
	
	@Test
	public void testeAndSimples() {
		Assert.assertEquals(vtrue, new ExpressaoBooleana(vtrue, vtrue, TipoExpressaoBooleana.AND).avaliar());
		Assert.assertEquals(vfalse, new ExpressaoBooleana(vfalse, vtrue, TipoExpressaoBooleana.AND).avaliar());
		Assert.assertEquals(vfalse, new ExpressaoBooleana(vtrue, vfalse, TipoExpressaoBooleana.AND).avaliar());
		Assert.assertEquals(vfalse, new ExpressaoBooleana(vfalse, vfalse, TipoExpressaoBooleana.AND).avaliar());
		
		Assert.assertEquals(vtrue, new ExpressaoBooleana(vtrue, vfalse, TipoExpressaoBooleana.OR).avaliar());
		Assert.assertEquals(vfalse, new ExpressaoBooleana(vfalse, vfalse, TipoExpressaoBooleana.OR).avaliar());
		
		Assert.assertEquals(Tipo.Booleano, new ExpressaoBooleana(vtrue, vtrue, TipoExpressaoBooleana.AND).tipo());
	}
	
	
}
