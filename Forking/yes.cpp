//
// Created by ibz on 9/21/23.
//
#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4;
    int max, second_max;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the third number: ";
    cin >> num3;
    cout << "Enter the fourth number: ";
    cin >> num4;

    max = (num1 > num2) ? num1 : num2;
    max = (num3 > max) ? num3 : max;
    max = (num4 > max) ? num4 : max;

    second_max = (num1 < max) ? num1 : max;
    second_max = (num2 < max && num2 > second_max) ? num2 : second_max;
    second_max = (num3 < max && num3 > second_max) ? num3 : second_max;
    second_max = (num4 < max && num4 > second_max) ? num4 : second_max;

    cout << "Second highest number: " << second_max << endl;

    return 0;
}
