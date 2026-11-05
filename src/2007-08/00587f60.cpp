// from server: 100% by auto
// roc 2007-08 00587f60  unit: RBX::SoundChannel  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587f60
//
// 00587f60  8b542404             mov edx, dword ptr [esp + 4]
// 00587f64  8b4208               mov eax, dword ptr [edx + 8]
// 00587f67  56                   push esi
// 00587f68  8b30                 mov esi, dword ptr [eax]
// 00587f6a  897208               mov dword ptr [edx + 8], esi
// 00587f6d  8b30                 mov esi, dword ptr [eax]
// 00587f6f  807e3500             cmp byte ptr [esi + 0x35], 0
// 00587f73  7503                 jne 0x587f78
// 00587f75  895604               mov dword ptr [esi + 4], edx
// 00587f78  8b7204               mov esi, dword ptr [edx + 4]
// 00587f7b  897004               mov dword ptr [eax + 4], esi
// 00587f7e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00587f81  3b5104               cmp edx, dword ptr [ecx + 4]
// 00587f84  5e                   pop esi
// 00587f85  750b                 jne 0x587f92
// 00587f87  894104               mov dword ptr [ecx + 4], eax
// 00587f8a  8910                 mov dword ptr [eax], edx
// 00587f8c  894204               mov dword ptr [edx + 4], eax
// 00587f8f  c20400               ret 4
// 00587f92  8b4a04               mov ecx, dword ptr [edx + 4]
// 00587f95  3b11                 cmp edx, dword ptr [ecx]
// 00587f97  750a                 jne 0x587fa3
// 00587f99  8901                 mov dword ptr [ecx], eax
// 00587f9b  8910                 mov dword ptr [eax], edx
// 00587f9d  894204               mov dword ptr [edx + 4], eax
// 00587fa0  c20400               ret 4
// 00587fa3  894108               mov dword ptr [ecx + 8], eax
// 00587fa6  8910                 mov dword ptr [eax], edx
// 00587fa8  894204               mov dword ptr [edx + 4], eax
// 00587fab  c20400               ret 4
// standard library set<pod40> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
