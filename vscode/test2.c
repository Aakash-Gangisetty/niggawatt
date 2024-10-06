#include <windows.h>
#include <stdio.h>

void setcolor(int textcolor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textcolor);
}

int main() {
    setcolor(2);
    printf("This text is green\n");
    setcolor(4);
    printf("This text is red!\n");
    setcolor(7);
    return 0;
}
