int largestRectangleArea(int* heights, int n) {
    int* stack = malloc((n + 1) * sizeof(int));
    int top = -1, maxArea = 0;
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (top != -1 && h < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        stack[++top] = i;
    }
    free(stack);
    return maxArea;
}
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0)
        return 0;
    int cols = matrixColSize[0];
    int* heights = calloc(cols, sizeof(int));
    int maxArea = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea)
            maxArea = area;
    }
    free(heights);
    return maxArea;
}