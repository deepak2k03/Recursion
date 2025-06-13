#include <iostream>
using namespace std;
void generateBinary(int n, string output) {
    if (n == 0) {
        cout << output << endl;
        return;
    }
    generateBinary(n - 1, output + "0");
    generateBinary(n - 1, output + "1");
}
int main() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;
    generateBinary(n, "");
    return 0;
}
