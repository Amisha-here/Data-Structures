import java.util.*;

public class PrimeSieve {
    public static void main(String[] args)
    {
      //  Scanner sc=new Scanner(System.in);
        int n=40;
        boolean[] primes=new boolean[n+1];

        sieve(n,primes);
        
    }

    // false means number is prime
    static void sieve(int n,boolean[] primes)
    {
        for (int i=2;(i*i)<n+1;i++)
        {
            if(primes[i]==false)
            {
                for (int j = (2*i); j < n+1; j=j+i) {
                    // make all the multiples true i.e. they are composite
                    primes[j]=true;
                }
            }
        }
        for (int i = 2; i < n+1; i++) {
            if(primes[i]==false)
            System.out.print(i+" ");

        }
    }
}
