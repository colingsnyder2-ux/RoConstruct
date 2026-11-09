// from server: 53% by Intel
struct Node {
    Node* prev;
    Node* next;
};

struct HttpQueueStatsItem {
    Node* head;
    Node* tail;
    int count;

    void __stdcall sub_8BAE20(Node* node, Node** outPrev);
};

extern "C" void __stdcall sub_8BA4D0(Node*);
extern "C" void __stdcall operator_delete(void*);

void __stdcall HttpQueueStatsItem::sub_8BAE20(Node* node, Node** outPrev) {
    Node* prev = node->prev;
    *outPrev = prev;
    if (node != tail) {
        Node* next = node->next;
        next->prev = prev;
        prev->next = next;
        sub_8BA4D0(node);
        operator_delete(node);
        --count;
    }
}
