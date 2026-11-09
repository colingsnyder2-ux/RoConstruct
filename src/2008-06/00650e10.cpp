// from server: 100% by auto
// roc 2008-06 00650e10  unit: RBX::ChatOutput  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00650e10
//
// 00650e10  8b542404             mov edx, dword ptr [esp + 4]
// 00650e14  8b02                 mov eax, dword ptr [edx]
// 00650e16  56                   push esi
// 00650e17  8b7008               mov esi, dword ptr [eax + 8]
// 00650e1a  8932                 mov dword ptr [edx], esi
// 00650e1c  8b7008               mov esi, dword ptr [eax + 8]
// 00650e1f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00650e23  7503                 jne 0x650e28
// 00650e25  895604               mov dword ptr [esi + 4], edx
// 00650e28  8b7204               mov esi, dword ptr [edx + 4]
// 00650e2b  897004               mov dword ptr [eax + 4], esi
// 00650e2e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00650e31  5e                   pop esi
// 00650e32  3b5104               cmp edx, dword ptr [ecx + 4]
// 00650e35  750c                 jne 0x650e43
// 00650e37  894104               mov dword ptr [ecx + 4], eax
// 00650e3a  895008               mov dword ptr [eax + 8], edx
// 00650e3d  894204               mov dword ptr [edx + 4], eax
// 00650e40  c20400               ret 4
// 00650e43  8b4a04               mov ecx, dword ptr [edx + 4]
// 00650e46  3b5108               cmp edx, dword ptr [ecx + 8]
// 00650e49  750c                 jne 0x650e57
// 00650e4b  894108               mov dword ptr [ecx + 8], eax
// 00650e4e  895008               mov dword ptr [eax + 8], edx
// 00650e51  894204               mov dword ptr [edx + 4], eax
// 00650e54  c20400               ret 4
// 00650e57  8901                 mov dword ptr [ecx], eax
// 00650e59  895008               mov dword ptr [eax + 8], edx
// 00650e5c  894204               mov dword ptr [edx + 4], eax
// 00650e5f  c20400               ret 4
// standard library set<pod36> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
