// from server: 100% by auto
// roc 2008-06 00587360  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00587360
//
// 00587360  8b542404             mov edx, dword ptr [esp + 4]
// 00587364  8b02                 mov eax, dword ptr [edx]
// 00587366  56                   push esi
// 00587367  8b7008               mov esi, dword ptr [eax + 8]
// 0058736a  8932                 mov dword ptr [edx], esi
// 0058736c  8b7008               mov esi, dword ptr [eax + 8]
// 0058736f  807e1900             cmp byte ptr [esi + 0x19], 0
// 00587373  7503                 jne 0x587378
// 00587375  895604               mov dword ptr [esi + 4], edx
// 00587378  8b7204               mov esi, dword ptr [edx + 4]
// 0058737b  897004               mov dword ptr [eax + 4], esi
// 0058737e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00587381  5e                   pop esi
// 00587382  3b5104               cmp edx, dword ptr [ecx + 4]
// 00587385  750c                 jne 0x587393
// 00587387  894104               mov dword ptr [ecx + 4], eax
// 0058738a  895008               mov dword ptr [eax + 8], edx
// 0058738d  894204               mov dword ptr [edx + 4], eax
// 00587390  c20400               ret 4
// 00587393  8b4a04               mov ecx, dword ptr [edx + 4]
// 00587396  3b5108               cmp edx, dword ptr [ecx + 8]
// 00587399  750c                 jne 0x5873a7
// 0058739b  894108               mov dword ptr [ecx + 8], eax
// 0058739e  895008               mov dword ptr [eax + 8], edx
// 005873a1  894204               mov dword ptr [edx + 4], eax
// 005873a4  c20400               ret 4
// 005873a7  8901                 mov dword ptr [ecx], eax
// 005873a9  895008               mov dword ptr [eax + 8], edx
// 005873ac  894204               mov dword ptr [edx + 4], eax
// 005873af  c20400               ret 4
// standard library set<double> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
