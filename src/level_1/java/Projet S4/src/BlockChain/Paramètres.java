package BlockChain;

public class Paramètres {
	
	private static int difficulty;
	private static int nbTransMax = 4;
	
	public static void setNbTransMax(int max) {
		nbTransMax = max;
	}
	
	public static void setDifficult(int diff) {
		difficulty = diff;
	}
	
	public static int getNbTransMax() {
		return nbTransMax;
	}
	
	public static int getDifficulty() {
		return difficulty;
	}
}
