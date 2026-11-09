// from server: 100% by auto
// roc 2009-06 004458c0  unit: CRobloxApp  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004458c0
//
// 004458c0  8b542404             mov edx, dword ptr [esp + 4]
// 004458c4  8b4208               mov eax, dword ptr [edx + 8]
// 004458c7  56                   push esi
// 004458c8  8b30                 mov esi, dword ptr [eax]
// 004458ca  897208               mov dword ptr [edx + 8], esi
// 004458cd  8b30                 mov esi, dword ptr [eax]
// 004458cf  807e2500             cmp byte ptr [esi + 0x25], 0
// 004458d3  7503                 jne 0x4458d8
// 004458d5  895604               mov dword ptr [esi + 4], edx
// 004458d8  8b7204               mov esi, dword ptr [edx + 4]
// 004458db  897004               mov dword ptr [eax + 4], esi
// 004458de  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004458e1  5e                   pop esi
// 004458e2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004458e5  750b                 jne 0x4458f2
// 004458e7  894104               mov dword ptr [ecx + 4], eax
// 004458ea  8910                 mov dword ptr [eax], edx
// 004458ec  894204               mov dword ptr [edx + 4], eax
// 004458ef  c20400               ret 4
// 004458f2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004458f5  3b11                 cmp edx, dword ptr [ecx]
// 004458f7  750a                 jne 0x445903
// 004458f9  8901                 mov dword ptr [ecx], eax
// 004458fb  8910                 mov dword ptr [eax], edx
// 004458fd  894204               mov dword ptr [edx + 4], eax
// 00445900  c20400               ret 4
// 00445903  894108               mov dword ptr [ecx + 8], eax
// 00445906  8910                 mov dword ptr [eax], edx
// 00445908  894204               mov dword ptr [edx + 4], eax
// 0044590b  c20400               ret 4
// standard library set<pod24> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
