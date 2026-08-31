class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int total = 0;

            for (int i = 0; i < piles.size(); i++) {
                total += ceil((double)piles[i] / mid);
            }

            if (total > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};