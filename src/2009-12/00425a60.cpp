// from server: 100% by auto
// roc 2009-12 00425a60  unit: MainLogManager  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425a60
//
// 00425a60  83ec08               sub esp, 8
// 00425a63  53                   push ebx
// 00425a64  55                   push ebp
// 00425a65  56                   push esi
// 00425a66  57                   push edi
// 00425a67  8bf9                 mov edi, ecx
// 00425a69  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00425a6c  85ed                 test ebp, ebp
// 00425a6e  7504                 jne 0x425a74
// 00425a70  33f6                 xor esi, esi
// 00425a72  eb18                 jmp 0x425a8c
// 00425a74  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00425a77  2bcd                 sub ecx, ebp
// 00425a79  b893244992           mov eax, 0x92492493
// 00425a7e  f7e9                 imul ecx
// 00425a80  03d1                 add edx, ecx
// 00425a82  c1fa04               sar edx, 4
// 00425a85  8bf2                 mov esi, edx
// 00425a87  c1ee1f               shr esi, 0x1f
// 00425a8a  03f2                 add esi, edx
// 00425a8c  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00425a8f  8bcb                 mov ecx, ebx
// 00425a91  2bcd                 sub ecx, ebp
// 00425a93  b893244992           mov eax, 0x92492493
// 00425a98  f7e9                 imul ecx
// 00425a9a  03d1                 add edx, ecx
// 00425a9c  c1fa04               sar edx, 4
// 00425a9f  8bc2                 mov eax, edx
// 00425aa1  c1e81f               shr eax, 0x1f
// 00425aa4  03c2                 add eax, edx
// 00425aa6  3bc6                 cmp eax, esi
// 00425aa8  7333                 jae 0x425add
// 00425aaa  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00425aae  c644241000           mov byte ptr [esp + 0x10], 0
// 00425ab3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00425ab7  51                   push ecx
// 00425ab8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00425abc  52                   push edx
// 00425abd  8d4708               lea eax, [edi + 8]
// 00425ac0  50                   push eax
// 00425ac1  51                   push ecx
// 00425ac2  6a01                 push 1
// 00425ac4  53                   push ebx
// 00425ac5  e8c6f1ffff           call 0x424c90
// 00425aca  83c418               add esp, 0x18
// 00425acd  83c31c               add ebx, 0x1c
// 00425ad0  895f10               mov dword ptr [edi + 0x10], ebx
// 00425ad3  5f                   pop edi
// 00425ad4  5e                   pop esi
// 00425ad5  5d                   pop ebp
// 00425ad6  5b                   pop ebx
// 00425ad7  83c408               add esp, 8
// 00425ada  c20400               ret 4
// 00425add  3beb                 cmp ebp, ebx
// 00425adf  7606                 jbe 0x425ae7
// 00425ae1  ff1560b79800         call dword ptr [0x98b760]
// 00425ae7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00425aeb  8b07                 mov eax, dword ptr [edi]
// 00425aed  52                   push edx
// 00425aee  53                   push ebx
// 00425aef  50                   push eax
// 00425af0  8d44241c             lea eax, [esp + 0x1c]
// 00425af4  50                   push eax
// 00425af5  8bcf                 mov ecx, edi
// 00425af7  e8c4fbffff           call 0x4256c0
// 00425afc  5f                   pop edi
// 00425afd  5e                   pop esi
// 00425afe  5d                   pop ebp
// 00425aff  5b                   pop ebx
// 00425b00  83c408               add esp, 8
// 00425b03  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
