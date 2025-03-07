/*https://www.codewars.com/kata/54b72c16cd7f5154e9000457
4 kyu
 */

import java.util.regex.*;

public class MorseCodeDecoder {
    public static String decodeBits(String bits) {
        bits = bits.replaceAll("^0+|0+$", "");
        
        int min = Integer.MAX_VALUE;
        Pattern pattern = Pattern.compile("(0+|1+)");
        Matcher matcher = pattern.matcher(bits);

        while(matcher.find()){
            min = Math.min(min, matcher.group().length());
        }

        return bits.replaceAll("1{" + (3 * min) + ",}", "-")
                   .replaceAll("1{" + min + ",}", ".")
                   .replaceAll("0{" + (7 * min) + ",}", "   ")
                   .replaceAll("0{" + (3 * min) + ",}", " ")
                   .replaceAll("0{" + min + ",}", "");
    }

    public static String decodeMorse(String morseCode) {
        StringBuilder decodedMessage = new StringBuilder();
        String[] words = morseCode.trim().split("   ");

        for (String word : words) {
            String[] letters = word.split(" ");
            for (String letter : letters) {
                decodedMessage.append(MorseCode.get(letter));
            }
            decodedMessage.append(" ");
        }

        return decodedMessage.toString().trim();
    }
}
