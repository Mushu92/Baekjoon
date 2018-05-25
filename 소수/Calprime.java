import java.util.Scanner;

public class Calprime {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int M,N,min = 0,sum=0;
		boolean flag = true;
		M=sc.nextInt();
		N=sc.nextInt();
		for(int i=M; i<=N; i++) {
			if(primecheck(i)) {
				sum+=i;
				if(flag == true) {
					min = i;
					flag = false;
				}
			}
		}
		if(sum == 0) {
			System.out.println(-1);
		}
		else {
			System.out.println(sum);
			System.out.println(min);
		}
		sc.close();

	}
	static boolean primecheck(int a) {
		if(a==1) return false;
		for(int i=2; i<a; i++) {
			if(a%i == 0) {
				return false;
			}
		}
		return true;
	}
}
