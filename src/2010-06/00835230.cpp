// from server: 100% by auto
// roc 2010-06 00835230  unit: CXTPOffice2007Theme  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00835230
//
// 00835230  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00835235  7550                 jne 0x835287
// 00835237  56                   push esi
// 00835238  8b742418             mov esi, dword ptr [esp + 0x18]
// 0083523c  2b742410             sub esi, dword ptr [esp + 0x10]
// 00835240  6a27                 push 0x27
// 00835242  e8c97ef7ff           call 0x7ad110
// 00835247  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0083524b  50                   push eax
// 0083524c  8b442414             mov eax, dword ptr [esp + 0x14]
// 00835250  83c6fe               add esi, -2
// 00835253  56                   push esi
// 00835254  8b742410             mov esi, dword ptr [esp + 0x10]
// 00835258  6a01                 push 1
// 0083525a  49                   dec ecx
// 0083525b  50                   push eax
// 0083525c  51                   push ecx
// 0083525d  8bce                 mov ecx, esi
// 0083525f  e8267b1400           call 0x97cd8a
// 00835264  8b442410             mov eax, dword ptr [esp + 0x10]
// 00835268  8b542418             mov edx, dword ptr [esp + 0x18]
// 0083526c  68ffffff00           push 0xffffff
// 00835271  2bd0                 sub edx, eax
// 00835273  83ea02               sub edx, 2
// 00835276  52                   push edx
// 00835277  6a01                 push 1
// 00835279  50                   push eax
// 0083527a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0083527e  50                   push eax
// 0083527f  8bce                 mov ecx, esi
// 00835281  e8047b1400           call 0x97cd8a
// 00835286  5e                   pop esi
// 00835287  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPOffice2007Theme.cpp (function ?DrawStatusBarPaneBorder@CXTPOffice2007Theme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2007Theme.cpp
