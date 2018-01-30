import java.math.BigInteger;
import java.util.Scanner;

public class bignum {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num=sc.nextInt();
		int count = 0;
		BigInteger result = BigInteger.ONE;
		for(int i=1; i<=num; i++) {
			result = result.multiply(BigInteger.valueOf(i));
		}
		char[] res = result.toString().toCharArray();
		for(int i=res.length-1; i>=0; --i) {
			if(res[i] != '0') break;
			else count++;
		}
		sc.close();
		System.out.println(count);

	}

}
