// from server: 100% by colin
struct CXTPDockingPaneContext {
    char pad[0xd0];
    int field_0xd0;
    int field_0xd4;
    int field_0xd8;
    int field_0xdc;
    void method();
};

struct Inner {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2(int);
};

extern "C" Inner* __fastcall sub_709C90(void*);

void CXTPDockingPaneContext::method() {
    if (field_0xdc != 0) {
        Inner* p;
        do {
            p = sub_709C90(&field_0xd0);
            (*(void (__thiscall**)(Inner*))(*(int*)p + 0x68))(p);
            (*(void (__thiscall**)(Inner*, int))(*(int*)p + 4))(p, 1);
        } while (field_0xdc != 0);
    }
}
