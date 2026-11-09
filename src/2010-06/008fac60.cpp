// from server: 100% by auto
// roc 2010-06 008fac60  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fac60
//
// 008fac60  83ec08               sub esp, 8
// 008fac63  53                   push ebx
// 008fac64  55                   push ebp
// 008fac65  56                   push esi
// 008fac66  8bf1                 mov esi, ecx
// 008fac68  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008fac6b  57                   push edi
// 008fac6c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008fac6f  8bcb                 mov ecx, ebx
// 008fac71  2bcf                 sub ecx, edi
// 008fac73  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008fac78  f7e9                 imul ecx
// 008fac7a  c1fa03               sar edx, 3
// 008fac7d  8bc2                 mov eax, edx
// 008fac7f  c1e81f               shr eax, 0x1f
// 008fac82  03c2                 add eax, edx
// 008fac84  7504                 jne 0x8fac8a
// 008fac86  33ff                 xor edi, edi
// 008fac88  eb35                 jmp 0x8facbf
// 008fac8a  3bfb                 cmp edi, ebx
// 008fac8c  7606                 jbe 0x8fac94
// 008fac8e  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fac94  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008fac98  8b06                 mov eax, dword ptr [esi]
// 008fac9a  85c9                 test ecx, ecx
// 008fac9c  7404                 je 0x8faca2
// 008fac9e  3bc8                 cmp ecx, eax
// 008faca0  7406                 je 0x8faca8
// 008faca2  ff150ca99e00         call dword ptr [0x9ea90c]
// 008faca8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008facac  2bcf                 sub ecx, edi
// 008facae  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008facb3  f7e9                 imul ecx
// 008facb5  c1fa03               sar edx, 3
// 008facb8  8bfa                 mov edi, edx
// 008facba  c1ef1f               shr edi, 0x1f
// 008facbd  03fa                 add edi, edx
// 008facbf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008facc3  8b542424             mov edx, dword ptr [esp + 0x24]
// 008facc7  8b442420             mov eax, dword ptr [esp + 0x20]
// 008faccb  51                   push ecx
// 008faccc  6a01                 push 1
// 008facce  52                   push edx
// 008faccf  50                   push eax
// 008facd0  8bce                 mov ecx, esi
// 008facd2  e849d0ffff           call 0x8f7d20
// 008facd7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008facda  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 008facdd  7606                 jbe 0x8face5
// 008facdf  ff150ca99e00         call dword ptr [0x9ea90c]
// 008face5  8b36                 mov esi, dword ptr [esi]
// 008face7  8bee                 mov ebp, esi
// 008face9  895c2414             mov dword ptr [esp + 0x14], ebx
// 008faced  85f6                 test esi, esi
// 008facef  751e                 jne 0x8fad0f
// 008facf1  ff150ca99e00         call dword ptr [0x9ea90c]
// 008facf7  33c0                 xor eax, eax
// 008facf9  8d0c7f               lea ecx, [edi + edi*2]
// 008facfc  c1e104               shl ecx, 4
// 008facff  8d3c19               lea edi, [ecx + ebx]
// 008fad02  3b7810               cmp edi, dword ptr [eax + 0x10]
// 008fad05  7713                 ja 0x8fad1a
// 008fad07  85f6                 test esi, esi
// 008fad09  7408                 je 0x8fad13
// 008fad0b  8b36                 mov esi, dword ptr [esi]
// 008fad0d  eb06                 jmp 0x8fad15
// 008fad0f  8b06                 mov eax, dword ptr [esi]
// 008fad11  ebe6                 jmp 0x8facf9
// 008fad13  33f6                 xor esi, esi
// 008fad15  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 008fad18  7306                 jae 0x8fad20
// 008fad1a  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fad20  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008fad24  897804               mov dword ptr [eax + 4], edi
// 008fad27  5f                   pop edi
// 008fad28  5e                   pop esi
// 008fad29  8928                 mov dword ptr [eax], ebp
// 008fad2b  5d                   pop ebp
// 008fad2c  5b                   pop ebx
// 008fad2d  83c408               add esp, 8
// 008fad30  c21000               ret 0x10
// standard library vector<pod48> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod48>
struct E { int v[12]; };
#include <vector>
template class std::vector<E>;
