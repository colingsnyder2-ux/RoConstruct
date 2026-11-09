// from server: 100% by auto
// roc 2007-08 0040f490  unit: CutVerb  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040f490
//
// 0040f490  8b542404             mov edx, dword ptr [esp + 4]
// 0040f494  8b02                 mov eax, dword ptr [edx]
// 0040f496  56                   push esi
// 0040f497  8b7008               mov esi, dword ptr [eax + 8]
// 0040f49a  8932                 mov dword ptr [edx], esi
// 0040f49c  8b7008               mov esi, dword ptr [eax + 8]
// 0040f49f  807e1900             cmp byte ptr [esi + 0x19], 0
// 0040f4a3  7503                 jne 0x40f4a8
// 0040f4a5  895604               mov dword ptr [esi + 4], edx
// 0040f4a8  8b7204               mov esi, dword ptr [edx + 4]
// 0040f4ab  897004               mov dword ptr [eax + 4], esi
// 0040f4ae  8b4904               mov ecx, dword ptr [ecx + 4]
// 0040f4b1  3b5104               cmp edx, dword ptr [ecx + 4]
// 0040f4b4  5e                   pop esi
// 0040f4b5  750c                 jne 0x40f4c3
// 0040f4b7  894104               mov dword ptr [ecx + 4], eax
// 0040f4ba  895008               mov dword ptr [eax + 8], edx
// 0040f4bd  894204               mov dword ptr [edx + 4], eax
// 0040f4c0  c20400               ret 4
// 0040f4c3  8b4a04               mov ecx, dword ptr [edx + 4]
// 0040f4c6  3b5108               cmp edx, dword ptr [ecx + 8]
// 0040f4c9  750c                 jne 0x40f4d7
// 0040f4cb  894108               mov dword ptr [ecx + 8], eax
// 0040f4ce  895008               mov dword ptr [eax + 8], edx
// 0040f4d1  894204               mov dword ptr [edx + 4], eax
// 0040f4d4  c20400               ret 4
// 0040f4d7  8901                 mov dword ptr [ecx], eax
// 0040f4d9  895008               mov dword ptr [eax + 8], edx
// 0040f4dc  894204               mov dword ptr [edx + 4], eax
// 0040f4df  c20400               ret 4
// standard library set<double> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
