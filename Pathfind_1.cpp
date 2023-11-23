#include <iostream>
#include <time.h>

using namespace std;

void printArray(int arrayMap[10][10]) {
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (arrayMap[i][j] < 10) {
                cout<<"0"<< arrayMap[i][j] << " ";
            } else {
                cout << arrayMap[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int arrayMap[10][10];
    srand(time(NULL));
    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            arrayMap[i][j] = ((rand() % 5) + 1);
        }
    }

    printArray(arrayMap);
    cout << endl << endl;

    int tmpTotal = 0;
    int answerMap[10][10];
    for (int i = 9; i > -1; i--) {
        for (int j = 9; j > -1; j--) {
            if (i == 9 && j == 9) {
                answerMap[i][j] = arrayMap[i][j];
            }

            if (i == 9 && j != 9) {
                answerMap[i][j] = answerMap[i][j + 1] + arrayMap[i][j];
            }

            if (i != 9 && j == 9) {
                answerMap[i][j] = answerMap[i + 1][j] + arrayMap[i][j];
            }

            if (i != 9 && j != 9) {
                if (answerMap[i + 1][j] < answerMap[i][j + 1]) {
                    answerMap[i][j] = answerMap[i + 1][j] + arrayMap[i][j];
                } else {
                    answerMap[i][j] = answerMap[i][j + 1] + arrayMap[i][j];
                }
            }
        }
    }

    printArray(answerMap);
}