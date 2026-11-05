// from server: 100% by auto
// roc 2010-06 006f3cf0  unit: RBX::VStudioTool::?$EventDesc  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f3cf0
//
// 006f3cf0  56                   push esi
// 006f3cf1  8bf1                 mov esi, ecx
// 006f3cf3  833e00               cmp dword ptr [esi], 0
// 006f3cf6  57                   push edi
// 006f3cf7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 006f3cfd  7502                 jne 0x6f3d01
// 006f3cff  ffd7                 call edi
// 006f3d01  8b4604               mov eax, dword ptr [esi + 4]
// 006f3d04  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f3d08  7405                 je 0x6f3d0f
// 006f3d0a  ffd7                 call edi
// 006f3d0c  5f                   pop edi
// 006f3d0d  5e                   pop esi
// 006f3d0e  c3                   ret 
// 006f3d0f  8b4808               mov ecx, dword ptr [eax + 8]
// 006f3d12  80790e00             cmp byte ptr [ecx + 0xe], 0
// 006f3d16  7518                 jne 0x6f3d30
// 006f3d18  8b01                 mov eax, dword ptr [ecx]
// 006f3d1a  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f3d1e  750a                 jne 0x6f3d2a
// 006f3d20  8bc8                 mov ecx, eax
// 006f3d22  8b01                 mov eax, dword ptr [ecx]
// 006f3d24  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f3d28  74f6                 je 0x6f3d20
// 006f3d2a  5f                   pop edi
// 006f3d2b  894e04               mov dword ptr [esi + 4], ecx
// 006f3d2e  5e                   pop esi
// 006f3d2f  c3                   ret 
// 006f3d30  8b4004               mov eax, dword ptr [eax + 4]
// 006f3d33  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f3d37  751d                 jne 0x6f3d56
// 006f3d39  8da42400000000       lea esp, [esp]
// 006f3d40  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f3d43  3b4808               cmp ecx, dword ptr [eax + 8]
// 006f3d46  750e                 jne 0x6f3d56
// 006f3d48  894604               mov dword ptr [esi + 4], eax
// 006f3d4b  8bd0                 mov edx, eax
// 006f3d4d  8b4204               mov eax, dword ptr [edx + 4]
// 006f3d50  80780e00             cmp byte ptr [eax + 0xe], 0
// 006f3d54  74ea                 je 0x6f3d40
// 006f3d56  5f                   pop edi
// 006f3d57  894604               mov dword ptr [esi + 4], eax
// 006f3d5a  5e                   pop esi
// 006f3d5b  c3                   ret 
// standard library set<char> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAEXXZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
