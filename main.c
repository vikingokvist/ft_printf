#include "./include/ft_printf.h"
#include <limits.h>

int     main(void)
{
    void *x;
    void *ptr = &x;
    char *nil_ptr = NULL;
    int   n = 0;

    printf("----------------------------------------- (char)\n");
    n = ft_printfb("My fav char is = %c - ", 'X');
    printf("(%d)\n", n);
        n = printf("OG fav char is = %c - ", 'X');
        printf("(%d)\n", n);
    printf("----------------------------------------- (str)\n");
    n = ft_printfb("My fav str is = %s - ", "HELLO WORLD");
    printf("(%d)\n", n);
        n = printf("OG fav str is = %s - ", "HELLO WORLD");
        printf("(%d)\n", n);
    printf("----------------------------------------- (null)\n");
    n = ft_printfb("My fav null_str is = %s - ", NULL);
    printf("(%d)\n", n);
        n = printf("OG fav null_str is = %s - ", NULL);
        printf("(%d)\n", n);
    printf("----------------------------------------- (04d)\n");
    n = ft_printfb("My fav number is = [%04d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%04d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (010d)\n");
    n = ft_printfb("My fav number is = [%010d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%010d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (d with 0)\n");
    n = ft_printfb("My fav number is = [%d] - ", 0);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%d] - ", 0);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+d with 0)\n");
    n = ft_printfb("My fav number is = [%+d] - ", 0);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%+d] - ", 0);
        printf("(%d)\n", n);
    printf("----------------------------------------- (d with INT_MAX)\n");
    n = ft_printfb("My fav number is = [%d] - ", 2147483647);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%d] - ", 2147483647);
        printf("(%d)\n", n);
    printf("----------------------------------------- (.5d)\n");
    n = ft_printfb("My fav number is = [%.5d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%.5d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (.5d with 0)\n");
    n = ft_printfb("My fav number is = [%.5d] - ", 0);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%.5d] - ", 0);
        printf("(%d)\n", n);
    printf("----------------------------------------- (10.5d)\n");
    n = ft_printfb("My fav number is = [%10.5d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%10.5d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+0.5d)\n");
    n = ft_printfb("My fav number is = [%+0.5d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%+0.5d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+10d)\n");
    n = ft_printfb("My fav number is = [%d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+0d)\n");
    n = ft_printfb("My fav number is = [%+0d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%+0d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (-10.5d)\n");
    n = ft_printfb("My fav number is = [%-10.5d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%-10.5d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+010d)\n");
    n = ft_printfb("My fav number is = [%+010d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%+010d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (-+10.5d)\n");
    n = ft_printfb("My fav number is = [%-+10.5d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%-+10.5d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- ( 10d)\n");
    n = ft_printfb("My fav number is = [% 10d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [% 10d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- ( 10.5d)\n");
    n = ft_printfb("My fav number is = [% 10.5d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [% 10.5d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+10.5d)\n");
    n = ft_printfb("My fav number is = [%+10.5d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%+10.5d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (- 10.5d)\n");
    n = ft_printfb("My fav number is = [%- 10.5d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%- 10.5d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (+-10.5d)\n"); 
    n = ft_printfb("My fav number is = [%+-10.5d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%+-10.5d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (-010.5d)\n");
    n = ft_printfb("My fav number is = [%-010.5d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%-010.5d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (-05d)\n");
    n = ft_printfb("My fav number is = [%-05d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%-05d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (010.5d)\n");
    n = ft_printfb("My fav number is = [%010.5d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%010.5d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (-10d)\n");
    n = ft_printfb("My fav number is = [%-10d] - ", -42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%-10d] - ", -42);
        printf("(%d)\n", n);
    printf("----------------------------------------- ( 010d)\n"); 
    n = ft_printfb("My fav number is = [% 010d] - ", 42);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [% 010d] - ", 42);
        printf("(%d)\n", n);
    printf("----------------------------------------- (.0d)\n"); //NEEDS FIX!!!!!!!!!!!
    n = ft_printfb("My fav number is = [%.0d] - ", 0);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%.0d] - ", 0);
        printf("(%d)\n", n);
    printf("----------------------------------------- (d with INT_MIN)\n");
    n = ft_printfb("My fav number is = [%d] - ", -2147483648);
    printf("(%d)\n", n);
        n = printf("OG fav number is = [%d] - ", -2147483648);
        printf("(%d)\n", n);
    printf("----------------------------------------- (pos x)\n");
    n = n = ft_printfb("My fav hexadcm is = [%X] - ", 100);
    printf("(%d)\n", n);
        n = n = printf("OG fav hexadcm is = [%X] - ", 100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (pos #x)\n");
    n = ft_printfb("My fav hexadcm is = [%#x] - ", 100);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%#x] - ", 100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (INT_MAX x)\n");
    n = ft_printfb("My fav hexadcm is = [%x] - ", INT_MAX);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%x] - ", INT_MAX);
        printf("(%d)\n", n);
    printf("----------------------------------------- (neg x)\n");
    n = ft_printfb("My fav hexadcm is = [%x] - ", -10);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%x] - ", -10);
        printf("(%d)\n", n);
    printf("----------------------------------------- (INT_MIN x)\n");
    n = ft_printfb("My fav hexadcm is = [%x] - ", INT_MIN);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%x] - ", INT_MIN);
        printf("(%d)\n", n);
    printf("----------------------------------------- (neg #x)\n");
    n = ft_printfb("My fav hexadcm is = [%#x] - ", -100);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%#x] - ", -100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (pos X)\n");
    n = ft_printfb("My fav hexadcm is = [%X] - ", 100);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%X] - ", 100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (pos #X)\n");
    n = ft_printfb("My fav hexadcm is = [%#X] - ", 100);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%#X] - ", 100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (neg X)\n");
    n = ft_printfb("My fav hexadcm is = [%X] - ", -100);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%X] - ", -100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (neg #X)\n");
    n = ft_printfb("My fav hexadcm is = [%#X] - ", -100);
    printf("(%d)\n", n);
        n = printf("OG fav hexadcm is = [%#X] - ", -100);
        printf("(%d)\n", n);
    printf("----------------------------------------- (ptr)\n");
    n = ft_printfb("My fav pointer is = [%#p] - ", ptr);
    printf("(%d)\n", n);
        n = printf("OG fav pointer is = [%#p] - ", ptr);
        printf("(%d)\n", n);
    printf("----------------------------------------- (nil ptr)\n");
    n = ft_printfb("My fav pointer is = [%p] - ", nil_ptr);
    printf("(%d)\n", n);
        n = printf("OG fav pointer is = [%p] - ", nil_ptr);
        printf("(%d)\n", n);
    printf("----------------------------------------- (unsigned)\n");
    n = ft_printfb("My fav size_t  is = [%#u] - ", 420);
    printf("(%d)\n", n);
        n = printf("OG fav size_t  is = [%#u] - ", 420);
        printf("(%d)\n", n);
    printf("----------------------------------------- (unsigned neg)\n");
    n = ft_printfb("My fav size_t  is = [%u] - ", -420);
    printf("(%d)\n", n);
        n = printf("OG fav size_t  is = [%u] - ", -420);
        printf("(%d)\n", n);
    return (0);
}
