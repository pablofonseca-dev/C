//Input & Output Default Library
#include <stdio.h>

int main(){
    int x = 10;
    printf("\n");
    printf(&x);
    int* xPointer = &x;
    logPointersMessage(xPointer);
    changeMemoryPositionValue(xPointer, 40);
    logPointersMessage(xPointer);
    return 0;
}

//This function receives a pointer
void changeMemoryPositionValue(int* x, int value){
    //Get memory number from the pointer memory address
    int tempMemoryCopy = *x;
    tempMemoryCopy = value;
    //Update memory position value
    *x = tempMemoryCopy;
    printf("\nMemory address value changed\n");

}

//This function prints messages in console
void logPointersMessage(int* argPointer){
    printf("The value of the variable is: %d\n", *argPointer);
    printf("The memory address is: <%d> \n", argPointer);
}
