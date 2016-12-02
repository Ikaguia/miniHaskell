package br.unb.poo.mh;

public abstract class ExpressaoBinaria implements Expressao {
	protected Expressao expDireita;
	protected Expressao expEsquerda; 
	
	/**
	 * O construtor recebe duas expressões para construir a estrutura de dados de uma operação envolvendo dois operandos.
	 * Exemplos são: soma, subtração, and e or. O que acontece, inicialmente, na formação é: o MiniHaskell acredita na
	 * corretude dos tipos destes operandos e só confere-os na hora de realizar, de fato, a operação com os termos já
	 * pertecentes a um tipo primitivo, como um inteiro, boolean, etc.
	 * @param expDireita
	 * @param expEsquerda
	 * @author asm95
	 */
	public ExpressaoBinaria(Expressao expDireita, Expressao expEsquerda) {
		this.expDireita = expDireita;
		this.expEsquerda = expEsquerda;
	}
	
}
