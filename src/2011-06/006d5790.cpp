// from server: 100% by atomic.potato
struct ManualGlue {
    void* vf0;
    void* vf1;
    char pad0[0x10];
    void* vf18;
    void* vf1c;
    char pad1[0x70];
    void* vf90;
    ManualGlue* construct(void*);
};

struct Base {
    void ctor(void*);
};

ManualGlue* ManualGlue::construct(void* a) {
    ((Base*)this)->ctor(a);
    vf0 = (void*)0xaa6af4;
    vf1 = (void*)0xaa6aec;
    vf18 = (void*)0xaa6ae0;
    vf1c = (void*)0xaa6ad4;
    vf90 = (void*)0xaa6aac;
    return this;
}
