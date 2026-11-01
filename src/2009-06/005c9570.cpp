// from server: 100% by atomic.potato
struct S {
    void* v0;
    int pad0[4];
    void* v14;
    void* v18;
    int pad1;
    void* v20;
    void cleanup();
    S* dtor(char flags);
};

void __cdecl op_delete(void*);

S* S::dtor(char flags) {
    v0 = (void*)0x8d435c;
    v14 = (void*)0x8d434c;
    v18 = (void*)0x8d4344;
    v20 = (void*)0x8d433c;
    cleanup();
    if (flags & 1) {
        op_delete(this);
    }
    return this;
}
