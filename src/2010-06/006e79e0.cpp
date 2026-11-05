// from server: 100% by auto
// roc 2010-06 006e79e0  unit: RBX::P8PVInstance::?$SetImpl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e79e0
//
// 006e79e0  56                   push esi
// 006e79e1  8bf1                 mov esi, ecx
// 006e79e3  833e00               cmp dword ptr [esi], 0
// 006e79e6  57                   push edi
// 006e79e7  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 006e79ed  7502                 jne 0x6e79f1
// 006e79ef  ffd7                 call edi
// 006e79f1  8b4604               mov eax, dword ptr [esi + 4]
// 006e79f4  80781500             cmp byte ptr [eax + 0x15], 0
// 006e79f8  7405                 je 0x6e79ff
// 006e79fa  ffd7                 call edi
// 006e79fc  5f                   pop edi
// 006e79fd  5e                   pop esi
// 006e79fe  c3                   ret 
// 006e79ff  8b4808               mov ecx, dword ptr [eax + 8]
// 006e7a02  80791500             cmp byte ptr [ecx + 0x15], 0
// 006e7a06  7518                 jne 0x6e7a20
// 006e7a08  8b01                 mov eax, dword ptr [ecx]
// 006e7a0a  80781500             cmp byte ptr [eax + 0x15], 0
// 006e7a0e  750a                 jne 0x6e7a1a
// 006e7a10  8bc8                 mov ecx, eax
// 006e7a12  8b01                 mov eax, dword ptr [ecx]
// 006e7a14  80781500             cmp byte ptr [eax + 0x15], 0
// 006e7a18  74f6                 je 0x6e7a10
// 006e7a1a  5f                   pop edi
// 006e7a1b  894e04               mov dword ptr [esi + 4], ecx
// 006e7a1e  5e                   pop esi
// 006e7a1f  c3                   ret 
// 006e7a20  8b4004               mov eax, dword ptr [eax + 4]
// 006e7a23  80781500             cmp byte ptr [eax + 0x15], 0
// 006e7a27  751d                 jne 0x6e7a46
// 006e7a29  8da42400000000       lea esp, [esp]
// 006e7a30  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e7a33  3b4808               cmp ecx, dword ptr [eax + 8]
// 006e7a36  750e                 jne 0x6e7a46
// 006e7a38  894604               mov dword ptr [esi + 4], eax
// 006e7a3b  8bd0                 mov edx, eax
// 006e7a3d  8b4204               mov eax, dword ptr [edx + 4]
// 006e7a40  80781500             cmp byte ptr [eax + 0x15], 0
// 006e7a44  74ea                 je 0x6e7a30
// 006e7a46  5f                   pop edi
// 006e7a47  894604               mov dword ptr [esi + 4], eax
// 006e7a4a  5e                   pop esi
// 006e7a4b  c3                   ret 
// standard library set<pod8> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
