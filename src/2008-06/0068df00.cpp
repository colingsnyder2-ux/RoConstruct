// from server: 100% by auto
// roc 2008-06 0068df00  unit: Ogre::VRbxSky::?$SharedPtr  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068df00
//
// 0068df00  8b542404             mov edx, dword ptr [esp + 4]
// 0068df04  8b4208               mov eax, dword ptr [edx + 8]
// 0068df07  56                   push esi
// 0068df08  8b30                 mov esi, dword ptr [eax]
// 0068df0a  897208               mov dword ptr [edx + 8], esi
// 0068df0d  8b30                 mov esi, dword ptr [eax]
// 0068df0f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0068df13  7503                 jne 0x68df18
// 0068df15  895604               mov dword ptr [esi + 4], edx
// 0068df18  8b7204               mov esi, dword ptr [edx + 4]
// 0068df1b  897004               mov dword ptr [eax + 4], esi
// 0068df1e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 0068df21  5e                   pop esi
// 0068df22  3b5104               cmp edx, dword ptr [ecx + 4]
// 0068df25  750b                 jne 0x68df32
// 0068df27  894104               mov dword ptr [ecx + 4], eax
// 0068df2a  8910                 mov dword ptr [eax], edx
// 0068df2c  894204               mov dword ptr [edx + 4], eax
// 0068df2f  c20400               ret 4
// 0068df32  8b4a04               mov ecx, dword ptr [edx + 4]
// 0068df35  3b11                 cmp edx, dword ptr [ecx]
// 0068df37  750a                 jne 0x68df43
// 0068df39  8901                 mov dword ptr [ecx], eax
// 0068df3b  8910                 mov dword ptr [eax], edx
// 0068df3d  894204               mov dword ptr [edx + 4], eax
// 0068df40  c20400               ret 4
// 0068df43  894108               mov dword ptr [ecx + 8], eax
// 0068df46  8910                 mov dword ptr [eax], edx
// 0068df48  894204               mov dword ptr [edx + 4], eax
// 0068df4b  c20400               ret 4
// standard library set<pod32> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
