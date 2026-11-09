// from server: 100% by auto
// roc 2009-06 006d5ce0  unit: RBX::Mechanism  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d5ce0
//
// 006d5ce0  53                   push ebx
// 006d5ce1  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 006d5ce7  56                   push esi
// 006d5ce8  57                   push edi
// 006d5ce9  8bf9                 mov edi, ecx
// 006d5ceb  8b07                 mov eax, dword ptr [edi]
// 006d5ced  85c0                 test eax, eax
// 006d5cef  7508                 jne 0x6d5cf9
// 006d5cf1  ffd3                 call ebx
// 006d5cf3  8b07                 mov eax, dword ptr [edi]
// 006d5cf5  85c0                 test eax, eax
// 006d5cf7  7404                 je 0x6d5cfd
// 006d5cf9  8b10                 mov edx, dword ptr [eax]
// 006d5cfb  eb02                 jmp 0x6d5cff
// 006d5cfd  33d2                 xor edx, edx
// 006d5cff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006d5d03  8d34cd00000000       lea esi, [ecx*8]
// 006d5d0a  2bf1                 sub esi, ecx
// 006d5d0c  8b4f04               mov ecx, dword ptr [edi + 4]
// 006d5d0f  03f6                 add esi, esi
// 006d5d11  03f6                 add esi, esi
// 006d5d13  03ce                 add ecx, esi
// 006d5d15  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 006d5d18  770f                 ja 0x6d5d29
// 006d5d1a  85c0                 test eax, eax
// 006d5d1c  7404                 je 0x6d5d22
// 006d5d1e  8b00                 mov eax, dword ptr [eax]
// 006d5d20  eb02                 jmp 0x6d5d24
// 006d5d22  33c0                 xor eax, eax
// 006d5d24  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 006d5d27  7302                 jae 0x6d5d2b
// 006d5d29  ffd3                 call ebx
// 006d5d2b  017704               add dword ptr [edi + 4], esi
// 006d5d2e  8bc7                 mov eax, edi
// 006d5d30  5f                   pop edi
// 006d5d31  5e                   pop esi
// 006d5d32  5b                   pop ebx
// 006d5d33  c20400               ret 4
// standard library vector<string> (function ??Y?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@H@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
