// from server: 100% by auto
// roc 2007-08 004d02f0  unit: RBX::TextureProxyBase  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d02f0
//
// 004d02f0  8b542404             mov edx, dword ptr [esp + 4]
// 004d02f4  8b02                 mov eax, dword ptr [edx]
// 004d02f6  56                   push esi
// 004d02f7  8b7008               mov esi, dword ptr [eax + 8]
// 004d02fa  8932                 mov dword ptr [edx], esi
// 004d02fc  8b7008               mov esi, dword ptr [eax + 8]
// 004d02ff  807e2100             cmp byte ptr [esi + 0x21], 0
// 004d0303  7503                 jne 0x4d0308
// 004d0305  895604               mov dword ptr [esi + 4], edx
// 004d0308  8b7204               mov esi, dword ptr [edx + 4]
// 004d030b  897004               mov dword ptr [eax + 4], esi
// 004d030e  8b4904               mov ecx, dword ptr [ecx + 4]
// 004d0311  3b5104               cmp edx, dword ptr [ecx + 4]
// 004d0314  5e                   pop esi
// 004d0315  750c                 jne 0x4d0323
// 004d0317  894104               mov dword ptr [ecx + 4], eax
// 004d031a  895008               mov dword ptr [eax + 8], edx
// 004d031d  894204               mov dword ptr [edx + 4], eax
// 004d0320  c20400               ret 4
// 004d0323  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d0326  3b5108               cmp edx, dword ptr [ecx + 8]
// 004d0329  750c                 jne 0x4d0337
// 004d032b  894108               mov dword ptr [ecx + 8], eax
// 004d032e  895008               mov dword ptr [eax + 8], edx
// 004d0331  894204               mov dword ptr [edx + 4], eax
// 004d0334  c20400               ret 4
// 004d0337  8901                 mov dword ptr [ecx], eax
// 004d0339  895008               mov dword ptr [eax + 8], edx
// 004d033c  894204               mov dword ptr [edx + 4], eax
// 004d033f  c20400               ret 4
// standard library set<pod20> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
