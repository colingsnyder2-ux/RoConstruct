// from server: 100% by auto
// roc 2009-12 0042a330  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042a330
//
// 0042a330  56                   push esi
// 0042a331  8bf1                 mov esi, ecx
// 0042a333  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0042a339  57                   push edi
// 0042a33a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042a33e  85c9                 test ecx, ecx
// 0042a340  7406                 je 0x42a348
// 0042a342  57                   push edi
// 0042a343  e878ac3e00           call 0x814fc0
// 0042a348  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042a34c  50                   push eax
// 0042a34d  57                   push edi
// 0042a34e  8bce                 mov ecx, esi
// 0042a350  e82b9c3c00           call 0x7f3f80
// 0042a355  5f                   pop edi
// 0042a356  5e                   pop esi
// 0042a357  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnSetPreviewMode@?$CXTPFrameWndBase@VCMDIFrameWnd@@@@UAEXHPAUCPrintPreviewState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
