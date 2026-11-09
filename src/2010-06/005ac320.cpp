// from server: 100% by auto
// roc 2010-06 005ac320  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005ac320
//
// 005ac320  8b542404             mov edx, dword ptr [esp + 4]
// 005ac324  8b4208               mov eax, dword ptr [edx + 8]
// 005ac327  56                   push esi
// 005ac328  8b30                 mov esi, dword ptr [eax]
// 005ac32a  897208               mov dword ptr [edx + 8], esi
// 005ac32d  8b30                 mov esi, dword ptr [eax]
// 005ac32f  807e1500             cmp byte ptr [esi + 0x15], 0
// 005ac333  7503                 jne 0x5ac338
// 005ac335  895604               mov dword ptr [esi + 4], edx
// 005ac338  8b7204               mov esi, dword ptr [edx + 4]
// 005ac33b  897004               mov dword ptr [eax + 4], esi
// 005ac33e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005ac341  5e                   pop esi
// 005ac342  3b5104               cmp edx, dword ptr [ecx + 4]
// 005ac345  750b                 jne 0x5ac352
// 005ac347  894104               mov dword ptr [ecx + 4], eax
// 005ac34a  8910                 mov dword ptr [eax], edx
// 005ac34c  894204               mov dword ptr [edx + 4], eax
// 005ac34f  c20400               ret 4
// 005ac352  8b4a04               mov ecx, dword ptr [edx + 4]
// 005ac355  3b11                 cmp edx, dword ptr [ecx]
// 005ac357  750a                 jne 0x5ac363
// 005ac359  8901                 mov dword ptr [ecx], eax
// 005ac35b  8910                 mov dword ptr [eax], edx
// 005ac35d  894204               mov dword ptr [edx + 4], eax
// 005ac360  c20400               ret 4
// 005ac363  894108               mov dword ptr [ecx + 8], eax
// 005ac366  8910                 mov dword ptr [eax], edx
// 005ac368  894204               mov dword ptr [edx + 4], eax
// 005ac36b  c20400               ret 4
// standard library set<pod8> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
