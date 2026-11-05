// from server: 100% by auto
// roc 2009-06 005169f0  unit: RBX::MeshRefPartAdapter  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005169f0
//
// 005169f0  8b542404             mov edx, dword ptr [esp + 4]
// 005169f4  8b02                 mov eax, dword ptr [edx]
// 005169f6  56                   push esi
// 005169f7  8b7008               mov esi, dword ptr [eax + 8]
// 005169fa  8932                 mov dword ptr [edx], esi
// 005169fc  8b7008               mov esi, dword ptr [eax + 8]
// 005169ff  807e2900             cmp byte ptr [esi + 0x29], 0
// 00516a03  7503                 jne 0x516a08
// 00516a05  895604               mov dword ptr [esi + 4], edx
// 00516a08  8b7204               mov esi, dword ptr [edx + 4]
// 00516a0b  897004               mov dword ptr [eax + 4], esi
// 00516a0e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00516a11  5e                   pop esi
// 00516a12  3b5104               cmp edx, dword ptr [ecx + 4]
// 00516a15  750c                 jne 0x516a23
// 00516a17  894104               mov dword ptr [ecx + 4], eax
// 00516a1a  895008               mov dword ptr [eax + 8], edx
// 00516a1d  894204               mov dword ptr [edx + 4], eax
// 00516a20  c20400               ret 4
// 00516a23  8b4a04               mov ecx, dword ptr [edx + 4]
// 00516a26  3b5108               cmp edx, dword ptr [ecx + 8]
// 00516a29  750c                 jne 0x516a37
// 00516a2b  894108               mov dword ptr [ecx + 8], eax
// 00516a2e  895008               mov dword ptr [eax + 8], edx
// 00516a31  894204               mov dword ptr [edx + 4], eax
// 00516a34  c20400               ret 4
// 00516a37  8901                 mov dword ptr [ecx], eax
// 00516a39  895008               mov dword ptr [eax + 8], edx
// 00516a3c  894204               mov dword ptr [edx + 4], eax
// 00516a3f  c20400               ret 4
// standard library set<string> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
