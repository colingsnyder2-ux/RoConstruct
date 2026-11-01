// from server: 100% by auto
// roc 2009-12 00454d70  unit: CRobloxDoc  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00454d70
//
// 00454d70  8b542404             mov edx, dword ptr [esp + 4]
// 00454d74  8b02                 mov eax, dword ptr [edx]
// 00454d76  56                   push esi
// 00454d77  8b7008               mov esi, dword ptr [eax + 8]
// 00454d7a  8932                 mov dword ptr [edx], esi
// 00454d7c  8b7008               mov esi, dword ptr [eax + 8]
// 00454d7f  807e1500             cmp byte ptr [esi + 0x15], 0
// 00454d83  7503                 jne 0x454d88
// 00454d85  895604               mov dword ptr [esi + 4], edx
// 00454d88  8b7204               mov esi, dword ptr [edx + 4]
// 00454d8b  897004               mov dword ptr [eax + 4], esi
// 00454d8e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00454d91  5e                   pop esi
// 00454d92  3b5104               cmp edx, dword ptr [ecx + 4]
// 00454d95  750c                 jne 0x454da3
// 00454d97  894104               mov dword ptr [ecx + 4], eax
// 00454d9a  895008               mov dword ptr [eax + 8], edx
// 00454d9d  894204               mov dword ptr [edx + 4], eax
// 00454da0  c20400               ret 4
// 00454da3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00454da6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00454da9  750c                 jne 0x454db7
// 00454dab  894108               mov dword ptr [ecx + 8], eax
// 00454dae  895008               mov dword ptr [eax + 8], edx
// 00454db1  894204               mov dword ptr [edx + 4], eax
// 00454db4  c20400               ret 4
// 00454db7  8901                 mov dword ptr [ecx], eax
// 00454db9  895008               mov dword ptr [eax + 8], edx
// 00454dbc  894204               mov dword ptr [edx + 4], eax
// 00454dbf  c20400               ret 4
// standard library set<pod8> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
