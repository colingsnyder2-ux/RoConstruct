// from server: 100% by auto
// roc 2010-06 0063aa80  unit: RBX::VBasicPartInstance::?$ActionStation  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0063aa80
//
// 0063aa80  83ec08               sub esp, 8
// 0063aa83  56                   push esi
// 0063aa84  8bf1                 mov esi, ecx
// 0063aa86  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0063aa89  57                   push edi
// 0063aa8a  85c9                 test ecx, ecx
// 0063aa8c  7504                 jne 0x63aa92
// 0063aa8e  33c0                 xor eax, eax
// 0063aa90  eb08                 jmp 0x63aa9a
// 0063aa92  8b4614               mov eax, dword ptr [esi + 0x14]
// 0063aa95  2bc1                 sub eax, ecx
// 0063aa97  c1f803               sar eax, 3
// 0063aa9a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0063aa9d  8bd7                 mov edx, edi
// 0063aa9f  2bd1                 sub edx, ecx
// 0063aaa1  c1fa03               sar edx, 3
// 0063aaa4  3bd0                 cmp edx, eax
// 0063aaa6  7331                 jae 0x63aad9
// 0063aaa8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0063aaac  c644240800           mov byte ptr [esp + 8], 0
// 0063aab1  8b442408             mov eax, dword ptr [esp + 8]
// 0063aab5  50                   push eax
// 0063aab6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0063aaba  51                   push ecx
// 0063aabb  8d5608               lea edx, [esi + 8]
// 0063aabe  52                   push edx
// 0063aabf  50                   push eax
// 0063aac0  6a01                 push 1
// 0063aac2  57                   push edi
// 0063aac3  e8588f1200           call 0x763a20
// 0063aac8  83c418               add esp, 0x18
// 0063aacb  83c708               add edi, 8
// 0063aace  897e10               mov dword ptr [esi + 0x10], edi
// 0063aad1  5f                   pop edi
// 0063aad2  5e                   pop esi
// 0063aad3  83c408               add esp, 8
// 0063aad6  c20400               ret 4
// 0063aad9  3bcf                 cmp ecx, edi
// 0063aadb  7606                 jbe 0x63aae3
// 0063aadd  ff150ca99e00         call dword ptr [0x9ea90c]
// 0063aae3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0063aae7  8b06                 mov eax, dword ptr [esi]
// 0063aae9  51                   push ecx
// 0063aaea  57                   push edi
// 0063aaeb  50                   push eax
// 0063aaec  8d542414             lea edx, [esp + 0x14]
// 0063aaf0  52                   push edx
// 0063aaf1  8bce                 mov ecx, esi
// 0063aaf3  e878feffff           call 0x63a970
// 0063aaf8  5f                   pop edi
// 0063aaf9  5e                   pop esi
// 0063aafa  83c408               add esp, 8
// 0063aafd  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
