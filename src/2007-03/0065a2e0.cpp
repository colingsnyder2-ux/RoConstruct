// from server: 100% by auto
// roc 2007-03 0065a2e0  unit: seg_00650000  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065a2e0
//
// 0065a2e0  837c2408fc           cmp dword ptr [esp + 8], -4
// 0065a2e5  56                   push esi
// 0065a2e6  8bf1                 mov esi, ecx
// 0065a2e8  7409                 je 0x65a2f3
// 0065a2ea  e8e343fcff           call 0x61e6d2
// 0065a2ef  5e                   pop esi
// 0065a2f0  c20800               ret 8
// 0065a2f3  6860257c00           push 0x7c2560
// 0065a2f8  e8af080e00           call 0x73abac
// 0065a2fd  85c0                 test eax, eax
// 0065a2ff  7509                 jne 0x65a30a
// 0065a301  b805400080           mov eax, 0x80004005
// 0065a306  5e                   pop esi
// 0065a307  c20800               ret 8
// 0065a30a  50                   push eax
// 0065a30b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065a30f  50                   push eax
// 0065a310  6860257c00           push 0x7c2560
// 0065a315  8d4e54               lea ecx, [esi + 0x54]
// 0065a318  e823c70200           call 0x686a40
// 0065a31d  5e                   pop esi
// 0065a31e  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnGetObject@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
