// from server: 100% by auto
// roc 2009-06 00429570  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00429570
//
// 00429570  56                   push esi
// 00429571  8bf1                 mov esi, ecx
// 00429573  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00429579  57                   push edi
// 0042957a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042957e  85c9                 test ecx, ecx
// 00429580  7406                 je 0x429588
// 00429582  57                   push edi
// 00429583  e8880d3000           call 0x72a310
// 00429588  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042958c  50                   push eax
// 0042958d  57                   push edi
// 0042958e  8bce                 mov ecx, esi
// 00429590  e8c3fb2e00           call 0x719158
// 00429595  5f                   pop edi
// 00429596  5e                   pop esi
// 00429597  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnSetPreviewMode@?$CXTPFrameWndBase@VCMDIFrameWnd@@@@UAEXHPAUCPrintPreviewState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
