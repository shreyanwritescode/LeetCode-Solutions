/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    struct ListNode* current = head;
    int len = 1;
    while (current->next != NULL) {
        current = current->next;
        len++;
    }
    current->next = head;
    k = k % len;
    int steps = len - k;
    current = head;
    for (int i = 1; i < steps; i++)
        current = current->next;
    head = current->next;
    current->next = NULL;
    return head;
}