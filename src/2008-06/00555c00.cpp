// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" void __cdecl sub_6a067a(void*);

struct __declspec(novtable) Buffer
{
    virtual void bufferMethod();
    void* allocation;
    unsigned long padding[2];
    void* data;
    unsigned long size;
    unsigned long capacity;
    unsigned long tail;
    ~Buffer();
};
struct Buffer1 : Buffer {};
struct Buffer2 : Buffer {};
struct Buffer3 : Buffer {};
struct Buffer4 : Buffer {};

struct A1 { unsigned long d[22]; void close(); };
struct Sp { unsigned long d; ~Sp(); };
struct B2 { unsigned long d[6]; ~B2(); };
struct C3 { unsigned long d[9]; ~C3(); };
struct Node { void destroy(); };
struct NodePtr { Node* p; ~NodePtr() { Node* n = p; if (n) { n->destroy(); sub_6a067a(n);} } };
struct Empty { unsigned long d; ~Empty() {} };
struct Raw { void* p; ~Raw() { void* d = p; sub_6a067a(d); } };
struct Vec { Raw r; void f(); ~Vec() { f(); } };
struct P00 { virtual void m00(); unsigned long pad[3]; };
struct P10 { virtual void m10(); };
struct P14 { virtual void m14(); unsigned long pad[2]; };
struct P20 { virtual void m20(); };
struct P24 { virtual void m24(); unsigned long pad[7]; };
struct P44 { virtual void m44(); unsigned long pad[7]; };
struct P64 { virtual void m64(); unsigned long pad[7]; };
struct P84 { virtual void m84(); unsigned long pad[7]; };
struct PA4 { virtual void mA4(); unsigned long pad[7]; };
struct PC4 { virtual void mC4(); unsigned long pad[26]; };

struct Base : P00, P10, P14, P20, P24, P44, P64, P84, PA4, PC4
{
    ~Base();
};


struct S : Base, Buffer1, Buffer2, Buffer3, Buffer4
{
    unsigned long pad1[14];
    A1 a1;
    Sp s0;
    unsigned long pad3[2];
    B2 b0;
    B2 b1;
    NodePtr node;
    Sp s1;
    unsigned long pad4;
    C3 c3;
    Sp s2;
    Empty e;
    Vec v;
    ~S();
};

inline Buffer::~Buffer()
{
    void* d = data;
    if (d)
        sub_6a067a(d);
    data = 0;
    size = 0;
    capacity = 0;
    void* a = allocation;
    sub_6a067a(a);
}

S::~S()
{
    a1.close();
}
