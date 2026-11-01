// from server: 100% by auto
// roc 2007-03 0050a4f0  unit: seg_00500000  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050a4f0
//
// 0050a4f0  56                   push esi
// 0050a4f1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0050a4f5  83fe08               cmp esi, 8
// 0050a4f8  57                   push edi
// 0050a4f9  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0050a4fd  7e0e                 jle 0x50a50d
// 0050a4ff  681c107a00           push 0x7a101c
// 0050a504  57                   push edi
// 0050a505  e816de0000           call 0x518320
// 0050a50a  83c408               add esp, 8
// 0050a50d  85f6                 test esi, esi
// 0050a50f  0f9cc0               setl al
// 0050a512  2c01                 sub al, 1
// 0050a514  23c6                 and eax, esi
// 0050a516  88872c010000         mov byte ptr [edi + 0x12c], al
// 0050a51c  5f                   pop edi
// 0050a51d  5e                   pop esi
// 0050a51e  c3                   ret 
// library libpng-1.2.7/png.c (function _png_set_sig_bytes)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 png.c
