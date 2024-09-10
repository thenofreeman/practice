ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* newNode = new ListNode();
    ListNode* curr = newNode;

    while (l1 || l2)
    {
        int val1 = (l1 ? l1->val : 0);
        int val2 = (l2 ? l2->val : 0);

        int sum = newNode->val + (val1+val2);
        int carry = sum / 10;
        newNode->val = sum % 10;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;

        if (l1 || l2 || carry > 0)
        {
            newNode->next = new ListNode(carry);
            newNode = newNode->next;
        }
    }

    return curr;    
}