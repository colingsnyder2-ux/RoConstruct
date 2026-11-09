// from server: 100% by auto
// roc 2010-06 006016e0  unit: RBX::Workspace  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006016e0
//
// 006016e0  8b542404             mov edx, dword ptr [esp + 4]
// 006016e4  8b02                 mov eax, dword ptr [edx]
// 006016e6  56                   push esi
// 006016e7  8b7008               mov esi, dword ptr [eax + 8]
// 006016ea  8932                 mov dword ptr [edx], esi
// 006016ec  8b7008               mov esi, dword ptr [eax + 8]
// 006016ef  807e1100             cmp byte ptr [esi + 0x11], 0
// 006016f3  7503                 jne 0x6016f8
// 006016f5  895604               mov dword ptr [esi + 4], edx
// 006016f8  8b7204               mov esi, dword ptr [edx + 4]
// 006016fb  897004               mov dword ptr [eax + 4], esi
// 006016fe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00601701  5e                   pop esi
// 00601702  3b5104               cmp edx, dword ptr [ecx + 4]
// 00601705  750c                 jne 0x601713
// 00601707  894104               mov dword ptr [ecx + 4], eax
// 0060170a  895008               mov dword ptr [eax + 8], edx
// 0060170d  894204               mov dword ptr [edx + 4], eax
// 00601710  c20400               ret 4
// 00601713  8b4a04               mov ecx, dword ptr [edx + 4]
// 00601716  3b5108               cmp edx, dword ptr [ecx + 8]
// 00601719  750c                 jne 0x601727
// 0060171b  894108               mov dword ptr [ecx + 8], eax
// 0060171e  895008               mov dword ptr [eax + 8], edx
// 00601721  894204               mov dword ptr [edx + 4], eax
// 00601724  c20400               ret 4
// 00601727  8901                 mov dword ptr [ecx], eax
// 00601729  895008               mov dword ptr [eax + 8], edx
// 0060172c  894204               mov dword ptr [edx + 4], eax
// 0060172f  c20400               ret 4
// standard library set<ptr> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
