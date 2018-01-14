class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if(size<3){return 0;}
        sort(nums.begin(),nums.end());
        int first,second,third;
        int curSum;
        int closest = nums[0]+nums[1]+nums[2];
        for(first = 0;first<size-2;first++){
            if(first>0&&nums[first]==nums[first-1]){continue;}
            second = first+1;
            third = size-1;
            while(third>second){
                curSum = nums[first]+nums[second]+nums[third];
                if(abs(curSum-target)<abs(closest-target)){
                    closest = curSum;
                }
                if(curSum==target){return curSum;}
                if(curSum<target){second++;}
                if(curSum>target){third--;}
            }
        }
        return closest;
    }
    
};