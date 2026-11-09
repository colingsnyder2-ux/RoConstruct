// from server: 100% by auto
// roc 2009-12 007b7140  unit: RBX::CleanStage  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b7140
//
// 007b7140  8b542404             mov edx, dword ptr [esp + 4]
// 007b7144  8b4208               mov eax, dword ptr [edx + 8]
// 007b7147  56                   push esi
// 007b7148  8b30                 mov esi, dword ptr [eax]
// 007b714a  897208               mov dword ptr [edx + 8], esi
// 007b714d  8b30                 mov esi, dword ptr [eax]
// 007b714f  807e1100             cmp byte ptr [esi + 0x11], 0
// 007b7153  7503                 jne 0x7b7158
// 007b7155  895604               mov dword ptr [esi + 4], edx
// 007b7158  8b7204               mov esi, dword ptr [edx + 4]
// 007b715b  897004               mov dword ptr [eax + 4], esi
// 007b715e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 007b7161  5e                   pop esi
// 007b7162  3b5104               cmp edx, dword ptr [ecx + 4]
// 007b7165  750b                 jne 0x7b7172
// 007b7167  894104               mov dword ptr [ecx + 4], eax
// 007b716a  8910                 mov dword ptr [eax], edx
// 007b716c  894204               mov dword ptr [edx + 4], eax
// 007b716f  c20400               ret 4
// 007b7172  8b4a04               mov ecx, dword ptr [edx + 4]
// 007b7175  3b11                 cmp edx, dword ptr [ecx]
// 007b7177  750a                 jne 0x7b7183
// 007b7179  8901                 mov dword ptr [ecx], eax
// 007b717b  8910                 mov dword ptr [eax], edx
// 007b717d  894204               mov dword ptr [edx + 4], eax
// 007b7180  c20400               ret 4
// 007b7183  894108               mov dword ptr [ecx + 8], eax
// 007b7186  8910                 mov dword ptr [eax], edx
// 007b7188  894204               mov dword ptr [edx + 4], eax
// 007b718b  c20400               ret 4
// standard library set<ptr> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
