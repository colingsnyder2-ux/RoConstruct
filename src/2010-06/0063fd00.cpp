// from server: 100% by auto
// roc 2010-06 0063fd00  unit: RBX::VVisit::?$BoundFuncDesc  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063fd00
//
// 0063fd00  8b542404             mov edx, dword ptr [esp + 4]
// 0063fd04  8b02                 mov eax, dword ptr [edx]
// 0063fd06  56                   push esi
// 0063fd07  8b7008               mov esi, dword ptr [eax + 8]
// 0063fd0a  8932                 mov dword ptr [edx], esi
// 0063fd0c  8b7008               mov esi, dword ptr [eax + 8]
// 0063fd0f  807e3500             cmp byte ptr [esi + 0x35], 0
// 0063fd13  7503                 jne 0x63fd18
// 0063fd15  895604               mov dword ptr [esi + 4], edx
// 0063fd18  8b7204               mov esi, dword ptr [edx + 4]
// 0063fd1b  897004               mov dword ptr [eax + 4], esi
// 0063fd1e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0063fd21  5e                   pop esi
// 0063fd22  3b5104               cmp edx, dword ptr [ecx + 4]
// 0063fd25  750c                 jne 0x63fd33
// 0063fd27  894104               mov dword ptr [ecx + 4], eax
// 0063fd2a  895008               mov dword ptr [eax + 8], edx
// 0063fd2d  894204               mov dword ptr [edx + 4], eax
// 0063fd30  c20400               ret 4
// 0063fd33  8b4a04               mov ecx, dword ptr [edx + 4]
// 0063fd36  3b5108               cmp edx, dword ptr [ecx + 8]
// 0063fd39  750c                 jne 0x63fd47
// 0063fd3b  894108               mov dword ptr [ecx + 8], eax
// 0063fd3e  895008               mov dword ptr [eax + 8], edx
// 0063fd41  894204               mov dword ptr [edx + 4], eax
// 0063fd44  c20400               ret 4
// 0063fd47  8901                 mov dword ptr [ecx], eax
// 0063fd49  895008               mov dword ptr [eax + 8], edx
// 0063fd4c  894204               mov dword ptr [edx + 4], eax
// 0063fd4f  c20400               ret 4
// standard library set<pod40> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
