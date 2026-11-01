// from server: 100% by auto
// roc 2009-12 007c1e10  unit: RBX::ImageButton  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c1e10
//
// 007c1e10  8b542404             mov edx, dword ptr [esp + 4]
// 007c1e14  8b02                 mov eax, dword ptr [edx]
// 007c1e16  56                   push esi
// 007c1e17  8b7008               mov esi, dword ptr [eax + 8]
// 007c1e1a  8932                 mov dword ptr [edx], esi
// 007c1e1c  8b7008               mov esi, dword ptr [eax + 8]
// 007c1e1f  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 007c1e23  7503                 jne 0x7c1e28
// 007c1e25  895604               mov dword ptr [esi + 4], edx
// 007c1e28  8b7204               mov esi, dword ptr [edx + 4]
// 007c1e2b  897004               mov dword ptr [eax + 4], esi
// 007c1e2e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007c1e31  5e                   pop esi
// 007c1e32  3b5104               cmp edx, dword ptr [ecx + 4]
// 007c1e35  750c                 jne 0x7c1e43
// 007c1e37  894104               mov dword ptr [ecx + 4], eax
// 007c1e3a  895008               mov dword ptr [eax + 8], edx
// 007c1e3d  894204               mov dword ptr [edx + 4], eax
// 007c1e40  c20400               ret 4
// 007c1e43  8b4a04               mov ecx, dword ptr [edx + 4]
// 007c1e46  3b5108               cmp edx, dword ptr [ecx + 8]
// 007c1e49  750c                 jne 0x7c1e57
// 007c1e4b  894108               mov dword ptr [ecx + 8], eax
// 007c1e4e  895008               mov dword ptr [eax + 8], edx
// 007c1e51  894204               mov dword ptr [edx + 4], eax
// 007c1e54  c20400               ret 4
// 007c1e57  8901                 mov dword ptr [ecx], eax
// 007c1e59  895008               mov dword ptr [eax + 8], edx
// 007c1e5c  894204               mov dword ptr [edx + 4], eax
// 007c1e5f  c20400               ret 4
// standard library set<pod64> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
