// from server: 100% by auto
// roc 2010-06 0076af80  unit: RBX::ImageButton  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076af80
//
// 0076af80  8b542404             mov edx, dword ptr [esp + 4]
// 0076af84  8b02                 mov eax, dword ptr [edx]
// 0076af86  56                   push esi
// 0076af87  8b7008               mov esi, dword ptr [eax + 8]
// 0076af8a  8932                 mov dword ptr [edx], esi
// 0076af8c  8b7008               mov esi, dword ptr [eax + 8]
// 0076af8f  807e4d00             cmp byte ptr [esi + 0x4d], 0
// 0076af93  7503                 jne 0x76af98
// 0076af95  895604               mov dword ptr [esi + 4], edx
// 0076af98  8b7204               mov esi, dword ptr [edx + 4]
// 0076af9b  897004               mov dword ptr [eax + 4], esi
// 0076af9e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0076afa1  5e                   pop esi
// 0076afa2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0076afa5  750c                 jne 0x76afb3
// 0076afa7  894104               mov dword ptr [ecx + 4], eax
// 0076afaa  895008               mov dword ptr [eax + 8], edx
// 0076afad  894204               mov dword ptr [edx + 4], eax
// 0076afb0  c20400               ret 4
// 0076afb3  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076afb6  3b5108               cmp edx, dword ptr [ecx + 8]
// 0076afb9  750c                 jne 0x76afc7
// 0076afbb  894108               mov dword ptr [ecx + 8], eax
// 0076afbe  895008               mov dword ptr [eax + 8], edx
// 0076afc1  894204               mov dword ptr [edx + 4], eax
// 0076afc4  c20400               ret 4
// 0076afc7  8901                 mov dword ptr [ecx], eax
// 0076afc9  895008               mov dword ptr [eax + 8], edx
// 0076afcc  894204               mov dword ptr [edx + 4], eax
// 0076afcf  c20400               ret 4
// standard library set<pod64> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
