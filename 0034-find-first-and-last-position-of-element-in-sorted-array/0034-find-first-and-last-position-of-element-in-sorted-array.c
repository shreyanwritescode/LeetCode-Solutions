/**
 * Note: The returned array must be malloced.
 */
 
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ans[0] = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    left = 0;
    right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ans[1] = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}