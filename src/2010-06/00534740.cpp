// from server: 100% by tester
struct S {
    void* vtable0;
    void* vtable4;
    char pad[0x10];
    void* vtable18;
    void* vtable1c;
    void destroy(int);
    S* construct(int);
};

extern "C" void __cdecl sub_599C50();
extern "C" void __cdecl sub_7A799A(void*);

S* S::construct(int flag)
{
    vtable0 = (void*)0xA1F074;
    vtable4 = (void*)0xA1F06C;
    vtable18 = (void*)0xA1F060;
    vtable1c = (void*)0xA1F054;
    sub_599C50();
    if (flag & 1) {
        sub_7A799A(this);
    }
    return this;
}
