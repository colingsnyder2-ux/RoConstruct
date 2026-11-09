// from server: 100% by auto
// roc 2007-08 00487710  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00487710
//
// 00487710  8b542404             mov edx, dword ptr [esp + 4]
// 00487714  8b4208               mov eax, dword ptr [edx + 8]
// 00487717  56                   push esi
// 00487718  8b30                 mov esi, dword ptr [eax]
// 0048771a  897208               mov dword ptr [edx + 8], esi
// 0048771d  8b30                 mov esi, dword ptr [eax]
// 0048771f  807e0e00             cmp byte ptr [esi + 0xe], 0
// 00487723  7503                 jne 0x487728
// 00487725  895604               mov dword ptr [esi + 4], edx
// 00487728  8b7204               mov esi, dword ptr [edx + 4]
// 0048772b  897004               mov dword ptr [eax + 4], esi
// 0048772e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00487731  3b5104               cmp edx, dword ptr [ecx + 4]
// 00487734  5e                   pop esi
// 00487735  750b                 jne 0x487742
// 00487737  894104               mov dword ptr [ecx + 4], eax
// 0048773a  8910                 mov dword ptr [eax], edx
// 0048773c  894204               mov dword ptr [edx + 4], eax
// 0048773f  c20400               ret 4
// 00487742  8b4a04               mov ecx, dword ptr [edx + 4]
// 00487745  3b11                 cmp edx, dword ptr [ecx]
// 00487747  750a                 jne 0x487753
// 00487749  8901                 mov dword ptr [ecx], eax
// 0048774b  8910                 mov dword ptr [eax], edx
// 0048774d  894204               mov dword ptr [edx + 4], eax
// 00487750  c20400               ret 4
// 00487753  894108               mov dword ptr [ecx + 8], eax
// 00487756  8910                 mov dword ptr [eax], edx
// 00487758  894204               mov dword ptr [edx + 4], eax
// 0048775b  c20400               ret 4
// standard library set<char> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
