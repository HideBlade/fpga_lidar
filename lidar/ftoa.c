#include "lidar.h"


//https://www.geeksforgeeks.org/convert-floating-point-number-string/
/* ^courtesy */
// reverses a string 'str' of length 'len'

void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}
// Implementation of itoa()
 
 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }
 
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}
 
// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;
 
    // Extract floating part
    float fpart = n - (float)ipart;
 
    // convert integer part to string
    int i = intToStr(ipart, res, 0);
 
    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot
 
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);
 
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}


/* float atof(const char* s){ */
/*   float rez = 0, fact = 1; */
/*   if (*s == '-'){ */
/*     s++; */
/*     fact = -1; */
/*   }; */
/*   for (int point_seen = 0; *s; s++){ */
/*     if (*s == '.'){ */
/*       point_seen = 1;  */
/*       continue; */
/*     }; */
/*     int d = *s - '0'; */
/*     if (d >= 0 && d <= 9){ */
/*       if (point_seen) fact /= 10.0f; */
/*       rez = rez * 10.0f + (float)d; */
/*     }; */
/*   }; */
/*   return rez * fact; */
/* } */
