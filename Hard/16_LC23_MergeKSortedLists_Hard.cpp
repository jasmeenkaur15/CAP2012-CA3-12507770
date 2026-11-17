class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
        function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != NULL) {
                pq.push(temp->next);
            }
        }

        return dummy->next;
    }
};
