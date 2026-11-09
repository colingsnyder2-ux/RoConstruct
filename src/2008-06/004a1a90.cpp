// from server: 100% by auto
// roc 2008-06 004a1a90  unit: RBX::Network::Server::ClientProxy  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a1a90
//
// 004a1a90  8b542404             mov edx, dword ptr [esp + 4]
// 004a1a94  8b02                 mov eax, dword ptr [edx]
// 004a1a96  56                   push esi
// 004a1a97  8b7008               mov esi, dword ptr [eax + 8]
// 004a1a9a  8932                 mov dword ptr [edx], esi
// 004a1a9c  8b7008               mov esi, dword ptr [eax + 8]
// 004a1a9f  807e2900             cmp byte ptr [esi + 0x29], 0
// 004a1aa3  7503                 jne 0x4a1aa8
// 004a1aa5  895604               mov dword ptr [esi + 4], edx
// 004a1aa8  8b7204               mov esi, dword ptr [edx + 4]
// 004a1aab  897004               mov dword ptr [eax + 4], esi
// 004a1aae  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004a1ab1  5e                   pop esi
// 004a1ab2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004a1ab5  750c                 jne 0x4a1ac3
// 004a1ab7  894104               mov dword ptr [ecx + 4], eax
// 004a1aba  895008               mov dword ptr [eax + 8], edx
// 004a1abd  894204               mov dword ptr [edx + 4], eax
// 004a1ac0  c20400               ret 4
// 004a1ac3  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a1ac6  3b5108               cmp edx, dword ptr [ecx + 8]
// 004a1ac9  750c                 jne 0x4a1ad7
// 004a1acb  894108               mov dword ptr [ecx + 8], eax
// 004a1ace  895008               mov dword ptr [eax + 8], edx
// 004a1ad1  894204               mov dword ptr [edx + 4], eax
// 004a1ad4  c20400               ret 4
// 004a1ad7  8901                 mov dword ptr [ecx], eax
// 004a1ad9  895008               mov dword ptr [eax + 8], edx
// 004a1adc  894204               mov dword ptr [edx + 4], eax
// 004a1adf  c20400               ret 4
// standard library set<string> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
