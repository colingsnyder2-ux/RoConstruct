// from server: 100% by auto
// roc 2007-08 005dfc60  unit: RBX::VMotorFeature::?$FactoryProduct  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005dfc60
//
// 005dfc60  53                   push ebx
// 005dfc61  56                   push esi
// 005dfc62  33db                 xor ebx, ebx
// 005dfc64  57                   push edi
// 005dfc65  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005dfc69  3bfb                 cmp edi, ebx
// 005dfc6b  8bf1                 mov esi, ecx
// 005dfc6d  895e04               mov dword ptr [esi + 4], ebx
// 005dfc70  895e08               mov dword ptr [esi + 8], ebx
// 005dfc73  895e0c               mov dword ptr [esi + 0xc], ebx
// 005dfc76  7445                 je 0x5dfcbd
// 005dfc78  81ffffffff3f         cmp edi, 0x3fffffff
// 005dfc7e  7605                 jbe 0x5dfc85
// 005dfc80  e87b7be3ff           call 0x417800
// 005dfc85  53                   push ebx
// 005dfc86  57                   push edi
// 005dfc87  e8d400fdff           call 0x5afd60
// 005dfc8c  8d0cb8               lea ecx, [eax + edi*4]
// 005dfc8f  83c408               add esp, 8
// 005dfc92  3bfb                 cmp edi, ebx
// 005dfc94  894e0c               mov dword ptr [esi + 0xc], ecx
// 005dfc97  894604               mov dword ptr [esi + 4], eax
// 005dfc9a  894608               mov dword ptr [esi + 8], eax
// 005dfc9d  8bcf                 mov ecx, edi
// 005dfc9f  8bd0                 mov edx, eax
// 005dfca1  7614                 jbe 0x5dfcb7
// 005dfca3  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005dfca7  55                   push ebp
// 005dfca8  8b2b                 mov ebp, dword ptr [ebx]
// 005dfcaa  892a                 mov dword ptr [edx], ebp
// 005dfcac  83e901               sub ecx, 1
// 005dfcaf  83c204               add edx, 4
// 005dfcb2  85c9                 test ecx, ecx
// 005dfcb4  77f2                 ja 0x5dfca8
// 005dfcb6  5d                   pop ebp
// 005dfcb7  8d14b8               lea edx, [eax + edi*4]
// 005dfcba  895608               mov dword ptr [esi + 8], edx
// 005dfcbd  5f                   pop edi
// 005dfcbe  5e                   pop esi
// 005dfcbf  5b                   pop ebx
// 005dfcc0  c20800               ret 8
// standard library vector<ptr> (function ?_Construct_n@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
