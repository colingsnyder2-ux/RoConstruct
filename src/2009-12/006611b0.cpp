// from server: 21% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);

struct C1 { void f(); };
struct C2 { void g(void*, void*); };

void C1::f() {}
void C2::g(void*, void*) {}

struct RBX_VObjectValue_FactoryProduct_Creator {
    void* __cdecl method(void* a);
};

void* RBX_VObjectValue_FactoryProduct_Creator::method(void* a)
{
    void* p = sub_7F3860(0xa4);
    void* q = 0;
    if (p) {
        ((C1*)p)->f();
        q = p;
    }
    ((C2*)this)->g(q, 0);
    return this;
}
