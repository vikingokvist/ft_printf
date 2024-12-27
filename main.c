#include "./include/ft_printf.h"

int     main(void)
{
    char    x = 'X';
    char    str[12] = "HELLO WORLD";
    char    *null_str = NULL;
    int     i_int = 420;

    // ft_printfb("My fav char is = %c\n", x);
    // ft_printfb("My fav str is = %s\n", str);
    // ft_printfb("My fav null_str is = %s\n", null_str);
    ft_printfb("My fav number is = %05d\n", i_int);
    printf("test = %04d\n", 420);

    return (0);
}
// #include <stdio.h>

// int main(void)
// {
//     int num = 42;
//     int neg_num = -42;

//     // --- Width and Padding (0, -) ---
//     printf("%10d\n", num);       // Right-aligned, width 10: "        42"
//     printf("%-10d\n", num);      // Left-aligned, width 10: "42        "
//     printf("%010d\n", num);      // Zero-padded, width 10: "0000000042"

//     // --- Sign (+) ---
//     printf("%+d\n", num);        // Always show sign: "+42"
//     printf("%+d\n", neg_num);    // Keeps negative sign: "-42"

//     // --- Space (' ') ---
//     printf("% d\n", num);        // Space for positive: " 42"
//     printf("% d\n", neg_num);    // Keeps negative sign: "-42"

//     // --- Precision (.) ---
//     printf("%.5d\n", num);       // Precision 5: "00042"
//     printf("%.5d\n", neg_num);   // Precision 5: "-00042"

//     // --- Width and Precision Combined ---
//     printf("%10.5d\n", num);     // Width 10, Precision 5: "     00042"
//     printf("%10.5d\n", neg_num); // Width 10, Precision 5: "    -00042"
//     printf("%-10.5d\n", num);    // Left-aligned: "00042     "
//     printf("%010.5d\n", num);    // Zero-padded ignored due to precision: "     00042"

//     // --- Combination with Sign (+) and Space (' ') ---
//     printf("%+10.5d\n", num);    // "+00042"
//     printf("% 10.5d\n", num);    // " 00042"

//     // --- Combination with Zero Padding ---
//     printf("%010d\n", num);      // Zero-padded: "0000000042"
//     printf("%010d\n", neg_num);  // Zero-padded: "-000000042"

//     // --- Edge cases with zero and precision ---
//     printf("%.0d\n", 0);         // Precision 0, value 0: ""
//     printf("%10.0d\n", 0);       // Width 10, precision 0, value 0: "          "
//     printf("%010.0d\n", 0);      // Zero-padded ignored due to precision: "          "
//     printf("%10d\n", 0);         // Width 10, value 0: "         0"

//     return 0;
// }
