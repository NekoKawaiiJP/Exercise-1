#include <stdio.h>

int main() 
{
    int age = 24;
    float height = 154.6; 
    char name[] = "MUHAMMAD SYUHAIRUDEN BIN NAMRAH"; 
    char tittle[] = "MSU";

    printf("%s\n", tittle);   
    printf("Name: %s\n", name);                             // %s → string → char name[]
    printf("Age: %d\n", age);                               // %d → integer → int age
    printf("Height: %.1f cm\n", height);                    // %f → float → float height

    return 0;
}