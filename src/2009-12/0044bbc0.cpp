// from server: 100% by auto
// roc 2009-12 0044bbc0  unit: CRobloxApp  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044bbc0
//
// 0044bbc0  8b542404             mov edx, dword ptr [esp + 4]
// 0044bbc4  8b4208               mov eax, dword ptr [edx + 8]
// 0044bbc7  56                   push esi
// 0044bbc8  8b30                 mov esi, dword ptr [eax]
// 0044bbca  897208               mov dword ptr [edx + 8], esi
// 0044bbcd  8b30                 mov esi, dword ptr [eax]
// 0044bbcf  807e2500             cmp byte ptr [esi + 0x25], 0
// 0044bbd3  7503                 jne 0x44bbd8
// 0044bbd5  895604               mov dword ptr [esi + 4], edx
// 0044bbd8  8b7204               mov esi, dword ptr [edx + 4]
// 0044bbdb  897004               mov dword ptr [eax + 4], esi
// 0044bbde  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0044bbe1  5e                   pop esi
// 0044bbe2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0044bbe5  750b                 jne 0x44bbf2
// 0044bbe7  894104               mov dword ptr [ecx + 4], eax
// 0044bbea  8910                 mov dword ptr [eax], edx
// 0044bbec  894204               mov dword ptr [edx + 4], eax
// 0044bbef  c20400               ret 4
// 0044bbf2  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044bbf5  3b11                 cmp edx, dword ptr [ecx]
// 0044bbf7  750a                 jne 0x44bc03
// 0044bbf9  8901                 mov dword ptr [ecx], eax
// 0044bbfb  8910                 mov dword ptr [eax], edx
// 0044bbfd  894204               mov dword ptr [edx + 4], eax
// 0044bc00  c20400               ret 4
// 0044bc03  894108               mov dword ptr [ecx + 8], eax
// 0044bc06  8910                 mov dword ptr [eax], edx
// 0044bc08  894204               mov dword ptr [edx + 4], eax
// 0044bc0b  c20400               ret 4
// standard library set<pod24> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
