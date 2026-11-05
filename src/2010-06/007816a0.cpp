// from server: 100% by auto
// roc 2010-06 007816a0  unit: seg_00780000  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007816a0
//
// 007816a0  53                   push ebx
// 007816a1  56                   push esi
// 007816a2  8bf0                 mov esi, eax
// 007816a4  8b4610               mov eax, dword ptr [esi + 0x10]
// 007816a7  05fefeffff           add eax, 0xfffffefe
// 007816ac  57                   push edi
// 007816ad  8b7e04               mov edi, dword ptr [esi + 4]
// 007816b0  83f813               cmp eax, 0x13
// 007816b3  0f87e2000000         ja 0x78179b
// 007816b9  0fb680d0177800       movzx eax, byte ptr [eax + 0x7817d0]
// 007816c0  ff2485a8177800       jmp dword ptr [eax*4 + 0x7817a8]
// 007816c7  57                   push edi
// 007816c8  8bc6                 mov eax, esi
// 007816ca  e841faffff           call 0x781110
// 007816cf  83c404               add esp, 4
// 007816d2  5f                   pop edi
// 007816d3  5e                   pop esi
// 007816d4  33c0                 xor eax, eax
// 007816d6  5b                   pop ebx
// 007816d7  c3                   ret 
// 007816d8  57                   push edi
// 007816d9  8bc6                 mov eax, esi
// 007816db  e8d0efffff           call 0x7806b0
// 007816e0  83c404               add esp, 4
// 007816e3  5f                   pop edi
// 007816e4  5e                   pop esi
// 007816e5  33c0                 xor eax, eax
// 007816e7  5b                   pop ebx
// 007816e8  c3                   ret 
// 007816e9  56                   push esi
// 007816ea  e891220000           call 0x783980
// 007816ef  8bc6                 mov eax, esi
// 007816f1  e81aedffff           call 0x780410
// 007816f6  8bc7                 mov eax, edi
// 007816f8  6803010000           push 0x103
// 007816fd  bf06010000           mov edi, 0x106
// 00781702  e829d4ffff           call 0x77eb30
// 00781707  83c408               add esp, 8
// 0078170a  5f                   pop edi
// 0078170b  5e                   pop esi
// 0078170c  33c0                 xor eax, eax
// 0078170e  5b                   pop ebx
// 0078170f  c3                   ret 
// 00781710  57                   push edi
// 00781711  8bc6                 mov eax, esi
// 00781713  e858f8ffff           call 0x780f70
// 00781718  83c404               add esp, 4
// 0078171b  5f                   pop edi
// 0078171c  5e                   pop esi
// 0078171d  33c0                 xor eax, eax
// 0078171f  5b                   pop ebx
// 00781720  c3                   ret 
// 00781721  57                   push edi
// 00781722  8bde                 mov ebx, esi
// 00781724  e8b7f0ffff           call 0x7807e0
// 00781729  83c404               add esp, 4
// 0078172c  5f                   pop edi
// 0078172d  5e                   pop esi
// 0078172e  33c0                 xor eax, eax
// 00781730  5b                   pop ebx
// 00781731  c3                   ret 
// 00781732  e899fdffff           call 0x7814d0
// 00781737  5f                   pop edi
// 00781738  5e                   pop esi
// 00781739  33c0                 xor eax, eax
// 0078173b  5b                   pop ebx
// 0078173c  c3                   ret 
// 0078173d  56                   push esi
// 0078173e  e83d220000           call 0x783980
// 00781743  83c404               add esp, 4
// 00781746  817e1009010000       cmp dword ptr [esi + 0x10], 0x109
// 0078174d  7516                 jne 0x781765
// 0078174f  56                   push esi
// 00781750  e82b220000           call 0x783980
// 00781755  83c404               add esp, 4
// 00781758  8bde                 mov ebx, esi
// 0078175a  e871faffff           call 0x7811d0
// 0078175f  5f                   pop edi
// 00781760  5e                   pop esi
// 00781761  33c0                 xor eax, eax
// 00781763  5b                   pop ebx
// 00781764  c3                   ret 
// 00781765  8bc6                 mov eax, esi
// 00781767  e864fbffff           call 0x7812d0
// 0078176c  5f                   pop edi
// 0078176d  5e                   pop esi
// 0078176e  33c0                 xor eax, eax
// 00781770  5b                   pop ebx
// 00781771  c3                   ret 
// 00781772  8bc6                 mov eax, esi
// 00781774  e807feffff           call 0x781580
// 00781779  5f                   pop edi
// 0078177a  5e                   pop esi
// 0078177b  b801000000           mov eax, 1
// 00781780  5b                   pop ebx
// 00781781  c3                   ret 
// 00781782  56                   push esi
// 00781783  e8f8210000           call 0x783980
// 00781788  83c404               add esp, 4
// 0078178b  8bc6                 mov eax, esi
// 0078178d  e8beeeffff           call 0x780650
// 00781792  5f                   pop edi
// 00781793  5e                   pop esi
// 00781794  b801000000           mov eax, 1
// 00781799  5b                   pop ebx
// 0078179a  c3                   ret 
// 0078179b  8bc6                 mov eax, esi
// 0078179d  e87efdffff           call 0x781520
// 007817a2  5f                   pop edi
// 007817a3  5e                   pop esi
// 007817a4  33c0                 xor eax, eax
// 007817a6  5b                   pop ebx
// 007817a7  c3                   ret 
// 007817a8  821778               adc byte ptr [edi], 0x78
// 007817ab  00e9                 add cl, ch
// 007817ad  16                   push ss
// 007817ae  7800                 js 0x7817b0
// 007817b0  1017                 adc byte ptr [edi], dl
// 007817b2  7800                 js 0x7817b4
// 007817b4  3217                 xor dl, byte ptr [edi]
// 007817b6  7800                 js 0x7817b8
// library lua-5.1/lparser.c (function _statement)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
