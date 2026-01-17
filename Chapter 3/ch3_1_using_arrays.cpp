/**
 * CHAPTER 3: USING ARRAYS
 * --- THE CONCEPT ---
 * 1. Arrays: Fixed-size concrete data structures using integer indices.
 * 2. Insertion/Removal: Requires "shifting" elements to maintain order.
 * 3. Sorting: Arranging elements (e.g., Insertion Sort).
 * 4. Multi-dimensional Arrays: Arrays of arrays used for matrices and game boards.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =============================================================================
// 3.1.1 STORING GAME ENTRIES (High Scores)
// =============================================================================

class GameEntry {
public:
    GameEntry(const string& n = "", int s = 0) : name(n), score(s) {}
    string getName() const { return name; }
    int getScore() const { return score; }
private:
    string name;
    int score;
};

class Scores {
public:
    Scores(int maxEnt = 10) {
        maxEntries = maxEnt;
        entries = new GameEntry[maxEntries];
        numEntries = 0;
    }
    ~Scores() { delete[] entries; }

    /**
     * INSERTION LOGIC:
     * To maintain a sorted list (Highest to Lowest), we find the spot
     * and shift all lower scores to the right.
     */
    void add(const GameEntry& e) {
        int newScore = e.getScore();
        if (numEntries == maxEntries) {
            if (newScore <= entries[maxEntries - 1].getScore()) return; 
        } else {
            numEntries++;
        }

        int i = numEntries - 2;
        while (i >= 0 && newScore > entries[i].getScore()) {
            entries[i + 1] = entries[i]; // Shift right
            i--;
        }
        entries[i + 1] = e; // Insert in spot
    }

    /**
     * REMOVAL LOGIC:
     * To remove index i, we shift all elements to the left.
     */
    GameEntry remove(int i) {
        if (i < 0 || i >= numEntries) throw out_of_range("Invalid index");
        GameEntry e = entries[i];
        for (int j = i + 1; j < numEntries; j++) {
            entries[j - 1] = entries[j]; // Shift left
        }
        numEntries--;
        return e;
    }

private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};

// =============================================================================
// 3.1.2 SORTING AN ARRAY (Insertion Sort)
// =============================================================================

/**
 * 
 */
void insertionSort(char* A, int n) {
    for (int i = 1; i < n; i++) {
        char cur = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > cur)) {
            A[j + 1] = A[j]; // Shift sorted elements right
            j--;
        }
        A[j + 1] = cur; // Insert cur in sorted position
    }
}

// =============================================================================
// 3.1.3 TWO-DIMENSIONAL ARRAYS (Tic-Tac-Toe)
// =============================================================================

/**
 * 
 */
class TicTacToe {
public:
    const int X = 1, O = -1, EMPTY = 0;
    int board[3][3];
    int currentPlayer;

    TicTacToe() { clearBoard(); }

    void clearBoard() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) board[i][j] = EMPTY;
        currentPlayer = X;
    }

    void putMark(int i, int j) {
        board[i][j] = currentPlayer;
        currentPlayer = -currentPlayer; // Switch player
    }

    bool isWin(int mark) {
        int win = 3 * mark;
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] + board[i][1] + board[i][2] == win) return true; // Rows
            if (board[0][i] + board[1][i] + board[2][i] == win) return true; // Cols
        }
        if (board[0][0] + board[1][1] + board[2][2] == win) return true; // Diag 1
        if (board[2][0] + board[1][1] + board[0][2] == win) return true; // Diag 2
        return false;
    }

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = (board[i][j] == X ? 'X' : (board[i][j] == O ? 'O' : ' '));
                cout << c << (j < 2 ? "|" : "");
            }
            if (i < 2) cout << "\n-+-+-\n";
        }
        cout << endl;
    }
};

// =============================================================================
// MAIN EXECUTION
// =============================================================================

int main() {
    // 1. Dynamic Matrix Allocation Example (int**)
    int rows = 3, cols = 3;
    int** M = new int*[rows];
    for (int i = 0; i < rows; i++) M[i] = new int[cols];
    
    // Cleanup dynamic matrix
    for (int i = 0; i < rows; i++) delete[] M[i];
    delete[] M;

    // 2. STL Vector of Vectors (Preferred approach)
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));

    // 3. Run Tic-Tac-Toe Simulation
    TicTacToe game;
    game.putMark(1, 1); // X center
    game.putMark(0, 0); // O top-left
    game.printBoard();

    return 0;
}
