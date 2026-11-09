// from server: 100% by auto
// roc 2010-06 0083a8e0  unit: XTPPaintThemes::CXTPNativeXPTheme  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083a8e0
//
// 0083a8e0  83ec10               sub esp, 0x10
// 0083a8e3  56                   push esi
// 0083a8e4  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0083a8e8  57                   push edi
// 0083a8e9  8bf9                 mov edi, ecx
// 0083a8eb  8bce                 mov ecx, esi
// 0083a8ed  e84ea80000           call 0x845140
// 0083a8f2  56                   push esi
// 0083a8f3  85c0                 test eax, eax
// 0083a8f5  7515                 jne 0x83a90c
// 0083a8f7  8b442420             mov eax, dword ptr [esp + 0x20]
// 0083a8fb  56                   push esi
// 0083a8fc  50                   push eax
// 0083a8fd  8bcf                 mov ecx, edi
// 0083a8ff  e80cffffff           call 0x83a810
// 0083a904  5f                   pop edi
// 0083a905  5e                   pop esi
// 0083a906  83c410               add esp, 0x10
// 0083a909  c20800               ret 8
// 0083a90c  8d4c240c             lea ecx, [esp + 0xc]
// 0083a910  e8fb49fcff           call 0x7ff310
// 0083a915  6a0f                 push 0xf
// 0083a917  8bcf                 mov ecx, edi
// 0083a919  8bf0                 mov esi, eax
// 0083a91b  e8f027f7ff           call 0x7ad110
// 0083a920  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0083a924  50                   push eax
// 0083a925  56                   push esi
// 0083a926  e813def6ff           call 0x7a873e
// 0083a92b  5f                   pop edi
// 0083a92c  5e                   pop esi
// 0083a92d  83c410               add esp, 0x10
// 0083a930  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPNativeXPTheme.cpp (function ?FillDockBar@CXTPNativeXPTheme@@MAEXPAVCDC@@PAVCXTPDockBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPNativeXPTheme.cpp
