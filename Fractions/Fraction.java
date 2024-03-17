package Fractions;

import java.util.*;

public class Fraction extends Number {
    private int numerator;
    private int denominator;
    public static final int MAX_VALUE = 1_000_000_000;
    private static final int MAX_SIMPLIFICATION = 100_000;
    public Fraction(long numerator, long denominator) {
        setNumerator((int) (isNegative((int) numerator, (int) denominator) ? -Math.abs(numerator) : Math.abs(numerator)));
        setDenominator((int) Math.abs(denominator));
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int num) {
        this.numerator = num;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) {
        if(denominator == 0){
            throw new IllegalArgumentException("Denominator cannot be 0!");
        }
        this.denominator = denominator;
    }
    public static Fraction parseFraction(String str){
        str = str.replace("_", "");
        try{
            int[] elements = Arrays.stream(str.split("/")).mapToInt(Integer::parseInt).toArray();
            int num = elements[0];
            int denom = elements[1];

            if(isTooBig(num * denom)){
                throw new IllegalArgumentException("Too big fraction");
            }
            Integer.parseInt(String.valueOf(str.charAt(str.length() - 1)));
            return new Fraction(num, denom);
        }
        catch (NumberFormatException ignored){
        }
        try{
            long a = Long.parseLong(str);
            if(isTooBig(a)){
                throw new IllegalArgumentException("Too big fraction");
            }
            return getFraction(a);
        }
        catch (NumberFormatException ignored){
        }
        try{
            double a = Double.parseDouble(str);
            if(isTooBig(a)){
                throw new IllegalArgumentException("Too big fraction");
            }
            return getFraction(a);
        }
        catch (NumberFormatException ignored){
        }
        throw new IllegalArgumentException("not a fraction");
    }
    public static Fraction sum(Number a, Number b) {

        int num = getFraction(a).getNumerator() * getFraction(b).getDenominator()
                +  getFraction(a).getDenominator() * getFraction(b).getNumerator();

        int denom =  getFraction(a).getDenominator() * getFraction(b).getDenominator();

        return Fraction.simplify(new Fraction(num, denom));
    }
    public static Fraction subtract(Number a, Number b){

        int num = getFraction(a).getNumerator() * getFraction(b).getDenominator()
                -  getFraction(a).getDenominator() * getFraction(b).getNumerator();

        int denom = getFraction(a).getDenominator() * getFraction(b).getDenominator();

        return Fraction.simplify(new Fraction(num, denom));
    }
    public static Fraction multiply(Number a, Number b) {

        int num = getFraction(a).getNumerator() * getFraction(b).getNumerator();

        int denom = getFraction(a).getDenominator() * getFraction(b).getDenominator();

        return Fraction.simplify(new Fraction(num, denom));
    }
    public static Fraction divide(Number a, Number b) {

        int num = getFraction(a).getNumerator() * getFraction(b).getDenominator();

        int denom = getFraction(a).getDenominator() * getFraction(b).getNumerator();

        return Fraction.simplify(new Fraction(num, denom));
    }

    public static Fraction simplify(Fraction a){

        int newNum = getFraction(a).getNumerator();
        int newDenom = getFraction(a).getDenominator();

        return Fraction.toSimplify(newNum, newDenom);
    }

    public Fraction simplify() {

        return Fraction.toSimplify(numerator, denominator);
    }

    public static double toDouble(Fraction a) {
        return (double) getFraction(a).getNumerator() / getFraction(a).getDenominator();
    }

    private boolean isNegative(int numerator, int denominator) {
        return numerator < 0 != denominator < 0;
    }

    public static boolean isNegative(Number a) {

        return getFraction(a).getNumerator() < 0 != getFraction(a).getDenominator() < 0;
    }

    private static boolean isTooBig(Number a){
        double value = a.doubleValue();
        return value > MAX_VALUE;
    }

    private static Fraction toSimplify(int num, int denom) {

        if(isTooBig(Math.log(num)) || isTooBig(Math.log(denom))){
            throw new IllegalArgumentException("Too big fraction to simplify");
        }
        int simplificationIndex = Math.min(num, denom);
        Set<Integer> primes = Prime.primesInRange(Math.min(simplificationIndex, MAX_SIMPLIFICATION));

        for (int current : primes) {
            while (num % current == 0 && denom % current == 0){
                num /= current;
                denom /= current;
            }
        }
        return new Fraction(num, denom);
    }

    private static Fraction getFraction(Number a) {
        if(a instanceof Integer){

            return new Fraction(a.longValue(), 1);
        }
        else if(a instanceof Double){
            a = a.doubleValue() * 1_000_000;
            return new Fraction(a.longValue(), 1_000_000);
        }
        else if(a instanceof Fraction){
            return (Fraction) a;
        }
        else{
            throw new IllegalArgumentException("not a fraction");
        }
    }

    public static Fraction reverse(Fraction a){

        int num = a.getDenominator();
        int denom = a.getNumerator();
        return new Fraction(num, denom);
    }

    public Fraction reverse(){
        return new Fraction(denominator, numerator);
    }

    public static Fraction doubleToFraction(double a){
        int zeros = 0;
        while (true){
            a *= 10;
            zeros++;
            if(a == (int) a){
                break;
            }
        }
        int denom = (int) Math.pow(10, zeros);
        return new Fraction((int) a, denom).simplify();
    }

    @Override
    public String toString(){
        if(numerator % denominator == 0){
            StringBuilder value =  new StringBuilder(String.valueOf(numerator / denominator));
            value = new StringBuilder(getStyled(value, " "));
            return value.toString();
        }
        StringBuilder strNum = new StringBuilder(String.valueOf(numerator));
        strNum = getStyled(strNum, " ");

        StringBuilder strDenom = new StringBuilder(String.valueOf(denominator));
        strDenom = getStyled(strDenom, " ");

        return strNum + "/" + strDenom;
    }
    public String toStringWithUnderscores(){
        if(numerator % denominator == 0){
            StringBuilder value =  new StringBuilder(String.valueOf(numerator / denominator));
            value = new StringBuilder(getStyled(value, "_")).replace(value.length() - 1, value.length(), "");
            return value.toString();
        }
        StringBuilder strNum = new StringBuilder(String.valueOf(numerator));
        strNum = getStyled(strNum, "_").replace(strNum.length() - 1, strNum.length(), "");

        StringBuilder strDenom = new StringBuilder(String.valueOf(denominator));
        strDenom = getStyled(strDenom, "_").replace(strDenom.length() - 1, strDenom.length(), "");

        return strNum + "/" + strDenom;
    }

    public String toStringSimple(){
        if(numerator % denominator == 0){
            return String.valueOf(numerator / denominator);
        }
        return numerator + "/" + denominator;
    }

    private StringBuilder getStyled(StringBuilder str, String delimiter){
        int count = 0;
        for (int index = str.length(); index > 0; index--) {
            if(count++ % 3 == 0){
                str.insert(index, delimiter);
            }
        }
        return new StringBuilder(str.toString().trim());
    }
    @Override
    public int intValue() {
        return numerator / denominator;
    }

    @Override
    public long longValue() {
        return numerator / denominator;
    }

    @Override
    public float floatValue() {
        return (float) numerator / denominator;
    }

    @Override
    public double doubleValue() {
        return (double) numerator / denominator;
    }
}