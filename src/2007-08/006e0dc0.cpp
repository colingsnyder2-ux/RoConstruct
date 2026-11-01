// from server: 100% by auto
// roc 2007-08 006e0dc0  unit: CXTPDockingPaneTabbedContainer  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e0dc0
//
// 006e0dc0  837c2408fc           cmp dword ptr [esp + 8], -4
// 006e0dc5  56                   push esi
// 006e0dc6  8bf1                 mov esi, ecx
// 006e0dc8  7409                 je 0x6e0dd3
// 006e0dca  e86ff4f4ff           call 0x63023e
// 006e0dcf  5e                   pop esi
// 006e0dd0  c20800               ret 8
// 006e0dd3  68ac4e7c00           push 0x7c4eac
// 006e0dd8  e817760500           call 0x7383f4
// 006e0ddd  85c0                 test eax, eax
// 006e0ddf  7509                 jne 0x6e0dea
// 006e0de1  b805400080           mov eax, 0x80004005
// 006e0de6  5e                   pop esi
// 006e0de7  c20800               ret 8
// 006e0dea  50                   push eax
// 006e0deb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006e0def  50                   push eax
// 006e0df0  68ac4e7c00           push 0x7c4eac
// 006e0df5  8d8e34010000         lea ecx, [esi + 0x134]
// 006e0dfb  e80011f9ff           call 0x671f00
// 006e0e00  5e                   pop esi
// 006e0e01  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?OnGetObject@CXTPDockingPaneTabbedContainer@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
