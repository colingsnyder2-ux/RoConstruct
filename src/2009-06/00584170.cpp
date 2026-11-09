// from server: 100% by auto
// roc 2009-06 00584170  unit: seg_00580000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00584170
//
// 00584170  8b442404             mov eax, dword ptr [esp + 4]
// 00584174  85c0                 test eax, eax
// 00584176  7469                 je 0x5841e1
// 00584178  53                   push ebx
// 00584179  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0058417d  85db                 test ebx, ebx
// 0058417f  7510                 jne 0x584191
// 00584181  684ce38c00           push 0x8ce34c
// 00584186  50                   push eax
// 00584187  e884a00000           call 0x58e210
// 0058418c  83c408               add esp, 8
// 0058418f  5b                   pop ebx
// 00584190  c3                   ret 
// 00584191  81487080000000       or dword ptr [eax + 0x70], 0x80
// 00584198  dd442418             fld qword ptr [esp + 0x18]
// 0058419c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005841a0  8b5070               mov edx, dword ptr [eax + 0x70]
// 005841a3  56                   push esi
// 005841a4  8b31                 mov esi, dword ptr [ecx]
// 005841a6  89b038010000         mov dword ptr [eax + 0x138], esi
// 005841ac  8b7104               mov esi, dword ptr [ecx + 4]
// 005841af  89b03c010000         mov dword ptr [eax + 0x13c], esi
// 005841b5  668b4908             mov cx, word ptr [ecx + 8]
// 005841b9  d99834010000         fstp dword ptr [eax + 0x134]
// 005841bf  66898840010000       mov word ptr [eax + 0x140], cx
// 005841c6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005841ca  f7d9                 neg ecx
// 005841cc  1bc9                 sbb ecx, ecx
// 005841ce  81e100010000         and ecx, 0x100
// 005841d4  0bca                 or ecx, edx
// 005841d6  5e                   pop esi
// 005841d7  889830010000         mov byte ptr [eax + 0x130], bl
// 005841dd  894870               mov dword ptr [eax + 0x70], ecx
// 005841e0  5b                   pop ebx
// 005841e1  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
