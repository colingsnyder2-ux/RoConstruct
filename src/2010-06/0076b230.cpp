// from server: 100% by auto
// roc 2010-06 0076b230  unit: RBX::ImageButton  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076b230
//
// 0076b230  8b542404             mov edx, dword ptr [esp + 4]
// 0076b234  8b4208               mov eax, dword ptr [edx + 8]
// 0076b237  56                   push esi
// 0076b238  8b30                 mov esi, dword ptr [eax]
// 0076b23a  897208               mov dword ptr [edx + 8], esi
// 0076b23d  8b30                 mov esi, dword ptr [eax]
// 0076b23f  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 0076b243  7503                 jne 0x76b248
// 0076b245  895604               mov dword ptr [esi + 4], edx
// 0076b248  8b7204               mov esi, dword ptr [edx + 4]
// 0076b24b  897004               mov dword ptr [eax + 4], esi
// 0076b24e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0076b251  5e                   pop esi
// 0076b252  3b5104               cmp edx, dword ptr [ecx + 4]
// 0076b255  750b                 jne 0x76b262
// 0076b257  894104               mov dword ptr [ecx + 4], eax
// 0076b25a  8910                 mov dword ptr [eax], edx
// 0076b25c  894204               mov dword ptr [edx + 4], eax
// 0076b25f  c20400               ret 4
// 0076b262  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076b265  3b11                 cmp edx, dword ptr [ecx]
// 0076b267  750a                 jne 0x76b273
// 0076b269  8901                 mov dword ptr [ecx], eax
// 0076b26b  8910                 mov dword ptr [eax], edx
// 0076b26d  894204               mov dword ptr [edx + 4], eax
// 0076b270  c20400               ret 4
// 0076b273  894108               mov dword ptr [ecx + 8], eax
// 0076b276  8910                 mov dword ptr [eax], edx
// 0076b278  894204               mov dword ptr [edx + 4], eax
// 0076b27b  c20400               ret 4
// standard library set<pod64> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
