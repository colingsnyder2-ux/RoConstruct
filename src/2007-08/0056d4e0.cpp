// from server: 100% by auto
// roc 2007-08 0056d4e0  unit: RBX::Lua::ThreadRef::VNode::?$sp_counted_impl_p  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0056d4e0
//
// 0056d4e0  8b542404             mov edx, dword ptr [esp + 4]
// 0056d4e4  8b4208               mov eax, dword ptr [edx + 8]
// 0056d4e7  56                   push esi
// 0056d4e8  8b30                 mov esi, dword ptr [eax]
// 0056d4ea  897208               mov dword ptr [edx + 8], esi
// 0056d4ed  8b30                 mov esi, dword ptr [eax]
// 0056d4ef  807e1500             cmp byte ptr [esi + 0x15], 0
// 0056d4f3  7503                 jne 0x56d4f8
// 0056d4f5  895604               mov dword ptr [esi + 4], edx
// 0056d4f8  8b7204               mov esi, dword ptr [edx + 4]
// 0056d4fb  897004               mov dword ptr [eax + 4], esi
// 0056d4fe  8b4904               mov ecx, dword ptr [ecx + 4]
// 0056d501  3b5104               cmp edx, dword ptr [ecx + 4]
// 0056d504  5e                   pop esi
// 0056d505  750b                 jne 0x56d512
// 0056d507  894104               mov dword ptr [ecx + 4], eax
// 0056d50a  8910                 mov dword ptr [eax], edx
// 0056d50c  894204               mov dword ptr [edx + 4], eax
// 0056d50f  c20400               ret 4
// 0056d512  8b4a04               mov ecx, dword ptr [edx + 4]
// 0056d515  3b11                 cmp edx, dword ptr [ecx]
// 0056d517  750a                 jne 0x56d523
// 0056d519  8901                 mov dword ptr [ecx], eax
// 0056d51b  8910                 mov dword ptr [eax], edx
// 0056d51d  894204               mov dword ptr [edx + 4], eax
// 0056d520  c20400               ret 4
// 0056d523  894108               mov dword ptr [ecx + 8], eax
// 0056d526  8910                 mov dword ptr [eax], edx
// 0056d528  894204               mov dword ptr [edx + 4], eax
// 0056d52b  c20400               ret 4
// standard library set<pod8> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
