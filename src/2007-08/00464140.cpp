// from server: 100% by EspClaude
// from server: 68% by Intel
// roc 2007-08 00464140  unit: DxUserInput  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464140
//
// 00464140  51                   push ecx
// 00464141  80796800             cmp byte ptr [ecx + 0x68], 0
// 00464145  c7042400000000       mov dword ptr [esp], 0
// 0046414c  7417                 je 0x464165
// 0046414e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00464152  56                   push esi
// 00464153  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00464157  50                   push eax
// 00464158  56                   push esi
// 00464159  e892821300           call 0x59c3f0
// 0046415e  8bc6                 mov eax, esi
// 00464160  5e                   pop esi
// 00464161  59                   pop ecx
// 00464162  c20800               ret 8
// 00464165  8b442408             mov eax, dword ptr [esp + 8]
// 00464169  c70000000000         mov dword ptr [eax], 0

// Return-by-hidden-pointer: [esp+8] is the return slot, [esp+0xc] the argument.
struct Handle {
    void *p;
    Handle() : p(0) {}
    ~Handle();
};

Handle __stdcall sub_59C3F0(int a1);

struct DxUserInput {
    char pad[0x68];
    bool enabled;
    Handle func(int a1);
};

Handle DxUserInput::func(int a1)
{
    if (enabled)
        return sub_59C3F0(a1);
    return Handle();
}
