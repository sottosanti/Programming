#include <stdio.h>

int display();

int main()
{
    int (*func_ptr)();
    func_ptr = display;

    printf("Address of function display is %p\n", func_ptr);

    (*func_ptr)();

    return 0;
}

int display() 
{
    printf("\n--Displaying some texts--\n");
    return 0;
}