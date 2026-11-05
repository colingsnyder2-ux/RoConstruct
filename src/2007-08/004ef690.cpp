// from server: 100% by auto
// roc 2007-08 004ef690  unit: RBX::Render::SceneManager  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ef690
//
// 004ef690  8b542404             mov edx, dword ptr [esp + 4]
// 004ef694  8b4208               mov eax, dword ptr [edx + 8]
// 004ef697  56                   push esi
// 004ef698  8b30                 mov esi, dword ptr [eax]
// 004ef69a  897208               mov dword ptr [edx + 8], esi
// 004ef69d  8b30                 mov esi, dword ptr [eax]
// 004ef69f  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 004ef6a3  7503                 jne 0x4ef6a8
// 004ef6a5  895604               mov dword ptr [esi + 4], edx
// 004ef6a8  8b7204               mov esi, dword ptr [edx + 4]
// 004ef6ab  897004               mov dword ptr [eax + 4], esi
// 004ef6ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 004ef6b1  3b5104               cmp edx, dword ptr [ecx + 4]
// 004ef6b4  5e                   pop esi
// 004ef6b5  750b                 jne 0x4ef6c2
// 004ef6b7  894104               mov dword ptr [ecx + 4], eax
// 004ef6ba  8910                 mov dword ptr [eax], edx
// 004ef6bc  894204               mov dword ptr [edx + 4], eax
// 004ef6bf  c20400               ret 4
// 004ef6c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ef6c5  3b11                 cmp edx, dword ptr [ecx]
// 004ef6c7  750a                 jne 0x4ef6d3
// 004ef6c9  8901                 mov dword ptr [ecx], eax
// 004ef6cb  8910                 mov dword ptr [eax], edx
// 004ef6cd  894204               mov dword ptr [edx + 4], eax
// 004ef6d0  c20400               ret 4
// 004ef6d3  894108               mov dword ptr [ecx + 8], eax
// 004ef6d6  8910                 mov dword ptr [eax], edx
// 004ef6d8  894204               mov dword ptr [edx + 4], eax
// 004ef6db  c20400               ret 4
// standard library set<pod16> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
