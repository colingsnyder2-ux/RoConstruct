// from server: 100% by auto
// roc 2008-06 00427e50  unit: RobloxCrashReporter  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00427e50
//
// 00427e50  53                   push ebx
// 00427e51  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00427e57  56                   push esi
// 00427e58  57                   push edi
// 00427e59  8bf9                 mov edi, ecx
// 00427e5b  8b07                 mov eax, dword ptr [edi]
// 00427e5d  85c0                 test eax, eax
// 00427e5f  7508                 jne 0x427e69
// 00427e61  ffd3                 call ebx
// 00427e63  8b07                 mov eax, dword ptr [edi]
// 00427e65  85c0                 test eax, eax
// 00427e67  7404                 je 0x427e6d
// 00427e69  8b10                 mov edx, dword ptr [eax]
// 00427e6b  eb02                 jmp 0x427e6f
// 00427e6d  33d2                 xor edx, edx
// 00427e6f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00427e73  8d34cd00000000       lea esi, [ecx*8]
// 00427e7a  2bf1                 sub esi, ecx
// 00427e7c  8b4f04               mov ecx, dword ptr [edi + 4]
// 00427e7f  03f6                 add esi, esi
// 00427e81  03f6                 add esi, esi
// 00427e83  03ce                 add ecx, esi
// 00427e85  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 00427e88  770f                 ja 0x427e99
// 00427e8a  85c0                 test eax, eax
// 00427e8c  7404                 je 0x427e92
// 00427e8e  8b00                 mov eax, dword ptr [eax]
// 00427e90  eb02                 jmp 0x427e94
// 00427e92  33c0                 xor eax, eax
// 00427e94  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00427e97  7302                 jae 0x427e9b
// 00427e99  ffd3                 call ebx
// 00427e9b  017704               add dword ptr [edi + 4], esi
// 00427e9e  8bc7                 mov eax, edi
// 00427ea0  5f                   pop edi
// 00427ea1  5e                   pop esi
// 00427ea2  5b                   pop ebx
// 00427ea3  c20400               ret 4
// standard library vector<string> (function ??Y?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@H@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
