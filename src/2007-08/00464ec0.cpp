// from server: 100% by auto
// roc 2007-08 00464ec0  unit: DxUserInput  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00464ec0
//
// 00464ec0  83ec08               sub esp, 8
// 00464ec3  56                   push esi
// 00464ec4  8bf1                 mov esi, ecx
// 00464ec6  8b5604               mov edx, dword ptr [esi + 4]
// 00464ec9  85d2                 test edx, edx
// 00464ecb  7504                 jne 0x464ed1
// 00464ecd  33c9                 xor ecx, ecx
// 00464ecf  eb08                 jmp 0x464ed9
// 00464ed1  8b4e08               mov ecx, dword ptr [esi + 8]
// 00464ed4  2bca                 sub ecx, edx
// 00464ed6  c1f902               sar ecx, 2
// 00464ed9  85d2                 test edx, edx
// 00464edb  7424                 je 0x464f01
// 00464edd  8b460c               mov eax, dword ptr [esi + 0xc]
// 00464ee0  2bc2                 sub eax, edx
// 00464ee2  c1f802               sar eax, 2
// 00464ee5  3bc8                 cmp ecx, eax
// 00464ee7  7318                 jae 0x464f01
// 00464ee9  8b4608               mov eax, dword ptr [esi + 8]
// 00464eec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00464ef0  8b11                 mov edx, dword ptr [ecx]
// 00464ef2  8910                 mov dword ptr [eax], edx
// 00464ef4  83c004               add eax, 4
// 00464ef7  894608               mov dword ptr [esi + 8], eax
// 00464efa  5e                   pop esi
// 00464efb  83c408               add esp, 8
// 00464efe  c20400               ret 4
// 00464f01  57                   push edi
// 00464f02  8b7e08               mov edi, dword ptr [esi + 8]
// 00464f05  3bd7                 cmp edx, edi
// 00464f07  7606                 jbe 0x464f0f
// 00464f09  ff15d8e67700         call dword ptr [0x77e6d8]
// 00464f0f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00464f13  50                   push eax
// 00464f14  57                   push edi
// 00464f15  56                   push esi
// 00464f16  8d4c2414             lea ecx, [esp + 0x14]
// 00464f1a  51                   push ecx
// 00464f1b  8bce                 mov ecx, esi
// 00464f1d  e8fe960800           call 0x4ee620
// 00464f22  5f                   pop edi
// 00464f23  5e                   pop esi
// 00464f24  83c408               add esp, 8
// 00464f27  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
