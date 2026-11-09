// from server: 58% by Intel
extern "C" void __cdecl sub_982114(void*);

struct S_func_00605f50 {
    int field_0;
    void* head;
    int field_8;
    void f();
};

void S_func_00605f50::f() {
    // Define a struct for the head node (with next and prev)
    struct HeadNode {
        void* next;
        void* prev;
    };
    HeadNode* headNode = (HeadNode*)head;
    // Get first node
    void* first = headNode->next;
    // Initialize head node to point to itself
    headNode->next = headNode;
    headNode->prev = headNode;
    field_8 = 0;

    // Define a minimal node struct for the next pointer
    struct Node {
        void* next;
    };

    Node* current = (Node*)first;
    while (current != (Node*)headNode) {
        // Get field_C
        void* field_C = *(void**)((char*)current + 0xC);
        // Save next node
        Node* next = (Node*)current->next;
        if (field_C != 0) {
            sub_982114(field_C);
        }
        // Zero out field_C, field_10, field_14
        *(void**)((char*)current + 0xC) = 0;
        *(void**)((char*)current + 0x10) = 0;
        *(void**)((char*)current + 0x14) = 0;
        // Deallocate current node
        sub_982114(current);
        current = next;
    }
}
