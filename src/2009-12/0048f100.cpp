// from server: 100% by auto
// roc 2009-12 0048f100  unit: RBX::RbxTextureProxy  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f100
//
// 0048f100  56                   push esi
// 0048f101  8bf1                 mov esi, ecx
// 0048f103  833e00               cmp dword ptr [esi], 0
// 0048f106  57                   push edi
// 0048f107  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 0048f10d  7502                 jne 0x48f111
// 0048f10f  ffd7                 call edi
// 0048f111  8b4604               mov eax, dword ptr [esi + 4]
// 0048f114  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f118  7405                 je 0x48f11f
// 0048f11a  ffd7                 call edi
// 0048f11c  5f                   pop edi
// 0048f11d  5e                   pop esi
// 0048f11e  c3                   ret 
// 0048f11f  8b4808               mov ecx, dword ptr [eax + 8]
// 0048f122  80792100             cmp byte ptr [ecx + 0x21], 0
// 0048f126  7518                 jne 0x48f140
// 0048f128  8b01                 mov eax, dword ptr [ecx]
// 0048f12a  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f12e  750a                 jne 0x48f13a
// 0048f130  8bc8                 mov ecx, eax
// 0048f132  8b01                 mov eax, dword ptr [ecx]
// 0048f134  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f138  74f6                 je 0x48f130
// 0048f13a  5f                   pop edi
// 0048f13b  894e04               mov dword ptr [esi + 4], ecx
// 0048f13e  5e                   pop esi
// 0048f13f  c3                   ret 
// 0048f140  8b4004               mov eax, dword ptr [eax + 4]
// 0048f143  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f147  751d                 jne 0x48f166
// 0048f149  8da42400000000       lea esp, [esp]
// 0048f150  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048f153  3b4808               cmp ecx, dword ptr [eax + 8]
// 0048f156  750e                 jne 0x48f166
// 0048f158  894604               mov dword ptr [esi + 4], eax
// 0048f15b  8bd0                 mov edx, eax
// 0048f15d  8b4204               mov eax, dword ptr [edx + 4]
// 0048f160  80782100             cmp byte ptr [eax + 0x21], 0
// 0048f164  74ea                 je 0x48f150
// 0048f166  5f                   pop edi
// 0048f167  894604               mov dword ptr [esi + 4], eax
// 0048f16a  5e                   pop esi
// 0048f16b  c3                   ret 
// standard library set<pod20> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
