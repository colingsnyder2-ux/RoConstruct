// from server: 100% by auto
// roc 2009-06 00618640  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618640
//
// 00618640  8b542404             mov edx, dword ptr [esp + 4]
// 00618644  8b4208               mov eax, dword ptr [edx + 8]
// 00618647  56                   push esi
// 00618648  8b30                 mov esi, dword ptr [eax]
// 0061864a  897208               mov dword ptr [edx + 8], esi
// 0061864d  8b30                 mov esi, dword ptr [eax]
// 0061864f  807e1900             cmp byte ptr [esi + 0x19], 0
// 00618653  7503                 jne 0x618658
// 00618655  895604               mov dword ptr [esi + 4], edx
// 00618658  8b7204               mov esi, dword ptr [edx + 4]
// 0061865b  897004               mov dword ptr [eax + 4], esi
// 0061865e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00618661  5e                   pop esi
// 00618662  3b5104               cmp edx, dword ptr [ecx + 4]
// 00618665  750b                 jne 0x618672
// 00618667  894104               mov dword ptr [ecx + 4], eax
// 0061866a  8910                 mov dword ptr [eax], edx
// 0061866c  894204               mov dword ptr [edx + 4], eax
// 0061866f  c20400               ret 4
// 00618672  8b4a04               mov ecx, dword ptr [edx + 4]
// 00618675  3b11                 cmp edx, dword ptr [ecx]
// 00618677  750a                 jne 0x618683
// 00618679  8901                 mov dword ptr [ecx], eax
// 0061867b  8910                 mov dword ptr [eax], edx
// 0061867d  894204               mov dword ptr [edx + 4], eax
// 00618680  c20400               ret 4
// 00618683  894108               mov dword ptr [ecx + 8], eax
// 00618686  8910                 mov dword ptr [eax], edx
// 00618688  894204               mov dword ptr [edx + 4], eax
// 0061868b  c20400               ret 4
// standard library set<double> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
