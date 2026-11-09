// from server: 100% by auto
// roc 2008-06 0068d280  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d280
//
// 0068d280  8b442404             mov eax, dword ptr [esp + 4]
// 0068d284  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d287  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0068d28b  750e                 jne 0x68d29b
// 0068d28d  8d4900               lea ecx, [ecx]
// 0068d290  8bc1                 mov eax, ecx
// 0068d292  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d295  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0068d299  74f5                 je 0x68d290
// 0068d29b  c3                   ret 
// standard library set<char> (function ?_Max@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@PAU342@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
