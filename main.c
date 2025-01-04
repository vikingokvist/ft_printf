#include "./include/ft_printf.h"

int     main(void)
{
    printf("--------------------------------- (char)\n");
    ft_printfb("My fav char is = %c\n", 'X');
        printf("OG fav char is = %c\n", 'X');
    printf("--------------------------------- (str)\n");
    ft_printfb("My fav str is = %s\n", "HELLO WORLD");
        printf("OG fav str is = %s\n", "HELLO WORLD");
    printf("--------------------------------- (null)\n");
    ft_printfb("My fav null_str is = %s\n", NULL);
        printf("OG fav null_str is = %s\n", NULL);
    printf("--------------------------------- (04d)\n");
    ft_printfb("My fav number is = [%04d]\n", -42);
        printf("OG fav number is = [%04d]\n", -42);
    
    printf("--------------------------------- (010d)\n");
    ft_printfb("My fav number is = [%010d]\n", -42);
        printf("OG fav number is = [%010d]\n", -42);
    printf("--------------------------------- (d with 0)\n");
    ft_printfb("My fav number is = [%d]\n", 0);
        printf("OG fav number is = [%d]\n", 0);
    printf("--------------------------------- (+d with 0)\n");
    ft_printfb("My fav number is = [%+d]\n", 0);
        printf("OG fav number is = [%+d]\n", 0);
    printf("--------------------------------- (d with INT_MAX)\n");
    ft_printfb("My fav number is = [%d]\n", 2147483647);
        printf("OG fav number is = [%d]\n", 2147483647);
    printf("--------------------------------- (.5d)\n");
    ft_printfb("My fav number is = [%.5d]\n", -42);
        printf("OG fav number is = [%.5d]\n", -42);
    printf("--------------------------------- (.5d with 0)\n");
    ft_printfb("My fav number is = [%.5d]\n", 0);
        printf("OG fav number is = [%.5d]\n", 0);
    printf("--------------------------------- (10.5d)\n");
    ft_printfb("My fav number is = [%10.5d]\n", -42);
        printf("OG fav number is = [%10.5d]\n", -42);
    printf("--------------------------------- (+0.5d)\n");
    ft_printfb("My fav number is = [%+0.5d]\n", 42);
        printf("OG fav number is = [%+0.5d]\n", 42);
    printf("--------------------------------- (+10d)\n");
    ft_printfb("My fav number is = [%d]\n", 42);
        printf("OG fav number is = [%d]\n", 42);
    printf("--------------------------------- (+0d)\n");
    ft_printfb("My fav number is = [%+0d]\n", 42);
        printf("OG fav number is = [%+0d]\n", 42);
    printf("--------------------------------- (-10.5d)\n");// NEEDS FIX
    ft_printfb("My fav number is = [%-10.5d]\n", -42);
        printf("OG fav number is = [%-10.5d]\n", -42);
    printf("--------------------------------- (+010d)\n"); // needs fix
    ft_printfb("My fav number is = [%+010d]\n", 42);
        printf("OG fav number is = [%+010d]\n", 42);
    printf("--------------------------------- (-+10.5d)\n"); // NEEDS FIX
    ft_printfb("My fav number is = [%-+10.5d]\n", 42);
        printf("OG fav number is = [%-+10.5d]\n", 42);
    printf("--------------------------------- ( 10d)\n"); // NEEDS FIX
    ft_printfb("My fav number is = [% 10d]\n", 42);
        printf("OG fav number is = [% 10d]\n", 42);
    printf("--------------------------------- ( 10.5d)\n"); // NEEDS FIZ
    ft_printfb("My fav number is = [% 10.5d]\n", 42);
        printf("OG fav number is = [% 10.5d]\n", 42);
    printf("--------------------------------- (+10.5d)\n"); //NEEDS FIX
    ft_printfb("My fav number is = [%+10.5d]\n", -42);
        printf("OG fav number is = [%+10.5d]\n", -42);
    printf("--------------------------------- (- 10.5d)\n"); //NEEDS FIX
    ft_printfb("My fav number is = [%- 10.5d]\n", -42);
        printf("OG fav number is = [%- 10.5d]\n", -42);
    printf("--------------------------------- (+-10.5d)\n"); //NEEDS FIX
    ft_printfb("My fav number is = [%+-10.5d]\n", 42);
        printf("OG fav number is = [%+-10.5d]\n", 42);
    printf("--------------------------------- (-010.5d)\n"); // NEEDS FIX
    ft_printfb("My fav number is = [%-010.5d]\n", 42);
        printf("OG fav number is = [%-010.5d]\n", 42);
    printf("--------------------------------- (-05d)\n");
    ft_printfb("My fav number is = [%-05d]\n", -42);
        printf("OG fav number is = [%-05d]\n", -42);
    printf("--------------------------------- (010.5d)\n");
    ft_printfb("My fav number is = [%010.5d]\n", -42);
        printf("OG fav number is = [%010.5d]\n", -42);
    printf("--------------------------------- (-10d)\n");
    ft_printfb("My fav number is = [%-10d]\n", -42);
        printf("OG fav number is = [%-10d]\n", -42);

    printf("\n\n--------------------------------- ( 010d)\n"); // NEEDS FIX
    ft_printfb("My fav number is = [% 010d]\n", 42);
        printf("OG fav number is = [% 010d]\n", 42);
    printf("--------------------------------- (.0d)\n"); //NEEDS FIX
    ft_printfb("My fav number is = [%.0d]\n", 0);
        printf("OG fav number is = [%.0d]\n", 0);
    printf("--------------------------------- (d with INT_MIN)\n");
    ft_printfb("My fav number is = [%d]\n", -2147483648);
        printf("OG fav number is = [%d]\n", -2147483648);


    return (0);
}
