// from server: 100% by auto
// roc 2007-03 0050a670  unit: seg_00500000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a670
//
// 0050a670  53                   push ebx
// 0050a671  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0050a675  83c8ff               or eax, 0xffffffff
// 0050a678  33d2                 xor edx, edx
// 0050a67a  f7f3                 div ebx
// 0050a67c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0050a680  56                   push esi
// 0050a681  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0050a685  57                   push edi
// 0050a686  8b7e6c               mov edi, dword ptr [esi + 0x6c]
// 0050a689  3bc8                 cmp ecx, eax
// 0050a68b  7614                 jbe 0x50a6a1
// 0050a68d  6840107a00           push 0x7a1040
// 0050a692  56                   push esi
// 0050a693  e838dd0000           call 0x5183d0
// 0050a698  83c408               add esp, 8
// 0050a69b  5f                   pop edi
// 0050a69c  5e                   pop esi
// 0050a69d  33c0                 xor eax, eax
// 0050a69f  5b                   pop ebx
// 0050a6a0  c3                   ret 
// 0050a6a1  0fafcb               imul ecx, ebx
// 0050a6a4  8bc7                 mov eax, edi
// 0050a6a6  51                   push ecx
// 0050a6a7  0d00001000           or eax, 0x100000
// 0050a6ac  56                   push esi
// 0050a6ad  89466c               mov dword ptr [esi + 0x6c], eax
// 0050a6b0  e8ebe80000           call 0x518fa0
// 0050a6b5  83c408               add esp, 8
// 0050a6b8  897e6c               mov dword ptr [esi + 0x6c], edi
// 0050a6bb  5f                   pop edi
// 0050a6bc  5e                   pop esi
// 0050a6bd  5b                   pop ebx
// 0050a6be  c3                   ret 
// library libpng-1.2.7/png.c (function _png_zalloc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
