// from server: 100% by king_originala
extern "C" void __cdecl release(void*);

struct S {
    char pad000[0x11c];
    void* field11c;
    char pad120[8];
    void* field128;
    unsigned int field12c;
    unsigned int field130;

    void baseDestroy();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags) {
    if (field128)
        release(field128);

    field128 = 0;
    field12c = 0;
    field130 = 0;
    release(field11c);

    baseDestroy();

    if (flags & 1)
        release(this);

    return this;
}
