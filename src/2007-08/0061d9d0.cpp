// from server: 100% by auto
// roc 2007-08 0061d9d0  unit: RBX::ChatOutput  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061d9d0
//
// 0061d9d0  8b542404             mov edx, dword ptr [esp + 4]
// 0061d9d4  8b02                 mov eax, dword ptr [edx]
// 0061d9d6  56                   push esi
// 0061d9d7  8b7008               mov esi, dword ptr [eax + 8]
// 0061d9da  8932                 mov dword ptr [edx], esi
// 0061d9dc  8b7008               mov esi, dword ptr [eax + 8]
// 0061d9df  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 0061d9e3  7503                 jne 0x61d9e8
// 0061d9e5  895604               mov dword ptr [esi + 4], edx
// 0061d9e8  8b7204               mov esi, dword ptr [edx + 4]
// 0061d9eb  897004               mov dword ptr [eax + 4], esi
// 0061d9ee  8b4904               mov ecx, dword ptr [ecx + 4]
// 0061d9f1  3b5104               cmp edx, dword ptr [ecx + 4]
// 0061d9f4  5e                   pop esi
// 0061d9f5  750c                 jne 0x61da03
// 0061d9f7  894104               mov dword ptr [ecx + 4], eax
// 0061d9fa  895008               mov dword ptr [eax + 8], edx
// 0061d9fd  894204               mov dword ptr [edx + 4], eax
// 0061da00  c20400               ret 4
// 0061da03  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061da06  3b5108               cmp edx, dword ptr [ecx + 8]
// 0061da09  750c                 jne 0x61da17
// 0061da0b  894108               mov dword ptr [ecx + 8], eax
// 0061da0e  895008               mov dword ptr [eax + 8], edx
// 0061da11  894204               mov dword ptr [edx + 4], eax
// 0061da14  c20400               ret 4
// 0061da17  8901                 mov dword ptr [ecx], eax
// 0061da19  895008               mov dword ptr [eax + 8], edx
// 0061da1c  894204               mov dword ptr [edx + 4], eax
// 0061da1f  c20400               ret 4
// standard library set<pod16> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
