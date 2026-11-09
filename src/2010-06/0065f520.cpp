// from server: 100% by auto
// roc 2010-06 0065f520  unit: RBX::VPlayerMouse::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065f520
//
// 0065f520  8b542404             mov edx, dword ptr [esp + 4]
// 0065f524  8b4208               mov eax, dword ptr [edx + 8]
// 0065f527  56                   push esi
// 0065f528  8b30                 mov esi, dword ptr [eax]
// 0065f52a  897208               mov dword ptr [edx + 8], esi
// 0065f52d  8b30                 mov esi, dword ptr [eax]
// 0065f52f  807e3100             cmp byte ptr [esi + 0x31], 0
// 0065f533  7503                 jne 0x65f538
// 0065f535  895604               mov dword ptr [esi + 4], edx
// 0065f538  8b7204               mov esi, dword ptr [edx + 4]
// 0065f53b  897004               mov dword ptr [eax + 4], esi
// 0065f53e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0065f541  5e                   pop esi
// 0065f542  3b5104               cmp edx, dword ptr [ecx + 4]
// 0065f545  750b                 jne 0x65f552
// 0065f547  894104               mov dword ptr [ecx + 4], eax
// 0065f54a  8910                 mov dword ptr [eax], edx
// 0065f54c  894204               mov dword ptr [edx + 4], eax
// 0065f54f  c20400               ret 4
// 0065f552  8b4a04               mov ecx, dword ptr [edx + 4]
// 0065f555  3b11                 cmp edx, dword ptr [ecx]
// 0065f557  750a                 jne 0x65f563
// 0065f559  8901                 mov dword ptr [ecx], eax
// 0065f55b  8910                 mov dword ptr [eax], edx
// 0065f55d  894204               mov dword ptr [edx + 4], eax
// 0065f560  c20400               ret 4
// 0065f563  894108               mov dword ptr [ecx + 8], eax
// 0065f566  8910                 mov dword ptr [eax], edx
// 0065f568  894204               mov dword ptr [edx + 4], eax
// 0065f56b  c20400               ret 4
// standard library set<pod36> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
