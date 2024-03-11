#include <stdio.h>
int main()
{
    for (int i = 1; i <= 200; i++)
    {
        if ((i % 5 == 0) && (i % 7 == 0))
        {
            printf("%s\n", "FOOBAR");
        }
        else if (i % 7 == 0)
        {
            printf("%s\n", "BAR");
        }
        else if (i % 5 == 0)
        {
            printf("%s\n", "FOO");
        }
        else
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
