// from server: 100% by auto
// roc 2009-06 007ac4c0  unit: XTPPaintThemes::CXTPNativeXPTheme  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ac4c0
//
// 007ac4c0  83ec10               sub esp, 0x10
// 007ac4c3  56                   push esi
// 007ac4c4  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007ac4c8  57                   push edi
// 007ac4c9  8bf9                 mov edi, ecx
// 007ac4cb  8bce                 mov ecx, esi
// 007ac4cd  e8ae600000           call 0x7b2580
// 007ac4d2  56                   push esi
// 007ac4d3  85c0                 test eax, eax
// 007ac4d5  7515                 jne 0x7ac4ec
// 007ac4d7  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ac4db  56                   push esi
// 007ac4dc  50                   push eax
// 007ac4dd  8bcf                 mov ecx, edi
// 007ac4df  e80cffffff           call 0x7ac3f0
// 007ac4e4  5f                   pop edi
// 007ac4e5  5e                   pop esi
// 007ac4e6  83c410               add esp, 0x10
// 007ac4e9  c20800               ret 8
// 007ac4ec  8d4c240c             lea ecx, [esp + 0xc]
// 007ac4f0  e8db3ffcff           call 0x7704d0
// 007ac4f5  6a0f                 push 0xf
// 007ac4f7  8bcf                 mov ecx, edi
// 007ac4f9  8bf0                 mov esi, eax
// 007ac4fb  e88062f7ff           call 0x722780
// 007ac500  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007ac504  50                   push eax
// 007ac505  56                   push esi
// 007ac506  e8c5d2f6ff           call 0x7197d0
// 007ac50b  5f                   pop edi
// 007ac50c  5e                   pop esi
// 007ac50d  83c410               add esp, 0x10
// 007ac510  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPNativeXPTheme.cpp (function ?FillDockBar@CXTPNativeXPTheme@@MAEXPAVCDC@@PAVCXTPDockBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPNativeXPTheme.cpp
