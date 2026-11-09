// from server: 100% by auto
// roc 2009-12 0057bec0  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057bec0
//
// 0057bec0  6a10                 push 0x10
// 0057bec2  e899792700           call 0x7f3860
// 0057bec7  83c404               add esp, 4
// 0057beca  85c0                 test eax, eax
// 0057becc  7406                 je 0x57bed4
// 0057bece  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0057bed2  8908                 mov dword ptr [eax], ecx
// 0057bed4  8d4804               lea ecx, [eax + 4]
// 0057bed7  85c9                 test ecx, ecx
// 0057bed9  7406                 je 0x57bee1
// 0057bedb  8b542408             mov edx, dword ptr [esp + 8]
// 0057bedf  8911                 mov dword ptr [ecx], edx
// 0057bee1  8d4808               lea ecx, [eax + 8]
// 0057bee4  85c9                 test ecx, ecx
// 0057bee6  7410                 je 0x57bef8
// 0057bee8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0057beec  56                   push esi
// 0057beed  8b32                 mov esi, dword ptr [edx]
// 0057beef  8931                 mov dword ptr [ecx], esi
// 0057bef1  8b5204               mov edx, dword ptr [edx + 4]
// 0057bef4  895104               mov dword ptr [ecx + 4], edx
// 0057bef7  5e                   pop esi
// 0057bef8  c20c00               ret 0xc
// standard library list<i64> (function ?_Buynode@?$list@_JV?$allocator@_J@std@@@std@@IAEPAU_Node@?$_List_nod@_JV?$allocator@_J@std@@@2@PAU342@0AB_J@Z)

// stl: list<i64>
typedef __int64 E;
#include <list>
template class std::list<E>;
