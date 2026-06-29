// Last updated: 29.06.2026 15:23:05
char* convert(char* s, int numRows) {
    int len = strlen(s);
    int numColumn = len;

    if (numRows == 1 || len <= numRows) {
        return s;
    }
    char new_matrix[numRows][numColumn];
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numColumn; c++) {
            new_matrix[r][c] = ' ';
        }
    }

    bool going_down = true;
    int row = 0;
    int column = 0;
    // place letters to zigzag matrix
    for (int i = 0; i < len; i++) {
        new_matrix[row][column] = s[i];
        if (going_down == true) {
            row++;
            if (row >= numRows) {
                going_down = false;
                column++;
                row = numRows - 2;
            }
        } else {
            row--;
            column++;
            if (row < 0) {
                row = 1;
                column--;
                going_down = true;
            }
        }
    }

    // read matrix from left to right

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c <= column; c++) {
            if (new_matrix[r][c] != ' ') {
                result[index++] = new_matrix[r][c];
            }
        }
    }
    result[index] = '\0';
    return result;
    free(result);
}