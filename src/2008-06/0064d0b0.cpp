// from server: 100% by auto
// roc 2008-06 0064d0b0  unit: RBX::SimJobStage  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064d0b0
//
// 0064d0b0  6a0c                 push 0xc
// 0064d0b2  e869380500           call 0x6a0920
// 0064d0b7  83c404               add esp, 4
// 0064d0ba  85c0                 test eax, eax
// 0064d0bc  7406                 je 0x64d0c4
// 0064d0be  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0064d0c2  8908                 mov dword ptr [eax], ecx
// 0064d0c4  8d4804               lea ecx, [eax + 4]
// 0064d0c7  85c9                 test ecx, ecx
// 0064d0c9  7406                 je 0x64d0d1
// 0064d0cb  8b542408             mov edx, dword ptr [esp + 8]
// 0064d0cf  8911                 mov dword ptr [ecx], edx
// 0064d0d1  8d4808               lea ecx, [eax + 8]
// 0064d0d4  85c9                 test ecx, ecx
// 0064d0d6  7408                 je 0x64d0e0
// 0064d0d8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0064d0dc  8b12                 mov edx, dword ptr [edx]
// 0064d0de  8911                 mov dword ptr [ecx], edx
// 0064d0e0  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
