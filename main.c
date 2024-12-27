#include "./include/ft_printf.h"

int     main(void)
{
    char    x = 'X';
    char    str[12] = "HELLO WORLD";
    char    *null_str = NULL;
    int     pos_int = 42;
    int     neg_int = 42;

    // ft_printfb("My fav char is = %c\n", x);
    // ft_printfb("My fav str is = %s\n", str);
    // ft_printfb("My fav null_str is = %s\n", null_str);
    ft_printfb("My fav number is = [%10.5d]\n", pos_int);
    printf("OG fav number is = [%10.5d]\n", pos_int);
    ft_printfb("My fav number is = [%-10.5d]\n", neg_int);
    printf("OG fav number is = [%-10.5d]\n", neg_int);

    return (0);
}
/*
--------------------------------------------------------------------------------Precision

printf("%.5d\n", 42);        // "00042" (precision forces 5 digits)
printf("%.5d\n", -42);       // "-00042" (keeps negative sign)

// --- && width---
printf("%10.5d\n", 42);      // "     00042" (width 10, precision 5)

// --- && zero padding (0)---
printf("%010.5d\n", 42);     // "     00042" (precision overrides zero-padding)

// --- && left allignment---
printf("%-10.5d\n", num);    // Left-aligned: "00042     "

// --- && sign---
printf("%+10.5d\n", num);    // "+00042"
printf("% 10.5d\n", num);    // " 00042"

--------------------------------------------------------------------------- zero padding

printf("%010d\n", num);      // Zero-padded: "0000000042"
printf("%010d\n", neg_num);  // Zero-padded: "-000000042"

--------------------------------------------------------------------------------------------

// --- left alignment && width ---
printf("%10d\n", num);       // Right-aligned, width 10: "        42"
printf("%-10d\n", num);      // Left-aligned, width 10: "42        "
printf("%010d\n", num);      // Zero-padded, width 10: "0000000042"

------------------------------------------------------------------------------------SIGN

// --- Sign (+) ---
printf("%+d\n", num);        // Always show sign: "+42"
printf("%+d\n", neg_num);    // Keeps negative sign: "-42"

----------------------------------------------------------------------------------SPACE

printf("% d\n", num);        // Space for positive: " 42"
printf("% d\n", neg_num);    // Keeps negative sign: "-42"

--------------------------------------------------------------------------------------------
*/

