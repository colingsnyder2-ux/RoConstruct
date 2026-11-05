// from server: 100% by auto
// roc 2009-12 007af600  unit: RBX::Block  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007af600
//
// 007af600  8b542404             mov edx, dword ptr [esp + 4]
// 007af604  8b02                 mov eax, dword ptr [edx]
// 007af606  56                   push esi
// 007af607  8b7008               mov esi, dword ptr [eax + 8]
// 007af60a  8932                 mov dword ptr [edx], esi
// 007af60c  8b7008               mov esi, dword ptr [eax + 8]
// 007af60f  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 007af613  7503                 jne 0x7af618
// 007af615  895604               mov dword ptr [esi + 4], edx
// 007af618  8b7204               mov esi, dword ptr [edx + 4]
// 007af61b  897004               mov dword ptr [eax + 4], esi
// 007af61e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007af621  5e                   pop esi
// 007af622  3b5104               cmp edx, dword ptr [ecx + 4]
// 007af625  750c                 jne 0x7af633
// 007af627  894104               mov dword ptr [ecx + 4], eax
// 007af62a  895008               mov dword ptr [eax + 8], edx
// 007af62d  894204               mov dword ptr [edx + 4], eax
// 007af630  c20400               ret 4
// 007af633  8b4a04               mov ecx, dword ptr [edx + 4]
// 007af636  3b5108               cmp edx, dword ptr [ecx + 8]
// 007af639  750c                 jne 0x7af647
// 007af63b  894108               mov dword ptr [ecx + 8], eax
// 007af63e  895008               mov dword ptr [eax + 8], edx
// 007af641  894204               mov dword ptr [edx + 4], eax
// 007af644  c20400               ret 4
// 007af647  8901                 mov dword ptr [ecx], eax
// 007af649  895008               mov dword ptr [eax + 8], edx
// 007af64c  894204               mov dword ptr [edx + 4], eax
// 007af64f  c20400               ret 4
// standard library set<pod16> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
