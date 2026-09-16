/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head=NULL;
    struct ListNode* tail=NULL;
    int carry=0;
    while(l1!=NULL||l2!=NULL||carry>0){
        int digit1=(l1!=NULL)?l1->val:0;
        int digit2=(l2!=NULL)?l2->val:0;
        int columnsum=digit1+digit2+carry;
        carry=columnsum/10;
        int newdigit=columnsum%10;
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=newdigit;
        newnode->next=NULL;
        if (head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=tail->next;
        }
        if (l1!=NULL) l1=l1->next;
        if (l2!=NULL) l2=l2->next;
    }return head;
}