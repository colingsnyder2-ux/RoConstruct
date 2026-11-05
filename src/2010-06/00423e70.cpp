// from server: 100% by auto
// roc 2010-06 00423e70  unit: LogManager  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00423e70
//
// 00423e70  53                   push ebx
// 00423e71  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00423e77  56                   push esi
// 00423e78  57                   push edi
// 00423e79  8bf9                 mov edi, ecx
// 00423e7b  8b07                 mov eax, dword ptr [edi]
// 00423e7d  85c0                 test eax, eax
// 00423e7f  7508                 jne 0x423e89
// 00423e81  ffd3                 call ebx
// 00423e83  8b07                 mov eax, dword ptr [edi]
// 00423e85  85c0                 test eax, eax
// 00423e87  7404                 je 0x423e8d
// 00423e89  8b10                 mov edx, dword ptr [eax]
// 00423e8b  eb02                 jmp 0x423e8f
// 00423e8d  33d2                 xor edx, edx
// 00423e8f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00423e93  8d34cd00000000       lea esi, [ecx*8]
// 00423e9a  2bf1                 sub esi, ecx
// 00423e9c  8b4f04               mov ecx, dword ptr [edi + 4]
// 00423e9f  03f6                 add esi, esi
// 00423ea1  03f6                 add esi, esi
// 00423ea3  03ce                 add ecx, esi
// 00423ea5  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 00423ea8  770f                 ja 0x423eb9
// 00423eaa  85c0                 test eax, eax
// 00423eac  7404                 je 0x423eb2
// 00423eae  8b00                 mov eax, dword ptr [eax]
// 00423eb0  eb02                 jmp 0x423eb4
// 00423eb2  33c0                 xor eax, eax
// 00423eb4  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00423eb7  7302                 jae 0x423ebb
// 00423eb9  ffd3                 call ebx
// 00423ebb  017704               add dword ptr [edi + 4], esi
// 00423ebe  8bc7                 mov eax, edi
// 00423ec0  5f                   pop edi
// 00423ec1  5e                   pop esi
// 00423ec2  5b                   pop ebx
// 00423ec3  c20400               ret 4
// standard library vector<string> (function ??Y?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@H@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
