// from server: 100% by auto
// roc 2010-06 005678a0  unit: seg_00560000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005678a0
//
// 005678a0  8b442404             mov eax, dword ptr [esp + 4]
// 005678a4  85c0                 test eax, eax
// 005678a6  7469                 je 0x567911
// 005678a8  53                   push ebx
// 005678a9  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005678ad  85db                 test ebx, ebx
// 005678af  7510                 jne 0x5678c1
// 005678b1  684c2fa200           push 0xa22f4c
// 005678b6  50                   push eax
// 005678b7  e8a4a20000           call 0x571b60
// 005678bc  83c408               add esp, 8
// 005678bf  5b                   pop ebx
// 005678c0  c3                   ret 
// 005678c1  81487080000000       or dword ptr [eax + 0x70], 0x80
// 005678c8  dd442418             fld qword ptr [esp + 0x18]
// 005678cc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005678d0  8b5070               mov edx, dword ptr [eax + 0x70]
// 005678d3  56                   push esi
// 005678d4  8b31                 mov esi, dword ptr [ecx]
// 005678d6  89b038010000         mov dword ptr [eax + 0x138], esi
// 005678dc  8b7104               mov esi, dword ptr [ecx + 4]
// 005678df  89b03c010000         mov dword ptr [eax + 0x13c], esi
// 005678e5  668b4908             mov cx, word ptr [ecx + 8]
// 005678e9  d99834010000         fstp dword ptr [eax + 0x134]
// 005678ef  66898840010000       mov word ptr [eax + 0x140], cx
// 005678f6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005678fa  f7d9                 neg ecx
// 005678fc  1bc9                 sbb ecx, ecx
// 005678fe  81e100010000         and ecx, 0x100
// 00567904  0bca                 or ecx, edx
// 00567906  5e                   pop esi
// 00567907  889830010000         mov byte ptr [eax + 0x130], bl
// 0056790d  894870               mov dword ptr [eax + 0x70], ecx
// 00567910  5b                   pop ebx
// 00567911  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
