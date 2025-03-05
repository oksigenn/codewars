/*https://www.codewars.com/kata/54b724efac3d5402db00065e
6 kyu
 */

public class MorseCodeDecoder {
    public static String decode(String s){
        String[] code = s.trim().split("   ");
        String decoded = "";

        for (String word: code){
            String[] letters = word.split(" ");
            for(String letter: letters){
                decoded += MorseCode.get(letter);
            }
            decoded += " ";
        }
        return decoded.trim();
    }
}