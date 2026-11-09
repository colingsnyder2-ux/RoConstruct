// from server: 100% by auto
// roc 2011-06 0060dcb0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0060dcb0
//
// 0060dcb0  6a0c                 push 0xc
// 0060dcb2  e8a7c31f00           call 0x80a05e
// 0060dcb7  83c404               add esp, 4
// 0060dcba  85c0                 test eax, eax
// 0060dcbc  7406                 je 0x60dcc4
// 0060dcbe  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0060dcc2  8908                 mov dword ptr [eax], ecx
// 0060dcc4  8d4804               lea ecx, [eax + 4]
// 0060dcc7  85c9                 test ecx, ecx
// 0060dcc9  7406                 je 0x60dcd1
// 0060dccb  8b542408             mov edx, dword ptr [esp + 8]
// 0060dccf  8911                 mov dword ptr [ecx], edx
// 0060dcd1  8d4808               lea ecx, [eax + 8]
// 0060dcd4  85c9                 test ecx, ecx
// 0060dcd6  7408                 je 0x60dce0
// 0060dcd8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0060dcdc  8b12                 mov edx, dword ptr [edx]
// 0060dcde  8911                 mov dword ptr [ecx], edx
// 0060dce0  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
