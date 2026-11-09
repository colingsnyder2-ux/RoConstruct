// from server: 100% by atomic.potato
struct S {
    void* vf0;
    void* vf4;
    char pad[0x10];
    void* vf18;
    void* vf1c;
    void destroy();
    void* dtor(char flag);
};

void S::destroy() {
    extern void __stdcall sub_637b00();
    sub_637b00();
}

void* S::dtor(char flag) {
    vf0 = (void*)0x9cded4;
    vf4 = (void*)0x9cdecc;
    vf18 = (void*)0x9cdec0;
    vf1c = (void*)0x9cdeb8;
    destroy();
    if (flag & 1) {
        extern void __cdecl sub_7f385a(void*);
        sub_7f385a(this);
    }
    return this;
}
