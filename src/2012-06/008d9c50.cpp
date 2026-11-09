// from server: 48% by atomic.potato
struct Sub {
    char pad[4];
    void init();
};

struct S {
    Sub sub;
    void* f(void* a, void* b);
};

extern "C" void __stdcall sub_init(Sub* self);

void Sub::init()
{
    sub_init(this);
}

extern "C" void __stdcall call_8d9b20(S* self, void* a, void* b);

void* S::f(void* a, void* b)
{
    sub.init();
    call_8d9b20(this, a, b);
    return a;
}
