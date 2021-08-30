#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buf;

void myFunction() {
    printf("in myFunction()\n");
    longjmp(buf, 1);

    /* NOT REACHED */
    printf("You will never see this because I longjmp'd");
}

int main()
{

    if (setjmp(buf))
        printf("back in main\n");
    else{
        printf("first time through\n");
        myFunction();
    }




    // int i = setjmp(buf);
    // printf("i=%d\n", i);

    // if (i != 0) exit(0);

    // longjmp(buf, 42);
    // printf("Does this line get printed?\n");

    return 0;
}

switch(setjmp(jbuf)) {
    case 0:
        apple = *suspicious;
        break;
    case 1;
        printf("suspicious is indeed a bad pointer\n");
        break;
    default:
        die("unexpected value returned by setjmp");
}