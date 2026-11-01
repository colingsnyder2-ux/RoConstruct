// from server: 100% by auto
// roc 2007-03 0051be40  unit: seg_00510000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0051be40
//
// 0051be40  56                   push esi
// 0051be41  8b742408             mov esi, dword ptr [esp + 8]
// 0051be45  8b4668               mov eax, dword ptr [esi + 0x68]
// 0051be48  a801                 test al, 1
// 0051be4a  57                   push edi
// 0051be4b  7404                 je 0x51be51
// 0051be4d  a804                 test al, 4
// 0051be4f  750e                 jne 0x51be5f
// 0051be51  689c387a00           push 0x7a389c
// 0051be56  56                   push esi
// 0051be57  e8c4c4ffff           call 0x518320
// 0051be5c  83c408               add esp, 8
// 0051be5f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0051be63  834e6818             or dword ptr [esi + 0x68], 0x18
// 0051be67  85ff                 test edi, edi
// 0051be69  740e                 je 0x51be79
// 0051be6b  6880387a00           push 0x7a3880
// 0051be70  56                   push esi
// 0051be71  e85ac5ffff           call 0x5183d0
// 0051be76  83c408               add esp, 8
// 0051be79  57                   push edi
// 0051be7a  56                   push esi
// 0051be7b  e8f0fbffff           call 0x51ba70
// 0051be80  83c408               add esp, 8
// 0051be83  5f                   pop edi
// 0051be84  5e                   pop esi
// 0051be85  c3                   ret 
// library libpng-1.2.7/pngrutil.c (function _png_handle_IEND)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrutil.c
