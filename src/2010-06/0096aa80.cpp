// from server: 100% by auto
// roc 2010-06 0096aa80  unit: Ogre::RbxSceneUpdater  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096aa80
//
// 0096aa80  83ec08               sub esp, 8
// 0096aa83  53                   push ebx
// 0096aa84  55                   push ebp
// 0096aa85  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0096aa8b  56                   push esi
// 0096aa8c  8bf1                 mov esi, ecx
// 0096aa8e  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0096aa91  57                   push edi
// 0096aa92  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0096aa95  8bcb                 mov ecx, ebx
// 0096aa97  2bcf                 sub ecx, edi
// 0096aa99  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096aa9e  f7e9                 imul ecx
// 0096aaa0  c1fa02               sar edx, 2
// 0096aaa3  8bc2                 mov eax, edx
// 0096aaa5  c1e81f               shr eax, 0x1f
// 0096aaa8  03c2                 add eax, edx
// 0096aaaa  7504                 jne 0x96aab0
// 0096aaac  33ff                 xor edi, edi
// 0096aaae  eb2d                 jmp 0x96aadd
// 0096aab0  3bfb                 cmp edi, ebx
// 0096aab2  7602                 jbe 0x96aab6
// 0096aab4  ffd5                 call ebp
// 0096aab6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0096aaba  8b06                 mov eax, dword ptr [esi]
// 0096aabc  85c9                 test ecx, ecx
// 0096aabe  7404                 je 0x96aac4
// 0096aac0  3bc8                 cmp ecx, eax
// 0096aac2  7402                 je 0x96aac6
// 0096aac4  ffd5                 call ebp
// 0096aac6  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0096aaca  2bcf                 sub ecx, edi
// 0096aacc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096aad1  f7e9                 imul ecx
// 0096aad3  c1fa02               sar edx, 2
// 0096aad6  8bfa                 mov edi, edx
// 0096aad8  c1ef1f               shr edi, 0x1f
// 0096aadb  03fa                 add edi, edx
// 0096aadd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0096aae1  8b542424             mov edx, dword ptr [esp + 0x24]
// 0096aae5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0096aae9  51                   push ecx
// 0096aaea  6a01                 push 1
// 0096aaec  52                   push edx
// 0096aaed  50                   push eax
// 0096aaee  8bce                 mov ecx, esi
// 0096aaf0  e84bfbffff           call 0x96a640
// 0096aaf5  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0096aaf8  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0096aafb  7602                 jbe 0x96aaff
// 0096aafd  ffd5                 call ebp
// 0096aaff  8b36                 mov esi, dword ptr [esi]
// 0096ab01  57                   push edi
// 0096ab02  8d4c2414             lea ecx, [esp + 0x14]
// 0096ab06  89742414             mov dword ptr [esp + 0x14], esi
// 0096ab0a  895c2418             mov dword ptr [esp + 0x18], ebx
// 0096ab0e  e86d5bdcff           call 0x730680
// 0096ab13  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0096ab17  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0096ab1b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0096ab1f  5f                   pop edi
// 0096ab20  5e                   pop esi
// 0096ab21  5d                   pop ebp
// 0096ab22  8908                 mov dword ptr [eax], ecx
// 0096ab24  895004               mov dword ptr [eax + 4], edx
// 0096ab27  5b                   pop ebx
// 0096ab28  83c408               add esp, 8
// 0096ab2b  c21000               ret 0x10
// standard library vector<pod24> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
