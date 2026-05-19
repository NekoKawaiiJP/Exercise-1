#include <stdio.h>

int main() 
{
    int age = 24;
    float height = 174.6; 
    char name[] = "X"; 
    char tittle[] = "X";

    printf("%s\n", tittle);   
    printf("Name: %s\n", name);                             // %s → string → char name[]
    printf("Age: %d\n", age);                               // %d → integer → int age
    printf("Height: %.1f cm\n", height);                    // %f → float → float height

    return 0;
}
