// from server: 100% by auto
// roc 2009-06 005d9a10  unit: RBX::MD5HasherImpl  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d9a10
//
// 005d9a10  8b542404             mov edx, dword ptr [esp + 4]
// 005d9a14  8b4208               mov eax, dword ptr [edx + 8]
// 005d9a17  56                   push esi
// 005d9a18  8b30                 mov esi, dword ptr [eax]
// 005d9a1a  897208               mov dword ptr [edx + 8], esi
// 005d9a1d  8b30                 mov esi, dword ptr [eax]
// 005d9a1f  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005d9a23  7503                 jne 0x5d9a28
// 005d9a25  895604               mov dword ptr [esi + 4], edx
// 005d9a28  8b7204               mov esi, dword ptr [edx + 4]
// 005d9a2b  897004               mov dword ptr [eax + 4], esi
// 005d9a2e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005d9a31  5e                   pop esi
// 005d9a32  3b5104               cmp edx, dword ptr [ecx + 4]
// 005d9a35  750b                 jne 0x5d9a42
// 005d9a37  894104               mov dword ptr [ecx + 4], eax
// 005d9a3a  8910                 mov dword ptr [eax], edx
// 005d9a3c  894204               mov dword ptr [edx + 4], eax
// 005d9a3f  c20400               ret 4
// 005d9a42  8b4a04               mov ecx, dword ptr [edx + 4]
// 005d9a45  3b11                 cmp edx, dword ptr [ecx]
// 005d9a47  750a                 jne 0x5d9a53
// 005d9a49  8901                 mov dword ptr [ecx], eax
// 005d9a4b  8910                 mov dword ptr [eax], edx
// 005d9a4d  894204               mov dword ptr [edx + 4], eax
// 005d9a50  c20400               ret 4
// 005d9a53  894108               mov dword ptr [ecx + 8], eax
// 005d9a56  8910                 mov dword ptr [eax], edx
// 005d9a58  894204               mov dword ptr [edx + 4], eax
// 005d9a5b  c20400               ret 4
// standard library set<pod48> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
