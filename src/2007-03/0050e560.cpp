// from server: 100% by auto
// roc 2007-03 0050e560  unit: seg_00500000  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050e560
//
// 0050e560  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0050e564  85d2                 test edx, edx
// 0050e566  8b442404             mov eax, dword ptr [esp + 4]
// 0050e56a  750f                 jne 0x50e57b
// 0050e56c  6868267a00           push 0x7a2668
// 0050e571  50                   push eax
// 0050e572  e8599e0000           call 0x5183d0
// 0050e577  83c408               add esp, 8
// 0050e57a  c3                   ret 
// 0050e57b  81487080000000       or dword ptr [eax + 0x70], 0x80
// 0050e582  dd442414             fld qword ptr [esp + 0x14]
// 0050e586  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050e58a  56                   push esi
// 0050e58b  8b7070               mov esi, dword ptr [eax + 0x70]
// 0050e58e  57                   push edi
// 0050e58f  8b39                 mov edi, dword ptr [ecx]
// 0050e591  89b838010000         mov dword ptr [eax + 0x138], edi
// 0050e597  8b7904               mov edi, dword ptr [ecx + 4]
// 0050e59a  89b83c010000         mov dword ptr [eax + 0x13c], edi
// 0050e5a0  668b7908             mov di, word ptr [ecx + 8]
// 0050e5a4  d99834010000         fstp dword ptr [eax + 0x134]
// 0050e5aa  6689b840010000       mov word ptr [eax + 0x140], di
// 0050e5b1  889030010000         mov byte ptr [eax + 0x130], dl
// 0050e5b7  8b542418             mov edx, dword ptr [esp + 0x18]
// 0050e5bb  8bfa                 mov edi, edx
// 0050e5bd  f7df                 neg edi
// 0050e5bf  1bff                 sbb edi, edi
// 0050e5c1  81e700010000         and edi, 0x100
// 0050e5c7  0bfe                 or edi, esi
// 0050e5c9  85d2                 test edx, edx
// 0050e5cb  897870               mov dword ptr [eax + 0x70], edi
// 0050e5ce  5f                   pop edi
// 0050e5cf  5e                   pop esi
// 0050e5d0  740a                 je 0x50e5dc
// 0050e5d2  f6802601000002       test byte ptr [eax + 0x126], 2
// 0050e5d9  7411                 je 0x50e5ec
// 0050e5db  c3                   ret 
// 0050e5dc  0fb75102             movzx edx, word ptr [ecx + 2]
// 0050e5e0  663b5104             cmp dx, word ptr [ecx + 4]
// 0050e5e4  750d                 jne 0x50e5f3
// 0050e5e6  663b5106             cmp dx, word ptr [ecx + 6]
// 0050e5ea  7507                 jne 0x50e5f3
// 0050e5ec  81486800080000       or dword ptr [eax + 0x68], 0x800
// 0050e5f3  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_set_background)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
