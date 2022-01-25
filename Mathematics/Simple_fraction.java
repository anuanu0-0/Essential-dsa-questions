import java.util.*;

public class Simple_fraction {

    /***
     * Given a fraction, Convert it into decimal.
     * If the fractional part is repeating, enclose it into paranthesis.
     * 
     * @param numerator
     * @param denominator
     * @return Decimal equivalent of the fraction as per problem statement
     */
    public String fractionToDecimal(int numerator, int denominator) {

        HashMap<Integer, Integer> hm = new HashMap<>();
        int quotient = numerator/denominator;
        int remainder = numerator%denominator;
        
        String result = Integer.toString(quotient);
        numerator = remainder;
        
        if(numerator == 0) {
            return result;
        }
        
        String fraction = "";
        while(numerator!=0 && !hm.containsKey(numerator)) {
            hm.put(numerator, fraction.length());
            numerator*=10;
            quotient = numerator/denominator;
            remainder = numerator%denominator;
            
            fraction += quotient;
            numerator = remainder;
        }
        
        if(numerator==0) {
            return result + "." + fraction;
        } else {
            int index = hm.get(numerator);
            fraction = fraction.substring(0,index) + "(" + fraction.substring(index) + ")" ;
            return result + "." + fraction;
        }
    }
};
