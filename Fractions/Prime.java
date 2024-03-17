package Fractions;

import java.util.*;

public class Prime {
    public static Set<Integer> primesInRange(long n){
        Set<Integer> primeNumbers = new LinkedHashSet<>();
        for (int current = 2; current <= n; current++) {
            boolean isPrime = true;
            for (int denom : primeNumbers) {
                if (current % denom == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                primeNumbers.add(current);
            }
        }
        return primeNumbers;
    }
}