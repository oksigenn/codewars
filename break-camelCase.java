/*https://www.codewars.com/kata/5208f99aee097e6552000148
6 kyu
 */

class Solution {
  public static String camelCase(String input) {
    StringBuilder result = new StringBuilder();
    for(int i = 0; i<input.length();i++){
        char curChar = input.charAt(i);

        if(Character.isUpperCase(curChar)){
            result.append(' ').append(Character.toLowerCase(curChar));
        } else{
            result.append(curChar);
        }
    }

    return result.toString();
  }
}