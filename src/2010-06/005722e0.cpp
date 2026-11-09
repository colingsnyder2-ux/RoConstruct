// from server: 100% by auto
// roc 2010-06 005722e0  unit: seg_00570000  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005722e0
//
// 005722e0  56                   push esi
// 005722e1  8b742408             mov esi, dword ptr [esp + 8]
// 005722e5  85f6                 test esi, esi
// 005722e7  0f8449010000         je 0x572436
// 005722ed  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 005722f4  741c                 je 0x572312
// 005722f6  8b465c               mov eax, dword ptr [esi + 0x5c]
// 005722f9  85c0                 test eax, eax
// 005722fb  7415                 je 0x572312
// 005722fd  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00572303  41                   inc ecx
// 00572304  51                   push ecx
// 00572305  8d9600010000         lea edx, [esi + 0x100]
// 0057230b  52                   push edx
// 0057230c  56                   push esi
// 0057230d  ffd0                 call eax
// 0057230f  83c40c               add esp, 0xc
// 00572312  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 00572319  741b                 je 0x572336
// 0057231b  8b466c               mov eax, dword ptr [esi + 0x6c]
// 0057231e  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00572324  50                   push eax
// 00572325  41                   inc ecx
// 00572326  51                   push ecx
// 00572327  8d9600010000         lea edx, [esi + 0x100]
// 0057232d  52                   push edx
// 0057232e  e83d52ffff           call 0x567570
// 00572333  83c40c               add esp, 0xc
// 00572336  f7467000000100       test dword ptr [esi + 0x70], 0x10000
// 0057233d  7417                 je 0x572356
// 0057233f  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00572345  40                   inc eax
// 00572346  50                   push eax
// 00572347  8d8e00010000         lea ecx, [esi + 0x100]
// 0057234d  51                   push ecx
// 0057234e  e8cd51ffff           call 0x567520
// 00572353  83c408               add esp, 8
// 00572356  f6467004             test byte ptr [esi + 0x70], 4
// 0057235a  741f                 je 0x57237b
// 0057235c  0fb69627010000       movzx edx, byte ptr [esi + 0x127]
// 00572363  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00572369  52                   push edx
// 0057236a  40                   inc eax
// 0057236b  50                   push eax
// 0057236c  8d8e00010000         lea ecx, [esi + 0x100]
// 00572372  51                   push ecx
// 00572373  e8e8f8ffff           call 0x571c60
// 00572378  83c40c               add esp, 0xc
// 0057237b  f6467010             test byte ptr [esi + 0x70], 0x10
// 0057237f  7417                 je 0x572398
// 00572381  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00572387  42                   inc edx
// 00572388  52                   push edx
// 00572389  8d8600010000         lea eax, [esi + 0x100]
// 0057238f  50                   push eax
// 00572390  e84b51ffff           call 0x5674e0
// 00572395  83c408               add esp, 8
// 00572398  f6467008             test byte ptr [esi + 0x70], 8
// 0057239c  741e                 je 0x5723bc
// 0057239e  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 005723a4  8d8e81010000         lea ecx, [esi + 0x181]
// 005723aa  51                   push ecx
// 005723ab  42                   inc edx
// 005723ac  52                   push edx
// 005723ad  8d8600010000         lea eax, [esi + 0x100]
// 005723b3  50                   push eax
// 005723b4  e8d7f9ffff           call 0x571d90
// 005723b9  83c40c               add esp, 0xc
// 005723bc  f7467000000200       test dword ptr [esi + 0x70], 0x20000
// 005723c3  7417                 je 0x5723dc
// 005723c5  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 005723cb  41                   inc ecx
// 005723cc  51                   push ecx
// 005723cd  8d9600010000         lea edx, [esi + 0x100]
// 005723d3  52                   push edx
// 005723d4  e857fcffff           call 0x572030
// 005723d9  83c408               add esp, 8
// 005723dc  f7467000000800       test dword ptr [esi + 0x70], 0x80000
// 005723e3  7417                 je 0x5723fc
// 005723e5  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 005723eb  40                   inc eax
// 005723ec  50                   push eax
// 005723ed  8d8e00010000         lea ecx, [esi + 0x100]
// 005723f3  51                   push ecx
// 005723f4  e857fdffff           call 0x572150
// 005723f9  83c408               add esp, 8
// 005723fc  f6467001             test byte ptr [esi + 0x70], 1
// 00572400  7417                 je 0x572419
// 00572402  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00572408  42                   inc edx
// 00572409  52                   push edx
// 0057240a  8d8600010000         lea eax, [esi + 0x100]
// 00572410  50                   push eax
// 00572411  e8aa53ffff           call 0x5677c0
// 00572416  83c408               add esp, 8
// 00572419  f6467020             test byte ptr [esi + 0x70], 0x20
// 0057241d  7417                 je 0x572436
// 0057241f  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00572425  41                   inc ecx
// 00572426  51                   push ecx
// 00572427  81c600010000         add esi, 0x100
// 0057242d  56                   push esi
// 0057242e  e81d50ffff           call 0x567450
// 00572433  83c408               add esp, 8
// 00572436  5e                   pop esi
// 00572437  c3                   ret 
// library libpng-1.2.10/pngwtran.c (function _png_do_write_transformations)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngwtran.c
