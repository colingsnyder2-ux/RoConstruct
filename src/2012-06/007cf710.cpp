// from server: 100% by atomic.potato
struct Node {
    Node* next;
    Node* prev;
};

struct SpawnLocation {
    char pad[0x88];
    Node* head;
    int count;
    void clear();
};

void __cdecl sub_982114(void* p);

void SpawnLocation::clear() {
    Node* h = head;
    Node* first = h->next;
    h->next = h;
    head->prev = head;
    count = 0;
    if (first != head) {
        do {
            Node* nxt = first->next;
            sub_982114(first);
            first = nxt;
        } while (first != head);
    }
}
