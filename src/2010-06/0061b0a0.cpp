// from server: 100% by auto
// roc 2010-06 0061b0a0  unit: RBX::Accoutrement  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b0a0
//
// 0061b0a0  8b542404             mov edx, dword ptr [esp + 4]
// 0061b0a4  8b02                 mov eax, dword ptr [edx]
// 0061b0a6  56                   push esi
// 0061b0a7  8b7008               mov esi, dword ptr [eax + 8]
// 0061b0aa  8932                 mov dword ptr [edx], esi
// 0061b0ac  8b7008               mov esi, dword ptr [eax + 8]
// 0061b0af  807e2100             cmp byte ptr [esi + 0x21], 0
// 0061b0b3  7503                 jne 0x61b0b8
// 0061b0b5  895604               mov dword ptr [esi + 4], edx
// 0061b0b8  8b7204               mov esi, dword ptr [edx + 4]
// 0061b0bb  897004               mov dword ptr [eax + 4], esi
// 0061b0be  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0061b0c1  5e                   pop esi
// 0061b0c2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0061b0c5  750c                 jne 0x61b0d3
// 0061b0c7  894104               mov dword ptr [ecx + 4], eax
// 0061b0ca  895008               mov dword ptr [eax + 8], edx
// 0061b0cd  894204               mov dword ptr [edx + 4], eax
// 0061b0d0  c20400               ret 4
// 0061b0d3  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061b0d6  3b5108               cmp edx, dword ptr [ecx + 8]
// 0061b0d9  750c                 jne 0x61b0e7
// 0061b0db  894108               mov dword ptr [ecx + 8], eax
// 0061b0de  895008               mov dword ptr [eax + 8], edx
// 0061b0e1  894204               mov dword ptr [edx + 4], eax
// 0061b0e4  c20400               ret 4
// 0061b0e7  8901                 mov dword ptr [ecx], eax
// 0061b0e9  895008               mov dword ptr [eax + 8], edx
// 0061b0ec  894204               mov dword ptr [edx + 4], eax
// 0061b0ef  c20400               ret 4
// standard library set<pod20> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
