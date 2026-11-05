// from server: 100% by auto
// roc 2007-08 005b4070  unit: RBX::Assembly  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b4070
//
// 005b4070  83ec08               sub esp, 8
// 005b4073  56                   push esi
// 005b4074  8bf1                 mov esi, ecx
// 005b4076  8b5604               mov edx, dword ptr [esi + 4]
// 005b4079  85d2                 test edx, edx
// 005b407b  7504                 jne 0x5b4081
// 005b407d  33c9                 xor ecx, ecx
// 005b407f  eb08                 jmp 0x5b4089
// 005b4081  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b4084  2bca                 sub ecx, edx
// 005b4086  c1f902               sar ecx, 2
// 005b4089  85d2                 test edx, edx
// 005b408b  7424                 je 0x5b40b1
// 005b408d  8b460c               mov eax, dword ptr [esi + 0xc]
// 005b4090  2bc2                 sub eax, edx
// 005b4092  c1f802               sar eax, 2
// 005b4095  3bc8                 cmp ecx, eax
// 005b4097  7318                 jae 0x5b40b1
// 005b4099  8b4608               mov eax, dword ptr [esi + 8]
// 005b409c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005b40a0  8b11                 mov edx, dword ptr [ecx]
// 005b40a2  8910                 mov dword ptr [eax], edx
// 005b40a4  83c004               add eax, 4
// 005b40a7  894608               mov dword ptr [esi + 8], eax
// 005b40aa  5e                   pop esi
// 005b40ab  83c408               add esp, 8
// 005b40ae  c20400               ret 4
// 005b40b1  57                   push edi
// 005b40b2  8b7e08               mov edi, dword ptr [esi + 8]
// 005b40b5  3bd7                 cmp edx, edi
// 005b40b7  7606                 jbe 0x5b40bf
// 005b40b9  ff15d8e67700         call dword ptr [0x77e6d8]
// 005b40bf  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b40c3  50                   push eax
// 005b40c4  57                   push edi
// 005b40c5  56                   push esi
// 005b40c6  8d4c2414             lea ecx, [esp + 0x14]
// 005b40ca  51                   push ecx
// 005b40cb  8bce                 mov ecx, esi
// 005b40cd  e8ae9e0100           call 0x5cdf80
// 005b40d2  5f                   pop edi
// 005b40d3  5e                   pop esi
// 005b40d4  83c408               add esp, 8
// 005b40d7  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
