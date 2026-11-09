// from server: 100% by auto
// roc 2010-06 0061b100  unit: RBX::Accoutrement  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b100
//
// 0061b100  56                   push esi
// 0061b101  8bf1                 mov esi, ecx
// 0061b103  833e00               cmp dword ptr [esi], 0
// 0061b106  57                   push edi
// 0061b107  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0061b10d  7502                 jne 0x61b111
// 0061b10f  ffd7                 call edi
// 0061b111  8b4604               mov eax, dword ptr [esi + 4]
// 0061b114  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b118  7405                 je 0x61b11f
// 0061b11a  ffd7                 call edi
// 0061b11c  5f                   pop edi
// 0061b11d  5e                   pop esi
// 0061b11e  c3                   ret 
// 0061b11f  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b122  80792100             cmp byte ptr [ecx + 0x21], 0
// 0061b126  7518                 jne 0x61b140
// 0061b128  8b01                 mov eax, dword ptr [ecx]
// 0061b12a  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b12e  750a                 jne 0x61b13a
// 0061b130  8bc8                 mov ecx, eax
// 0061b132  8b01                 mov eax, dword ptr [ecx]
// 0061b134  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b138  74f6                 je 0x61b130
// 0061b13a  5f                   pop edi
// 0061b13b  894e04               mov dword ptr [esi + 4], ecx
// 0061b13e  5e                   pop esi
// 0061b13f  c3                   ret 
// 0061b140  8b4004               mov eax, dword ptr [eax + 4]
// 0061b143  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b147  751d                 jne 0x61b166
// 0061b149  8da42400000000       lea esp, [esp]
// 0061b150  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b153  3b4808               cmp ecx, dword ptr [eax + 8]
// 0061b156  750e                 jne 0x61b166
// 0061b158  894604               mov dword ptr [esi + 4], eax
// 0061b15b  8bd0                 mov edx, eax
// 0061b15d  8b4204               mov eax, dword ptr [edx + 4]
// 0061b160  80782100             cmp byte ptr [eax + 0x21], 0
// 0061b164  74ea                 je 0x61b150
// 0061b166  5f                   pop edi
// 0061b167  894604               mov dword ptr [esi + 4], eax
// 0061b16a  5e                   pop esi
// 0061b16b  c3                   ret 
// standard library set<pod20> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
