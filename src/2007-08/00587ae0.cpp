// from server: 100% by auto
// roc 2007-08 00587ae0  unit: RBX::Reflection::EnumDescriptor  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587ae0
//
// 00587ae0  56                   push esi
// 00587ae1  8bf1                 mov esi, ecx
// 00587ae3  833e00               cmp dword ptr [esi], 0
// 00587ae6  57                   push edi
// 00587ae7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 00587aed  7502                 jne 0x587af1
// 00587aef  ffd7                 call edi
// 00587af1  8b4604               mov eax, dword ptr [esi + 4]
// 00587af4  80783500             cmp byte ptr [eax + 0x35], 0
// 00587af8  7405                 je 0x587aff
// 00587afa  ffd7                 call edi
// 00587afc  5f                   pop edi
// 00587afd  5e                   pop esi
// 00587afe  c3                   ret 
// 00587aff  8b4808               mov ecx, dword ptr [eax + 8]
// 00587b02  80793500             cmp byte ptr [ecx + 0x35], 0
// 00587b06  7518                 jne 0x587b20
// 00587b08  8b01                 mov eax, dword ptr [ecx]
// 00587b0a  80783500             cmp byte ptr [eax + 0x35], 0
// 00587b0e  750a                 jne 0x587b1a
// 00587b10  8bc8                 mov ecx, eax
// 00587b12  8b01                 mov eax, dword ptr [ecx]
// 00587b14  80783500             cmp byte ptr [eax + 0x35], 0
// 00587b18  74f6                 je 0x587b10
// 00587b1a  5f                   pop edi
// 00587b1b  894e04               mov dword ptr [esi + 4], ecx
// 00587b1e  5e                   pop esi
// 00587b1f  c3                   ret 
// 00587b20  8b4004               mov eax, dword ptr [eax + 4]
// 00587b23  80783500             cmp byte ptr [eax + 0x35], 0
// 00587b27  751d                 jne 0x587b46
// 00587b29  8da42400000000       lea esp, [esp]
// 00587b30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00587b33  3b4808               cmp ecx, dword ptr [eax + 8]
// 00587b36  750e                 jne 0x587b46
// 00587b38  894604               mov dword ptr [esi + 4], eax
// 00587b3b  8bd0                 mov edx, eax
// 00587b3d  8b4204               mov eax, dword ptr [edx + 4]
// 00587b40  80783500             cmp byte ptr [eax + 0x35], 0
// 00587b44  74ea                 je 0x587b30
// 00587b46  5f                   pop edi
// 00587b47  894604               mov dword ptr [esi + 4], eax
// 00587b4a  5e                   pop esi
// 00587b4b  c3                   ret 
// standard library set<pod40> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
