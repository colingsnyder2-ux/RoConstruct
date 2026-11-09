// from server: 100% by auto
// roc 2008-06 005b6ae0  unit: RBX::DropperTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b6ae0
//
// 005b6ae0  8b542404             mov edx, dword ptr [esp + 4]
// 005b6ae4  8b02                 mov eax, dword ptr [edx]
// 005b6ae6  56                   push esi
// 005b6ae7  8b7008               mov esi, dword ptr [eax + 8]
// 005b6aea  8932                 mov dword ptr [edx], esi
// 005b6aec  8b7008               mov esi, dword ptr [eax + 8]
// 005b6aef  807e3500             cmp byte ptr [esi + 0x35], 0
// 005b6af3  7503                 jne 0x5b6af8
// 005b6af5  895604               mov dword ptr [esi + 4], edx
// 005b6af8  8b7204               mov esi, dword ptr [edx + 4]
// 005b6afb  897004               mov dword ptr [eax + 4], esi
// 005b6afe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005b6b01  5e                   pop esi
// 005b6b02  3b5104               cmp edx, dword ptr [ecx + 4]
// 005b6b05  750c                 jne 0x5b6b13
// 005b6b07  894104               mov dword ptr [ecx + 4], eax
// 005b6b0a  895008               mov dword ptr [eax + 8], edx
// 005b6b0d  894204               mov dword ptr [edx + 4], eax
// 005b6b10  c20400               ret 4
// 005b6b13  8b4a04               mov ecx, dword ptr [edx + 4]
// 005b6b16  3b5108               cmp edx, dword ptr [ecx + 8]
// 005b6b19  750c                 jne 0x5b6b27
// 005b6b1b  894108               mov dword ptr [ecx + 8], eax
// 005b6b1e  895008               mov dword ptr [eax + 8], edx
// 005b6b21  894204               mov dword ptr [edx + 4], eax
// 005b6b24  c20400               ret 4
// 005b6b27  8901                 mov dword ptr [ecx], eax
// 005b6b29  895008               mov dword ptr [eax + 8], edx
// 005b6b2c  894204               mov dword ptr [edx + 4], eax
// 005b6b2f  c20400               ret 4
// standard library set<pod40> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
