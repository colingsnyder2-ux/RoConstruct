// from server: 50% by atomic.potato
struct Node {
    Node* next;
    Node* prev;
    Node* parent;
    char pad[9];
    char color;
};

struct List {
    Node* head;
    int size;
    void init();
};

struct Base {
    void ctor(int, const char*);
    void set(int, const char*);
};

struct S : Base {
    char pad0[0x30];
    List list1;
    List list2;
    char pad1[0x10];
    int f50, f54, f58;
    char pad2[4];
    int f60, f64, f68;
    char pad3[4];
    int f70, f74, f78;
    char pad4[4];
    int f80, f84, f88;
    char pad5[4];
    int f90, f94, f98;
    char pad6[4];
    int fa0, fa4, fa8;
    S();
};

extern "C" void* __stdcall sub_7cd1f0();
extern "C" void __stdcall sub_6cb830(int, int);
extern "C" void __stdcall sub_467830(int, int);
extern "C" void* __stdcall sub_67f2e0(int);
extern "C" void __stdcall sub_457100(void*);

void List::init() {
    Node* n = (Node*)sub_7cd1f0();
    head = n;
    n->color = 1;
    n->next = n;
    n->prev = n;
    n->parent = n;
    size = 0;
}

S::S() {
    sub_6cb830(0xba6d94, 0xdafe24);
    *(int*)this = 0xba6ce4;
    list1.init();
    list2.init();
    f50 = 0; f54 = 0; f58 = 0;
    f60 = 0; f64 = 0; f68 = 0;
    f70 = 0; f74 = 0; f78 = 0;
    f80 = 0; f84 = 0; f88 = 0;
    f90 = 0; f94 = 0; f98 = 0;
    fa0 = 0; fa4 = 0; fa8 = 0;
    sub_467830(0xba6d8c, 0);
    sub_467830(0xba6d88, 1);
    int* p = (int*)sub_67f2e0(0xba6d78);
    sub_457100(p);
    *p = 1;
    sub_467830(0xb8e1f8, 2);
}
