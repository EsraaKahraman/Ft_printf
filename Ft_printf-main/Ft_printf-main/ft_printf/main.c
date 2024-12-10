#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *s =  NULL;
    printf("%d\n    ", printf(" %p %p ", s, s));
    ft_printf("%d", ft_printf(" %p %p ", s, s));
}