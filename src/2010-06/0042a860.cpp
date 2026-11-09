// from server: 100% by auto
// roc 2010-06 0042a860  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042a860
//
// 0042a860  56                   push esi
// 0042a861  8bf1                 mov esi, ecx
// 0042a863  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0042a869  57                   push edi
// 0042a86a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042a86e  85c9                 test ecx, ecx
// 0042a870  7406                 je 0x42a878
// 0042a872  57                   push edi
// 0042a873  e818e83900           call 0x7c9090
// 0042a878  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042a87c  50                   push eax
// 0042a87d  57                   push edi
// 0042a87e  8bce                 mov ecx, esi
// 0042a880  e83bd83700           call 0x7a80c0
// 0042a885  5f                   pop edi
// 0042a886  5e                   pop esi
// 0042a887  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnSetPreviewMode@?$CXTPFrameWndBase@VCMDIFrameWnd@@@@UAEXHPAUCPrintPreviewState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPFrameWnd.cpp
