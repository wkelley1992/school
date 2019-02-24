#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

char alphabet[] = "abc";
char multiplicationTable[3][3] = {
  { 'a', 'c', 'c' },
  { 'a', 'a', 'b' },
  { 'c', 'c', 'c' }
};  // Dimensions are k*k.

char *s = "bbbba";  // The string

int N = strlen(s);
int k = strlen(alphabet);

/* Recursive function that returns 1 if it is
 * possible to get symbol from
 * string s of length n.
 */
int isSymbolPossible(char *s, char symbol, int n) {
    int i, j1, j2;
    if (n == 1) {
        return *s == symbol;
    }
    /* Loop over all possible ways to split the string in two. */
    for (i=0; i < n - 1; i++) {
        /* For each such subdivision, find all the multiplications that yield the desired symbol */
        for (j1 = 0; j1 < k; j1++) {
            for (j2=0; j2 < k; j2++) {
                if (multiplicationTable[j1][j2] == symbol) {
                    /* Check if it is possible to get the required left and right symbols for this multiplication */
                    if (isSymbolPossible(s, alphabet[j1], i+1) &&
                            isSymbolPossible(s+i+1, alphabet[j2], n - i - 1)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    if (isSymbolPossible(s,'a',N)) {
      cout << "Yes!\n";
    } else {
      cout << "No...\n";
    }
    return 0;
}