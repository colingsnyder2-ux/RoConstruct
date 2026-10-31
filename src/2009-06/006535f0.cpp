// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct B1 { virtual void a(); };
struct B2 { virtual void b(); };
struct Verb : B1, B2 {
    char data[20];
    Verb(int a1);
};

struct Mid : Verb {
    bool flag;
    Mid(int a1) : Verb(a1) { flag = false; }
};

struct Tool : Mid {
    Tool(int a1) : Mid(a1) {}
    virtual void a();
    virtual void b();
};

struct S {
    char padding[12];
    char* owner;
    Tool* f();
};

Tool* S::f()
{
    return new Tool(*(int*)(owner + 0x20c));
}
