#include<iostream>
#include<vector>
using namespace std;

    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        
        if (row == 0 || col == 0) return res;
        
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; ++i) 
                res.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; ++i) 
                res.push_back(matrix[i][right]);
            if (top != bottom)
                for (int i = right - 1; i >= left; --i) 
                    res.push_back(matrix[bottom][i]);
            if (left != right)
                for (int i = bottom - 1; i > top; --i) 
                    res.push_back(matrix[i][left]);
            left++,top++,right--,bottom--;
        }
        return res;
    }
int main(){
    vector<int> col1 = {1,2,3,4};
    vector<int> col2 = {5,6,7,8};
    vector<int> col3 = {9,10,11,12};
    vector<int> col4 = {13,14,15,16};
    vector<int> col5 = {17,18,19,20};
    vector<vector<int> > matrix = {col1,col2,col3,col4,col5};
    auto result = printMatrix(matrix);
    for(int val:result)
        cout<<val<<endl;
}