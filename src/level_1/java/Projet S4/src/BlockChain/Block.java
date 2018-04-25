package BlockChain;

import java.security.MessageDigest;

public class Block {
	
	//-----------------------------------------------//
	//----------------- Attributs -------------------//
	//-----------------------------------------------//
	
	private int index;//Num�ro du block dans la continuit�
	private String timestamp;//date de cr�ation du bloc
	private String hash;//Hash final avec le Hash de merkel et les Hash
	private String hashMerk;//Hash de l'arbre de Merkel
	private String hashPrev;//Hash du block qui pr�c�de
	private int nbTrans; // Nombre de transactions
	private int nonce;//Indice pour le minage
	private String[] transactions;//Liste des transactions 
	
	
	
	//------------------------------------------------//
	//----------------- Constructeur -----------------//
	//------------------------------------------------//
	
	
	public Block(int index, String timestamp, String hashPrev, int nbTransMax) {
		this.index = index;
		this.timestamp = timestamp;
		this.hashPrev = hashPrev;
		this.nonce = 0;
		this.transactions = new String[nbTransMax];
	}
	
	
	
	//--------------------------------------------//
	//----------------- M�thodes -----------------//
	//--------------------------------------------//
	
	
	//M�thode pour cr�er ou mettre � jour le hash du bloc entier 
	 public static String sha256(String input) {
		  
		 try {
			 MessageDigest digest = MessageDigest.getInstance("SHA-256");
		         
			 //Applique le SHA-256 � notre input 
			 byte[] hash = digest.digest(input.getBytes("UTF-8"));
		         
			 StringBuffer hexString = new StringBuffer(); // Cela contiendra le Hash sous forme Hexad�cimale
			 for (int i = 0; i < hash.length; i++) {
				 String hex = Integer.toHexString(0xff & hash[i]);
				 if(hex.length() == 1) hexString.append('0');
				 hexString.append(hex);
			 }
			 return hexString.toString();
		 }
		 catch(Exception e) {
			 throw new RuntimeException(e);
		 }
	}
	
	 
	 
	//--------------------------------------------//
	//------------------ Getter ------------------//
	//--------------------------------------------//
	 
	//M�thode pour obtenir le hash du bloc courant
	public String getHash() {
		return hash;
	}
	
	public String 
	
	
}
	
