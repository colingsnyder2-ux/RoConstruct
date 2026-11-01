// from server: 100% by atomic.potato
extern "C" void __cdecl op(void*);
extern "C" void __cdecl op2(void*);

struct S {
    void* vfptr;
    char pad[0x14];
    void* field18;
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags) {
    if (field18) {
        op(field18);
    }
    vfptr = (void*)0x80b730;
    if (flags & 1) {
        op2(this);
    }
    return this;
}
