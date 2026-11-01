// from server: 100% by auto
// roc 2007-03 005fdf00  unit: seg_005f0000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fdf00
//
// 005fdf00  837e2400             cmp dword ptr [esi + 0x24], 0
// 005fdf04  7456                 je 0x5fdf5c
// 005fdf06  8b06                 mov eax, dword ptr [esi]
// 005fdf08  83f80d               cmp eax, 0xd
// 005fdf0b  742c                 je 0x5fdf39
// 005fdf0d  83f80e               cmp eax, 0xe
// 005fdf10  7427                 je 0x5fdf39
// 005fdf12  85c0                 test eax, eax
// 005fdf14  740a                 je 0x5fdf20
// 005fdf16  56                   push esi
// 005fdf17  57                   push edi
// 005fdf18  e8a3720100           call 0x6151c0
// 005fdf1d  83c408               add esp, 8
// 005fdf20  8b4624               mov eax, dword ptr [esi + 0x24]
// 005fdf23  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005fdf26  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fdf29  50                   push eax
// 005fdf2a  8b4208               mov eax, dword ptr [edx + 8]
// 005fdf2d  51                   push ecx
// 005fdf2e  50                   push eax
// 005fdf2f  57                   push edi
// 005fdf30  e8db6c0100           call 0x614c10
// 005fdf35  83c410               add esp, 0x10
// 005fdf38  c3                   ret 
// 005fdf39  6aff                 push -1
// 005fdf3b  56                   push esi
// 005fdf3c  57                   push edi
// 005fdf3d  e87e690100           call 0x6148c0
// 005fdf42  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005fdf45  8b5618               mov edx, dword ptr [esi + 0x18]
// 005fdf48  8b4208               mov eax, dword ptr [edx + 8]
// 005fdf4b  6aff                 push -1
// 005fdf4d  51                   push ecx
// 005fdf4e  50                   push eax
// 005fdf4f  57                   push edi
// 005fdf50  e8bb6c0100           call 0x614c10
// 005fdf55  83c41c               add esp, 0x1c
// 005fdf58  834620ff             add dword ptr [esi + 0x20], -1
// 005fdf5c  c3                   ret 
// library lua-5.1.1/lparser.c (function _lastlistfield)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
