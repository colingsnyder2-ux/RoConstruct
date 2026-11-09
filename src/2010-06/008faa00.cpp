// from server: 100% by auto
// roc 2010-06 008faa00  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008faa00
//
// 008faa00  83ec08               sub esp, 8
// 008faa03  53                   push ebx
// 008faa04  55                   push ebp
// 008faa05  56                   push esi
// 008faa06  8bf1                 mov esi, ecx
// 008faa08  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008faa0b  57                   push edi
// 008faa0c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008faa0f  8bcb                 mov ecx, ebx
// 008faa11  2bcf                 sub ecx, edi
// 008faa13  b8398ee338           mov eax, 0x38e38e39
// 008faa18  f7e9                 imul ecx
// 008faa1a  c1fa03               sar edx, 3
// 008faa1d  8bc2                 mov eax, edx
// 008faa1f  c1e81f               shr eax, 0x1f
// 008faa22  03c2                 add eax, edx
// 008faa24  7504                 jne 0x8faa2a
// 008faa26  33ff                 xor edi, edi
// 008faa28  eb35                 jmp 0x8faa5f
// 008faa2a  3bfb                 cmp edi, ebx
// 008faa2c  7606                 jbe 0x8faa34
// 008faa2e  ff150ca99e00         call dword ptr [0x9ea90c]
// 008faa34  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008faa38  8b06                 mov eax, dword ptr [esi]
// 008faa3a  85c9                 test ecx, ecx
// 008faa3c  7404                 je 0x8faa42
// 008faa3e  3bc8                 cmp ecx, eax
// 008faa40  7406                 je 0x8faa48
// 008faa42  ff150ca99e00         call dword ptr [0x9ea90c]
// 008faa48  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008faa4c  2bcf                 sub ecx, edi
// 008faa4e  b8398ee338           mov eax, 0x38e38e39
// 008faa53  f7e9                 imul ecx
// 008faa55  c1fa03               sar edx, 3
// 008faa58  8bfa                 mov edi, edx
// 008faa5a  c1ef1f               shr edi, 0x1f
// 008faa5d  03fa                 add edi, edx
// 008faa5f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008faa63  8b542424             mov edx, dword ptr [esp + 0x24]
// 008faa67  8b442420             mov eax, dword ptr [esp + 0x20]
// 008faa6b  51                   push ecx
// 008faa6c  6a01                 push 1
// 008faa6e  52                   push edx
// 008faa6f  50                   push eax
// 008faa70  8bce                 mov ecx, esi
// 008faa72  e889caffff           call 0x8f7500
// 008faa77  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008faa7a  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008faa7d  7606                 jbe 0x8faa85
// 008faa7f  ff150ca99e00         call dword ptr [0x9ea90c]
// 008faa85  8b36                 mov esi, dword ptr [esi]
// 008faa87  8bee                 mov ebp, esi
// 008faa89  895c2414             mov dword ptr [esp + 0x14], ebx
// 008faa8d  85f6                 test esi, esi
// 008faa8f  751b                 jne 0x8faaac
// 008faa91  ff150ca99e00         call dword ptr [0x9ea90c]
// 008faa97  33c0                 xor eax, eax
// 008faa99  8d0cff               lea ecx, [edi + edi*8]
// 008faa9c  8d3c8b               lea edi, [ebx + ecx*4]
// 008faa9f  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008faaa2  7713                 ja 0x8faab7
// 008faaa4  85f6                 test esi, esi
// 008faaa6  7408                 je 0x8faab0
// 008faaa8  8b36                 mov esi, dword ptr [esi]
// 008faaaa  eb06                 jmp 0x8faab2
// 008faaac  8b06                 mov eax, dword ptr [esi]
// 008faaae  ebe9                 jmp 0x8faa99
// 008faab0  33f6                 xor esi, esi
// 008faab2  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008faab5  7306                 jae 0x8faabd
// 008faab7  ff150ca99e00         call dword ptr [0x9ea90c]
// 008faabd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008faac1  897804               mov dword ptr [eax + 4], edi
// 008faac4  5f                   pop edi
// 008faac5  5e                   pop esi
// 008faac6  8928                 mov dword ptr [eax], ebp
// 008faac8  5d                   pop ebp
// 008faac9  5b                   pop ebx
// 008faaca  83c408               add esp, 8
// 008faacd  c21000               ret 0x10
// standard library vector<pod36> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
