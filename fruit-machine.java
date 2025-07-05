/* https://www.codewars.com/kata/590adadea658017d90000039
  6 kyu
*/

import java.util.*;

public class Solution {
    public static int fruit(final String[][] fruits, final int[] spins) {
        List<String> items = new ArrayList<>();
        int target = 0;

        for (int i = 0; i < 3; i++) {
            items.add(fruits[i][spins[i]]);
        }

        Map<String, Integer> scores = Map.of(
                "Jack", 1, "Queen", 2, "King", 3, "Bar", 4, "Cherry", 5,
                "Seven", 6, "Shell", 7, "Bell", 8, "Star", 9, "Wild", 10
        );

        for (String str : scores.keySet()) {
            int count = Collections.frequency(items, str);

            if (count == 3) {
                target = scores.get(str)* 10;
                break;
            }

            if (count == 2) {
                target = scores.get(str) * ((items.contains("Wild") & str!="Wild")?2:1);
            }
        }

        return target;
    }
}