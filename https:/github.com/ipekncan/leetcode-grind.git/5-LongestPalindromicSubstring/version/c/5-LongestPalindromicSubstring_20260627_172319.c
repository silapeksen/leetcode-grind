// Last updated: 27.06.2026 17:23:19
1char* convert(char* s, int numRows) {
2    int len = strlen(s);
3    int numColumn = len;
4   
5    if (numRows == 1 || len <= numRows) {
6        return s;
7    }
8    char new_matrix[numRows][numColumn];
9    for(int r = 0; r < numRows; r++) {
10        for(int c = 0; c < numColumn; c++) {
11            new_matrix[r][c] = ' ';
12        }
13    }
14   
15    bool going_down=true;
16    int row=0;
17    int column=0;
18    //place letters to zigzag matrix
19    for(int i=0;i<len;i++){
20        new_matrix[row][column]=s[i];
21        if(going_down==true){
22        row++;
23        if(row>=numRows){
24            going_down=false;
25            column++;
26            row = numRows - 2;
27
28        }
29        }
30        else{
31            row--;
32            column++;
33            if(row<0){
34                row=1;
35                column--;
36                going_down=true;
37            }
38        }
39
40    }
41
42    //read matrix from left to right
43
44    char* result = (char*)malloc((len + 1) * sizeof(char));
45    int index=0;
46
47    for(int r=0;r<numRows;r++){
48        for(int c=0;c<=column;c++){
49            if(new_matrix[r][c]!=' '){
50                result[index++]=new_matrix[r][c];
51            }
52            
53        }
54    }
55    result[index] = '\0';
56    return result;
57    free(result);
58}