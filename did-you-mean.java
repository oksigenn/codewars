import java.util.Arrays;

/*https://www.codewars.com/kata/5259510fc76e59579e0009d4/
5 kyu
 */

public class Dictionary {
    private final String[] words;

    public Dictionary(String[] words) {
        this.words = words;
    }

    public String findMostSimilar(String to) {
        int minDistance = Integer.MAX_VALUE;
        String mostSimilar = "";
        for (String word : words) {
            int distance = LevenshteinDistance(word, to);
            if (distance < minDistance) {
                minDistance = distance;
                mostSimilar = word;
            }
        }
        return mostSimilar;
    }

    private int LevenshteinDistance(String a, String b) {
        int aLength = a.length();
        int bLength = b.length();
        int[][] res = new int[aLength + 1][bLength + 1];

        for (int i = 0; i <= aLength; i++) {
            res[i][0] = i;
        }
        for (int j = 0; j <= bLength; j++) {
            res[0][j] = j;
        }

        for (int i = 1; i <= aLength; i++) {
            for (int j = 1; j <= bLength; j++) {
                int cost = (a.charAt(i - 1) == b.charAt(j - 1)) ? 0 : 1;
                res[i][j] = Math.min(
                        Math.min(res[i - 1][j] + 1, res[i][j - 1] + 1),
                        res[i - 1][j - 1] + cost
                );
            }
        }

        return res[aLength][bLength];
    }
}