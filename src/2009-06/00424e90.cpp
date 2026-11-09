// from server: 100% by auto
// roc 2009-06 00424e90  unit: MainLogManager  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424e90
//
// 00424e90  83ec08               sub esp, 8
// 00424e93  53                   push ebx
// 00424e94  55                   push ebp
// 00424e95  56                   push esi
// 00424e96  57                   push edi
// 00424e97  8bf9                 mov edi, ecx
// 00424e99  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00424e9c  85ed                 test ebp, ebp
// 00424e9e  7504                 jne 0x424ea4
// 00424ea0  33f6                 xor esi, esi
// 00424ea2  eb18                 jmp 0x424ebc
// 00424ea4  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00424ea7  2bcd                 sub ecx, ebp
// 00424ea9  b893244992           mov eax, 0x92492493
// 00424eae  f7e9                 imul ecx
// 00424eb0  03d1                 add edx, ecx
// 00424eb2  c1fa04               sar edx, 4
// 00424eb5  8bf2                 mov esi, edx
// 00424eb7  c1ee1f               shr esi, 0x1f
// 00424eba  03f2                 add esi, edx
// 00424ebc  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00424ebf  8bcb                 mov ecx, ebx
// 00424ec1  2bcd                 sub ecx, ebp
// 00424ec3  b893244992           mov eax, 0x92492493
// 00424ec8  f7e9                 imul ecx
// 00424eca  03d1                 add edx, ecx
// 00424ecc  c1fa04               sar edx, 4
// 00424ecf  8bc2                 mov eax, edx
// 00424ed1  c1e81f               shr eax, 0x1f
// 00424ed4  03c2                 add eax, edx
// 00424ed6  3bc6                 cmp eax, esi
// 00424ed8  7333                 jae 0x424f0d
// 00424eda  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00424ede  c644241000           mov byte ptr [esp + 0x10], 0
// 00424ee3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00424ee7  51                   push ecx
// 00424ee8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00424eec  52                   push edx
// 00424eed  8d4708               lea eax, [edi + 8]
// 00424ef0  50                   push eax
// 00424ef1  51                   push ecx
// 00424ef2  6a01                 push 1
// 00424ef4  53                   push ebx
// 00424ef5  e896f4ffff           call 0x424390
// 00424efa  83c418               add esp, 0x18
// 00424efd  83c31c               add ebx, 0x1c
// 00424f00  895f10               mov dword ptr [edi + 0x10], ebx
// 00424f03  5f                   pop edi
// 00424f04  5e                   pop esi
// 00424f05  5d                   pop ebp
// 00424f06  5b                   pop ebx
// 00424f07  83c408               add esp, 8
// 00424f0a  c20400               ret 4
// 00424f0d  3beb                 cmp ebp, ebx
// 00424f0f  7606                 jbe 0x424f17
// 00424f11  ff15ace98900         call dword ptr [0x89e9ac]
// 00424f17  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00424f1b  8b07                 mov eax, dword ptr [edi]
// 00424f1d  52                   push edx
// 00424f1e  53                   push ebx
// 00424f1f  50                   push eax
// 00424f20  8d44241c             lea eax, [esp + 0x1c]
// 00424f24  50                   push eax
// 00424f25  8bcf                 mov ecx, edi
// 00424f27  e8c4fbffff           call 0x424af0
// 00424f2c  5f                   pop edi
// 00424f2d  5e                   pop esi
// 00424f2e  5d                   pop ebp
// 00424f2f  5b                   pop ebx
// 00424f30  83c408               add esp, 8
// 00424f33  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
