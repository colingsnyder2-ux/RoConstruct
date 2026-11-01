// from server: 100% by auto
// roc 2009-12 00702ca0  unit: RBX::Assembly  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00702ca0
//
// 00702ca0  8b542404             mov edx, dword ptr [esp + 4]
// 00702ca4  8b02                 mov eax, dword ptr [edx]
// 00702ca6  56                   push esi
// 00702ca7  8b7008               mov esi, dword ptr [eax + 8]
// 00702caa  8932                 mov dword ptr [edx], esi
// 00702cac  8b7008               mov esi, dword ptr [eax + 8]
// 00702caf  807e3100             cmp byte ptr [esi + 0x31], 0
// 00702cb3  7503                 jne 0x702cb8
// 00702cb5  895604               mov dword ptr [esi + 4], edx
// 00702cb8  8b7204               mov esi, dword ptr [edx + 4]
// 00702cbb  897004               mov dword ptr [eax + 4], esi
// 00702cbe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00702cc1  5e                   pop esi
// 00702cc2  3b5104               cmp edx, dword ptr [ecx + 4]
// 00702cc5  750c                 jne 0x702cd3
// 00702cc7  894104               mov dword ptr [ecx + 4], eax
// 00702cca  895008               mov dword ptr [eax + 8], edx
// 00702ccd  894204               mov dword ptr [edx + 4], eax
// 00702cd0  c20400               ret 4
// 00702cd3  8b4a04               mov ecx, dword ptr [edx + 4]
// 00702cd6  3b5108               cmp edx, dword ptr [ecx + 8]
// 00702cd9  750c                 jne 0x702ce7
// 00702cdb  894108               mov dword ptr [ecx + 8], eax
// 00702cde  895008               mov dword ptr [eax + 8], edx
// 00702ce1  894204               mov dword ptr [edx + 4], eax
// 00702ce4  c20400               ret 4
// 00702ce7  8901                 mov dword ptr [ecx], eax
// 00702ce9  895008               mov dword ptr [eax + 8], edx
// 00702cec  894204               mov dword ptr [edx + 4], eax
// 00702cef  c20400               ret 4
// standard library set<pod36> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
