// from server: 100% by auto
// roc 2007-08 005e9d20  unit: RBX::VFlagStand::?$FactoryProduct  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e9d20
//
// 005e9d20  6a0c                 push 0xc
// 005e9d22  e8cf610400           call 0x62fef6
// 005e9d27  83c404               add esp, 4
// 005e9d2a  85c0                 test eax, eax
// 005e9d2c  7406                 je 0x5e9d34
// 005e9d2e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005e9d32  8908                 mov dword ptr [eax], ecx
// 005e9d34  8d4804               lea ecx, [eax + 4]
// 005e9d37  85c9                 test ecx, ecx
// 005e9d39  7406                 je 0x5e9d41
// 005e9d3b  8b542408             mov edx, dword ptr [esp + 8]
// 005e9d3f  8911                 mov dword ptr [ecx], edx
// 005e9d41  8d4808               lea ecx, [eax + 8]
// 005e9d44  85c9                 test ecx, ecx
// 005e9d46  7408                 je 0x5e9d50
// 005e9d48  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005e9d4c  8b12                 mov edx, dword ptr [edx]
// 005e9d4e  8911                 mov dword ptr [ecx], edx
// 005e9d50  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
