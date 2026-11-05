// from server: 100% by auto
// roc 2012-06 00649280  unit: seg_00640000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00649280
//
// 00649280  8b442404             mov eax, dword ptr [esp + 4]
// 00649284  85c0                 test eax, eax
// 00649286  7469                 je 0x6492f1
// 00649288  53                   push ebx
// 00649289  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0064928d  85db                 test ebx, ebx
// 0064928f  7510                 jne 0x6492a1
// 00649291  687469b800           push 0xb86974
// 00649296  50                   push eax
// 00649297  e8c44f0000           call 0x64e260
// 0064929c  83c408               add esp, 8
// 0064929f  5b                   pop ebx
// 006492a0  c3                   ret 
// 006492a1  81487080000000       or dword ptr [eax + 0x70], 0x80
// 006492a8  dd442418             fld qword ptr [esp + 0x18]
// 006492ac  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006492b0  8b5070               mov edx, dword ptr [eax + 0x70]
// 006492b3  56                   push esi
// 006492b4  8b31                 mov esi, dword ptr [ecx]
// 006492b6  89b038010000         mov dword ptr [eax + 0x138], esi
// 006492bc  8b7104               mov esi, dword ptr [ecx + 4]
// 006492bf  89b03c010000         mov dword ptr [eax + 0x13c], esi
// 006492c5  668b4908             mov cx, word ptr [ecx + 8]
// 006492c9  d99834010000         fstp dword ptr [eax + 0x134]
// 006492cf  66898840010000       mov word ptr [eax + 0x140], cx
// 006492d6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006492da  f7d9                 neg ecx
// 006492dc  1bc9                 sbb ecx, ecx
// 006492de  81e100010000         and ecx, 0x100
// 006492e4  0bca                 or ecx, edx
// 006492e6  5e                   pop esi
// 006492e7  889830010000         mov byte ptr [eax + 0x130], bl
// 006492ed  894870               mov dword ptr [eax + 0x70], ecx
// 006492f0  5b                   pop ebx
// 006492f1  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
