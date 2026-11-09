// from server: 100% by auto
// roc 2007-08 005dfbf0  unit: RBX::VMotorFeature::?$FactoryProduct  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005dfbf0
//
// 005dfbf0  53                   push ebx
// 005dfbf1  56                   push esi
// 005dfbf2  33db                 xor ebx, ebx
// 005dfbf4  57                   push edi
// 005dfbf5  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005dfbf9  3bfb                 cmp edi, ebx
// 005dfbfb  8bf1                 mov esi, ecx
// 005dfbfd  895e04               mov dword ptr [esi + 4], ebx
// 005dfc00  895e08               mov dword ptr [esi + 8], ebx
// 005dfc03  895e0c               mov dword ptr [esi + 0xc], ebx
// 005dfc06  7445                 je 0x5dfc4d
// 005dfc08  81ffffffff3f         cmp edi, 0x3fffffff
// 005dfc0e  7605                 jbe 0x5dfc15
// 005dfc10  e81bd1feff           call 0x5ccd30
// 005dfc15  53                   push ebx
// 005dfc16  57                   push edi
// 005dfc17  e84401fdff           call 0x5afd60
// 005dfc1c  8d0cb8               lea ecx, [eax + edi*4]
// 005dfc1f  83c408               add esp, 8
// 005dfc22  3bfb                 cmp edi, ebx
// 005dfc24  894e0c               mov dword ptr [esi + 0xc], ecx
// 005dfc27  894604               mov dword ptr [esi + 4], eax
// 005dfc2a  894608               mov dword ptr [esi + 8], eax
// 005dfc2d  8bcf                 mov ecx, edi
// 005dfc2f  8bd0                 mov edx, eax
// 005dfc31  7614                 jbe 0x5dfc47
// 005dfc33  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005dfc37  55                   push ebp
// 005dfc38  8b2b                 mov ebp, dword ptr [ebx]
// 005dfc3a  892a                 mov dword ptr [edx], ebp
// 005dfc3c  83e901               sub ecx, 1
// 005dfc3f  83c204               add edx, 4
// 005dfc42  85c9                 test ecx, ecx
// 005dfc44  77f2                 ja 0x5dfc38
// 005dfc46  5d                   pop ebp
// 005dfc47  8d14b8               lea edx, [eax + edi*4]
// 005dfc4a  895608               mov dword ptr [esi + 8], edx
// 005dfc4d  5f                   pop edi
// 005dfc4e  5e                   pop esi
// 005dfc4f  5b                   pop ebx
// 005dfc50  c20800               ret 8
// standard library vector<ptr> (function ?_Construct_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
