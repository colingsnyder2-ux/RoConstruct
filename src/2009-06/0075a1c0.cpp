// from server: 100% by auto
// roc 2009-06 0075a1c0  unit: CXTPMDIFrameWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a1c0
//
// 0075a1c0  56                   push esi
// 0075a1c1  8bf1                 mov esi, ecx
// 0075a1c3  e816eefbff           call 0x718fde
// 0075a1c8  c786e800000000000000 mov dword ptr [esi + 0xe8], 0
// 0075a1d2  c70684708f00         mov dword ptr [esi], 0x8f7084
// 0075a1d8  8bc6                 mov eax, esi
// 0075a1da  5e                   pop esi
// 0075a1db  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ??0?$CXTPFrameWndBase@VCFrameWnd@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
