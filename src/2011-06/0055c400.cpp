// from server: 100% by auto
// roc 2011-06 0055c400  unit: seg_00550000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055c400
//
// 0055c400  8b442404             mov eax, dword ptr [esp + 4]
// 0055c404  85c0                 test eax, eax
// 0055c406  7469                 je 0x55c471
// 0055c408  53                   push ebx
// 0055c409  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0055c40d  85db                 test ebx, ebx
// 0055c40f  7510                 jne 0x55c421
// 0055c411  68c42aa800           push 0xa82ac4
// 0055c416  50                   push eax
// 0055c417  e8c44f0000           call 0x5613e0
// 0055c41c  83c408               add esp, 8
// 0055c41f  5b                   pop ebx
// 0055c420  c3                   ret 
// 0055c421  81487080000000       or dword ptr [eax + 0x70], 0x80
// 0055c428  dd442418             fld qword ptr [esp + 0x18]
// 0055c42c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055c430  8b5070               mov edx, dword ptr [eax + 0x70]
// 0055c433  56                   push esi
// 0055c434  8b31                 mov esi, dword ptr [ecx]
// 0055c436  89b038010000         mov dword ptr [eax + 0x138], esi
// 0055c43c  8b7104               mov esi, dword ptr [ecx + 4]
// 0055c43f  89b03c010000         mov dword ptr [eax + 0x13c], esi
// 0055c445  668b4908             mov cx, word ptr [ecx + 8]
// 0055c449  d99834010000         fstp dword ptr [eax + 0x134]
// 0055c44f  66898840010000       mov word ptr [eax + 0x140], cx
// 0055c456  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055c45a  f7d9                 neg ecx
// 0055c45c  1bc9                 sbb ecx, ecx
// 0055c45e  81e100010000         and ecx, 0x100
// 0055c464  0bca                 or ecx, edx
// 0055c466  5e                   pop esi
// 0055c467  889830010000         mov byte ptr [eax + 0x130], bl
// 0055c46d  894870               mov dword ptr [eax + 0x70], ecx
// 0055c470  5b                   pop ebx
// 0055c471  c3                   ret 
// library libpng-1.2.16/pngrtran.c (function _png_set_background)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngrtran.c
