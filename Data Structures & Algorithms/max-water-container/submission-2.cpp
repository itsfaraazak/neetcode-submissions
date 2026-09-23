class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int maxArea = 0;
        while (left < right) {
            int currentArea = std::min(heights[left], heights[right]) * (right - left);
            maxArea = std::max(currentArea, maxArea);

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;

    }
};
