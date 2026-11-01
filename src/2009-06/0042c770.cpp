// from server: 100% by auto
// roc 2009-06 0042c770  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c770
//
// 0042c770  56                   push esi
// 0042c771  8bf1                 mov esi, ecx
// 0042c773  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042c779  57                   push edi
// 0042c77a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042c77e  85c9                 test ecx, ecx
// 0042c780  7406                 je 0x42c788
// 0042c782  57                   push edi
// 0042c783  e888db2f00           call 0x72a310
// 0042c788  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042c78c  50                   push eax
// 0042c78d  57                   push edi
// 0042c78e  8bce                 mov ecx, esi
// 0042c790  e8c3c92e00           call 0x719158
// 0042c795  5f                   pop edi
// 0042c796  5e                   pop esi
// 0042c797  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnSetPreviewMode@?$CXTPFrameWndBase@VCFrameWnd@@@@UAEXHPAUCPrintPreviewState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
