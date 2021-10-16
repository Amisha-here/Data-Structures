import java.util.*;

public class PrimeNumber {
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        boolean flag=true;

        if(n==0 || n==1)
        System.out.println("NULL");

        if(n==2)
        System.out.println("Even prime");

        for (int i = 2; (i*i) < n; i++) {
            if(n%i==0)
            flag=false;
            break;
        }

        if(flag)
        System.out.println("Prime number");
        else
        System.out.println("Not a prime number");
       
        
    }
}
