// from server: 100% by auto
// roc 2012-06 008598f0  unit: boost::iostreams::Uinput::V?$chain::?$chain_client  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008598f0
//
// 008598f0  6a0c                 push 0xc
// 008598f2  e823881200           call 0x98211a
// 008598f7  83c404               add esp, 4
// 008598fa  85c0                 test eax, eax
// 008598fc  7406                 je 0x859904
// 008598fe  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00859902  8908                 mov dword ptr [eax], ecx
// 00859904  8d4804               lea ecx, [eax + 4]
// 00859907  85c9                 test ecx, ecx
// 00859909  7406                 je 0x859911
// 0085990b  8b542408             mov edx, dword ptr [esp + 8]
// 0085990f  8911                 mov dword ptr [ecx], edx
// 00859911  8d4808               lea ecx, [eax + 8]
// 00859914  85c9                 test ecx, ecx
// 00859916  7408                 je 0x859920
// 00859918  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085991c  8b12                 mov edx, dword ptr [edx]
// 0085991e  8911                 mov dword ptr [ecx], edx
// 00859920  c20c00               ret 0xc
// standard library list<ptr> (function ?_Buynode@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAU_Node@?$_List_nod@PAUT@@V?$allocator@PAUT@@@std@@@2@PAU342@0ABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
