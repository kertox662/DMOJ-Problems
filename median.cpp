#include <vector>
#include <iostream>

using namespace std;

vector<int> a{1,2}, b{3,4};

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int aInd = 0, bInd = 0, total = nums1.size() + nums2.size();
        vector<int> all;
        for(int i = 0; i <= total/2; i++){
            if(bInd >= nums2.size() || (aInd < nums1.size() && nums1[aInd] < nums2[bInd])){
                all.push_back(nums1[aInd]);
                aInd++;
            } else if(aInd >= nums1.size() || (bInd < nums2.size() && nums2[bInd] <= nums1[aInd])){
                all.push_back(nums2[bInd]);
                
                bInd++;
            }
        }
        for(int i : all) cout << i << ' ';
        cout << endl;
        if(total%2 == 0){
            return (all[all.size()-1] + all[all.size()-2])/2.0;
        }
        return all[all.size()-1];
    }

int main(){
    cout << findMedianSortedArrays(a,b) << endl;
    return 0;
}