// from server: 100% by auto
// roc 2009-12 00432e40  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00432e40
//
// 00432e40  8b542404             mov edx, dword ptr [esp + 4]
// 00432e44  8b02                 mov eax, dword ptr [edx]
// 00432e46  56                   push esi
// 00432e47  8b7008               mov esi, dword ptr [eax + 8]
// 00432e4a  8932                 mov dword ptr [edx], esi
// 00432e4c  8b7008               mov esi, dword ptr [eax + 8]
// 00432e4f  807e1900             cmp byte ptr [esi + 0x19], 0
// 00432e53  7503                 jne 0x432e58
// 00432e55  895604               mov dword ptr [esi + 4], edx
// 00432e58  8b7204               mov esi, dword ptr [edx + 4]
// 00432e5b  897004               mov dword ptr [eax + 4], esi
// 00432e5e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00432e61  5e                   pop esi
// 00432e62  3b5104               cmp edx, dword ptr [ecx + 4]
// 00432e65  750c                 jne 0x432e73
// 00432e67  894104               mov dword ptr [ecx + 4], eax
// 00432e6a  895008               mov dword ptr [eax + 8], edx
// 00432e6d  894204               mov dword ptr [edx + 4], eax
// 00432e70  c20400               ret 4
// 00432e73  8b4a04               mov ecx, dword ptr [edx + 4]
// 00432e76  3b5108               cmp edx, dword ptr [ecx + 8]
// 00432e79  750c                 jne 0x432e87
// 00432e7b  894108               mov dword ptr [ecx + 8], eax
// 00432e7e  895008               mov dword ptr [eax + 8], edx
// 00432e81  894204               mov dword ptr [edx + 4], eax
// 00432e84  c20400               ret 4
// 00432e87  8901                 mov dword ptr [ecx], eax
// 00432e89  895008               mov dword ptr [eax + 8], edx
// 00432e8c  894204               mov dword ptr [edx + 4], eax
// 00432e8f  c20400               ret 4
// standard library set<double> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
