#include <iostream>
using namespace std;

class Solution {
  public:
    // Function to print steps and return count of moves
    int towerOfHanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return 1;  // Base case: only one move
    }
    int moves = 0;
    moves += towerOfHanoi(n - 1, from, aux, to); // Step 1: move n-1 disks to aux
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    moves += 1; // Step 2: move the nth disk from source to destination (this line)
    moves += towerOfHanoi(n - 1, aux, to, from); // Step 3: move n-1 disks from aux to destination
    return moves;
}

};

int main() {
    Solution sol;
    int n;
    cin >> n; // number of disks
    int totalMoves = sol.towerOfHanoi(n, 1, 3, 2); // rods: 1 = from, 3 = to, 2 = aux
    cout << "Total moves: " << totalMoves << endl;
    return 0;
}
