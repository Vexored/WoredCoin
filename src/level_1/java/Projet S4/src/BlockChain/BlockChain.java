package BlockChain;

import java.util.ArrayList;


public class BlockChain {
	
	//-----------------------------------------------//
	//----------------- Attributs -------------------//
	//-----------------------------------------------//
	
	private int difficulty;
	private int nbBlock;
	private ArrayList blockchain;
	
	//------------------------------------------------//
	//----------------- Constructeur -----------------//
	//------------------------------------------------//
	
	public BlockChain(int difficulty) {
		this.difficulty = difficulty;
		this.nbBlock = 1;
		blockchain = new ArrayList();
		blockchain.add(new Block(1, Date.chaine(), "0", Paramètres.getNbTransMax()));
			
	}
	
}
