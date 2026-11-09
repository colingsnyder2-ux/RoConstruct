// from server: 100% by auto
// roc 2008-06 00438690  unit: RBX::Soundscape::VSoundId::?$XItem  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438690
//
// 00438690  8b542404             mov edx, dword ptr [esp + 4]
// 00438694  8b4208               mov eax, dword ptr [edx + 8]
// 00438697  56                   push esi
// 00438698  8b30                 mov esi, dword ptr [eax]
// 0043869a  897208               mov dword ptr [edx + 8], esi
// 0043869d  8b30                 mov esi, dword ptr [eax]
// 0043869f  807e1100             cmp byte ptr [esi + 0x11], 0
// 004386a3  7503                 jne 0x4386a8
// 004386a5  895604               mov dword ptr [esi + 4], edx
// 004386a8  8b7204               mov esi, dword ptr [edx + 4]
// 004386ab  897004               mov dword ptr [eax + 4], esi
// 004386ae  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004386b1  5e                   pop esi
// 004386b2  3b5104               cmp edx, dword ptr [ecx + 4]
// 004386b5  750b                 jne 0x4386c2
// 004386b7  894104               mov dword ptr [ecx + 4], eax
// 004386ba  8910                 mov dword ptr [eax], edx
// 004386bc  894204               mov dword ptr [edx + 4], eax
// 004386bf  c20400               ret 4
// 004386c2  8b4a04               mov ecx, dword ptr [edx + 4]
// 004386c5  3b11                 cmp edx, dword ptr [ecx]
// 004386c7  750a                 jne 0x4386d3
// 004386c9  8901                 mov dword ptr [ecx], eax
// 004386cb  8910                 mov dword ptr [eax], edx
// 004386cd  894204               mov dword ptr [edx + 4], eax
// 004386d0  c20400               ret 4
// 004386d3  894108               mov dword ptr [ecx + 8], eax
// 004386d6  8910                 mov dword ptr [eax], edx
// 004386d8  894204               mov dword ptr [edx + 4], eax
// 004386db  c20400               ret 4
// standard library set<ptr> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@2@@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
