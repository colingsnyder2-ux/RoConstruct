// from server: 100% by auto
// roc 2009-12 00605f20  unit: seg_00600000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00605f20
//
// 00605f20  8b442404             mov eax, dword ptr [esp + 4]
// 00605f24  85c0                 test eax, eax
// 00605f26  7469                 je 0x605f91
// 00605f28  53                   push ebx
// 00605f29  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00605f2d  85db                 test ebx, ebx
// 00605f2f  7510                 jne 0x605f41
// 00605f31  68ec519c00           push 0x9c51ec
// 00605f36  50                   push eax
// 00605f37  e804a30000           call 0x610240
// 00605f3c  83c408               add esp, 8
// 00605f3f  5b                   pop ebx
// 00605f40  c3                   ret 
// 00605f41  81487080000000       or dword ptr [eax + 0x70], 0x80
// 00605f48  dd442418             fld qword ptr [esp + 0x18]
// 00605f4c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00605f50  8b5070               mov edx, dword ptr [eax + 0x70]
// 00605f53  56                   push esi
// 00605f54  8b31                 mov esi, dword ptr [ecx]
// 00605f56  89b038010000         mov dword ptr [eax + 0x138], esi
// 00605f5c  8b7104               mov esi, dword ptr [ecx + 4]
// 00605f5f  89b03c010000         mov dword ptr [eax + 0x13c], esi
// 00605f65  668b4908             mov cx, word ptr [ecx + 8]
// 00605f69  d99834010000         fstp dword ptr [eax + 0x134]
// 00605f6f  66898840010000       mov word ptr [eax + 0x140], cx
// 00605f76  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00605f7a  f7d9                 neg ecx
// 00605f7c  1bc9                 sbb ecx, ecx
// 00605f7e  81e100010000         and ecx, 0x100
// 00605f84  0bca                 or ecx, edx
// 00605f86  5e                   pop esi
// 00605f87  889830010000         mov byte ptr [eax + 0x130], bl
// 00605f8d  894870               mov dword ptr [eax + 0x70], ecx
// 00605f90  5b                   pop ebx
// 00605f91  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
