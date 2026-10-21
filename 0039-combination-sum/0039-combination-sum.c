#include <stdlib.h>
void backtrack(int* candidates, int n, int target, int start,
               int* path, int size, int** ans,
               int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        ans[*returnSize] = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            ans[*returnSize][i] = path[i];
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < n; i++) {
        if (candidates[i] <= target) {
            path[size] = candidates[i];
            backtrack(candidates, n, target - candidates[i], i,
                      path, size + 1, ans,
                      returnSize, returnColumnSizes);
        }
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {
    int capacity = 10000;
    int** ans = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    int* path = malloc((target + 1) * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, path, 0,
              ans, returnSize, returnColumnSizes);

    free(path);
    return ans;
}