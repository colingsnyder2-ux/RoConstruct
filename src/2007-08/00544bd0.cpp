// from server: 65% by colin
struct VItem {
    char pad0[0x8c];
    int field_8c;
};

struct GetSet {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct BoundPropGetSet {
    void* vtable0;
    void* vtable4;
    char pad8[8];
    void* vtable10;
    void* vtable14;
    char pad18[0x14];
    void* vtable2c;
    char pad30[0x14];
    void* vtable44;
    char pad48[0x14];
    void* vtable5c;
    char pad60[0x14];
    void* vtable74;
    char pad78[0x14];
    void* vtable8c;
    char pad90[0x14];
    void* vtablea4;

    BoundPropGetSet();
};

extern void* G_007a6c5c;
extern void* G_007a6c54;
extern void* G_007a6c4c;
extern void* G_007a6c3c;
extern void* G_007a6c2c;
extern void* G_007a6c1c;
extern void* G_007a6c0c;
extern void* G_007a6bfc;
extern void* G_007a6bec;
extern void* G_008baf44;

extern "C" void __stdcall sub_544b20();
extern "C" void __stdcall sub_541bf0();
extern "C" void* __stdcall sub_77e698();
extern "C" void __stdcall sub_77e6ac();

struct StdString {
    char buf[0x1c];
    StdString(const char*);
    ~StdString();
};

BoundPropGetSet::BoundPropGetSet() {
    sub_544b20();
    StdString s("DebugSettings");
    vtable0 = &G_007a6c5c;
    vtable4 = &G_007a6c54;
    vtable10 = &G_007a6c4c;
    vtable14 = &G_007a6c3c;
    vtable2c = &G_007a6c2c;
    vtable44 = &G_007a6c1c;
    vtable5c = &G_007a6c0c;
    vtable74 = &G_007a6bfc;
    vtable8c = &G_007a6bec;
    sub_77e698();
    sub_541bf0();
    sub_77e6ac();
    G_008baf44 = this;
}
