// from server: 100% by auto
// roc 2012-06 00645480  unit: seg_00640000  size: 489 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00645480
//
// 00645480  55                   push ebp
// 00645481  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00645485  85ed                 test ebp, ebp
// 00645487  0f84da010000         je 0x645667
// 0064548d  56                   push esi
// 0064548e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00645492  85f6                 test esi, esi
// 00645494  0f84cc010000         je 0x645666
// 0064549a  f7456800040000       test dword ptr [ebp + 0x68], 0x400
// 006454a1  0f85bf010000         jne 0x645666
// 006454a7  57                   push edi
// 006454a8  55                   push ebp
// 006454a9  e8a20b0100           call 0x656050
// 006454ae  bf00100000           mov edi, 0x1000
// 006454b3  83c404               add esp, 4
// 006454b6  857d68               test dword ptr [ebp + 0x68], edi
// 006454b9  7421                 je 0x6454dc
// 006454bb  83bd3002000000       cmp dword ptr [ebp + 0x230], 0
// 006454c2  7418                 je 0x6454dc
// 006454c4  68105eb800           push 0xb85e10
// 006454c9  55                   push ebp
// 006454ca  e8918d0000           call 0x64e260
// 006454cf  83c408               add esp, 8
// 006454d2  c7853002000000000000 mov dword ptr [ebp + 0x230], 0
// 006454dc  0fb6461c             movzx eax, byte ptr [esi + 0x1c]
// 006454e0  0fb64e1b             movzx ecx, byte ptr [esi + 0x1b]
// 006454e4  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 006454e8  50                   push eax
// 006454e9  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 006454ed  51                   push ecx
// 006454ee  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 006454f2  52                   push edx
// 006454f3  8b5604               mov edx, dword ptr [esi + 4]
// 006454f6  50                   push eax
// 006454f7  8b06                 mov eax, dword ptr [esi]
// 006454f9  51                   push ecx
// 006454fa  52                   push edx
// 006454fb  50                   push eax
// 006454fc  55                   push ebp
// 006454fd  e89e1d0100           call 0x6572a0
// 00645502  83c420               add esp, 0x20
// 00645505  f6460801             test byte ptr [esi + 8], 1
// 00645509  7412                 je 0x64551d
// 0064550b  d94628               fld dword ptr [esi + 0x28]
// 0064550e  83ec08               sub esp, 8
// 00645511  dd1c24               fstp qword ptr [esp]
// 00645514  55                   push ebp
// 00645515  e876230100           call 0x657890
// 0064551a  83c40c               add esp, 0xc
// 0064551d  f7460800080000       test dword ptr [esi + 8], 0x800
// 00645524  740e                 je 0x645534
// 00645526  0fb64e2c             movzx ecx, byte ptr [esi + 0x2c]
// 0064552a  51                   push ecx
// 0064552b  55                   push ebp
// 0064552c  e83f240100           call 0x657970
// 00645531  83c408               add esp, 8
// 00645534  857e08               test dword ptr [esi + 8], edi
// 00645537  7420                 je 0x645559
// 00645539  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0064553f  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00645545  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0064554b  52                   push edx
// 0064554c  50                   push eax
// 0064554d  6a00                 push 0
// 0064554f  51                   push ecx
// 00645550  55                   push ebp
// 00645551  e8ca240100           call 0x657a20
// 00645556  83c414               add esp, 0x14
// 00645559  f6460802             test byte ptr [esi + 8], 2
// 0064555d  7412                 je 0x645571
// 0064555f  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 00645563  52                   push edx
// 00645564  8d4644               lea eax, [esi + 0x44]
// 00645567  50                   push eax
// 00645568  55                   push ebp
// 00645569  e812280100           call 0x657d80
// 0064556e  83c40c               add esp, 0xc
// 00645571  f6460804             test byte ptr [esi + 8], 4
// 00645575  745b                 je 0x6455d2
// 00645577  d9869c000000         fld dword ptr [esi + 0x9c]
// 0064557d  83ec40               sub esp, 0x40
// 00645580  dd5c2438             fstp qword ptr [esp + 0x38]
// 00645584  d98698000000         fld dword ptr [esi + 0x98]
// 0064558a  dd5c2430             fstp qword ptr [esp + 0x30]
// 0064558e  d98694000000         fld dword ptr [esi + 0x94]
// 00645594  dd5c2428             fstp qword ptr [esp + 0x28]
// 00645598  d98690000000         fld dword ptr [esi + 0x90]
// 0064559e  dd5c2420             fstp qword ptr [esp + 0x20]
// 006455a2  d9868c000000         fld dword ptr [esi + 0x8c]
// 006455a8  dd5c2418             fstp qword ptr [esp + 0x18]
// 006455ac  d98688000000         fld dword ptr [esi + 0x88]
// 006455b2  dd5c2410             fstp qword ptr [esp + 0x10]
// 006455b6  d98684000000         fld dword ptr [esi + 0x84]
// 006455bc  dd5c2408             fstp qword ptr [esp + 8]
// 006455c0  d98680000000         fld dword ptr [esi + 0x80]
// 006455c6  dd1c24               fstp qword ptr [esp]
// 006455c9  55                   push ebp
// 006455ca  e891280100           call 0x657e60
// 006455cf  83c444               add esp, 0x44
// 006455d2  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 006455d8  85c0                 test eax, eax
// 006455da  0f847e000000         je 0x64565e
// 006455e0  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 006455e6  8d0c80               lea ecx, [eax + eax*4]
// 006455e9  8d148f               lea edx, [edi + ecx*4]
// 006455ec  3bfa                 cmp edi, edx
// 006455ee  736e                 jae 0x64565e
// 006455f0  57                   push edi
// 006455f1  55                   push ebp
// 006455f2  e8098dffff           call 0x63e300
// 006455f7  83c408               add esp, 8
// 006455fa  83f801               cmp eax, 1
// 006455fd  7446                 je 0x645645
// 006455ff  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00645602  84c9                 test cl, cl
// 00645604  743f                 je 0x645645
// 00645606  f6c106               test cl, 6
// 00645609  753a                 jne 0x645645
// 0064560b  f6470320             test byte ptr [edi + 3], 0x20
// 0064560f  750e                 jne 0x64561f
// 00645611  83f803               cmp eax, 3
// 00645614  7409                 je 0x64561f
// 00645616  f7456c00000100       test dword ptr [ebp + 0x6c], 0x10000
// 0064561d  7426                 je 0x645645
// 0064561f  837f0c00             cmp dword ptr [edi + 0xc], 0
// 00645623  750e                 jne 0x645633
// 00645625  68ec5db800           push 0xb85dec
// 0064562a  55                   push ebp
// 0064562b  e8308c0000           call 0x64e260
// 00645630  83c408               add esp, 8
// 00645633  8b470c               mov eax, dword ptr [edi + 0xc]
// 00645636  8b4f08               mov ecx, dword ptr [edi + 8]
// 00645639  50                   push eax
// 0064563a  51                   push ecx
// 0064563b  57                   push edi
// 0064563c  55                   push ebp
// 0064563d  e8de1b0100           call 0x657220
// 00645642  83c410               add esp, 0x10
// 00645645  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0064564b  8d1480               lea edx, [eax + eax*4]
// 0064564e  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00645654  83c714               add edi, 0x14
// 00645657  8d0c90               lea ecx, [eax + edx*4]
// 0064565a  3bf9                 cmp edi, ecx
// 0064565c  7292                 jb 0x6455f0
// 0064565e  814d6800040000       or dword ptr [ebp + 0x68], 0x400
// 00645665  5f                   pop edi
// 00645666  5e                   pop esi
// 00645667  5d                   pop ebp
// 00645668  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_write_info_before_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
