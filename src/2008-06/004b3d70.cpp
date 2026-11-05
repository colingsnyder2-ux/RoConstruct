// from server: 100% by EspClaude
// from server: 92% by king_originala
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2008-06 004b3d70  unit: RBX::Network::VPeer::?$BoundFuncDesc  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b3d70
//
// 004b3d70  6aff                 push -1
// 004b3d72  68f8877c00           push 0x7c87f8
// 004b3d77  64a100000000         mov eax, dword ptr fs:[0]
// 004b3d7d  50                   push eax
// 004b3d7e  64892500000000       mov dword ptr fs:[0], esp
// 004b3d85  51                   push ecx
// 004b3d86  56                   push esi
// 004b3d87  8bf1                 mov esi, ecx
// 004b3d89  89742404             mov dword ptr [esp + 4], esi
// 004b3d8d  8b0d68248000         mov ecx, dword ptr [0x802468]
// 004b3d93  51                   push ecx
// 004b3d94  6800010000           push 0x100
// 004b3d99  8d86240e0000         lea eax, [esi + 0xe24]
// 004b3d9f  6a1c                 push 0x1c
// 004b3da1  50                   push eax
// 004b3da2  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004b3daa  e8acd81e00           call 0x6a165b
// 004b3daf  8bce                 mov ecx, esi
// 004b3db1  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004b3db9  e832f9ffff           call 0x4b36f0
// 004b3dbe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004b3dc2  5e                   pop esi
// 004b3dc3  64890d00000000       mov dword ptr fs:[0], ecx
// 004b3dca  83c410               add esp, 0x10
// 004b3dcd  c3                   ret 

#include <string>
typedef std::string Element;

struct Base {
    char storage[0xe24];
    ~Base();
};

struct S : Base {
    struct Table { Element e[0x100]; } elements;
    ~S();
};

S::~S()
{
}
