// from server: 100% by auto
// roc 2009-06 00671c90  unit: RBX::VSpawnLocation::?$BoundPropGetSet  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00671c90
//
// 00671c90  6a0c                 push 0xc
// 00671c92  e8a16d0a00           call 0x718a38
// 00671c97  83c404               add esp, 4
// 00671c9a  85c0                 test eax, eax
// 00671c9c  7406                 je 0x671ca4
// 00671c9e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00671ca2  8908                 mov dword ptr [eax], ecx
// 00671ca4  8d4804               lea ecx, [eax + 4]
// 00671ca7  85c9                 test ecx, ecx
// 00671ca9  7406                 je 0x671cb1
// 00671cab  8b542408             mov edx, dword ptr [esp + 8]
// 00671caf  8911                 mov dword ptr [ecx], edx
// 00671cb1  8d4808               lea ecx, [eax + 8]
// 00671cb4  85c9                 test ecx, ecx
// 00671cb6  7408                 je 0x671cc0
// 00671cb8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00671cbc  8b12                 mov edx, dword ptr [edx]
// 00671cbe  8911                 mov dword ptr [ecx], edx
// 00671cc0  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
