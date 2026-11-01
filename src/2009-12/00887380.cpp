// from server: 100% by auto
// roc 2009-12 00887380  unit: XTPPaintThemes::CXTPNativeXPTheme  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00887380
//
// 00887380  83ec10               sub esp, 0x10
// 00887383  56                   push esi
// 00887384  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00887388  57                   push edi
// 00887389  8bf9                 mov edi, ecx
// 0088738b  8bce                 mov ecx, esi
// 0088738d  e8be9b0000           call 0x890f50
// 00887392  56                   push esi
// 00887393  85c0                 test eax, eax
// 00887395  7515                 jne 0x8873ac
// 00887397  8b442420             mov eax, dword ptr [esp + 0x20]
// 0088739b  56                   push esi
// 0088739c  50                   push eax
// 0088739d  8bcf                 mov ecx, edi
// 0088739f  e80cffffff           call 0x8872b0
// 008873a4  5f                   pop edi
// 008873a5  5e                   pop esi
// 008873a6  83c410               add esp, 0x10
// 008873a9  c20800               ret 8
// 008873ac  8d4c240c             lea ecx, [esp + 0xc]
// 008873b0  e81b3ffcff           call 0x84b2d0
// 008873b5  6a0f                 push 0xf
// 008873b7  8bcf                 mov ecx, edi
// 008873b9  8bf0                 mov esi, eax
// 008873bb  e88062f7ff           call 0x7fd640
// 008873c0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008873c4  50                   push eax
// 008873c5  56                   push esi
// 008873c6  e833d2f6ff           call 0x7f45fe
// 008873cb  5f                   pop edi
// 008873cc  5e                   pop esi
// 008873cd  83c410               add esp, 0x10
// 008873d0  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPNativeXPTheme.cpp (function ?FillDockBar@CXTPNativeXPTheme@@MAEXPAVCDC@@PAVCXTPDockBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPNativeXPTheme.cpp
