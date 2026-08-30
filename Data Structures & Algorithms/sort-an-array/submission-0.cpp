class Solution {
public:

    vector<int> quickSort(vector<int>& arr) {

        if (arr.size() <= 1) {
            return arr;
        }

        int pivot = arr[arr.size() / 2];

        vector<int> left;
        vector<int> right;
        vector<int> equal;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] < pivot) {
                left.push_back(arr[i]);
            }
            else if (arr[i] > pivot) {
                right.push_back(arr[i]);
            }
            else {
                equal.push_back(arr[i]);
            }
        }

        vector<int> sortedLeft = quickSort(left);
        vector<int> sortedRight = quickSort(right);

        vector<int> result;

        for (int x : sortedLeft) {
            result.push_back(x);
        }

        for (int x : equal) {
            result.push_back(x);
        }

        for (int x : sortedRight) {
            result.push_back(x);
        }

        return result;
    }

    vector<int> sortArray(vector<int>& nums) {
        return quickSort(nums);
    }
};