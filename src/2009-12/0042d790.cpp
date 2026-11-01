// from server: 100% by auto
// roc 2009-12 0042d790  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042d790
//
// 0042d790  56                   push esi
// 0042d791  8bf1                 mov esi, ecx
// 0042d793  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042d799  57                   push edi
// 0042d79a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042d79e  85c9                 test ecx, ecx
// 0042d7a0  7406                 je 0x42d7a8
// 0042d7a2  57                   push edi
// 0042d7a3  e818783e00           call 0x814fc0
// 0042d7a8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042d7ac  50                   push eax
// 0042d7ad  57                   push edi
// 0042d7ae  8bce                 mov ecx, esi
// 0042d7b0  e8cb673c00           call 0x7f3f80
// 0042d7b5  5f                   pop edi
// 0042d7b6  5e                   pop esi
// 0042d7b7  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnSetPreviewMode@?$CXTPFrameWndBase@VCFrameWnd@@@@UAEXHPAUCPrintPreviewState@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
