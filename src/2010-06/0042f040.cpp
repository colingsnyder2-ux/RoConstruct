// from server: 100% by Yeetserama
// roc 2010-06 0042f040  unit: CMemberTreeView  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042f040
//
// 0042f040  56                   push esi
// 0042f041  8bf1                 mov esi, ecx
// 0042f043  e88c943700           call 0x7a84d4
// 0042f048  33c0                 xor eax, eax
// 0042f04a  c7065c6ca000         mov dword ptr [esi], 0xa06c5c
// 0042f050  8986f4000000         mov dword ptr [esi + 0xf4], eax
// 0042f056  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0042f05c  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0042f062  898600010000         mov dword ptr [esi + 0x100], eax
// 0042f068  898604010000         mov dword ptr [esi + 0x104], eax
// 0042f06e  898608010000         mov dword ptr [esi + 0x108], eax
// 0042f074  89860c010000         mov dword ptr [esi + 0x10c], eax
// 0042f07a  898610010000         mov dword ptr [esi + 0x110], eax
// 0042f080  8bc6                 mov eax, esi
// 0042f082  5e                   pop esi
// 0042f083  c3                   ret 
// copied from an identical function in another client (function ??0S@ns_ROCX00001e@@QAE@XZ)

namespace ns_ROCX00001e {
// from server: 100% by colin
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
