// from server: 100% by auto
// roc 2007-08 00486b00  unit: G3D::GWindow  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00486b00
//
// 00486b00  56                   push esi
// 00486b01  8bf1                 mov esi, ecx
// 00486b03  833e00               cmp dword ptr [esi], 0
// 00486b06  57                   push edi
// 00486b07  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 00486b0d  7502                 jne 0x486b11
// 00486b0f  ffd7                 call edi
// 00486b11  8b4604               mov eax, dword ptr [esi + 4]
// 00486b14  80780e00             cmp byte ptr [eax + 0xe], 0
// 00486b18  7405                 je 0x486b1f
// 00486b1a  ffd7                 call edi
// 00486b1c  5f                   pop edi
// 00486b1d  5e                   pop esi
// 00486b1e  c3                   ret 
// 00486b1f  8b4808               mov ecx, dword ptr [eax + 8]
// 00486b22  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00486b26  7518                 jne 0x486b40
// 00486b28  8b01                 mov eax, dword ptr [ecx]
// 00486b2a  80780e00             cmp byte ptr [eax + 0xe], 0
// 00486b2e  750a                 jne 0x486b3a
// 00486b30  8bc8                 mov ecx, eax
// 00486b32  8b01                 mov eax, dword ptr [ecx]
// 00486b34  80780e00             cmp byte ptr [eax + 0xe], 0
// 00486b38  74f6                 je 0x486b30
// 00486b3a  5f                   pop edi
// 00486b3b  894e04               mov dword ptr [esi + 4], ecx
// 00486b3e  5e                   pop esi
// 00486b3f  c3                   ret 
// 00486b40  8b4004               mov eax, dword ptr [eax + 4]
// 00486b43  80780e00             cmp byte ptr [eax + 0xe], 0
// 00486b47  751d                 jne 0x486b66
// 00486b49  8da42400000000       lea esp, [esp]
// 00486b50  8b4e04               mov ecx, dword ptr [esi + 4]
// 00486b53  3b4808               cmp ecx, dword ptr [eax + 8]
// 00486b56  750e                 jne 0x486b66
// 00486b58  894604               mov dword ptr [esi + 4], eax
// 00486b5b  8bd0                 mov edx, eax
// 00486b5d  8b4204               mov eax, dword ptr [edx + 4]
// 00486b60  80780e00             cmp byte ptr [eax + 0xe], 0
// 00486b64  74ea                 je 0x486b50
// 00486b66  5f                   pop edi
// 00486b67  894604               mov dword ptr [esi + 4], eax
// 00486b6a  5e                   pop esi
// 00486b6b  c3                   ret 
// standard library set<char> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
