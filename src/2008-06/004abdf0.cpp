// from server: 100% by auto
// roc 2008-06 004abdf0  unit: RBX::Network::Replicator  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004abdf0
//
// 004abdf0  8b542404             mov edx, dword ptr [esp + 4]
// 004abdf4  8b4208               mov eax, dword ptr [edx + 8]
// 004abdf7  56                   push esi
// 004abdf8  8b30                 mov esi, dword ptr [eax]
// 004abdfa  897208               mov dword ptr [edx + 8], esi
// 004abdfd  8b30                 mov esi, dword ptr [eax]
// 004abdff  807e1900             cmp byte ptr [esi + 0x19], 0
// 004abe03  7503                 jne 0x4abe08
// 004abe05  895604               mov dword ptr [esi + 4], edx
// 004abe08  8b7204               mov esi, dword ptr [edx + 4]
// 004abe0b  897004               mov dword ptr [eax + 4], esi
// 004abe0e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004abe11  5e                   pop esi
// 004abe12  3b5104               cmp edx, dword ptr [ecx + 4]
// 004abe15  750b                 jne 0x4abe22
// 004abe17  894104               mov dword ptr [ecx + 4], eax
// 004abe1a  8910                 mov dword ptr [eax], edx
// 004abe1c  894204               mov dword ptr [edx + 4], eax
// 004abe1f  c20400               ret 4
// 004abe22  8b4a04               mov ecx, dword ptr [edx + 4]
// 004abe25  3b11                 cmp edx, dword ptr [ecx]
// 004abe27  750a                 jne 0x4abe33
// 004abe29  8901                 mov dword ptr [ecx], eax
// 004abe2b  8910                 mov dword ptr [eax], edx
// 004abe2d  894204               mov dword ptr [edx + 4], eax
// 004abe30  c20400               ret 4
// 004abe33  894108               mov dword ptr [ecx + 8], eax
// 004abe36  8910                 mov dword ptr [eax], edx
// 004abe38  894204               mov dword ptr [edx + 4], eax
// 004abe3b  c20400               ret 4
// standard library set<double> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
