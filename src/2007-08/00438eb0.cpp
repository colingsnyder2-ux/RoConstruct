// from server: 100% by auto
// roc 2007-08 00438eb0  unit: CXTPPropertyGridItem  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00438eb0
//
// 00438eb0  56                   push esi
// 00438eb1  8bf1                 mov esi, ecx
// 00438eb3  833e00               cmp dword ptr [esi], 0
// 00438eb6  57                   push edi
// 00438eb7  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 00438ebd  7502                 jne 0x438ec1
// 00438ebf  ffd7                 call edi
// 00438ec1  8b4604               mov eax, dword ptr [esi + 4]
// 00438ec4  80781500             cmp byte ptr [eax + 0x15], 0
// 00438ec8  7405                 je 0x438ecf
// 00438eca  ffd7                 call edi
// 00438ecc  5f                   pop edi
// 00438ecd  5e                   pop esi
// 00438ece  c3                   ret 
// 00438ecf  8b4808               mov ecx, dword ptr [eax + 8]
// 00438ed2  80791500             cmp byte ptr [ecx + 0x15], 0
// 00438ed6  7518                 jne 0x438ef0
// 00438ed8  8b01                 mov eax, dword ptr [ecx]
// 00438eda  80781500             cmp byte ptr [eax + 0x15], 0
// 00438ede  750a                 jne 0x438eea
// 00438ee0  8bc8                 mov ecx, eax
// 00438ee2  8b01                 mov eax, dword ptr [ecx]
// 00438ee4  80781500             cmp byte ptr [eax + 0x15], 0
// 00438ee8  74f6                 je 0x438ee0
// 00438eea  5f                   pop edi
// 00438eeb  894e04               mov dword ptr [esi + 4], ecx
// 00438eee  5e                   pop esi
// 00438eef  c3                   ret 
// 00438ef0  8b4004               mov eax, dword ptr [eax + 4]
// 00438ef3  80781500             cmp byte ptr [eax + 0x15], 0
// 00438ef7  751d                 jne 0x438f16
// 00438ef9  8da42400000000       lea esp, [esp]
// 00438f00  8b4e04               mov ecx, dword ptr [esi + 4]
// 00438f03  3b4808               cmp ecx, dword ptr [eax + 8]
// 00438f06  750e                 jne 0x438f16
// 00438f08  894604               mov dword ptr [esi + 4], eax
// 00438f0b  8bd0                 mov edx, eax
// 00438f0d  8b4204               mov eax, dword ptr [edx + 4]
// 00438f10  80781500             cmp byte ptr [eax + 0x15], 0
// 00438f14  74ea                 je 0x438f00
// 00438f16  5f                   pop edi
// 00438f17  894604               mov dword ptr [esi + 4], eax
// 00438f1a  5e                   pop esi
// 00438f1b  c3                   ret 
// standard library set<pod8> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
