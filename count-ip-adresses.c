#include <inttypes.h>
#include <string.h>

/*https://www.codewars.com/kata/526989a41034285187000de4/
5 kyu
*/

uint32_t ip_to_int(char *ip){
    uint32_t a, b, c, d;
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}

uint32_t ips_between (char *start, char* end)
{
    return ip_to_int(end) - ip_to_int(start);
}
