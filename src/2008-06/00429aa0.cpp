// from server: 100% by auto
// roc 2008-06 00429aa0  unit: ThreadLogManager  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00429aa0
//
// 00429aa0  83ec08               sub esp, 8
// 00429aa3  53                   push ebx
// 00429aa4  55                   push ebp
// 00429aa5  56                   push esi
// 00429aa6  57                   push edi
// 00429aa7  8bf9                 mov edi, ecx
// 00429aa9  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 00429aac  85ed                 test ebp, ebp
// 00429aae  7504                 jne 0x429ab4
// 00429ab0  33f6                 xor esi, esi
// 00429ab2  eb18                 jmp 0x429acc
// 00429ab4  8b4f14               mov ecx, dword ptr [edi + 0x14]
// 00429ab7  2bcd                 sub ecx, ebp
// 00429ab9  b893244992           mov eax, 0x92492493
// 00429abe  f7e9                 imul ecx
// 00429ac0  03d1                 add edx, ecx
// 00429ac2  c1fa04               sar edx, 4
// 00429ac5  8bf2                 mov esi, edx
// 00429ac7  c1ee1f               shr esi, 0x1f
// 00429aca  03f2                 add esi, edx
// 00429acc  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 00429acf  8bcb                 mov ecx, ebx
// 00429ad1  2bcd                 sub ecx, ebp
// 00429ad3  b893244992           mov eax, 0x92492493
// 00429ad8  f7e9                 imul ecx
// 00429ada  03d1                 add edx, ecx
// 00429adc  c1fa04               sar edx, 4
// 00429adf  8bc2                 mov eax, edx
// 00429ae1  c1e81f               shr eax, 0x1f
// 00429ae4  03c2                 add eax, edx
// 00429ae6  3bc6                 cmp eax, esi
// 00429ae8  7333                 jae 0x429b1d
// 00429aea  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00429aee  c644241000           mov byte ptr [esp + 0x10], 0
// 00429af3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00429af7  51                   push ecx
// 00429af8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00429afc  52                   push edx
// 00429afd  8d4708               lea eax, [edi + 8]
// 00429b00  50                   push eax
// 00429b01  51                   push ecx
// 00429b02  6a01                 push 1
// 00429b04  53                   push ebx
// 00429b05  e8a6f4ffff           call 0x428fb0
// 00429b0a  83c418               add esp, 0x18
// 00429b0d  83c31c               add ebx, 0x1c
// 00429b10  895f10               mov dword ptr [edi + 0x10], ebx
// 00429b13  5f                   pop edi
// 00429b14  5e                   pop esi
// 00429b15  5d                   pop ebp
// 00429b16  5b                   pop ebx
// 00429b17  83c408               add esp, 8
// 00429b1a  c20400               ret 4
// 00429b1d  3beb                 cmp ebp, ebx
// 00429b1f  7606                 jbe 0x429b27
// 00429b21  ff1590288000         call dword ptr [0x802890]
// 00429b27  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00429b2b  8b07                 mov eax, dword ptr [edi]
// 00429b2d  52                   push edx
// 00429b2e  53                   push ebx
// 00429b2f  50                   push eax
// 00429b30  8d44241c             lea eax, [esp + 0x1c]
// 00429b34  50                   push eax
// 00429b35  8bcf                 mov ecx, edi
// 00429b37  e834fdffff           call 0x429870
// 00429b3c  5f                   pop edi
// 00429b3d  5e                   pop esi
// 00429b3e  5d                   pop ebp
// 00429b3f  5b                   pop ebx
// 00429b40  83c408               add esp, 8
// 00429b43  c20400               ret 4
// standard library vector<string> (function ?push_back@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
