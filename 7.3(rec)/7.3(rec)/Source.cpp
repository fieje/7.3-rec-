#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void PrintRow(const vector<vector<int>>& matrix, int rowNo) {
    for (int colNo = 0; colNo < matrix[rowNo].size(); colNo++) {
        cout << setw(4) << matrix[rowNo][colNo];
    }
    cout << endl;
}

void PrintMatrix(const vector<vector<int>>& matrix) {
    for (int rowNo = 0; rowNo < matrix.size(); rowNo++) {
        PrintRow(matrix, rowNo);
    }
}

void CreateRow(vector<vector<int>>& matrix, const int colCount, const int Low, const int High) {
    vector<int> row;
    for (int colNo = 0; colNo < colCount; colNo++) {
        row.push_back(Low + rand() % (High - Low + 1));
    }
    matrix.push_back(row);
}

void CreateMatrix(vector<vector<int>>& matrix, const int rowCount, const int colCount, const int Low, const int High) {
    for (int rowNo = 0; rowNo < rowCount; rowNo++) {
        CreateRow(matrix, colCount, Low, High);
    }
}

int CountPositiveElementsInRow(const vector<int>& row) {
    int count = 0;
    for (int colNo = 0; colNo < row.size(); colNo++) {
        if (row[colNo] > 0) {
            count++;
        }
    }
    return count;
}

int LongestSeriesLengthInColumn(const vector<vector<int>>& matrix, int colNo) {
    int maxLength = 0;
    int currentLength = 1;
    for (int rowNo = 0; rowNo < matrix.size() - 1; rowNo++) {
        if (matrix[rowNo][colNo] == matrix[rowNo + 1][colNo]) {
            currentLength++;
        }
        else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    maxLength = max(maxLength, currentLength);
    return maxLength;
}

int main() {
    srand((unsigned)time(NULL));
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    if (rowCount <= 0 || colCount <= 0) {
        cout << "Invalid matrix dimensions." << endl;
        return 1;
    }

    const int Low = -7;
    const int High = 7;

    vector<vector<int>> matrix;
    CreateMatrix(matrix, rowCount, colCount, Low, High);
    PrintMatrix(matrix);

    int positiveElementsWithZeroCount = 0;
    for (int rowNo = 0; rowNo < rowCount; rowNo++) {
        bool hasZero = false;
        for (int colNo = 0; colNo < colCount; colNo++) {
            if (matrix[rowNo][colNo] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            positiveElementsWithZeroCount += CountPositiveElementsInRow(matrix[rowNo]);
        }
    }
    cout << "Number of positive elements in rows with at least one zero element: " << positiveElementsWithZeroCount << endl;

    int maxSeriesColumn = -1;
    int maxSeriesCount = 0;
    for (int colNo = 0; colNo < colCount; colNo++) {
        int seriesLength = LongestSeriesLengthInColumn(matrix, colNo);
        if (seriesLength > maxSeriesCount) {
            maxSeriesCount = seriesLength;
            maxSeriesColumn = colNo;
        }
    }
    if (maxSeriesColumn != -1) {
        cout << "The longest series of identical elements occurs in column " << maxSeriesColumn << " and has length " << maxSeriesCount << endl;
    }
    else {
        cout << "The matrix does not have the same elements in any column." << endl;
    }

    return 0;
}
