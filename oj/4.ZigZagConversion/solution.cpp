class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(size<=numRows||numRows==1){return s;}
        int index = 0;
        int col = 0;
        int i = 0;
        bool ifHasMid;
        int midIndex;
        string result = s;
        for(int row=0;row<numRows;row++){
            ifHasMid = (row==numRows-1||row==0)?false:true;
            col = 0;
            while(true){
                index = row + (2*numRows-2)*col;
                if(index>=size){break;}
                if(ifHasMid){
                    midIndex = index + (numRows-row-1)*2;
                    if(midIndex<size)
                    {
                        result[i]=s[index];i++;
                        result[i]=s[midIndex];i++;
                    }else{
                        result[i]=s[index];i++;
                        break;
                    }
                }else{
                    result[i]=s[index];i++;
                }
                col++;
            }
        }
        return result;
    }
};