/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getMid(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* mid = slow->next;
    slow->next = NULL;
    return mid;
}
struct ListNode* merge(struct ListNode* a, struct ListNode* b) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    tail->next = a ? a : b;
    return dummy.next;
}
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode* mid = getMid(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    return merge(left, right);
}
