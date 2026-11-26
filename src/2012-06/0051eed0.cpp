// from server: 100% by Xemicl
// roc 2012-06 0051eed0  unit: RBX::Network::P8Player::?$GetSetImpl  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051eed0
//
// 0051eed0  53                   push ebx
// 0051eed1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0051eed5  56                   push esi
// 0051eed6  57                   push edi
// 0051eed7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0051eedb  2bfb                 sub edi, ebx
// 0051eedd  8bc7                 mov eax, edi
// 0051eedf  99                   cdq 
// 0051eee0  2bc2                 sub eax, edx
// 0051eee2  8bf0                 mov esi, eax
// 0051eee4  d1fe                 sar esi, 1
// 0051eee6  85f6                 test esi, esi
// 0051eee8  7e1c                 jle 0x51ef06
// 0051eeea  8d9b00000000         lea ebx, [ebx]
// 0051eef0  0fb6441eff           movzx eax, byte ptr [esi + ebx - 1]
// 0051eef5  4e                   dec esi
// 0051eef6  50                   push eax
// 0051eef7  57                   push edi
// 0051eef8  56                   push esi
// 0051eef9  53                   push ebx
// 0051eefa  e8f1e9ffff           call 0x51d8f0
// 0051eeff  83c410               add esp, 0x10
// 0051ef02  85f6                 test esi, esi
// 0051ef04  7fea                 jg 0x51eef0
// 0051ef06  5f                   pop edi
// 0051ef07  5e                   pop esi
// 0051ef08  5b                   pop ebx
// 0051ef09  c3                   ret 
// copied from an identical function in another client (function ??$_Make_heap@PAEHE@std@@YAXPAE0PAH0@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <algorithm>
template void std::_Make_heap<unsigned char*, int, unsigned char>(unsigned char*, unsigned char*, int*, unsigned char*);