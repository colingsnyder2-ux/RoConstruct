// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
//
// CAboutRobloxDialog::construct: base ctor, eight vtable stores, then a
// virtual call on the global dialog pointer. The call is a normal virtual
// dispatch, so the object lands in ecx and the slot in edx; declaring vfunc
// as the second slot reproduces the target's [eax + 4].

struct CAboutRobloxDialog {
    virtual void slot0();
    virtual void vfunc();
    CAboutRobloxDialog* construct(int);
};

extern CAboutRobloxDialog* g_8bae44;

extern "C" void __stdcall sub_466de0();

CAboutRobloxDialog* CAboutRobloxDialog::construct(int)
{
    sub_466de0();
    *(int*)((char*)this + 0) = 0x784b4c;
    *(int*)((char*)this + 4) = 0x784b34;
    *(int*)((char*)this + 8) = 0x784b1c;
    *(int*)((char*)this + 0xc) = 0x784af8;
    *(int*)((char*)this + 0x18) = 0x784ae0;
    *(int*)((char*)this + 0x20) = 0x784ac4;
    *(int*)((char*)this + 0x28) = 0x784ab8;
    *(int*)((char*)this + 0x2c) = 0x784aac;
    g_8bae44->vfunc();
    return this;
}
