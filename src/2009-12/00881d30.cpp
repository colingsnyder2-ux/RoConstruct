// from server: 100% by auto
// roc 2009-12 00881d30  unit: CXTPOffice2007Theme  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00881d30
//
// 00881d30  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00881d35  7550                 jne 0x881d87
// 00881d37  56                   push esi
// 00881d38  8b742418             mov esi, dword ptr [esp + 0x18]
// 00881d3c  2b742410             sub esi, dword ptr [esp + 0x10]
// 00881d40  6a27                 push 0x27
// 00881d42  e8f9b8f7ff           call 0x7fd640
// 00881d47  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00881d4b  50                   push eax
// 00881d4c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00881d50  83c6fe               add esi, -2
// 00881d53  56                   push esi
// 00881d54  8b742410             mov esi, dword ptr [esp + 0x10]
// 00881d58  6a01                 push 1
// 00881d5a  49                   dec ecx
// 00881d5b  50                   push eax
// 00881d5c  51                   push ecx
// 00881d5d  8bce                 mov ecx, esi
// 00881d5f  e832470a00           call 0x926496
// 00881d64  8b442410             mov eax, dword ptr [esp + 0x10]
// 00881d68  8b542418             mov edx, dword ptr [esp + 0x18]
// 00881d6c  68ffffff00           push 0xffffff
// 00881d71  2bd0                 sub edx, eax
// 00881d73  83ea02               sub edx, 2
// 00881d76  52                   push edx
// 00881d77  6a01                 push 1
// 00881d79  50                   push eax
// 00881d7a  8b442424             mov eax, dword ptr [esp + 0x24]
// 00881d7e  50                   push eax
// 00881d7f  8bce                 mov ecx, esi
// 00881d81  e810470a00           call 0x926496
// 00881d86  5e                   pop esi
// 00881d87  c21c00               ret 0x1c
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ?DrawStatusBarPaneBorder@CXTPResourceTheme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
