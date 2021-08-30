#include <stdio.h>
#include <complex.h>

#define __STDC_WANT_LIB_EXT1__ 1

int main() {

    #ifdef __STDC_NO_COMPLEX__
    	printf("Complex arithmetic is not supported.\n");
        exit(1);
    #else
        printf("Complex arithmetic is supported.\n");

        double complex a = 32.123 + 24.456 * I; // a is 32.123 + 24.456i
        double complex b = 23.789 + 42.987 * I; // b is 23.789 + 42.987i 
        double complex c = 3.0 + 2.0 * I; // c is 3.0 + 2.0i

        double complex sum_ab = a + b; // perform complex addition
        // double complex pwr = cpow( a, c ); // perform complex exponentiation

        printf( "\na is %f + %fi\n", creal( a ), cimag( a ));
        printf( "b is %f + %fi\n", creal( b ), cimag( b ));
        printf( "a + b is: %f + %fi\n", creal( sum_ab ), cimag( sum_ab ));
        printf( "a - b is: %f + %fi\n", creal( a - b ), cimag( a - b ));
        printf( "a * b is: %f + %fi\n", creal( a * b ), cimag( a * b ));
        printf( "a / b is: %f + %fi\n", creal( a / b ), cimag( a / b ));
        // printf( "a ^ c is %f + %fi\n", creal( pwr ), cimag( pwr ));
        

        double _Complex cx = 1.0 + 3.0*I;
        double complex cy = 1.0 - 4.0*I;

        printf("\nWorking with complex numbers:\n");
        printf("Starting values: cx = %.2f%+.2fi cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy)); 

        double complex sum = cx + cy;
        printf("\nThe sum cx + cy = %.2f%+.2fi\n", creal(sum), cimag(sum));

        double complex difference = cx - cy;
        printf("The difference cx - cy = %.2f%+.2fi\n", creal(difference), cimag(difference));

        double complex product = cx * cy;
        printf("The product cx * cy = %.2f%+.2fi\n", creal(product), cimag(product));

        double complex quotient = cx / cy;
        printf("The quotient cx / cy = %.2f%+.2fi\n", creal(quotient), cimag(quotient));

        double complex conjugate = conj(cx);
        printf("\nThe conjugate cx = %.2f%+.2fi\n", creal(conjugate), cimag(conjugate));



    #endif

}