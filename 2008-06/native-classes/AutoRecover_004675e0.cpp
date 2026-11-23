// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers describe the objects involved, so the interfaces are
// declared as minimal COM-style vtables. The calls are made through the
// vtable slots seen in the disassembly.

namespace ATL {
    void __stdcall AtlThrowImpl(long hr);
}

// INFERRED: the two data addresses (0x81f038, 0x850114) look like GUIDs/IIDs.
struct FakeGuid { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };
extern "C" const FakeGuid g_data_0081f038;
extern "C" const FakeGuid g_data_00850114;

// INFERRED: interface held at this+0x174, slot 3 is a QueryService-like call.
struct IFirst {
    virtual long __stdcall s0() = 0;
    virtual long __stdcall s1() = 0;
    virtual long __stdcall s2() = 0;
    virtual long __stdcall Query(const FakeGuid* id, void** out, int extra) = 0;
};

struct SetupBlock {
    unsigned long cb;
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long flags;
};

// INFERRED: interface stored at this+0x17c; slot 11 takes an id, slot 6 takes (int, struct*).
struct ISecond {
    virtual long __stdcall s0() = 0;
    virtual long __stdcall s1() = 0;
    virtual long __stdcall s2() = 0;
    virtual long __stdcall s3() = 0;
    virtual long __stdcall s4() = 0;
    virtual long __stdcall s5() = 0;
    virtual long __stdcall Configure(int flag, SetupBlock* blk) = 0;
    virtual long __stdcall s7() = 0;
    virtual long __stdcall s8() = 0;
    virtual long __stdcall s9() = 0;
    virtual long __stdcall s10() = 0;
    virtual long __stdcall SetId(const FakeGuid* id) = 0;
};

extern "C" void __fastcall fn_004675e0(void* self, int unusedEdx)
{
    char* base = (char*)self;
    IFirst* first = *(IFirst**)(base + 0x174);
    ISecond** slot = (ISecond**)(base + 0x17c);

    long hr = first->Query(&g_data_0081f038, (void**)slot, 0);
    if (hr < 0)
        ATL::AtlThrowImpl(hr);

    hr = (*slot)->SetId(&g_data_00850114);
    if (hr < 0)
        ATL::AtlThrowImpl(hr);

    ISecond* second = *slot;
    SetupBlock blk;
    blk.cb = 0x14;
    blk.a = 0x10;
    blk.b = 0;
    blk.c = 0;
    blk.flags = 0x800;
    hr = second->Configure(1, &blk);
    if (hr < 0)
        ATL::AtlThrowImpl(hr);
}
