// from server: 88% by atomic.potato
struct Node_004b9370 {
    Node_004b9370* prev;
    Node_004b9370* next;
    int value;
};

struct S_004b9370 {
    Node_004b9370* head;
    Node_004b9370* tail;
    int count;
    int field_c;
    int freeCount;
    Node_004b9370* freeList;
    void f(int a);
};

extern "C" void* __cdecl sub_004b9370_alloc(unsigned int size);

void S_004b9370::f(int a)
{
    Node_004b9370* node = freeList;
    if (node != 0) {
        freeList = node->next;
        freeCount--;
    }
    if (node == 0) {
        node = (Node_004b9370*)sub_004b9370_alloc(0xc);
        if (node == 0)
            return;
    }
    node->value = a;
    node->next = 0;
    node->prev = tail;
    if (tail == 0) {
        count++;
        head = node;
        tail = node;
    } else {
        tail->next = node;
        count++;
        tail = node;
    }
}
