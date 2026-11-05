// from server: 100% by auto
// roc 2011-06 005595c0  unit: seg_00550000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005595c0
//
// 005595c0  53                   push ebx
// 005595c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005595c5  85db                 test ebx, ebx
// 005595c7  744b                 je 0x559614
// 005595c9  53                   push ebx
// 005595ca  e8b1290000           call 0x55bf80
// 005595cf  83c404               add esp, 4
// 005595d2  85c0                 test eax, eax
// 005595d4  7e3e                 jle 0x559614
// 005595d6  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 005595dc  55                   push ebp
// 005595dd  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005595e1  56                   push esi
// 005595e2  57                   push edi
// 005595e3  89442414             mov dword ptr [esp + 0x14], eax
// 005595e7  33f6                 xor esi, esi
// 005595e9  8bfd                 mov edi, ebp
// 005595eb  85c9                 test ecx, ecx
// 005595ed  761b                 jbe 0x55960a
// 005595ef  90                   nop 
// 005595f0  8b07                 mov eax, dword ptr [edi]
// 005595f2  50                   push eax
// 005595f3  53                   push ebx
// 005595f4  e847f6ffff           call 0x558c40
// 005595f9  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 005595ff  46                   inc esi
// 00559600  83c408               add esp, 8
// 00559603  83c704               add edi, 4
// 00559606  3bf1                 cmp esi, ecx
// 00559608  72e6                 jb 0x5595f0
// 0055960a  836c241401           sub dword ptr [esp + 0x14], 1
// 0055960f  75d6                 jne 0x5595e7
// 00559611  5f                   pop edi
// 00559612  5e                   pop esi
// 00559613  5d                   pop ebp
// 00559614  5b                   pop ebx
// 00559615  c3                   ret 
// library libpng-1.2.10/pngwrite.c (function _png_write_image)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwrite.c
