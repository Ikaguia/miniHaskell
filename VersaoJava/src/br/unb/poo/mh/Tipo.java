package br.unb.poo.mh;

/**
 * Representa os tipos validos na linguagem MiniHaskell. 
 * 
 * Desafio: seria interessante MiniHaskell suportar funcoes 
 * de alta ordem, ou seja, funcoes podem ser passadas como 
 * argumentos para outras funcoes ou serem usadas como 
 * retorno de uma funcao. Para isso, funcao precisa ser 
 * um valor, e ter um tipo associado. Uma possivel solucao 
 * seria definir expressoes lambda como expressoes. 
 * 
 * Exemplo: a) \x y -> x + y
 *          b) \x -> x + 1
 *          
 * Como toda expressao deve ser tipada, as expressoes 
 * lambda deveriam incluir informacoes sobre o tipo. 
 * O tipo de uma expressao Lambda eh denotado pelo tipo 
 * "seta" (arrow). 
 * 
 * O tipo de a) deveria ser Int -> Int -> Int e b) 
 * deveria ser Int -> Int 
 * @author rbonifacio
 */
public enum Tipo {

	Inteiro, Booleano, Error;
	
}
