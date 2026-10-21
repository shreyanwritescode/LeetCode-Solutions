/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void backtrack(int* c, int n, int target, int start,
               int* path, int size, int** ans,
               int* returnSize, int** colSize) {
    if (target == 0) {
        ans[*returnSize] = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            ans[*returnSize][i] = path[i];
        colSize[0][*returnSize] = size;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < n; i++) {
        if (i > start && c[i] == c[i - 1])
            continue;
        if (c[i] > target)
            break;
        path[size] = c[i];
        backtrack(c, n, target - c[i], i + 1,
                  path, size + 1, ans,
                  returnSize, colSize);
    }
}
int** combinationSum2(int* candidates, int candidatesSize,
                      int target, int* returnSize,
                      int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), compare);
    int capacity = 10000;
    int** ans = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    int* path = malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0,
              path, 0, ans, returnSize, returnColumnSizes);
    free(path);
    return ans;
}