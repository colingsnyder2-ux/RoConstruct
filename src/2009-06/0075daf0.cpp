// from server: 100% by auto
// roc 2009-06 0075daf0  unit: CXTPDockingPaneManager  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075daf0
//
// 0075daf0  837c2408fc           cmp dword ptr [esp + 8], -4
// 0075daf5  56                   push esi
// 0075daf6  8bf1                 mov esi, ecx
// 0075daf8  7409                 je 0x75db03
// 0075dafa  e809b5fbff           call 0x719008
// 0075daff  5e                   pop esi
// 0075db00  c20800               ret 8
// 0075db03  6840128f00           push 0x8f1240
// 0075db08  e87de40e00           call 0x84bf8a
// 0075db0d  85c0                 test eax, eax
// 0075db0f  7509                 jne 0x75db1a
// 0075db11  b805400080           mov eax, 0x80004005
// 0075db16  5e                   pop esi
// 0075db17  c20800               ret 8
// 0075db1a  50                   push eax
// 0075db1b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0075db1f  50                   push eax
// 0075db20  6840128f00           push 0x8f1240
// 0075db25  8d4e54               lea ecx, [esi + 0x54]
// 0075db28  e8c33b0000           call 0x7616f0
// 0075db2d  5e                   pop esi
// 0075db2e  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?OnGetObject@CXTPDockingPaneManager@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
