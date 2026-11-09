// from server: 100% by auto
// roc 2008-06 0055ca20  unit: RBX::MD5HasherImpl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055ca20
//
// 0055ca20  56                   push esi
// 0055ca21  8bf1                 mov esi, ecx
// 0055ca23  833e00               cmp dword ptr [esi], 0
// 0055ca26  57                   push edi
// 0055ca27  8b3d90288000         mov edi, dword ptr [0x802890]
// 0055ca2d  7502                 jne 0x55ca31
// 0055ca2f  ffd7                 call edi
// 0055ca31  8b4604               mov eax, dword ptr [esi + 4]
// 0055ca34  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055ca38  7405                 je 0x55ca3f
// 0055ca3a  ffd7                 call edi
// 0055ca3c  5f                   pop edi
// 0055ca3d  5e                   pop esi
// 0055ca3e  c3                   ret 
// 0055ca3f  8b4808               mov ecx, dword ptr [eax + 8]
// 0055ca42  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 0055ca46  7518                 jne 0x55ca60
// 0055ca48  8b01                 mov eax, dword ptr [ecx]
// 0055ca4a  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055ca4e  750a                 jne 0x55ca5a
// 0055ca50  8bc8                 mov ecx, eax
// 0055ca52  8b01                 mov eax, dword ptr [ecx]
// 0055ca54  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055ca58  74f6                 je 0x55ca50
// 0055ca5a  5f                   pop edi
// 0055ca5b  894e04               mov dword ptr [esi + 4], ecx
// 0055ca5e  5e                   pop esi
// 0055ca5f  c3                   ret 
// 0055ca60  8b4004               mov eax, dword ptr [eax + 4]
// 0055ca63  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055ca67  751d                 jne 0x55ca86
// 0055ca69  8da42400000000       lea esp, [esp]
// 0055ca70  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055ca73  3b4808               cmp ecx, dword ptr [eax + 8]
// 0055ca76  750e                 jne 0x55ca86
// 0055ca78  894604               mov dword ptr [esi + 4], eax
// 0055ca7b  8bd0                 mov edx, eax
// 0055ca7d  8b4204               mov eax, dword ptr [edx + 4]
// 0055ca80  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0055ca84  74ea                 je 0x55ca70
// 0055ca86  5f                   pop edi
// 0055ca87  894604               mov dword ptr [esi + 4], eax
// 0055ca8a  5e                   pop esi
// 0055ca8b  c3                   ret 
// standard library set<pod48> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
