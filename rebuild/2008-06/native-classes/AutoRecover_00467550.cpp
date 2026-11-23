// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: interface identities unknown; raw vtable slot shapes taken from the disassembly.
namespace ATL { void __stdcall AtlThrowImpl(long hr); }

struct IfaceA {
    virtual long __stdcall a0() = 0; virtual long __stdcall a1() = 0; virtual long __stdcall a2() = 0;
    virtual long __stdcall a3(const void* iid, void** out, int flags) = 0;
};

struct IfaceB {
    virtual long __stdcall b0() = 0; virtual long __stdcall b1() = 0; virtual long __stdcall b2() = 0;
    virtual long __stdcall b3() = 0; virtual long __stdcall b4() = 0; virtual long __stdcall b5() = 0;
    virtual long __stdcall b6() = 0; virtual long __stdcall b7() = 0; virtual long __stdcall b8() = 0;
    virtual long __stdcall b9() = 0; virtual long __stdcall b10() = 0;
    virtual long __stdcall b11(const void* iid) = 0;
};

struct IfaceC {
    virtual long __stdcall c0() = 0; virtual long __stdcall c1() = 0; virtual long __stdcall c2() = 0;
    virtual long __stdcall c3() = 0; virtual long __stdcall c4() = 0; virtual long __stdcall c5() = 0;
    virtual long __stdcall c6(int flag, void* info) = 0;
};

struct Fn467550Self {
    char pad[0x174];
    IfaceA* a;      // +0x174
    IfaceB* b;      // +0x178
};

extern "C" void __fastcall fn_00467550(Fn467550Self* self, int unusedEdx)
{
    long hr = self->a->a3((const void*)0x85012c, (void**)&self->b, 0);
    if (hr < 0) ATL::AtlThrowImpl(hr);

    hr = self->b->b11((const void*)0x84ff0c);
    if (hr < 0) ATL::AtlThrowImpl(hr);

    IfaceC* c = *(IfaceC**)&self->b;
    int info[5];
    info[0] = 0x14;
    info[1] = 0x10;
    info[2] = 0;
    info[3] = 0;
    info[4] = 0x800;
    hr = c->c6(1, info);
    if (hr < 0) ATL::AtlThrowImpl(hr);
}
