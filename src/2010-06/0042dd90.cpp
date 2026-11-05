// from server: 100% by auto
// roc 2010-06 0042dd90  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042dd90
//
// 0042dd90  56                   push esi
// 0042dd91  8bf1                 mov esi, ecx
// 0042dd93  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042dd99  57                   push edi
// 0042dd9a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042dd9e  85c9                 test ecx, ecx
// 0042dda0  7406                 je 0x42dda8
// 0042dda2  57                   push edi
// 0042dda3  e8e8b23900           call 0x7c9090
// 0042dda8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042ddac  50                   push eax
// 0042ddad  57                   push edi
// 0042ddae  8bce                 mov ecx, esi
// 0042ddb0  e80ba33700           call 0x7a80c0
// 0042ddb5  5f                   pop edi
// 0042ddb6  5e                   pop esi
// 0042ddb7  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnSetPreviewMode@?$CXTPFrameWndBase@VCFrameWnd@@@@UAEXHPAUCPrintPreviewState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPFrameWnd.cpp
