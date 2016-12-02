package br.unb.cic.poo.mh;

import java.util.ArrayList;
import java.util.List;

import org.junit.Assert;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import br.unb.poo.mh.Ambiente;
import br.unb.poo.mh.AplicacaoFuncao;
import br.unb.poo.mh.DeclaracaoFuncao;
import br.unb.poo.mh.Expressao;
import br.unb.poo.mh.ExpressaoSoma;
import br.unb.poo.mh.ExpressaoSubtracao;
import br.unb.poo.mh.Identificador;
import br.unb.poo.mh.PrettyPrinter;
import br.unb.poo.mh.TamanhoDasExpressoes;
import br.unb.poo.mh.ValorInteiro;

public class TesteAplicacaoFuncao {

	private DeclaracaoFuncao soma;
	private DeclaracaoFuncao subtracao;
	
	@BeforeClass
	public static void SuiteSetUp(){
		System.out.println("\n==Teste Aplicação de Função==");
	}
	
	@Before
	public void setUp() {
		Identificador id_x = new Identificador("x");
		Identificador id_y = new Identificador("y");
		
		List<String> args = new ArrayList<>();
		args.add("x");
		args.add("y");
		Expressao corpo_soma = new ExpressaoSoma(id_x,id_y);
		
		soma = new DeclaracaoFuncao("soma", args, corpo_soma);
		Ambiente.instance().declaraFuncao(soma);
	
		Expressao corpo_subtracao = new ExpressaoSubtracao(id_x, id_y);
		subtracao = new DeclaracaoFuncao("subtracao", args, corpo_subtracao);
		Ambiente.instance().declaraFuncao(subtracao);
	}
	
	@Test
	public void testeAplicacaoFuncao() {
		List<Expressao> parametros = new ArrayList<>();
		parametros.add(new ValorInteiro(3));
		parametros.add(new ExpressaoSoma(new ValorInteiro(4), new ValorInteiro(5)));
		
		Expressao aplicaSoma = new AplicacaoFuncao("soma", parametros);
		
		Assert.assertEquals(new ValorInteiro(12), aplicaSoma.avaliar());
		
		PrettyPrinter pp = new PrettyPrinter();
		TamanhoDasExpressoes t = new TamanhoDasExpressoes();
		
		aplicaSoma.aceitar(pp);
		aplicaSoma.aceitar(t);
		Assert.assertEquals(5, t.getTamanho());
		System.out.println("Tamanho da expressão soma: " + t.getTamanho());
		
		
		Expressao aplicaSubtracao = new AplicacaoFuncao("subtracao", parametros);
		Assert.assertEquals(new ValorInteiro(6), aplicaSubtracao.avaliar());
		
		aplicaSubtracao.aceitar(pp);
		aplicaSubtracao.aceitar(t);
	}
}
