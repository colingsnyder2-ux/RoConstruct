// from server: 100% by EspClaude
// roc 2009-06 0042da20  unit: CMemberTreeView  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042da20
//
// 0042da20  56                   push esi
// 0042da21  8bf1                 mov esi, ecx
// 0042da23  e83ebb2e00           call 0x719566
// 0042da28  33c0                 xor eax, eax
// 0042da2a  c70664318b00         mov dword ptr [esi], 0x8b3164
// 0042da30  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 0042da36  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0042da3c  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0042da42  898600010000         mov dword ptr [esi + 0x100], eax
// 0042da48  898604010000         mov dword ptr [esi + 0x104], eax
// 0042da4e  898608010000         mov dword ptr [esi + 0x108], eax
// 0042da54  89860c010000         mov dword ptr [esi + 0x10c], eax
// 0042da5a  898610010000         mov dword ptr [esi + 0x110], eax
// 0042da60  8bc6                 mov eax, esi
// 0042da62  5e                   pop esi
// 0042da63  c3                   ret 
// copied from an identical function in another client (function ??0S@ns_ROCX000003@@QAE@XZ)

namespace ns_ROCX000003 {
struct Vftable
{
    void* entries[8];
};

const Vftable S_vftable = {0, 0, 0, 0, 0, 0, 0, 0};

struct Base
{
    char storage[0xF4];
};

struct S : Base
{
    unsigned int fields[8];
    S();
};

extern "C" void __stdcall sub_6a10fa();

S::S()
{
    sub_6a10fa();
    *(volatile void**)this = (void*)&S_vftable;
    volatile unsigned int* f = fields;
    f[0] = 0;
    f[1] = 0;
    f[2] = 0;
    f[3] = 0;
    f[4] = 0;
    f[5] = 0;
    f[6] = 0;
    f[7] = 0;
}
}
