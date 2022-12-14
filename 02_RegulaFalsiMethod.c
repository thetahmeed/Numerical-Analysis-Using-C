// Bisection Method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) ((3* x) - cos(x) -1)

int main()
{
    float a = 0, b = 0, error = 0, c, c_old;
    int i = 0;
    printf("Input Interval: ");
    scanf("%f %f", &a, &b);
    if ((f(a) * f(b)) > 0)
    {
        printf("Invalid Interval Exit!"); // to test whether search interval
        exit(1);                          // is okay or not
    }
    else if (f(a) == 0 || f(b) == 0)
    {
        printf("Root is one of interval bounds. Root is %f\n", f(a) == 0 ? a : b);
        exit(0);
    }
    printf("Ite\ta\t\tb\t\tm\t\tf(m)\t\terror\n");
    do
    {
        c_old = c;
        c = (((a*f(b)) - (b*f(a))) / (f(b)-f(a)));

        printf("%2d\t%4.6f\t%4.6f\t%4.6f\t%4.6f\t", i++, a, b, c, f(c));
        if (f(c) == 0)
        {
            printf("Root is %4.6f\n", c);
        }
        else if ((f(a) * f(c)) < 0)
        {
            b = c;
        }
        else
            a = c;
        error = fabs(c - c_old);
        if (i == 1)
        {
            printf("----\n");
        }
        else
            printf("%4.6f\n", error);
    } while (error > 0.00005);
    printf("Approximate Root is %4.6f", c);
    return 0;
}

// © https://github.com/thetahmeed

/* Output: 
Input Interval: 0 1
Ite     a               b               m               f(m)            error
 0      0.000000        1.000000        0.578085        -0.103255       ----
 1      0.578085        1.000000        0.605959        -0.004081       0.027873
 2      0.605959        1.000000        0.607057        -0.000159       0.001099
 3      0.607057        1.000000        0.607100        -0.000006       0.000043
Approximate Root is 0.607100
*/
