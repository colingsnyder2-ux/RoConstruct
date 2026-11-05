// from server: 100% by auto
// roc 2007-08 004a2260  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2260
//
// 004a2260  55                   push ebp
// 004a2261  8bec                 mov ebp, esp
// 004a2263  6aff                 push -1
// 004a2265  6810967400           push 0x749610
// 004a226a  64a100000000         mov eax, dword ptr fs:[0]
// 004a2270  50                   push eax
// 004a2271  83ec0c               sub esp, 0xc
// 004a2274  53                   push ebx
// 004a2275  56                   push esi
// 004a2276  57                   push edi
// 004a2277  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a227c  33c5                 xor eax, ebp
// 004a227e  50                   push eax
// 004a227f  8d45f4               lea eax, [ebp - 0xc]
// 004a2282  64a300000000         mov dword ptr fs:[0], eax
// 004a2288  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a228b  8bf9                 mov edi, ecx
// 004a228d  897de8               mov dword ptr [ebp - 0x18], edi
// 004a2290  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004a2293  8b4304               mov eax, dword ptr [ebx + 4]
// 004a2296  33c9                 xor ecx, ecx
// 004a2298  3bc1                 cmp eax, ecx
// 004a229a  7504                 jne 0x4a22a0
// 004a229c  33f6                 xor esi, esi
// 004a229e  eb17                 jmp 0x4a22b7
// 004a22a0  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004a22a3  2bc8                 sub ecx, eax
// 004a22a5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a22aa  f7e9                 imul ecx
// 004a22ac  d1fa                 sar edx, 1
// 004a22ae  8bf2                 mov esi, edx
// 004a22b0  c1ee1f               shr esi, 0x1f
// 004a22b3  03f2                 add esi, edx
// 004a22b5  33c9                 xor ecx, ecx
// 004a22b7  3bf1                 cmp esi, ecx
// 004a22b9  894f04               mov dword ptr [edi + 4], ecx
// 004a22bc  894f08               mov dword ptr [edi + 8], ecx
// 004a22bf  894f0c               mov dword ptr [edi + 0xc], ecx
// 004a22c2  746d                 je 0x4a2331
// 004a22c4  81fe55555515         cmp esi, 0x15555555
// 004a22ca  7605                 jbe 0x4a22d1
// 004a22cc  e82f55f7ff           call 0x417800
// 004a22d1  51                   push ecx
// 004a22d2  56                   push esi
// 004a22d3  e868e1ffff           call 0x4a0440
// 004a22d8  8d0c76               lea ecx, [esi + esi*2]
// 004a22db  8d1488               lea edx, [eax + ecx*4]
// 004a22de  894704               mov dword ptr [edi + 4], eax
// 004a22e1  894708               mov dword ptr [edi + 8], eax
// 004a22e4  89570c               mov dword ptr [edi + 0xc], edx
// 004a22e7  8b4308               mov eax, dword ptr [ebx + 8]
// 004a22ea  83c408               add esp, 8
// 004a22ed  394304               cmp dword ptr [ebx + 4], eax
// 004a22f0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a22f7  8945ec               mov dword ptr [ebp - 0x14], eax
// 004a22fa  7606                 jbe 0x4a2302
// 004a22fc  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a2302  8b7304               mov esi, dword ptr [ebx + 4]
// 004a2305  3b7308               cmp esi, dword ptr [ebx + 8]
// 004a2308  7606                 jbe 0x4a2310
// 004a230a  ff15d8e67700         call dword ptr [0x77e6d8]
// 004a2310  8b4704               mov eax, dword ptr [edi + 4]
// 004a2313  c6450800             mov byte ptr [ebp + 8], 0
// 004a2317  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004a231a  8b5508               mov edx, dword ptr [ebp + 8]
// 004a231d  51                   push ecx
// 004a231e  52                   push edx
// 004a231f  57                   push edi
// 004a2320  50                   push eax
// 004a2321  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004a2324  50                   push eax
// 004a2325  56                   push esi
// 004a2326  e8c5f4ffff           call 0x4a17f0
// 004a232b  83c418               add esp, 0x18
// 004a232e  894708               mov dword ptr [edi + 8], eax
// 004a2331  8bc7                 mov eax, edi
// 004a2333  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a2336  64890d00000000       mov dword ptr fs:[0], ecx
// 004a233d  59                   pop ecx
// 004a233e  5f                   pop edi
// 004a233f  5e                   pop esi
// 004a2340  5b                   pop ebx
// 004a2341  8be5                 mov esp, ebp
// 004a2343  5d                   pop ebp
// 004a2344  c20400               ret 4
// standard library vector<pod12> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
