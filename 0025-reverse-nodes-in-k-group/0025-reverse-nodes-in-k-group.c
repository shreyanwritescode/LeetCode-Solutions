/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* current = head;
    int count = 0;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }
    if (count == k) {
        current = reverseKGroup(current, k);
        while (count > 0) {
            struct ListNode* temp = head->next;
            head->next = current;
            current = head;
            head = temp;
            count--;
        }
        head = current;
    }
    return head;
}