// from server: 52% by atomic.potato
struct Node {
    char pad0[4];
    Node* next;
    char pad8[0x20];
    void* item;
};

struct Stage {
    char pad0[0x28];
    Node* node;
};

struct Vtbl {
    void* pad0;
    bool (__thiscall* fn1)(void*, void*);
};

extern "C" Node* __cdecl sub_9639D0(int, Node*, void**, int*);

Node* __cdecl sub_963A10(Stage* a, Stage* b, void** out, int* flag) {
    Node* n1 = a->node;
    Node* n2 = b->node;
    int c1 = 0;
    int c2 = 0;
    while (n1 != n2) {
        if (c1 > c2) {
            void* it = n1->item;
            if (it) {
                void* cur = *out;
                if (!cur || ((Vtbl*)*(void**)cur)->fn1(cur, it)) {
                    *out = it;
                    *flag = 0;
                }
            }
            c1--;
            n1 = n1->next;
        } else {
            void* it = n2->item;
            if (it) {
                void* cur = *out;
                if (!cur || ((Vtbl*)*(void**)cur)->fn1(cur, it)) {
                    *out = it;
                    *flag = 1;
                }
            }
            c2--;
            n2 = n2->next;
        }
    }
    if (n1) {
        n1 = sub_9639D0(0, n1, out, flag);
    } else {
        n1 = 0;
    }
    if (n2) {
        n2 = sub_9639D0(1, n2, out, flag);
        c2--;
        c1--;
    } else {
        c1--;
        n2 = 0;
    }
    return n1;
}
