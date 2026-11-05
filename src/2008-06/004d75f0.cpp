// from server: 100% by auto
// roc 2008-06 004d75f0  unit: Ogre::VDataStream::?$SharedPtr  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d75f0
//
// 004d75f0  8b542404             mov edx, dword ptr [esp + 4]
// 004d75f4  8b4208               mov eax, dword ptr [edx + 8]
// 004d75f7  56                   push esi
// 004d75f8  8b30                 mov esi, dword ptr [eax]
// 004d75fa  897208               mov dword ptr [edx + 8], esi
// 004d75fd  8b30                 mov esi, dword ptr [eax]
// 004d75ff  807e2100             cmp byte ptr [esi + 0x21], 0
// 004d7603  7503                 jne 0x4d7608
// 004d7605  895604               mov dword ptr [esi + 4], edx
// 004d7608  8b7204               mov esi, dword ptr [edx + 4]
// 004d760b  897004               mov dword ptr [eax + 4], esi
// 004d760e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 004d7611  5e                   pop esi
// 004d7612  3b5104               cmp edx, dword ptr [ecx + 4]
// 004d7615  750b                 jne 0x4d7622
// 004d7617  894104               mov dword ptr [ecx + 4], eax
// 004d761a  8910                 mov dword ptr [eax], edx
// 004d761c  894204               mov dword ptr [edx + 4], eax
// 004d761f  c20400               ret 4
// 004d7622  8b4a04               mov ecx, dword ptr [edx + 4]
// 004d7625  3b11                 cmp edx, dword ptr [ecx]
// 004d7627  750a                 jne 0x4d7633
// 004d7629  8901                 mov dword ptr [ecx], eax
// 004d762b  8910                 mov dword ptr [eax], edx
// 004d762d  894204               mov dword ptr [edx + 4], eax
// 004d7630  c20400               ret 4
// 004d7633  894108               mov dword ptr [ecx + 8], eax
// 004d7636  8910                 mov dword ptr [eax], edx
// 004d7638  894204               mov dword ptr [edx + 4], eax
// 004d763b  c20400               ret 4
// standard library set<pod20> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
