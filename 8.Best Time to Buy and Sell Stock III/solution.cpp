class Solution {
public:

    int calculateMax(vector<int> prices) {
        int firstBuy = -2147483648,secondBuy = -2147483648;
        int firstSell=0,secondSell = 0;
        for(auto price : prices){
            firstBuy = max(firstBuy,-price);
            firstSell = max(firstSell , firstBuy + price);
            secondBuy = max(secondBuy,firstSell -price);
            secondSell = max(secondSell, secondBuy + price);
        }
        return secondSell;
    }
};