package DsaSelfPaced;

public class CountNoOfSetBit {

	public static void main(String[] args) {
		
		
		int resultValue = 0;
		int givenNo = 5;
		while( givenNo != 0) {
			
		  if((givenNo & 1) == 1) {
			  resultValue++;
		  }
		  
		  givenNo = givenNo>>1;
		  
		}
		
		System.out.println(resultValue);
		
		
	}

}
