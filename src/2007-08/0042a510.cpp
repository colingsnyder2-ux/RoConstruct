// from server: 100% by colin
// roc 2007-08 0042a510  unit: seg_00420000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042a510
//
// 0042a510  e83b5a2000           call 0x62ff50
// 0042a515  8b10                 mov edx, dword ptr [eax]
// 0042a517  8bc8                 mov ecx, eax
// 0042a519  8b4268               mov eax, dword ptr [edx + 0x68]
// 0042a51c  ffe0                 jmp eax

struct CLuaHtmlView;

extern "C" CLuaHtmlView* __cdecl sub_62FF50();

struct CLuaHtmlView {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
};

void sub_42A510() {
    CLuaHtmlView* p = sub_62FF50();
    p->v068();
}
