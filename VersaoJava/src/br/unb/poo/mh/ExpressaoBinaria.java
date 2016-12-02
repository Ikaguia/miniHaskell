package br.unb.poo.mh;

public abstract class ExpressaoBinaria implements Expressao {
	protected Expressao expDireita;
	protected Expressao expEsquerda; 
	
	/**
	 * O construtor recebe duas express�es para construir a estrutura de dados de uma opera��o envolvendo dois operandos.
	 * Exemplos s�o: soma, subtra��o, and e or. O que acontece, inicialmente, na forma��o �: o MiniHaskell acredita na
	 * corretude dos tipos destes operandos e s� confere-os na hora de realizar, de fato, a opera��o com os termos j�
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
