/* https://www.codewars.com/kata/5647c3858d4acbbe550000ad/
4 kyu 
 */

import java.util.regex.Pattern;

public class DivisibleByFive {
    public static Pattern pattern() {
        String regex = "^(0|1(10)*(0|11)(01*01|01*00(10)*(0|11))*1)+$";
        return Pattern.compile(regex);
    }
}