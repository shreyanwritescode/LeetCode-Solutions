void backtrack(int* nums, int n, int start, int* path, int size,
               int** ans, int* returnSize, int** colSize) {
    ans[*returnSize] = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        ans[*returnSize][i] = path[i];
    colSize[0][*returnSize] = size;
    (*returnSize)++;
    for (int i = start; i < n; i++) {
        path[size] = nums[i];
        backtrack(nums, n, i + 1, path, size + 1,
                  ans, returnSize, colSize);
    }
}
int** subsets(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes) {
    int total = 1 << numsSize;
    int** ans = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));
    *returnSize = 0;
    int* path = malloc(numsSize * sizeof(int));
    backtrack(nums, numsSize, 0, path, 0,
              ans, returnSize, returnColumnSizes);
    free(path);
    return ans;
}