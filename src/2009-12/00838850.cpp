// from server: 100% by auto
// roc 2009-12 00838850  unit: CXTPDockingPaneManager  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838850
//
// 00838850  837c2408fc           cmp dword ptr [esp + 8], -4
// 00838855  56                   push esi
// 00838856  8bf1                 mov esi, ecx
// 00838858  7409                 je 0x838863
// 0083885a  e8d1b5fbff           call 0x7f3e30
// 0083885f  5e                   pop esi
// 00838860  c20800               ret 8
// 00838863  6800179f00           push 0x9f1700
// 00838868  e84ddc0e00           call 0x9264ba
// 0083886d  85c0                 test eax, eax
// 0083886f  7509                 jne 0x83887a
// 00838871  b805400080           mov eax, 0x80004005
// 00838876  5e                   pop esi
// 00838877  c20800               ret 8
// 0083887a  50                   push eax
// 0083887b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083887f  50                   push eax
// 00838880  6800179f00           push 0x9f1700
// 00838885  8d4e54               lea ecx, [esi + 0x54]
// 00838888  e8333c0000           call 0x83c4c0
// 0083888d  5e                   pop esi
// 0083888e  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnGetObject@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
