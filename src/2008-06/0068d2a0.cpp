// from server: 100% by auto
// roc 2008-06 0068d2a0  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d2a0
//
// 0068d2a0  8b442404             mov eax, dword ptr [esp + 4]
// 0068d2a4  8b08                 mov ecx, dword ptr [eax]
// 0068d2a6  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0068d2aa  750e                 jne 0x68d2ba
// 0068d2ac  8d642400             lea esp, [esp]
// 0068d2b0  8bc1                 mov eax, ecx
// 0068d2b2  8b08                 mov ecx, dword ptr [eax]
// 0068d2b4  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0068d2b8  74f6                 je 0x68d2b0
// 0068d2ba  c3                   ret 
// standard library set<char> (function ?_Min@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
