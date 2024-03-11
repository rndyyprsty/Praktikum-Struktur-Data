#include <iostream>

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    const double PI = 3.14159265358979323846;
    return PI * radius * radius;
}

// Function to check if a number is even or odd
void checkEvenOdd(int number) {
    if (number % 2 == 0) {
        std::cout << number << " is even." << std::endl;
    } else {
        std::cout << number << " is odd." << std::endl;
    }
}

int main() {
    double radius = 5.5;
    int number = 13;

    std::cout << "The area of the circle with radius " << radius << " is " << calculateCircleArea(radius) << std::endl;
    checkEvenOdd(number);

    return 0;
}