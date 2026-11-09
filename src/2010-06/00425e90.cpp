// from server: 100% by auto
// roc 2010-06 00425e90  unit: MainLogManager  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425e90
//
// 00425e90  83ec08               sub esp, 8
// 00425e93  53                   push ebx
// 00425e94  55                   push ebp
// 00425e95  56                   push esi
// 00425e96  57                   push edi
// 00425e97  8bf9                 mov edi, ecx
// 00425e99  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00425e9c  85ed                 test ebp, ebp
// 00425e9e  7504                 jne 0x425ea4
// 00425ea0  33f6                 xor esi, esi
// 00425ea2  eb18                 jmp 0x425ebc
// 00425ea4  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00425ea7  2bcd                 sub ecx, ebp
// 00425ea9  b893244992           mov eax, 0x92492493
// 00425eae  f7e9                 imul ecx
// 00425eb0  03d1                 add edx, ecx
// 00425eb2  c1fa04               sar edx, 4
// 00425eb5  8bf2                 mov esi, edx
// 00425eb7  c1ee1f               shr esi, 0x1f
// 00425eba  03f2                 add esi, edx
// 00425ebc  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00425ebf  8bcb                 mov ecx, ebx
// 00425ec1  2bcd                 sub ecx, ebp
// 00425ec3  b893244992           mov eax, 0x92492493
// 00425ec8  f7e9                 imul ecx
// 00425eca  03d1                 add edx, ecx
// 00425ecc  c1fa04               sar edx, 4
// 00425ecf  8bc2                 mov eax, edx
// 00425ed1  c1e81f               shr eax, 0x1f
// 00425ed4  03c2                 add eax, edx
// 00425ed6  3bc6                 cmp eax, esi
// 00425ed8  7333                 jae 0x425f0d
// 00425eda  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00425ede  c644241000           mov byte ptr [esp + 0x10], 0
// 00425ee3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00425ee7  51                   push ecx
// 00425ee8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00425eec  52                   push edx
// 00425eed  8d4708               lea eax, [edi + 8]
// 00425ef0  50                   push eax
// 00425ef1  51                   push ecx
// 00425ef2  6a01                 push 1
// 00425ef4  53                   push ebx
// 00425ef5  e8c6f1ffff           call 0x4250c0
// 00425efa  83c418               add esp, 0x18
// 00425efd  83c31c               add ebx, 0x1c
// 00425f00  895f10               mov dword ptr [edi + 0x10], ebx
// 00425f03  5f                   pop edi
// 00425f04  5e                   pop esi
// 00425f05  5d                   pop ebp
// 00425f06  5b                   pop ebx
// 00425f07  83c408               add esp, 8
// 00425f0a  c20400               ret 4
// 00425f0d  3beb                 cmp ebp, ebx
// 00425f0f  7606                 jbe 0x425f17
// 00425f11  ff150ca99e00         call dword ptr [0x9ea90c]
// 00425f17  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00425f1b  8b07                 mov eax, dword ptr [edi]
// 00425f1d  52                   push edx
// 00425f1e  53                   push ebx
// 00425f1f  50                   push eax
// 00425f20  8d44241c             lea eax, [esp + 0x1c]
// 00425f24  50                   push eax
// 00425f25  8bcf                 mov ecx, edi
// 00425f27  e8c4fbffff           call 0x425af0
// 00425f2c  5f                   pop edi
// 00425f2d  5e                   pop esi
// 00425f2e  5d                   pop ebp
// 00425f2f  5b                   pop ebx
// 00425f30  83c408               add esp, 8
// 00425f33  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
