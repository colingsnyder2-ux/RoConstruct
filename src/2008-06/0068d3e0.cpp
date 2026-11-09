// from server: 100% by auto
// roc 2008-06 0068d3e0  unit: Ogre::VShadowCameraSetup::?$SharedPtr  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068d3e0
//
// 0068d3e0  56                   push esi
// 0068d3e1  8bf1                 mov esi, ecx
// 0068d3e3  833e00               cmp dword ptr [esi], 0
// 0068d3e6  57                   push edi
// 0068d3e7  8b3d90288000         mov edi, dword ptr [0x802890]
// 0068d3ed  7502                 jne 0x68d3f1
// 0068d3ef  ffd7                 call edi
// 0068d3f1  8b4604               mov eax, dword ptr [esi + 4]
// 0068d3f4  80780e00             cmp byte ptr [eax + 0xe], 0
// 0068d3f8  7405                 je 0x68d3ff
// 0068d3fa  ffd7                 call edi
// 0068d3fc  5f                   pop edi
// 0068d3fd  5e                   pop esi
// 0068d3fe  c3                   ret 
// 0068d3ff  8b4808               mov ecx, dword ptr [eax + 8]
// 0068d402  80790e00             cmp byte ptr [ecx + 0xe], 0
// 0068d406  7518                 jne 0x68d420
// 0068d408  8b01                 mov eax, dword ptr [ecx]
// 0068d40a  80780e00             cmp byte ptr [eax + 0xe], 0
// 0068d40e  750a                 jne 0x68d41a
// 0068d410  8bc8                 mov ecx, eax
// 0068d412  8b01                 mov eax, dword ptr [ecx]
// 0068d414  80780e00             cmp byte ptr [eax + 0xe], 0
// 0068d418  74f6                 je 0x68d410
// 0068d41a  5f                   pop edi
// 0068d41b  894e04               mov dword ptr [esi + 4], ecx
// 0068d41e  5e                   pop esi
// 0068d41f  c3                   ret 
// 0068d420  8b4004               mov eax, dword ptr [eax + 4]
// 0068d423  80780e00             cmp byte ptr [eax + 0xe], 0
// 0068d427  751d                 jne 0x68d446
// 0068d429  8da42400000000       lea esp, [esp]
// 0068d430  8b4e04               mov ecx, dword ptr [esi + 4]
// 0068d433  3b4808               cmp ecx, dword ptr [eax + 8]
// 0068d436  750e                 jne 0x68d446
// 0068d438  894604               mov dword ptr [esi + 4], eax
// 0068d43b  8bd0                 mov edx, eax
// 0068d43d  8b4204               mov eax, dword ptr [edx + 4]
// 0068d440  80780e00             cmp byte ptr [eax + 0xe], 0
// 0068d444  74ea                 je 0x68d430
// 0068d446  5f                   pop edi
// 0068d447  894604               mov dword ptr [esi + 4], eax
// 0068d44a  5e                   pop esi
// 0068d44b  c3                   ret 
// standard library set<char> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
