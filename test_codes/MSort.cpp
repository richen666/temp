#include<vector>
#include<iostream>

using namespace std;

// class Solution {
// public:
//     void merge(vector<int>&tmp, vector<int>&ans, int left, int mid, int right) {
//         // int i = left, j = mid + 1, k = 0;
//         // k=0; 错误的根源
//         int i = left, j = mid + 1, k = left;
//         while(i <= mid && j <= right) {
//             if(tmp[i] <= tmp[j]) {
//                 ans[k++] = tmp[i++];
//             } else{
//                 ans[k++] = tmp[j++];
//             }
//         }
//         // if(i <= mid) {
//         while(i <= mid) {
//             // 丢掉了循环
//             ans[k++] = tmp[i++];
//         }
//         // if(j <= right) {
//         while(j <= right) {
//             ans[k++] = tmp[j++];
//         }
//     }

//     void mergeSort(vector<int>& nums, vector<int>& ans, int left, int right) {
//         // vector<int> tmp(ans);
//         // 实现存在一个问题，导致超时：如果nums中的数据量很大时，会导致大量拷贝，所以如下将ans拷贝到tmp是不合适的
//         // 此外，不需要拷贝，直接通过引用传递即可
//         // 之前写的程序结果输出错误的原因在于，在上述的merge函数中，每次merge时，k值的都置为0，从而覆盖原来已经merge的元素，所有k值应该为k=left
//         vector<int> tmp(nums.size());
//         // 当left == right时，temp没有使用，但也不影响，因为其后的return以后，内存被回收了
//         if(left == right) {
//             ans[left] = nums[left];
//             return;
//         }
//         int mid = left + (right - left) / 2;
//         mergeSort(nums, tmp, left, mid);
//         mergeSort(nums, tmp, mid + 1, right);
//         // 这里也发生拷贝
//         // 和标准答案相比，这里主要开销主要在于每层递归中，将tmp拷贝进ans中，如果数据量很大，那么拷贝的开销会很大
//         // 所以可以将tmp放在外面
//         merge(tmp, ans, left, mid, right);
//     }

//     vector<int> sortArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);
//         mergeSort(nums, ans, 0, n - 1);
//         return ans;
//     }
// };

// class Solution {
//     vector<int> tmp;
//     void mergeSort(vector<int>& nums, int l, int r) {
//         if (l >= r) return;
//         int mid = (l + r) >> 1;
//         mergeSort(nums, l, mid);
//         mergeSort(nums, mid + 1, r);
//         int i = l, j = mid + 1;
//         int cnt = 0;
//         while (i <= mid && j <= r) {
//             if (nums[i] <= nums[j]) {
//                 tmp[cnt++] = nums[i++];
//             }
//             else {
//                 tmp[cnt++] = nums[j++];
//             }
//         }
//         while (i <= mid) {
//             tmp[cnt++] = nums[i++];
//         }
//         while (j <= r) {
//             tmp[cnt++] = nums[j++];
//         }
//         for (int i = 0; i < r - l + 1; ++i) {
//             nums[i + l] = tmp[i];
//         }
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         tmp.resize((int)nums.size(), 0);
//         mergeSort(nums, 0, (int)nums.size() - 1);
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> tmp;
    void merge(vector<int>&nums, int left, int right) {
        int mid = left + (right - left) / 2;
        int i = left, j = mid + 1, k = left;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else{
                tmp[k++] = nums[j++];
            }
        }
        while(i <= mid) {
            tmp[k++] = nums[i++];
        }
        while(j <= right) {
            tmp[k++] = nums[j++];
        }
        int n = right - left + 1;
        // for(int i = 0; i < n; ++i) {
        //     nums[i] = tmp[i];
        // }

        for(int i = left; i <= right; ++i) {
            nums[i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if(right <= left) return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums{5,2,3,1};
    vector<int>ans = s.sortArray(nums);
}