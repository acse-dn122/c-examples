#include <iostream>

void swap1(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

}
void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int *&a, int *&b) {
    int *temp = a;
    a = b;
    b = temp;
}

int main( ) {
    int x = 1;
    int y = 2;

    int *px = &x;
    int *py = &y;

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "px = " << px << ", py = " << py << std::endl;
    // swap1(x, y);
    // swap2(&x, &y);
    swap3(px, py);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "px = " << px << ", py = " << py << std::endl;
    return 0;
}