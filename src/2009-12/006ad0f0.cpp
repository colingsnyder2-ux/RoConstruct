// from server: 100% by auto
// roc 2009-12 006ad0f0  unit: RBX::Accoutrement  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad0f0
//
// 006ad0f0  56                   push esi
// 006ad0f1  8bf1                 mov esi, ecx
// 006ad0f3  833e00               cmp dword ptr [esi], 0
// 006ad0f6  57                   push edi
// 006ad0f7  8b3d60b79800         mov edi, dword ptr [0x98b760]
// 006ad0fd  7502                 jne 0x6ad101
// 006ad0ff  ffd7                 call edi
// 006ad101  8b4604               mov eax, dword ptr [esi + 4]
// 006ad104  80781500             cmp byte ptr [eax + 0x15], 0
// 006ad108  7405                 je 0x6ad10f
// 006ad10a  ffd7                 call edi
// 006ad10c  5f                   pop edi
// 006ad10d  5e                   pop esi
// 006ad10e  c3                   ret 
// 006ad10f  8b4808               mov ecx, dword ptr [eax + 8]
// 006ad112  80791500             cmp byte ptr [ecx + 0x15], 0
// 006ad116  7518                 jne 0x6ad130
// 006ad118  8b01                 mov eax, dword ptr [ecx]
// 006ad11a  80781500             cmp byte ptr [eax + 0x15], 0
// 006ad11e  750a                 jne 0x6ad12a
// 006ad120  8bc8                 mov ecx, eax
// 006ad122  8b01                 mov eax, dword ptr [ecx]
// 006ad124  80781500             cmp byte ptr [eax + 0x15], 0
// 006ad128  74f6                 je 0x6ad120
// 006ad12a  5f                   pop edi
// 006ad12b  894e04               mov dword ptr [esi + 4], ecx
// 006ad12e  5e                   pop esi
// 006ad12f  c3                   ret 
// 006ad130  8b4004               mov eax, dword ptr [eax + 4]
// 006ad133  80781500             cmp byte ptr [eax + 0x15], 0
// 006ad137  751d                 jne 0x6ad156
// 006ad139  8da42400000000       lea esp, [esp]
// 006ad140  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ad143  3b4808               cmp ecx, dword ptr [eax + 8]
// 006ad146  750e                 jne 0x6ad156
// 006ad148  894604               mov dword ptr [esi + 4], eax
// 006ad14b  8bd0                 mov edx, eax
// 006ad14d  8b4204               mov eax, dword ptr [edx + 4]
// 006ad150  80781500             cmp byte ptr [eax + 0x15], 0
// 006ad154  74ea                 je 0x6ad140
// 006ad156  5f                   pop edi
// 006ad157  894604               mov dword ptr [esi + 4], eax
// 006ad15a  5e                   pop esi
// 006ad15b  c3                   ret 
// standard library set<pod8> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
