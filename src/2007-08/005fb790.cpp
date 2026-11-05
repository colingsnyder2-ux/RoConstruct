// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct WeldTool {
    char pad[0x18];
    void* field18;
    void construct(void* workspace);
};

struct Inner {
    void m1();
    void m2();
    void m3(int);
    void m4();
};

struct Inner2 {
    void m5(int);
};

extern "C" void* __cdecl sub_561B10(void* a);

void WeldTool::construct(void* workspace) {
    Inner* p = *(Inner**)workspace;
    p->m1();
    ((Inner*)workspace)->m2();
    ((Inner*)workspace)->m3(2);
    p = *(Inner**)workspace;
    p->m4();
    ((Inner2*)sub_561B10(field18))->m5(8);
}
