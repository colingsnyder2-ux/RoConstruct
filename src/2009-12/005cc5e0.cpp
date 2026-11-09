// from server: 100% by auto
// roc 2009-12 005cc5e0  unit: RBX::MeshRefPartAdapter  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005cc5e0
//
// 005cc5e0  8b542404             mov edx, dword ptr [esp + 4]
// 005cc5e4  8b02                 mov eax, dword ptr [edx]
// 005cc5e6  56                   push esi
// 005cc5e7  8b7008               mov esi, dword ptr [eax + 8]
// 005cc5ea  8932                 mov dword ptr [edx], esi
// 005cc5ec  8b7008               mov esi, dword ptr [eax + 8]
// 005cc5ef  807e2900             cmp byte ptr [esi + 0x29], 0
// 005cc5f3  7503                 jne 0x5cc5f8
// 005cc5f5  895604               mov dword ptr [esi + 4], edx
// 005cc5f8  8b7204               mov esi, dword ptr [edx + 4]
// 005cc5fb  897004               mov dword ptr [eax + 4], esi
// 005cc5fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005cc601  5e                   pop esi
// 005cc602  3b5104               cmp edx, dword ptr [ecx + 4]
// 005cc605  750c                 jne 0x5cc613
// 005cc607  894104               mov dword ptr [ecx + 4], eax
// 005cc60a  895008               mov dword ptr [eax + 8], edx
// 005cc60d  894204               mov dword ptr [edx + 4], eax
// 005cc610  c20400               ret 4
// 005cc613  8b4a04               mov ecx, dword ptr [edx + 4]
// 005cc616  3b5108               cmp edx, dword ptr [ecx + 8]
// 005cc619  750c                 jne 0x5cc627
// 005cc61b  894108               mov dword ptr [ecx + 8], eax
// 005cc61e  895008               mov dword ptr [eax + 8], edx
// 005cc621  894204               mov dword ptr [edx + 4], eax
// 005cc624  c20400               ret 4
// 005cc627  8901                 mov dword ptr [ecx], eax
// 005cc629  895008               mov dword ptr [eax + 8], edx
// 005cc62c  894204               mov dword ptr [edx + 4], eax
// 005cc62f  c20400               ret 4
// standard library set<string> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
