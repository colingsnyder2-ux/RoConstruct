// from server: 100% by auto
// roc 2009-12 0047a980  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047a980
//
// 0047a980  8b542404             mov edx, dword ptr [esp + 4]
// 0047a984  8b4208               mov eax, dword ptr [edx + 8]
// 0047a987  56                   push esi
// 0047a988  8b30                 mov esi, dword ptr [eax]
// 0047a98a  897208               mov dword ptr [edx + 8], esi
// 0047a98d  8b30                 mov esi, dword ptr [eax]
// 0047a98f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0047a993  7503                 jne 0x47a998
// 0047a995  895604               mov dword ptr [esi + 4], edx
// 0047a998  8b7204               mov esi, dword ptr [edx + 4]
// 0047a99b  897004               mov dword ptr [eax + 4], esi
// 0047a99e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0047a9a1  5e                   pop esi
// 0047a9a2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0047a9a5  750b                 jne 0x47a9b2
// 0047a9a7  894104               mov dword ptr [ecx + 4], eax
// 0047a9aa  8910                 mov dword ptr [eax], edx
// 0047a9ac  894204               mov dword ptr [edx + 4], eax
// 0047a9af  c20400               ret 4
// 0047a9b2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047a9b5  3b11                 cmp edx, dword ptr [ecx]
// 0047a9b7  750a                 jne 0x47a9c3
// 0047a9b9  8901                 mov dword ptr [ecx], eax
// 0047a9bb  8910                 mov dword ptr [eax], edx
// 0047a9bd  894204               mov dword ptr [edx + 4], eax
// 0047a9c0  c20400               ret 4
// 0047a9c3  894108               mov dword ptr [ecx + 8], eax
// 0047a9c6  8910                 mov dword ptr [eax], edx
// 0047a9c8  894204               mov dword ptr [edx + 4], eax
// 0047a9cb  c20400               ret 4
// standard library set<pod32> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
