// from server: 72% by atomic.potato
struct Node {
    Node* next;
    char pad[0x24];
    char flag29;
    char pad2[0x0];
};

struct Outer {
    void f(Node* n);
};

extern "C" void __stdcall sub_75e660(void*);
extern "C" void __stdcall sub_7f385a(void*);

void Outer::f(Node* n) {
    Node* p = n;
    if (p->flag29 == 0) {
        do {
            f((Node*)p->next);
            sub_75e660((char*)n + 0x10);
            sub_7f385a(n);
            p = (Node*)p->next;
        } while (p->flag29 == 0);
    }
}
