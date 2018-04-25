package BlockChain;

public class Transaction {
	private int index;
	private String timestamp;
	private String source;
	private String destination;
	private int montant;
	
	public Transaction(String source, String destination, int montant) {
		this.source = source;
		this.destination = destination;
		this.montant = montant;
	}
}
