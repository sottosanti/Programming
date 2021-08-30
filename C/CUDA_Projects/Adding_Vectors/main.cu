#include <stdio.h>

#define SIZE 1024

__global__ 
void kernel(int *a, int *b, int *c, int n)
{
    int i = threadIdx.x;
    // printf("Thread %d\n", i);

    if(i < n)
        c[i] = a[i] + b[i];
}

int main(void)
{
    int *a, *b, *c;

    // Available to both CPU and GPU
    cudaMallocManaged(&a, SIZE * sizeof(int));
    cudaMallocManaged(&b, SIZE * sizeof(int));
    cudaMallocManaged(&c, SIZE * sizeof(int));

    for(int i = 0; i < SIZE; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    // Specify the launch configuration of the kernel
    // The first parameter id the number of thread blocks
    // The next parameter is the number of threads within each thread block
    kernel<<<1, SIZE>>> (a, b, c, SIZE);

    // To ensure the CPU waits for the GPU to finish
    cudaDeviceSynchronize();

    for(int i = 0; i < 10; i++)
        printf("c[%d] = %d\n", i, c[i]);

    cudaFree(a);
    cudaFree(b);
    cudaFree(b);

    return 0;
}