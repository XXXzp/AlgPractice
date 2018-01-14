class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0){
            return getSingleHalf(nums2);
        }
        if(nums2.size()==0){
            return getSingleHalf(nums1);
        }
        return getHalfArrays(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1);
    }
    double getSingleHalf(vector<int>& nums){
        int halfIndex = nums.size()/2;
        if(nums.size()%2==0){
            return (nums[halfIndex]+nums[halfIndex-1])/2.0;
        }
        return nums[halfIndex];
    }

    double getHalfArrays(vector<int>& nums1, int begin1, int end1, vector<int>&nums2,int begin2, int end2){
        if(end1-begin1<=2&&end2-begin2<=2){
            vector<int> num = nums1;
            num.insert(num.end(),nums2.begin(),nums2.end());
            sort(num.begin(),num.end());
            return getSingleHalf(num);
        }
        int num1Mid = ceil((begin1+end1)/2.0);
        int num2Mid = ceil((begin2+end2)/2.0);
        if(nums1[num1Mid]>nums2[num2Mid]){
            return getHalfArrays(nums1,begin1,num1Mid,nums2,num2Mid,end2);
        }else{
            return getHalfArrays(nums1,num1Mid,end1,nums2,begin2,num2Mid);
        }
        
    }
};