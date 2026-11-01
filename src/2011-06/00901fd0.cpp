// from server: 100% by auto
// roc 2011-06 00901fd0  unit: CXTCaptionButtonTheme  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00901fd0
//
// 00901fd0  83ec10               sub esp, 0x10
// 00901fd3  56                   push esi
// 00901fd4  8b742424             mov esi, dword ptr [esp + 0x24]
// 00901fd8  56                   push esi
// 00901fd9  8d4c2408             lea ecx, [esp + 8]
// 00901fdd  e8aeadf5ff           call 0x85cd90
// 00901fe2  8b06                 mov eax, dword ptr [esi]
// 00901fe4  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 00901fea  8bce                 mov ecx, esi
// 00901fec  ffd2                 call edx
// 00901fee  a804                 test al, 4
// 00901ff0  741e                 je 0x902010
// 00901ff2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00901ff6  2b442404             sub eax, dword ptr [esp + 4]
// 00901ffa  b900000000           mov ecx, 0
// 00901fff  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 00902003  99                   cdq 
// 00902004  2bc2                 sub eax, edx
// 00902006  d1f8                 sar eax, 1
// 00902008  0f98c1               sets cl
// 0090200b  49                   dec ecx
// 0090200c  23c1                 and eax, ecx
// 0090200e  eb03                 jmp 0x902013
// 00902010  8b466c               mov eax, dword ptr [esi + 0x6c]
// 00902013  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00902017  8901                 mov dword ptr [ecx], eax
// 00902019  8b442410             mov eax, dword ptr [esp + 0x10]
// 0090201d  2b442408             sub eax, dword ptr [esp + 8]
// 00902021  5e                   pop esi
// 00902022  2b44241c             sub eax, dword ptr [esp + 0x1c]
// 00902026  99                   cdq 
// 00902027  2bc2                 sub eax, edx
// 00902029  d1f8                 sar eax, 1
// 0090202b  ba00000000           mov edx, 0
// 00902030  0f98c2               sets dl
// 00902033  4a                   dec edx
// 00902034  23c2                 and eax, edx
// 00902036  894104               mov dword ptr [ecx + 4], eax
// 00902039  83c410               add esp, 0x10
// 0090203c  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?OffsetPoint@CXTButtonTheme@@MAEXAAVCPoint@@VCSize@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButtonTheme.cpp
