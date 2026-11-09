// from server: 100% by auto
// roc 2009-06 005d9030  unit: VAuthoringSettings::?$BoundPropGetSet  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d9030
//
// 005d9030  56                   push esi
// 005d9031  8bf1                 mov esi, ecx
// 005d9033  833e00               cmp dword ptr [esi], 0
// 005d9036  57                   push edi
// 005d9037  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 005d903d  7502                 jne 0x5d9041
// 005d903f  ffd7                 call edi
// 005d9041  8b4604               mov eax, dword ptr [esi + 4]
// 005d9044  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d9048  7405                 je 0x5d904f
// 005d904a  ffd7                 call edi
// 005d904c  5f                   pop edi
// 005d904d  5e                   pop esi
// 005d904e  c3                   ret 
// 005d904f  8b4808               mov ecx, dword ptr [eax + 8]
// 005d9052  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005d9056  7518                 jne 0x5d9070
// 005d9058  8b01                 mov eax, dword ptr [ecx]
// 005d905a  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d905e  750a                 jne 0x5d906a
// 005d9060  8bc8                 mov ecx, eax
// 005d9062  8b01                 mov eax, dword ptr [ecx]
// 005d9064  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d9068  74f6                 je 0x5d9060
// 005d906a  5f                   pop edi
// 005d906b  894e04               mov dword ptr [esi + 4], ecx
// 005d906e  5e                   pop esi
// 005d906f  c3                   ret 
// 005d9070  8b4004               mov eax, dword ptr [eax + 4]
// 005d9073  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d9077  751d                 jne 0x5d9096
// 005d9079  8da42400000000       lea esp, [esp]
// 005d9080  8b4e04               mov ecx, dword ptr [esi + 4]
// 005d9083  3b4808               cmp ecx, dword ptr [eax + 8]
// 005d9086  750e                 jne 0x5d9096
// 005d9088  894604               mov dword ptr [esi + 4], eax
// 005d908b  8bd0                 mov edx, eax
// 005d908d  8b4204               mov eax, dword ptr [edx + 4]
// 005d9090  80783d00             cmp byte ptr [eax + 0x3d], 0
// 005d9094  74ea                 je 0x5d9080
// 005d9096  5f                   pop edi
// 005d9097  894604               mov dword ptr [esi + 4], eax
// 005d909a  5e                   pop esi
// 005d909b  c3                   ret 
// standard library set<pod48> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
