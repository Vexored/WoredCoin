package Test;

import BlockChain.Block;

public class TestSHA {
	static private Block block = new Block(1, "18/04/2018", "0", 10);

	
	
	public static void main(String[] args) {
		String SHA256;
		
		System.out.println(block.sha256("Astérix donne 1000 dcc à Obélix"));
	}
}
