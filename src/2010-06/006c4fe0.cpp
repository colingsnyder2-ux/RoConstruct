// from server: 100% by auto
// roc 2010-06 006c4fe0  unit: RBX::VFlagStandService::?$FactoryProduct  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006c4fe0
//
// 006c4fe0  6a0c                 push 0xc
// 006c4fe2  e8b9290e00           call 0x7a79a0
// 006c4fe7  83c404               add esp, 4
// 006c4fea  85c0                 test eax, eax
// 006c4fec  7406                 je 0x6c4ff4
// 006c4fee  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006c4ff2  8908                 mov dword ptr [eax], ecx
// 006c4ff4  8d4804               lea ecx, [eax + 4]
// 006c4ff7  85c9                 test ecx, ecx
// 006c4ff9  7406                 je 0x6c5001
// 006c4ffb  8b542408             mov edx, dword ptr [esp + 8]
// 006c4fff  8911                 mov dword ptr [ecx], edx
// 006c5001  8d4808               lea ecx, [eax + 8]
// 006c5004  85c9                 test ecx, ecx
// 006c5006  7408                 je 0x6c5010
// 006c5008  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006c500c  8b12                 mov edx, dword ptr [edx]
// 006c500e  8911                 mov dword ptr [ecx], edx
// 006c5010  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
