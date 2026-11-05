// from server: 100% by auto
// roc 2009-06 006d2fb0  unit: RBX::Block  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d2fb0
//
// 006d2fb0  8b542404             mov edx, dword ptr [esp + 4]
// 006d2fb4  8b4208               mov eax, dword ptr [edx + 8]
// 006d2fb7  56                   push esi
// 006d2fb8  8b30                 mov esi, dword ptr [eax]
// 006d2fba  897208               mov dword ptr [edx + 8], esi
// 006d2fbd  8b30                 mov esi, dword ptr [eax]
// 006d2fbf  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 006d2fc3  7503                 jne 0x6d2fc8
// 006d2fc5  895604               mov dword ptr [esi + 4], edx
// 006d2fc8  8b7204               mov esi, dword ptr [edx + 4]
// 006d2fcb  897004               mov dword ptr [eax + 4], esi
// 006d2fce  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006d2fd1  5e                   pop esi
// 006d2fd2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006d2fd5  750b                 jne 0x6d2fe2
// 006d2fd7  894104               mov dword ptr [ecx + 4], eax
// 006d2fda  8910                 mov dword ptr [eax], edx
// 006d2fdc  894204               mov dword ptr [edx + 4], eax
// 006d2fdf  c20400               ret 4
// 006d2fe2  8b4a04               mov ecx, dword ptr [edx + 4]
// 006d2fe5  3b11                 cmp edx, dword ptr [ecx]
// 006d2fe7  750a                 jne 0x6d2ff3
// 006d2fe9  8901                 mov dword ptr [ecx], eax
// 006d2feb  8910                 mov dword ptr [eax], edx
// 006d2fed  894204               mov dword ptr [edx + 4], eax
// 006d2ff0  c20400               ret 4
// 006d2ff3  894108               mov dword ptr [ecx + 8], eax
// 006d2ff6  8910                 mov dword ptr [eax], edx
// 006d2ff8  894204               mov dword ptr [edx + 4], eax
// 006d2ffb  c20400               ret 4
// standard library set<pod16> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
