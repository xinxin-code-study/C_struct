#include <stdarg.h>  
#include <stdio.h>  
  
void print_numbers(int n, ...) {  
    va_list args;  
    va_start(args, n);  
  
    for (int i = 0; i < n; ++i) {  
        int value = va_arg(args, int);  
        printf("%d ", value);  
    }  
  
    va_end(args);  
    printf("\n");  
}  
  
int main() {  
    print_numbers(3, 1, 2, 3);    // Êä³ö: 1 2 3  
    print_numbers(5, 5, 10, 15, 20, 25); // Êä³ö: 5 10 15 20 25  
    return 0;  
}
