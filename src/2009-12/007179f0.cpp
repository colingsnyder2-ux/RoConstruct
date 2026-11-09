// from server: 100% by nuck16
// roc 2009-12 007179f0  (same-shape propagation from exact 007175f0)

struct Name {
    char pad0[0x94];
    void* field94;
};

struct Base {
    void sub_716fd0(void* arg);
};

struct VWeld : Base {
    void* field0;
    void* field4;
    char pad8[0x10];
    void* field18;
    void* field1c;
    char pad20[0x74];
    void* field94;
    VWeld* construct(void* arg);
};

VWeld* VWeld::construct(void* arg) {
    sub_716fd0(arg);
    *(void**)this = (void*)0x9df2dc;
    *(void**)((char*)this + 4) = (void*)0x9df2d0;
    *(void**)((char*)this + 0x18) = (void*)0x9df2c4;
    *(void**)((char*)this + 0x1c) = (void*)0x9df2bc;
    *(void**)((char*)this + 0x94) = (void*)0x9df2a4;
    return this;
}
