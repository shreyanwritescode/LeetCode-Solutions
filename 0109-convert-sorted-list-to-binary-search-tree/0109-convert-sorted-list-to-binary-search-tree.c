/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        struct TreeNode* root = malloc(sizeof(struct TreeNode));
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = slow->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}