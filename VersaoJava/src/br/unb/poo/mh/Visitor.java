package br.unb.poo.mh;

/**
 * Interface com a declaracao dos metodos que 
 * "visitam" aplicando alguma operacao sobre 
 * os elementos sintaticos de uma linguagem 
 * de programacao. 
 * @author rbonifacio
 *
 */
public interface Visitor {
	public void visitar(ValorInteiro exp);
	public void visitar(ValorBooleano exp);
	public void visitar(ExpressaoSoma exp);
	public void visitar(ExpressaoSubtracao exp);
	public void visitar(Multiplicacao exp);
	public void visitar(IfThenElse exp);
	public void visitar(AplicacaoFuncao exp);
	public void visitar(Identificador exp);
	public void visitar(ExpressaoDivisao exp);
	public void visitar(ExpressaoBooleana exp);
}
