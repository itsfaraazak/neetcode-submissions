class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> possibleNums = new HashMap<>(); // key = num, value = index
        for (int i = 0; i < nums.length; i++) {
            possibleNums.put(nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            int difference = target - nums[i];
            if (possibleNums.get(difference) != null && possibleNums.get(difference) != i) {
                return new int[]{i, possibleNums.get(difference)};
            }
        }
        return null;
    }
}
