// from server: 100% by EspClaude
// roc 2009-06 0040f280  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040f280
//
// 0040f280  83ec10               sub esp, 0x10
// 0040f283  e8869a3000           call 0x718d0e
// 0040f288  50                   push eax
// 0040f289  8d4c2404             lea ecx, [esp + 4]
// 0040f28d  e8769a3000           call 0x718d08
// 0040f292  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040f296  668b4808             mov cx, word ptr [eax + 8]
// 0040f29a  8b442404             mov eax, dword ptr [esp + 4]
// 0040f29e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0040f2a2  66890a               mov word ptr [edx], cx
// 0040f2a5  85c0                 test eax, eax
// 0040f2a7  7406                 je 0x40f2af
// 0040f2a9  8b0c24               mov ecx, dword ptr [esp]
// 0040f2ac  894804               mov dword ptr [eax + 4], ecx
// 0040f2af  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0040f2b4  740c                 je 0x40f2c2
// 0040f2b6  8b542408             mov edx, dword ptr [esp + 8]
// 0040f2ba  52                   push edx
// 0040f2bb  6a00                 push 0
// 0040f2bd  e83a9a3000           call 0x718cfc
// 0040f2c2  33c0                 xor eax, eax
// 0040f2c4  83c410               add esp, 0x10
// 0040f2c7  c20800               ret 8
// copied from an identical function in another client (function ?function@ns_ROCX00000f@@YGHPBUInput@1@PAG@Z)

namespace ns_ROCX00000f {
struct Link {
    void* unused;
    void* previous;
};

struct State {
    void* previous;
    Link* link;
    void* context;
    int active;

    State(void*);
};

struct Input {
    unsigned char reserved[8];
    unsigned short value;
};

extern "C" void* __cdecl get_state();
extern "C" void __stdcall release_state(int, void*);

int __stdcall function(const Input* input, unsigned short* output)
{
    State state(get_state());
    *output = input->value;

    if (state.link)
        state.link->previous = state.previous;

    if (state.active)
        release_state(0, state.context);

    return 0;
}
}
