// from server: 100% by auto
// roc 2008-06 0068cfd0  unit: Ogre::RbxSceneManagerFactory  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068cfd0
//
// 0068cfd0  8b542404             mov edx, dword ptr [esp + 4]
// 0068cfd4  8b02                 mov eax, dword ptr [edx]
// 0068cfd6  56                   push esi
// 0068cfd7  8b7008               mov esi, dword ptr [eax + 8]
// 0068cfda  8932                 mov dword ptr [edx], esi
// 0068cfdc  8b7008               mov esi, dword ptr [eax + 8]
// 0068cfdf  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0068cfe3  7503                 jne 0x68cfe8
// 0068cfe5  895604               mov dword ptr [esi + 4], edx
// 0068cfe8  8b7204               mov esi, dword ptr [edx + 4]
// 0068cfeb  897004               mov dword ptr [eax + 4], esi
// 0068cfee  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0068cff1  5e                   pop esi
// 0068cff2  3b5104               cmp edx, dword ptr [ecx + 4]
// 0068cff5  750c                 jne 0x68d003
// 0068cff7  894104               mov dword ptr [ecx + 4], eax
// 0068cffa  895008               mov dword ptr [eax + 8], edx
// 0068cffd  894204               mov dword ptr [edx + 4], eax
// 0068d000  c20400               ret 4
// 0068d003  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068d006  3b5108               cmp edx, dword ptr [ecx + 8]
// 0068d009  750c                 jne 0x68d017
// 0068d00b  894108               mov dword ptr [ecx + 8], eax
// 0068d00e  895008               mov dword ptr [eax + 8], edx
// 0068d011  894204               mov dword ptr [edx + 4], eax
// 0068d014  c20400               ret 4
// 0068d017  8901                 mov dword ptr [ecx], eax
// 0068d019  895008               mov dword ptr [eax + 8], edx
// 0068d01c  894204               mov dword ptr [edx + 4], eax
// 0068d01f  c20400               ret 4
// standard library set<pod32> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
