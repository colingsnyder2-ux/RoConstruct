// from server: 100% by auto
// roc 2007-03 00508f90  unit: seg_00500000  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00508f90
//
// 00508f90  8b442404             mov eax, dword ptr [esp + 4]
// 00508f94  53                   push ebx
// 00508f95  55                   push ebp
// 00508f96  56                   push esi
// 00508f97  33f6                 xor esi, esi
// 00508f99  33db                 xor ebx, ebx
// 00508f9b  33ed                 xor ebp, ebp
// 00508f9d  85c0                 test eax, eax
// 00508f9f  740e                 je 0x508faf
// 00508fa1  8b30                 mov esi, dword ptr [eax]
// 00508fa3  8b9e4c020000         mov ebx, dword ptr [esi + 0x24c]
// 00508fa9  8bae44020000         mov ebp, dword ptr [esi + 0x244]
// 00508faf  8b442414             mov eax, dword ptr [esp + 0x14]
// 00508fb3  85c0                 test eax, eax
// 00508fb5  7455                 je 0x50900c
// 00508fb7  57                   push edi
// 00508fb8  8b38                 mov edi, dword ptr [eax]
// 00508fba  85ff                 test edi, edi
// 00508fbc  744d                 je 0x50900b
// 00508fbe  6aff                 push -1
// 00508fc0  68ff7f0000           push 0x7fff
// 00508fc5  57                   push edi
// 00508fc6  56                   push esi
// 00508fc7  e8b4170000           call 0x50a780
// 00508fcc  83c410               add esp, 0x10
// 00508fcf  83be2002000000       cmp dword ptr [esi + 0x220], 0
// 00508fd6  741e                 je 0x508ff6
// 00508fd8  8b8624020000         mov eax, dword ptr [esi + 0x224]
// 00508fde  50                   push eax
// 00508fdf  56                   push esi
// 00508fe0  e80b000100           call 0x518ff0
// 00508fe5  83c408               add esp, 8
// 00508fe8  33c0                 xor eax, eax
// 00508fea  898624020000         mov dword ptr [esi + 0x224], eax
// 00508ff0  898620020000         mov dword ptr [esi + 0x220], eax
// 00508ff6  55                   push ebp
// 00508ff7  53                   push ebx
// 00508ff8  57                   push edi
// 00508ff9  e832fe0000           call 0x518e30
// 00508ffe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00509002  83c40c               add esp, 0xc
// 00509005  c70100000000         mov dword ptr [ecx], 0
// 0050900b  5f                   pop edi
// 0050900c  85f6                 test esi, esi
// 0050900e  741b                 je 0x50902b
// 00509010  56                   push esi
// 00509011  e80af9ffff           call 0x508920
// 00509016  55                   push ebp
// 00509017  53                   push ebx
// 00509018  56                   push esi
// 00509019  e812fe0000           call 0x518e30
// 0050901e  8b542420             mov edx, dword ptr [esp + 0x20]
// 00509022  83c410               add esp, 0x10
// 00509025  c70200000000         mov dword ptr [edx], 0
// 0050902b  5e                   pop esi
// 0050902c  5d                   pop ebp
// 0050902d  5b                   pop ebx
// 0050902e  c3                   ret 
// library libpng-1.2.7/pngwrite.c (function _png_destroy_write_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwrite.c
