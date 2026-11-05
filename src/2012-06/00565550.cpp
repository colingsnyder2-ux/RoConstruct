// from server: 96% by tajop
struct Node { Node* next; Node* prev; };
struct VT { void* a; void (*f)(void*); };
struct Temp {
    char pad[0xc];
    VT* vt;
    char buf[0x3c];
    Temp(const void* a, const void* b);
    ~Temp() { if (vt) vt->f(buf); }
};
struct List {
    int al;
    Node* head;
    unsigned size;
    Node* _Buynode(Node* n, Node* p, const Temp& v);
    void _Incsize(unsigned n);
    void _Insert(Node* w, const Temp& v) {
        Node* n = _Buynode(w, w->prev, v);
        _Incsize(1);
        w->prev = n;
        n->prev->next = n;
    }
    void push_back(const Temp& v) { _Insert(head, v); }
};
struct Base {
    char pad[0x1c];
    List list;
    Base(void* x);
    virtual ~Base();
};
void* __stdcall makeArg(int a, int b, int c, int d);
const void* getFirst();
const void* getSecond();
const void* convert(const int* p);
struct D : Base {
    int m;
    D(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
    virtual ~D();
};
D::D(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
    : Base(makeArg(a1, a4, a5, a6)), m(a0)
{
    Temp t1(convert(&a2), getFirst());
    list.push_back(t1);
    Temp t2(convert(&a3), getSecond());
    list.push_back(t2);
}
