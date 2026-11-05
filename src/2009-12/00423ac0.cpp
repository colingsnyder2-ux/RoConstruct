// from server: 100% by auto
// roc 2009-12 00423ac0  unit: LogManager  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00423ac0
//
// 00423ac0  53                   push ebx
// 00423ac1  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00423ac7  56                   push esi
// 00423ac8  57                   push edi
// 00423ac9  8bf9                 mov edi, ecx
// 00423acb  8b07                 mov eax, dword ptr [edi]
// 00423acd  85c0                 test eax, eax
// 00423acf  7508                 jne 0x423ad9
// 00423ad1  ffd3                 call ebx
// 00423ad3  8b07                 mov eax, dword ptr [edi]
// 00423ad5  85c0                 test eax, eax
// 00423ad7  7404                 je 0x423add
// 00423ad9  8b10                 mov edx, dword ptr [eax]
// 00423adb  eb02                 jmp 0x423adf
// 00423add  33d2                 xor edx, edx
// 00423adf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00423ae3  8d34cd00000000       lea esi, [ecx*8]
// 00423aea  2bf1                 sub esi, ecx
// 00423aec  8b4f04               mov ecx, dword ptr [edi + 4]
// 00423aef  03f6                 add esi, esi
// 00423af1  03f6                 add esi, esi
// 00423af3  03ce                 add ecx, esi
// 00423af5  3b4a10               cmp ecx, dword ptr [edx + 0x10]
// 00423af8  770f                 ja 0x423b09
// 00423afa  85c0                 test eax, eax
// 00423afc  7404                 je 0x423b02
// 00423afe  8b00                 mov eax, dword ptr [eax]
// 00423b00  eb02                 jmp 0x423b04
// 00423b02  33c0                 xor eax, eax
// 00423b04  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 00423b07  7302                 jae 0x423b0b
// 00423b09  ffd3                 call ebx
// 00423b0b  017704               add dword ptr [edi + 4], esi
// 00423b0e  8bc7                 mov eax, edi
// 00423b10  5f                   pop edi
// 00423b11  5e                   pop esi
// 00423b12  5b                   pop ebx
// 00423b13  c20400               ret 4
// standard library vector<string> (function ??Y?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEAAV01@H@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
