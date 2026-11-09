// from server: 100% by auto
// roc 2008-06 0067da70  unit: Ogre::RbxEntity  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067da70
//
// 0067da70  83ec08               sub esp, 8
// 0067da73  56                   push esi
// 0067da74  8bf1                 mov esi, ecx
// 0067da76  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0067da79  57                   push edi
// 0067da7a  85c9                 test ecx, ecx
// 0067da7c  7504                 jne 0x67da82
// 0067da7e  33c0                 xor eax, eax
// 0067da80  eb08                 jmp 0x67da8a
// 0067da82  8b4614               mov eax, dword ptr [esi + 0x14]
// 0067da85  2bc1                 sub eax, ecx
// 0067da87  c1f804               sar eax, 4
// 0067da8a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0067da8d  8bd7                 mov edx, edi
// 0067da8f  2bd1                 sub edx, ecx
// 0067da91  c1fa04               sar edx, 4
// 0067da94  3bd0                 cmp edx, eax
// 0067da96  7331                 jae 0x67dac9
// 0067da98  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0067da9c  c644240800           mov byte ptr [esp + 8], 0
// 0067daa1  8b442408             mov eax, dword ptr [esp + 8]
// 0067daa5  50                   push eax
// 0067daa6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0067daaa  51                   push ecx
// 0067daab  8d5608               lea edx, [esi + 8]
// 0067daae  52                   push edx
// 0067daaf  50                   push eax
// 0067dab0  6a01                 push 1
// 0067dab2  57                   push edi
// 0067dab3  e8e8eeffff           call 0x67c9a0
// 0067dab8  83c418               add esp, 0x18
// 0067dabb  83c710               add edi, 0x10
// 0067dabe  897e10               mov dword ptr [esi + 0x10], edi
// 0067dac1  5f                   pop edi
// 0067dac2  5e                   pop esi
// 0067dac3  83c408               add esp, 8
// 0067dac6  c20400               ret 4
// 0067dac9  3bcf                 cmp ecx, edi
// 0067dacb  7606                 jbe 0x67dad3
// 0067dacd  ff1590288000         call dword ptr [0x802890]
// 0067dad3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0067dad7  8b06                 mov eax, dword ptr [esi]
// 0067dad9  51                   push ecx
// 0067dada  57                   push edi
// 0067dadb  50                   push eax
// 0067dadc  8d542414             lea edx, [esp + 0x14]
// 0067dae0  52                   push edx
// 0067dae1  8bce                 mov ecx, esi
// 0067dae3  e808feffff           call 0x67d8f0
// 0067dae8  5f                   pop edi
// 0067dae9  5e                   pop esi
// 0067daea  83c408               add esp, 8
// 0067daed  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
