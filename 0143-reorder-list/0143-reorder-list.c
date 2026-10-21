/**
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return;
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = slow->next;
    slow->next = NULL;
    struct ListNode* prev = NULL;
    while (second != NULL) {
        struct ListNode* next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }
    second = prev;
    struct ListNode* first = head;
    while (second != NULL) {
        struct ListNode* next1 = first->next;
        struct ListNode* next2 = second->next;
        first->next = second;
        second->next = next1;
        first = next1;
        second = next2;
    }
}