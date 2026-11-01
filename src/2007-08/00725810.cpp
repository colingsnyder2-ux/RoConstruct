// from server: 100% by colin
struct S {
    void* vfptr;
    int pad[2];
    int field_c;
    S* ctor();
};

extern "C" void (__stdcall *exception_ctor)();

S* S::ctor()
{
    exception_ctor();
    field_c = 0;
    vfptr = (void*)0x78a14c;
    return this;
}
