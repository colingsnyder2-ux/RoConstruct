// from server: 100% by Yeetserama
// roc 2007-08 0040c920  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c920
//
// 0040c920  83ec10               sub esp, 0x10
// 0040c923  e81c362200           call 0x62ff44
// 0040c928  50                   push eax
// 0040c929  8d4c2404             lea ecx, [esp + 4]
// 0040c92d  e80c362200           call 0x62ff3e
// 0040c932  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040c936  668b4808             mov cx, word ptr [eax + 8]
// 0040c93a  8b442404             mov eax, dword ptr [esp + 4]
// 0040c93e  85c0                 test eax, eax
// 0040c940  8b542418             mov edx, dword ptr [esp + 0x18]
// 0040c944  66890a               mov word ptr [edx], cx
// 0040c947  7406                 je 0x40c94f
// 0040c949  8b0c24               mov ecx, dword ptr [esp]
// 0040c94c  894804               mov dword ptr [eax + 4], ecx
// 0040c94f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0040c954  740c                 je 0x40c962
// 0040c956  8b542408             mov edx, dword ptr [esp + 8]
// 0040c95a  52                   push edx
// 0040c95b  6a00                 push 0
// 0040c95d  e8d6352200           call 0x62ff38
// 0040c962  33c0                 xor eax, eax
// 0040c964  83c410               add esp, 0x10
// 0040c967  c20800               ret 8
// copied from an identical function in another client (function ?function@ns_ROCX000008@@YGHPBUInput@1@PAG@Z)

namespace ns_ROCX000008 {
// from server: 100% by king_originala
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
