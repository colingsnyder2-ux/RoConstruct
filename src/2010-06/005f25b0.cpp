// from server: 100% by auto
// roc 2010-06 005f25b0  unit: TextXmlParser  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f25b0
//
// 005f25b0  8b542404             mov edx, dword ptr [esp + 4]
// 005f25b4  8b02                 mov eax, dword ptr [edx]
// 005f25b6  56                   push esi
// 005f25b7  8b7008               mov esi, dword ptr [eax + 8]
// 005f25ba  8932                 mov dword ptr [edx], esi
// 005f25bc  8b7008               mov esi, dword ptr [eax + 8]
// 005f25bf  807e1900             cmp byte ptr [esi + 0x19], 0
// 005f25c3  7503                 jne 0x5f25c8
// 005f25c5  895604               mov dword ptr [esi + 4], edx
// 005f25c8  8b7204               mov esi, dword ptr [edx + 4]
// 005f25cb  897004               mov dword ptr [eax + 4], esi
// 005f25ce  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005f25d1  5e                   pop esi
// 005f25d2  3b5104               cmp edx, dword ptr [ecx + 4]
// 005f25d5  750c                 jne 0x5f25e3
// 005f25d7  894104               mov dword ptr [ecx + 4], eax
// 005f25da  895008               mov dword ptr [eax + 8], edx
// 005f25dd  894204               mov dword ptr [edx + 4], eax
// 005f25e0  c20400               ret 4
// 005f25e3  8b4a04               mov ecx, dword ptr [edx + 4]
// 005f25e6  3b5108               cmp edx, dword ptr [ecx + 8]
// 005f25e9  750c                 jne 0x5f25f7
// 005f25eb  894108               mov dword ptr [ecx + 8], eax
// 005f25ee  895008               mov dword ptr [eax + 8], edx
// 005f25f1  894204               mov dword ptr [edx + 4], eax
// 005f25f4  c20400               ret 4
// 005f25f7  8901                 mov dword ptr [ecx], eax
// 005f25f9  895008               mov dword ptr [eax + 8], edx
// 005f25fc  894204               mov dword ptr [edx + 4], eax
// 005f25ff  c20400               ret 4
// standard library set<double> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
