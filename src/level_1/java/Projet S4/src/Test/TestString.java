package Test;

public class TestString {
	public static void main(String[] args) {
		
		String test = "bonjour la famille sisi comment ça va";
		char[] testTab = test.toCharArray();
		testTab[0] = '0';
		testTab[1] = '0';
				
		for (int i = 0; i < test.length(); i++)
			System.out.print(testTab[i]);
	}

}
