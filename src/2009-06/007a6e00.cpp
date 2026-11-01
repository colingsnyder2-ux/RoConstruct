// from server: 100% by auto
// roc 2009-06 007a6e00  unit: CXTPOffice2007Theme  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a6e00
//
// 007a6e00  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 007a6e05  7550                 jne 0x7a6e57
// 007a6e07  56                   push esi
// 007a6e08  8b742418             mov esi, dword ptr [esp + 0x18]
// 007a6e0c  2b742410             sub esi, dword ptr [esp + 0x10]
// 007a6e10  6a27                 push 0x27
// 007a6e12  e869b9f7ff           call 0x722780
// 007a6e17  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a6e1b  50                   push eax
// 007a6e1c  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a6e20  83c6fe               add esi, -2
// 007a6e23  56                   push esi
// 007a6e24  8b742410             mov esi, dword ptr [esp + 0x10]
// 007a6e28  6a01                 push 1
// 007a6e2a  49                   dec ecx
// 007a6e2b  50                   push eax
// 007a6e2c  51                   push ecx
// 007a6e2d  8bce                 mov ecx, esi
// 007a6e2f  e8fc500a00           call 0x84bf30
// 007a6e34  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a6e38  8b542418             mov edx, dword ptr [esp + 0x18]
// 007a6e3c  68ffffff00           push 0xffffff
// 007a6e41  2bd0                 sub edx, eax
// 007a6e43  83ea02               sub edx, 2
// 007a6e46  52                   push edx
// 007a6e47  6a01                 push 1
// 007a6e49  50                   push eax
// 007a6e4a  8b442424             mov eax, dword ptr [esp + 0x24]
// 007a6e4e  50                   push eax
// 007a6e4f  8bce                 mov ecx, esi
// 007a6e51  e8da500a00           call 0x84bf30
// 007a6e56  5e                   pop esi
// 007a6e57  c21c00               ret 0x1c
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ?DrawStatusBarPaneBorder@CXTPResourceTheme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
