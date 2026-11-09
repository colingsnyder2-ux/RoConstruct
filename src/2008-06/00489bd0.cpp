// from server: 100% by auto
// roc 2008-06 00489bd0  unit: G3D::GWindow  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00489bd0
//
// 00489bd0  8b542404             mov edx, dword ptr [esp + 4]
// 00489bd4  8b02                 mov eax, dword ptr [edx]
// 00489bd6  56                   push esi
// 00489bd7  8b7008               mov esi, dword ptr [eax + 8]
// 00489bda  8932                 mov dword ptr [edx], esi
// 00489bdc  8b7008               mov esi, dword ptr [eax + 8]
// 00489bdf  807e0e00             cmp byte ptr [esi + 0xe], 0
// 00489be3  7503                 jne 0x489be8
// 00489be5  895604               mov dword ptr [esi + 4], edx
// 00489be8  8b7204               mov esi, dword ptr [edx + 4]
// 00489beb  897004               mov dword ptr [eax + 4], esi
// 00489bee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00489bf1  5e                   pop esi
// 00489bf2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00489bf5  750c                 jne 0x489c03
// 00489bf7  894104               mov dword ptr [ecx + 4], eax
// 00489bfa  895008               mov dword ptr [eax + 8], edx
// 00489bfd  894204               mov dword ptr [edx + 4], eax
// 00489c00  c20400               ret 4
// 00489c03  8b4a04               mov ecx, dword ptr [edx + 4]
// 00489c06  3b5108               cmp edx, dword ptr [ecx + 8]
// 00489c09  750c                 jne 0x489c17
// 00489c0b  894108               mov dword ptr [ecx + 8], eax
// 00489c0e  895008               mov dword ptr [eax + 8], edx
// 00489c11  894204               mov dword ptr [edx + 4], eax
// 00489c14  c20400               ret 4
// 00489c17  8901                 mov dword ptr [ecx], eax
// 00489c19  895008               mov dword ptr [eax + 8], edx
// 00489c1c  894204               mov dword ptr [edx + 4], eax
// 00489c1f  c20400               ret 4
// standard library set<char> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
