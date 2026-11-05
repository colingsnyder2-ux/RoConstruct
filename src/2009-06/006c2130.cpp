// from server: 100% by auto
// roc 2009-06 006c2130  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c2130
//
// 006c2130  55                   push ebp
// 006c2131  8bec                 mov ebp, esp
// 006c2133  6aff                 push -1
// 006c2135  68680c8700           push 0x870c68
// 006c213a  64a100000000         mov eax, dword ptr fs:[0]
// 006c2140  50                   push eax
// 006c2141  64892500000000       mov dword ptr fs:[0], esp
// 006c2148  83ec0c               sub esp, 0xc
// 006c214b  53                   push ebx
// 006c214c  56                   push esi
// 006c214d  57                   push edi
// 006c214e  8965f0               mov dword ptr [ebp - 0x10], esp
// 006c2151  8bf1                 mov esi, ecx
// 006c2153  6a04                 push 4
// 006c2155  8975e8               mov dword ptr [ebp - 0x18], esi
// 006c2158  e8db680500           call 0x718a38
// 006c215d  83c404               add esp, 4
// 006c2160  85c0                 test eax, eax
// 006c2162  7404                 je 0x6c2168
// 006c2164  8930                 mov dword ptr [eax], esi
// 006c2166  eb02                 jmp 0x6c216a
// 006c2168  33c0                 xor eax, eax
// 006c216a  8906                 mov dword ptr [esi], eax
// 006c216c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 006c216f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 006c2172  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 006c2175  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006c217a  f7e9                 imul ecx
// 006c217c  c1fa02               sar edx, 2
// 006c217f  8bfa                 mov edi, edx
// 006c2181  b800000000           mov eax, 0
// 006c2186  c1ef1f               shr edi, 0x1f
// 006c2189  03fa                 add edi, edx
// 006c218b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006c2192  89460c               mov dword ptr [esi + 0xc], eax
// 006c2195  894610               mov dword ptr [esi + 0x10], eax
// 006c2198  894614               mov dword ptr [esi + 0x14], eax
// 006c219b  746d                 je 0x6c220a
// 006c219d  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 006c21a3  7605                 jbe 0x6c21aa
// 006c21a5  e8b6e1dcff           call 0x490360
// 006c21aa  50                   push eax
// 006c21ab  57                   push edi
// 006c21ac  e84ff9ffff           call 0x6c1b00
// 006c21b1  8d0c7f               lea ecx, [edi + edi*2]
// 006c21b4  8d14c8               lea edx, [eax + ecx*8]
// 006c21b7  89460c               mov dword ptr [esi + 0xc], eax
// 006c21ba  894610               mov dword ptr [esi + 0x10], eax
// 006c21bd  895614               mov dword ptr [esi + 0x14], edx
// 006c21c0  8b4310               mov eax, dword ptr [ebx + 0x10]
// 006c21c3  83c408               add esp, 8
// 006c21c6  c645fc01             mov byte ptr [ebp - 4], 1
// 006c21ca  8945ec               mov dword ptr [ebp - 0x14], eax
// 006c21cd  39430c               cmp dword ptr [ebx + 0xc], eax
// 006c21d0  7606                 jbe 0x6c21d8
// 006c21d2  ff15ace98900         call dword ptr [0x89e9ac]
// 006c21d8  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 006c21db  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 006c21de  7606                 jbe 0x6c21e6
// 006c21e0  ff15ace98900         call dword ptr [0x89e9ac]
// 006c21e6  8b460c               mov eax, dword ptr [esi + 0xc]
// 006c21e9  c6450800             mov byte ptr [ebp + 8], 0
// 006c21ed  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006c21f0  8b5508               mov edx, dword ptr [ebp + 8]
// 006c21f3  51                   push ecx
// 006c21f4  52                   push edx
// 006c21f5  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 006c21f8  8d4e08               lea ecx, [esi + 8]
// 006c21fb  51                   push ecx
// 006c21fc  50                   push eax
// 006c21fd  52                   push edx
// 006c21fe  57                   push edi
// 006c21ff  e86cfcffff           call 0x6c1e70
// 006c2204  83c418               add esp, 0x18
// 006c2207  894610               mov dword ptr [esi + 0x10], eax
// 006c220a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006c220d  5f                   pop edi
// 006c220e  8bc6                 mov eax, esi
// 006c2210  5e                   pop esi
// 006c2211  64890d00000000       mov dword ptr fs:[0], ecx
// 006c2218  5b                   pop ebx
// 006c2219  8be5                 mov esp, ebp
// 006c221b  5d                   pop ebp
// 006c221c  c20400               ret 4
// standard library vector<pod24> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
