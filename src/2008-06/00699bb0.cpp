// from server: 100% by auto
// roc 2008-06 00699bb0  unit: Ogre::RbxSceneManager  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00699bb0
//
// 00699bb0  83ec08               sub esp, 8
// 00699bb3  53                   push ebx
// 00699bb4  55                   push ebp
// 00699bb5  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00699bbb  56                   push esi
// 00699bbc  8bf1                 mov esi, ecx
// 00699bbe  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00699bc1  57                   push edi
// 00699bc2  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00699bc5  8bcb                 mov ecx, ebx
// 00699bc7  2bcf                 sub ecx, edi
// 00699bc9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699bce  f7e9                 imul ecx
// 00699bd0  c1fa02               sar edx, 2
// 00699bd3  8bc2                 mov eax, edx
// 00699bd5  c1e81f               shr eax, 0x1f
// 00699bd8  03c2                 add eax, edx
// 00699bda  7504                 jne 0x699be0
// 00699bdc  33ff                 xor edi, edi
// 00699bde  eb2d                 jmp 0x699c0d
// 00699be0  3bfb                 cmp edi, ebx
// 00699be2  7602                 jbe 0x699be6
// 00699be4  ffd5                 call ebp
// 00699be6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00699bea  8b06                 mov eax, dword ptr [esi]
// 00699bec  85c9                 test ecx, ecx
// 00699bee  7404                 je 0x699bf4
// 00699bf0  3bc8                 cmp ecx, eax
// 00699bf2  7402                 je 0x699bf6
// 00699bf4  ffd5                 call ebp
// 00699bf6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00699bfa  2bcf                 sub ecx, edi
// 00699bfc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00699c01  f7e9                 imul ecx
// 00699c03  c1fa02               sar edx, 2
// 00699c06  8bfa                 mov edi, edx
// 00699c08  c1ef1f               shr edi, 0x1f
// 00699c0b  03fa                 add edi, edx
// 00699c0d  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00699c11  8b542424             mov edx, dword ptr [esp + 0x24]
// 00699c15  8b442420             mov eax, dword ptr [esp + 0x20]
// 00699c19  51                   push ecx
// 00699c1a  6a01                 push 1
// 00699c1c  52                   push edx
// 00699c1d  50                   push eax
// 00699c1e  8bce                 mov ecx, esi
// 00699c20  e83bddffff           call 0x697960
// 00699c25  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00699c28  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00699c2b  7602                 jbe 0x699c2f
// 00699c2d  ffd5                 call ebp
// 00699c2f  8b36                 mov esi, dword ptr [esi]
// 00699c31  57                   push edi
// 00699c32  8d4c2414             lea ecx, [esp + 0x14]
// 00699c36  89742414             mov dword ptr [esp + 0x14], esi
// 00699c3a  895c2418             mov dword ptr [esp + 0x18], ebx
// 00699c3e  e80d38ffff           call 0x68d450
// 00699c43  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00699c47  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00699c4b  8b542414             mov edx, dword ptr [esp + 0x14]
// 00699c4f  5f                   pop edi
// 00699c50  5e                   pop esi
// 00699c51  5d                   pop ebp
// 00699c52  8908                 mov dword ptr [eax], ecx
// 00699c54  895004               mov dword ptr [eax + 4], edx
// 00699c57  5b                   pop ebx
// 00699c58  83c408               add esp, 8
// 00699c5b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
