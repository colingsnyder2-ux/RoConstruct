// from server: 100% by auto
// roc 2007-08 00569490  unit: RBX::ModelInstance  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00569490
//
// 00569490  8b542404             mov edx, dword ptr [esp + 4]
// 00569494  8b02                 mov eax, dword ptr [edx]
// 00569496  56                   push esi
// 00569497  8b7008               mov esi, dword ptr [eax + 8]
// 0056949a  8932                 mov dword ptr [edx], esi
// 0056949c  8b7008               mov esi, dword ptr [eax + 8]
// 0056949f  807e3100             cmp byte ptr [esi + 0x31], 0
// 005694a3  7503                 jne 0x5694a8
// 005694a5  895604               mov dword ptr [esi + 4], edx
// 005694a8  8b7204               mov esi, dword ptr [edx + 4]
// 005694ab  897004               mov dword ptr [eax + 4], esi
// 005694ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 005694b1  3b5104               cmp edx, dword ptr [ecx + 4]
// 005694b4  5e                   pop esi
// 005694b5  750c                 jne 0x5694c3
// 005694b7  894104               mov dword ptr [ecx + 4], eax
// 005694ba  895008               mov dword ptr [eax + 8], edx
// 005694bd  894204               mov dword ptr [edx + 4], eax
// 005694c0  c20400               ret 4
// 005694c3  8b4a04               mov ecx, dword ptr [edx + 4]
// 005694c6  3b5108               cmp edx, dword ptr [ecx + 8]
// 005694c9  750c                 jne 0x5694d7
// 005694cb  894108               mov dword ptr [ecx + 8], eax
// 005694ce  895008               mov dword ptr [eax + 8], edx
// 005694d1  894204               mov dword ptr [edx + 4], eax
// 005694d4  c20400               ret 4
// 005694d7  8901                 mov dword ptr [ecx], eax
// 005694d9  895008               mov dword ptr [eax + 8], edx
// 005694dc  894204               mov dword ptr [edx + 4], eax
// 005694df  c20400               ret 4
// standard library set<pod36> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
