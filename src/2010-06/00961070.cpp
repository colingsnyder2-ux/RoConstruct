// from server: 100% by auto
// roc 2010-06 00961070  unit: RBX::SphereBuilder  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00961070
//
// 00961070  6a10                 push 0x10
// 00961072  e82969e4ff           call 0x7a79a0
// 00961077  83c404               add esp, 4
// 0096107a  85c0                 test eax, eax
// 0096107c  7406                 je 0x961084
// 0096107e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00961082  8908                 mov dword ptr [eax], ecx
// 00961084  8d4804               lea ecx, [eax + 4]
// 00961087  85c9                 test ecx, ecx
// 00961089  7406                 je 0x961091
// 0096108b  8b542408             mov edx, dword ptr [esp + 8]
// 0096108f  8911                 mov dword ptr [ecx], edx
// 00961091  8d4808               lea ecx, [eax + 8]
// 00961094  85c9                 test ecx, ecx
// 00961096  7410                 je 0x9610a8
// 00961098  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0096109c  56                   push esi
// 0096109d  8b32                 mov esi, dword ptr [edx]
// 0096109f  8931                 mov dword ptr [ecx], esi
// 009610a1  8b5204               mov edx, dword ptr [edx + 4]
// 009610a4  895104               mov dword ptr [ecx + 4], edx
// 009610a7  5e                   pop esi
// 009610a8  c20c00               ret 0xc
// standard library list<i64> (function ?_Buynode@?$list@_JV?$allocator@_J@std@@@std@@IAEPAU_Node@?$_List_nod@_JV?$allocator@_J@std@@@2@PAU342@0AB_J@Z)

// stl: list<i64>
typedef __int64 E;
#include <list>
template class std::list<E>;
