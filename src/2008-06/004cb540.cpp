// from server: 100% by colin
extern int bounds[30];

extern "C" int* __cdecl selectCount(const int*, const int*, const int*, int);

struct Node {
    Node* next;
};

extern "C" Node** __cdecl allocateSlots(unsigned int, int);

struct S {
    int count;
    int unused;
    unsigned int capacity;
    Node** slots;

    S(void*, Node*, int);
};

S::S(void*, Node* node, int requested)
{
    int key = requested;
    int* selected = selectCount(&bounds[1], &bounds[29], &key, 0);
    if (selected == &bounds[29])
        --selected;

    count = *selected;
    capacity = count + 1;
    Node** allocated = capacity ? allocateSlots(capacity, 0) : 0;
    Node** volatile* slot_ptr = reinterpret_cast<Node** volatile*>(&slots);
    *slot_ptr = allocated;

    Node** current = allocated;
    Node** end = allocated + count;
    while (current != end) {
        *current = reinterpret_cast<Node*>(current);
        ++current;
    }

    slots[count] = node;
    node->next = reinterpret_cast<Node*>(slots + count);
}
