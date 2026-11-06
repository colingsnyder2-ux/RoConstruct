// from server: 100% by tajop
extern "C" void __cdecl sub_982114(void*);
extern "C" int vtbl_b47028;
extern "C" int vtbl_b47008;

struct S
{
    void* vt0;
    void* vt1;
    long ref;
    void release();
    S* sdd(unsigned int flags);
};

S* S::sdd(unsigned int flags)
{
    vt0 = &vtbl_b47028;
    vt1 = &vtbl_b47008;
    ref = (long)0xC0000001;
    release();
    if (flags & 1)
        sub_982114(this);
    return this;
}
