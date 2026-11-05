// from server: 100% by EspClaude
// roc 2009-06 004eba10  unit: std::D::DU?$char_traits::$$A6AXV?$basic_string::?$signal::slot  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004eba10
//
// 004eba10  6aff                 push -1
// 004eba12  6898c28500           push 0x85c298
// 004eba17  64a100000000         mov eax, dword ptr fs:[0]
// 004eba1d  50                   push eax
// 004eba1e  64892500000000       mov dword ptr fs:[0], esp
// 004eba25  51                   push ecx
// 004eba26  56                   push esi
// 004eba27  8bf1                 mov esi, ecx
// 004eba29  89742404             mov dword ptr [esp + 4], esi
// 004eba2d  8b0dc4e48900         mov ecx, dword ptr [0x89e4c4]
// 004eba33  51                   push ecx
// 004eba34  6800010000           push 0x100
// 004eba39  8d86240e0000         lea eax, [esi + 0xe24]
// 004eba3f  6a1c                 push 0x1c
// 004eba41  50                   push eax
// 004eba42  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004eba4a  e827e12200           call 0x719b76
// 004eba4f  8bce                 mov ecx, esi
// 004eba51  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004eba59  e852ecffff           call 0x4ea6b0
// 004eba5e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004eba62  5e                   pop esi
// 004eba63  64890d00000000       mov dword ptr fs:[0], ecx
// 004eba6a  83c410               add esp, 0x10
// 004eba6d  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

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