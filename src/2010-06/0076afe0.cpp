// from server: 100% by auto
// roc 2010-06 0076afe0  unit: RBX::ImageButton  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076afe0
//
// 0076afe0  56                   push esi
// 0076afe1  8bf1                 mov esi, ecx
// 0076afe3  833e00               cmp dword ptr [esi], 0
// 0076afe6  57                   push edi
// 0076afe7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0076afed  7502                 jne 0x76aff1
// 0076afef  ffd7                 call edi
// 0076aff1  8b4604               mov eax, dword ptr [esi + 4]
// 0076aff4  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076aff8  7405                 je 0x76afff
// 0076affa  ffd7                 call edi
// 0076affc  5f                   pop edi
// 0076affd  5e                   pop esi
// 0076affe  c3                   ret 
// 0076afff  8b4808               mov ecx, dword ptr [eax + 8]
// 0076b002  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076b006  7518                 jne 0x76b020
// 0076b008  8b01                 mov eax, dword ptr [ecx]
// 0076b00a  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b00e  750a                 jne 0x76b01a
// 0076b010  8bc8                 mov ecx, eax
// 0076b012  8b01                 mov eax, dword ptr [ecx]
// 0076b014  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b018  74f6                 je 0x76b010
// 0076b01a  5f                   pop edi
// 0076b01b  894e04               mov dword ptr [esi + 4], ecx
// 0076b01e  5e                   pop esi
// 0076b01f  c3                   ret 
// 0076b020  8b4004               mov eax, dword ptr [eax + 4]
// 0076b023  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b027  751d                 jne 0x76b046
// 0076b029  8da42400000000       lea esp, [esp]
// 0076b030  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076b033  3b4808               cmp ecx, dword ptr [eax + 8]
// 0076b036  750e                 jne 0x76b046
// 0076b038  894604               mov dword ptr [esi + 4], eax
// 0076b03b  8bd0                 mov edx, eax
// 0076b03d  8b4204               mov eax, dword ptr [edx + 4]
// 0076b040  80784d00             cmp byte ptr [eax + 0x4d], 0
// 0076b044  74ea                 je 0x76b030
// 0076b046  5f                   pop edi
// 0076b047  894604               mov dword ptr [esi + 4], eax
// 0076b04a  5e                   pop esi
// 0076b04b  c3                   ret 
// standard library set<pod64> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
