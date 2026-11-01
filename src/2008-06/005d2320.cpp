// from server: 100% by king_originala
struct Node {
    Node* next;
    Node* prev;
};

extern "C" void __cdecl release_node(void*);

struct S {
    char padding[0x144];
    Node* head;
    unsigned int count;

    void clear();
};

void S::clear()
{
    Node* current = head->next;
    head->next = head;
    head->prev = head;
    count = 0;

    while (current != head) {
        Node* next = current->next;
        release_node(current);
        current = next;
    }
}
