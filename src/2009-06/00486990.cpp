// from server: 100% by auto
// roc 2009-06 00486990  unit: Ogre::RbxMeshPartAdapter  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486990
//
// 00486990  55                   push ebp
// 00486991  8bec                 mov ebp, esp
// 00486993  6aff                 push -1
// 00486995  6890548500           push 0x855490
// 0048699a  64a100000000         mov eax, dword ptr fs:[0]
// 004869a0  50                   push eax
// 004869a1  64892500000000       mov dword ptr fs:[0], esp
// 004869a8  83ec10               sub esp, 0x10
// 004869ab  8b5508               mov edx, dword ptr [ebp + 8]
// 004869ae  53                   push ebx
// 004869af  56                   push esi
// 004869b0  57                   push edi
// 004869b1  8965f0               mov dword ptr [ebp - 0x10], esp
// 004869b4  8bf1                 mov esi, ecx
// 004869b6  81faffffff1f         cmp edx, 0x1fffffff
// 004869bc  7605                 jbe 0x4869c3
// 004869be  e89d990000           call 0x490360
// 004869c3  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004869c6  85c9                 test ecx, ecx
// 004869c8  7504                 jne 0x4869ce
// 004869ca  33c0                 xor eax, eax
// 004869cc  eb08                 jmp 0x4869d6
// 004869ce  8b4614               mov eax, dword ptr [esi + 0x14]
// 004869d1  2bc1                 sub eax, ecx
// 004869d3  c1f803               sar eax, 3
// 004869d6  3bc2                 cmp eax, edx
// 004869d8  737e                 jae 0x486a58
// 004869da  6a00                 push 0
// 004869dc  52                   push edx
// 004869dd  e80ee5ffff           call 0x484ef0
// 004869e2  8bd8                 mov ebx, eax
// 004869e4  8b4610               mov eax, dword ptr [esi + 0x10]
// 004869e7  83c408               add esp, 8
// 004869ea  895de4               mov dword ptr [ebp - 0x1c], ebx
// 004869ed  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004869f4  8945e8               mov dword ptr [ebp - 0x18], eax
// 004869f7  39460c               cmp dword ptr [esi + 0xc], eax
// 004869fa  7606                 jbe 0x486a02
// 004869fc  ff15ace98900         call dword ptr [0x89e9ac]
// 00486a02  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00486a05  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00486a08  7606                 jbe 0x486a10
// 00486a0a  ff15ace98900         call dword ptr [0x89e9ac]
// 00486a10  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00486a13  c645ec00             mov byte ptr [ebp - 0x14], 0
// 00486a17  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 00486a1a  50                   push eax
// 00486a1b  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 00486a1e  51                   push ecx
// 00486a1f  8d5608               lea edx, [esi + 8]
// 00486a22  52                   push edx
// 00486a23  53                   push ebx
// 00486a24  50                   push eax
// 00486a25  57                   push edi
// 00486a26  e875f4ffff           call 0x485ea0
// 00486a2b  8b460c               mov eax, dword ptr [esi + 0xc]
// 00486a2e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00486a31  2bf8                 sub edi, eax
// 00486a33  83c418               add esp, 0x18
// 00486a36  c1ff03               sar edi, 3
// 00486a39  85c0                 test eax, eax
// 00486a3b  7409                 je 0x486a46
// 00486a3d  50                   push eax
// 00486a3e  e8ef1f2900           call 0x718a32
// 00486a43  83c404               add esp, 4
// 00486a46  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00486a49  8d14cb               lea edx, [ebx + ecx*8]
// 00486a4c  8d04fb               lea eax, [ebx + edi*8]
// 00486a4f  895614               mov dword ptr [esi + 0x14], edx
// 00486a52  894610               mov dword ptr [esi + 0x10], eax
// 00486a55  895e0c               mov dword ptr [esi + 0xc], ebx
// 00486a58  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486a5b  5f                   pop edi
// 00486a5c  5e                   pop esi
// 00486a5d  64890d00000000       mov dword ptr fs:[0], ecx
// 00486a64  5b                   pop ebx
// 00486a65  8be5                 mov esp, ebp
// 00486a67  5d                   pop ebp
// 00486a68  c20400               ret 4
// standard library vector<pod8> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
