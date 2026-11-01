// from server: 100% by tester
#define PADV(n) virtual void p##n() {}
struct Viewport { char pad[0x70]; char bg[4]; };
struct Target { virtual void f() = 0; };
struct Sys {
    virtual void v0();
};
// vtable slots are addressed by byte offset; model with function-pointer tables
struct VT1 { void* s[0x33]; void (__thiscall *setViewport)(void*, Viewport*); };
struct VT2 { void* s[0x28]; void (__thiscall *setBg)(void*, const char*); };
struct Obj1 { VT1* vt; };
struct Obj2 { VT2* vt; };
__declspec(dllimport) Obj2* __stdcall getSingleton();
struct SM {
    char pad[0x34];
    Obj1* rs;
    char pad2[0xbc - 0x38];
    Viewport* vp;
    void setViewport(Viewport* v);
};
void SM::setViewport(Viewport* v) {
    vp = v;
    rs->vt->setViewport(rs, v);
    Obj2* o = getSingleton();
    o->vt->setBg(o, v->bg);
}
