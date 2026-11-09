// from server: 100% by auto
// roc 2010-06 004e68e0  unit: RBX::Network::Replicator  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004e68e0
//
// 004e68e0  8b542404             mov edx, dword ptr [esp + 4]
// 004e68e4  8b4208               mov eax, dword ptr [edx + 8]
// 004e68e7  56                   push esi
// 004e68e8  8b30                 mov esi, dword ptr [eax]
// 004e68ea  897208               mov dword ptr [edx + 8], esi
// 004e68ed  8b30                 mov esi, dword ptr [eax]
// 004e68ef  807e1900             cmp byte ptr [esi + 0x19], 0
// 004e68f3  7503                 jne 0x4e68f8
// 004e68f5  895604               mov dword ptr [esi + 4], edx
// 004e68f8  8b7204               mov esi, dword ptr [edx + 4]
// 004e68fb  897004               mov dword ptr [eax + 4], esi
// 004e68fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004e6901  5e                   pop esi
// 004e6902  3b5104               cmp edx, dword ptr [ecx + 4]
// 004e6905  750b                 jne 0x4e6912
// 004e6907  894104               mov dword ptr [ecx + 4], eax
// 004e690a  8910                 mov dword ptr [eax], edx
// 004e690c  894204               mov dword ptr [edx + 4], eax
// 004e690f  c20400               ret 4
// 004e6912  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e6915  3b11                 cmp edx, dword ptr [ecx]
// 004e6917  750a                 jne 0x4e6923
// 004e6919  8901                 mov dword ptr [ecx], eax
// 004e691b  8910                 mov dword ptr [eax], edx
// 004e691d  894204               mov dword ptr [edx + 4], eax
// 004e6920  c20400               ret 4
// 004e6923  894108               mov dword ptr [ecx + 8], eax
// 004e6926  8910                 mov dword ptr [eax], edx
// 004e6928  894204               mov dword ptr [edx + 4], eax
// 004e692b  c20400               ret 4
// standard library set<double> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
