// from server: 100% by auto
// roc 2009-12 006b3aa0  unit: RBX::DropperTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b3aa0
//
// 006b3aa0  56                   push esi
// 006b3aa1  8bf1                 mov esi, ecx
// 006b3aa3  833e00               cmp dword ptr [esi], 0
// 006b3aa6  57                   push edi
// 006b3aa7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 006b3aad  7502                 jne 0x6b3ab1
// 006b3aaf  ffd7                 call edi
// 006b3ab1  8b4604               mov eax, dword ptr [esi + 4]
// 006b3ab4  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3ab8  7405                 je 0x6b3abf
// 006b3aba  ffd7                 call edi
// 006b3abc  5f                   pop edi
// 006b3abd  5e                   pop esi
// 006b3abe  c3                   ret 
// 006b3abf  8b4808               mov ecx, dword ptr [eax + 8]
// 006b3ac2  80793500             cmp byte ptr [ecx + 0x35], 0
// 006b3ac6  7518                 jne 0x6b3ae0
// 006b3ac8  8b01                 mov eax, dword ptr [ecx]
// 006b3aca  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3ace  750a                 jne 0x6b3ada
// 006b3ad0  8bc8                 mov ecx, eax
// 006b3ad2  8b01                 mov eax, dword ptr [ecx]
// 006b3ad4  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3ad8  74f6                 je 0x6b3ad0
// 006b3ada  5f                   pop edi
// 006b3adb  894e04               mov dword ptr [esi + 4], ecx
// 006b3ade  5e                   pop esi
// 006b3adf  c3                   ret 
// 006b3ae0  8b4004               mov eax, dword ptr [eax + 4]
// 006b3ae3  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3ae7  751d                 jne 0x6b3b06
// 006b3ae9  8da42400000000       lea esp, [esp]
// 006b3af0  8b4e04               mov ecx, dword ptr [esi + 4]
// 006b3af3  3b4808               cmp ecx, dword ptr [eax + 8]
// 006b3af6  750e                 jne 0x6b3b06
// 006b3af8  894604               mov dword ptr [esi + 4], eax
// 006b3afb  8bd0                 mov edx, eax
// 006b3afd  8b4204               mov eax, dword ptr [edx + 4]
// 006b3b00  80783500             cmp byte ptr [eax + 0x35], 0
// 006b3b04  74ea                 je 0x6b3af0
// 006b3b06  5f                   pop edi
// 006b3b07  894604               mov dword ptr [esi + 4], eax
// 006b3b0a  5e                   pop esi
// 006b3b0b  c3                   ret 
// standard library set<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
