// from server: 100% by auto
// roc 2008-06 004c7a90  unit: RBX::VInstance::?$Association::Item  size: 384 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c7a90
//
// 004c7a90  55                   push ebp
// 004c7a91  56                   push esi
// 004c7a92  8bf1                 mov esi, ecx
// 004c7a94  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c7a97  57                   push edi
// 004c7a98  85c9                 test ecx, ecx
// 004c7a9a  7504                 jne 0x4c7aa0
// 004c7a9c  33ed                 xor ebp, ebp
// 004c7a9e  eb08                 jmp 0x4c7aa8
// 004c7aa0  8b6e14               mov ebp, dword ptr [esi + 0x14]
// 004c7aa3  2be9                 sub ebp, ecx
// 004c7aa5  c1fd02               sar ebp, 2
// 004c7aa8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004c7aac  85ff                 test edi, edi
// 004c7aae  0f8456010000         je 0x4c7c0a
// 004c7ab4  53                   push ebx
// 004c7ab5  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004c7ab8  8bc3                 mov eax, ebx
// 004c7aba  2bc1                 sub eax, ecx
// 004c7abc  c1f802               sar eax, 2
// 004c7abf  b9ffffff3f           mov ecx, 0x3fffffff
// 004c7ac4  2bc8                 sub ecx, eax
// 004c7ac6  3bcf                 cmp ecx, edi
// 004c7ac8  7305                 jae 0x4c7acf
// 004c7aca  e871f2ffff           call 0x4c6d40
// 004c7acf  8d0c38               lea ecx, [eax + edi]
// 004c7ad2  3be9                 cmp ebp, ecx
// 004c7ad4  0f8388000000         jae 0x4c7b62
// 004c7ada  8bc5                 mov eax, ebp
// 004c7adc  d1e8                 shr eax, 1
// 004c7ade  baffffff3f           mov edx, 0x3fffffff
// 004c7ae3  2bd0                 sub edx, eax
// 004c7ae5  3bd5                 cmp edx, ebp
// 004c7ae7  7304                 jae 0x4c7aed
// 004c7ae9  33ed                 xor ebp, ebp
// 004c7aeb  eb02                 jmp 0x4c7aef
// 004c7aed  03e8                 add ebp, eax
// 004c7aef  3be9                 cmp ebp, ecx
// 004c7af1  7302                 jae 0x4c7af5
// 004c7af3  8be9                 mov ebp, ecx
// 004c7af5  6a00                 push 0
// 004c7af7  55                   push ebp
// 004c7af8  e85390f5ff           call 0x420b50
// 004c7afd  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c7b00  83c408               add esp, 8
// 004c7b03  8bd8                 mov ebx, eax
// 004c7b05  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c7b09  53                   push ebx
// 004c7b0a  50                   push eax
// 004c7b0b  51                   push ecx
// 004c7b0c  8bce                 mov ecx, esi
// 004c7b0e  e8edc0f5ff           call 0x423c00
// 004c7b13  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c7b17  52                   push edx
// 004c7b18  57                   push edi
// 004c7b19  50                   push eax
// 004c7b1a  8bce                 mov ecx, esi
// 004c7b1c  e8dffbffff           call 0x4c7700
// 004c7b21  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c7b25  50                   push eax
// 004c7b26  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c7b29  50                   push eax
// 004c7b2a  51                   push ecx
// 004c7b2b  8bce                 mov ecx, esi
// 004c7b2d  e8cec0f5ff           call 0x423c00
// 004c7b32  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c7b35  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c7b38  2bd0                 sub edx, eax
// 004c7b3a  c1fa02               sar edx, 2
// 004c7b3d  03fa                 add edi, edx
// 004c7b3f  85c0                 test eax, eax
// 004c7b41  7409                 je 0x4c7b4c
// 004c7b43  50                   push eax
// 004c7b44  e8318b1d00           call 0x6a067a
// 004c7b49  83c404               add esp, 4
// 004c7b4c  8d04ab               lea eax, [ebx + ebp*4]
// 004c7b4f  8d0cbb               lea ecx, [ebx + edi*4]
// 004c7b52  895e0c               mov dword ptr [esi + 0xc], ebx
// 004c7b55  5b                   pop ebx
// 004c7b56  5f                   pop edi
// 004c7b57  894614               mov dword ptr [esi + 0x14], eax
// 004c7b5a  894e10               mov dword ptr [esi + 0x10], ecx
// 004c7b5d  5e                   pop esi
// 004c7b5e  5d                   pop ebp
// 004c7b5f  c21000               ret 0x10
// 004c7b62  8b442418             mov eax, dword ptr [esp + 0x18]
// 004c7b66  8bd3                 mov edx, ebx
// 004c7b68  2bd0                 sub edx, eax
// 004c7b6a  c1fa02               sar edx, 2
// 004c7b6d  8d2cbd00000000       lea ebp, [edi*4]
// 004c7b74  3bd7                 cmp edx, edi
// 004c7b76  7355                 jae 0x4c7bcd
// 004c7b78  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004c7b7c  d901                 fld dword ptr [ecx]
// 004c7b7e  8d1428               lea edx, [eax + ebp]
// 004c7b81  52                   push edx
// 004c7b82  d95c2424             fstp dword ptr [esp + 0x24]
// 004c7b86  53                   push ebx
// 004c7b87  50                   push eax
// 004c7b88  8bce                 mov ecx, esi
// 004c7b8a  e871c0f5ff           call 0x423c00
// 004c7b8f  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c7b92  8bd0                 mov edx, eax
// 004c7b94  2b542418             sub edx, dword ptr [esp + 0x18]
// 004c7b98  8d4c2420             lea ecx, [esp + 0x20]
// 004c7b9c  51                   push ecx
// 004c7b9d  c1fa02               sar edx, 2
// 004c7ba0  2bfa                 sub edi, edx
// 004c7ba2  57                   push edi
// 004c7ba3  50                   push eax
// 004c7ba4  8bce                 mov ecx, esi
// 004c7ba6  e855fbffff           call 0x4c7700
// 004c7bab  016e10               add dword ptr [esi + 0x10], ebp
// 004c7bae  8b7610               mov esi, dword ptr [esi + 0x10]
// 004c7bb1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c7bb5  8d442420             lea eax, [esp + 0x20]
// 004c7bb9  50                   push eax
// 004c7bba  2bf5                 sub esi, ebp
// 004c7bbc  56                   push esi
// 004c7bbd  51                   push ecx
// 004c7bbe  e8edf5ffff           call 0x4c71b0
// 004c7bc3  83c40c               add esp, 0xc
// 004c7bc6  5b                   pop ebx
// 004c7bc7  5f                   pop edi
// 004c7bc8  5e                   pop esi
// 004c7bc9  5d                   pop ebp
// 004c7bca  c21000               ret 0x10
// 004c7bcd  8b542420             mov edx, dword ptr [esp + 0x20]
// 004c7bd1  d902                 fld dword ptr [edx]
// 004c7bd3  53                   push ebx
// 004c7bd4  8bfb                 mov edi, ebx
// 004c7bd6  d95c2424             fstp dword ptr [esp + 0x24]
// 004c7bda  53                   push ebx
// 004c7bdb  2bfd                 sub edi, ebp
// 004c7bdd  57                   push edi
// 004c7bde  8bce                 mov ecx, esi
// 004c7be0  e81bc0f5ff           call 0x423c00
// 004c7be5  53                   push ebx
// 004c7be6  894610               mov dword ptr [esi + 0x10], eax
// 004c7be9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004c7bed  57                   push edi
// 004c7bee  50                   push eax
// 004c7bef  e87c1af9ff           call 0x459670
// 004c7bf4  8b442424             mov eax, dword ptr [esp + 0x24]
// 004c7bf8  8d4c242c             lea ecx, [esp + 0x2c]
// 004c7bfc  51                   push ecx
// 004c7bfd  03e8                 add ebp, eax
// 004c7bff  55                   push ebp
// 004c7c00  50                   push eax
// 004c7c01  e8aaf5ffff           call 0x4c71b0
// 004c7c06  83c418               add esp, 0x18
// 004c7c09  5b                   pop ebx
// 004c7c0a  5f                   pop edi
// 004c7c0b  5e                   pop esi
// 004c7c0c  5d                   pop ebp
// 004c7c0d  c21000               ret 0x10
// standard library vector<float> (function ?_Insert_n@?$vector@MV?$allocator@M@std@@@std@@IAEXV?$_Vector_const_iterator@MV?$allocator@M@std@@@2@IABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
