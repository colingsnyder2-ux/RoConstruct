// from server: 100% by auto
// roc 2010-06 008a8910  unit: CXTCaptionButtonTheme  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a8910
//
// 008a8910  83ec10               sub esp, 0x10
// 008a8913  56                   push esi
// 008a8914  8b742424             mov esi, dword ptr [esp + 0x24]
// 008a8918  56                   push esi
// 008a8919  8d4c2408             lea ecx, [esp + 8]
// 008a891d  e8ee69f5ff           call 0x7ff310
// 008a8922  8b06                 mov eax, dword ptr [esi]
// 008a8924  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 008a892a  8bce                 mov ecx, esi
// 008a892c  ffd2                 call edx
// 008a892e  a804                 test al, 4
// 008a8930  741e                 je 0x8a8950
// 008a8932  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008a8936  2b442404             sub eax, dword ptr [esp + 4]
// 008a893a  b900000000           mov ecx, 0
// 008a893f  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 008a8943  99                   cdq 
// 008a8944  2bc2                 sub eax, edx
// 008a8946  d1f8                 sar eax, 1
// 008a8948  0f98c1               sets cl
// 008a894b  49                   dec ecx
// 008a894c  23c1                 and eax, ecx
// 008a894e  eb03                 jmp 0x8a8953
// 008a8950  8b466c               mov eax, dword ptr [esi + 0x6c]
// 008a8953  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008a8957  8901                 mov dword ptr [ecx], eax
// 008a8959  8b442410             mov eax, dword ptr [esp + 0x10]
// 008a895d  2b442408             sub eax, dword ptr [esp + 8]
// 008a8961  5e                   pop esi
// 008a8962  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 008a8966  99                   cdq 
// 008a8967  2bc2                 sub eax, edx
// 008a8969  d1f8                 sar eax, 1
// 008a896b  ba00000000           mov edx, 0
// 008a8970  0f98c2               sets dl
// 008a8973  4a                   dec edx
// 008a8974  23c2                 and eax, edx
// 008a8976  894104               mov dword ptr [ecx + 4], eax
// 008a8979  83c410               add esp, 0x10
// 008a897c  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButtonTheme.cpp (function ?OffsetPoint@CXTButtonTheme@@MAEXAAVCPoint@@VCSize@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButtonTheme.cpp
