class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        int len = 1;

        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        temp->next = head;

        k = k % len;

        int steps = len - k;

        while (steps > 0) {
            temp = temp->next;
            steps--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
