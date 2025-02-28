#include <stdio.h>
#include <ctype.h>

/*https://www.codewars.com/kata/513e08acc600c94f01000001
5 kyu
*/

void rgb(int r, int g, int b, char hex[7]) {
    if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;
  
    sprintf(hex, "%02X%02X%02X", r, g, b);
    hex[6] = '\0';
}
