class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        if (head == NULL || head->next == NULL) return;

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (slow != fast) return;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        Node* prev = NULL;
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    }
};