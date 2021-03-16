#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int nLines;
int nColumns;
char lcdNumber[23][12];
char lcdNumbers[8][23][12];

void setLcdSize(int size) {
    nLines = 2 * size + 3;
    nColumns = size + 2;
}

void clearLcd() {
    int i;
    for (i = 0; i < nLines; i++) {
        int j;
        for (j = 0; j < nColumns; j++) {
            lcdNumber[i][j] = ' ';
        }
    }    
}

void drawLine(int lineNumber) {
    int j;
    for (j = 1; j < nColumns - 1; j++) {
        lcdNumber[lineNumber][j] = '-';
    }
}

void drawFirstLine() {
    drawLine(0);
}

void drawMiddleLine() {
    drawLine(nLines / 2);
}

void drawLastLine() {
    drawLine(nLines - 1);
}

void drawFirstColumn(int columnNumber) {
    int i;
    for (i = 1; i < nLines / 2; i++) {
        lcdNumber[i][columnNumber] = '|';    
    }
}

void drawLastColumn(int columnNumber) {
    int i;
    for (i = (nLines / 2) + 1; i < nLines - 1; i++) {
        lcdNumber[i][columnNumber] = '|';    
    }
}

void drawFirstLeftColumn() {
    drawFirstColumn(0);
}

void drawLastLeftColumn() {
    drawLastColumn(0);
}

void drawFirstRightColumn() {
    drawFirstColumn(nColumns - 1);
}

void drawLastRightColumn() {
    drawLastColumn(nColumns - 1);
}

void printLcd(int position) {
    int i;
    for (i = 0; i < nLines; i++) {
        int j;
        for (j = 0; j < nColumns; j++) {
            lcdNumbers[position][i][j] = lcdNumber[i][j];
        }
    }    
}

void printZero(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstLeftColumn();
    drawFirstRightColumn();
    drawLastLeftColumn();
    drawLastRightColumn();
    drawLastLine();
    printLcd(position);
}

void printOne(int position) {
    clearLcd();
    drawFirstRightColumn();
    drawLastRightColumn();
    printLcd(position);
}

void printTwo(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstRightColumn();
    drawMiddleLine();
    drawLastLeftColumn();
    drawLastLine();
    printLcd(position);
}

void printThree(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstRightColumn();
    drawMiddleLine();
    drawLastRightColumn();
    drawLastLine();
    printLcd(position);
}

void printFour(int position) {
    clearLcd();
    drawFirstLeftColumn();
    drawFirstRightColumn();
    drawMiddleLine();
    drawLastRightColumn();
    printLcd(position);
}

void printFive(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstLeftColumn();
    drawMiddleLine();
    drawLastRightColumn();
    drawLastLine();
    printLcd(position);
}

void printSix(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstLeftColumn();
    drawMiddleLine();
    drawLastLeftColumn();
    drawLastRightColumn();
    drawLastLine();
    printLcd(position);
}

void printSeven(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstRightColumn();
    drawLastRightColumn();
    printLcd(position);
}

void printEight(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstLeftColumn();
    drawFirstRightColumn();
    drawMiddleLine();
    drawLastLeftColumn();
    drawLastRightColumn();
    drawLastLine();
    printLcd(position);
}

void printNine(int position) {
    clearLcd();
    drawFirstLine();
    drawFirstLeftColumn();
    drawFirstRightColumn();
    drawMiddleLine();
    drawLastRightColumn();
    drawLastLine();
    printLcd(position);
}

void printNumber(int n, int position) {
    void (*functions[10]) (int position) = {
    printZero,
    printOne,
    printTwo,
    printThree,
    printFour,
    printFive,
    printSix,
    printSeven,
    printEight,
    printNine
    };

    functions[n](position);
}

int main() {
    int size = 0;
    char strNumber[9];
    scanf("%d %s", &size, strNumber);
    
    while (size != 0 || atoi(strNumber) != 0) {
        setLcdSize(size);
        int length = strlen(strNumber);
        
        int i;
        for (i = 0; i < length; i++) {
            int n = strNumber[i] - '0';
            printNumber(n, i);
        }
        
        for (i = 0; i < nLines; i++) {
            int n;
            for (n = 0; n < length; n++) {
                int j;
                for (j = 0; j < nColumns; j++) {
                    printf("%c", lcdNumbers[n][i][j]);
                }
                if (n < length - 1) {
                    printf(" "); 
                }
            }
            printf("\n");
        }
        printf("\n");

        scanf("%d %s", &size, strNumber);
    }
    return 0;
}