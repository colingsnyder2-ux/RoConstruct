// from server: 55% by atomic.potato
struct S_func_00490dd0 {
    int m_x;
    int f();
};

int S_func_00490dd0::f()
{
    return m_x;
}

struct Node {
    Node* next;
    Node* prev;
};

struct S {
    char pad0[4];
    Node head;
    char pad8[0x24 - 8];
    int field24;
    int f(Node* a, Node* b, Node* c);
    void g(Node* a, Node* b);
    void h();
    void i(Node* a, Node* b);
};

extern "C" int __stdcall sub_69b5f0(void* p);
extern "C" int __stdcall sub_490dd0(void* p);

int S::f(Node* a, Node* b, Node* c)
{
    Node* esi = &head;
    if (head.next == 0 || head.next == esi)
        return 0;

    if (!sub_69b5f0(a)) {
        Node* n = head.next;
        Node* arg;
        if (n != 0)
            arg = (Node*)((char*)n - 4);
        else
            arg = 0;
        g(a, arg);
    }

    int count = sub_490dd0(a);
    Node* cur = (Node*)count;
    int idx = 0;
    Node* ebx = 0;

    while ((unsigned)idx < *(unsigned*)&head) {
        idx++;
        ebx = cur;
        Node* eax;
        if (cur != 0)
            eax = (Node*)((char*)cur + 4);
        else
            eax = 0;
        Node* ecx = (Node*)((char*)&head + 4);
        Node* v = *(Node**)eax;
        if (v == ecx)
            v = *(Node**)ecx;
        if (v != 0)
            cur = (Node*)((char*)v - 4);
        else
            cur = 0;

        if (ebx == c)
            continue;

        if (*(int*)((char*)a + 0x14) == 0)
            h();

        i(*(Node**)((char*)a + 8), *(Node**)((char*)a + 0x14));

        int sz = *(int*)((char*)a + 0x14);
        int bits = (*(int*)sz + 7) >> 3;
        if (bits < *(int*)((char*)a + 0x10))
            continue;
    }

    g(a, cur);
    return 0;
}
