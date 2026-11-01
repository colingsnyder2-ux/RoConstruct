// from server: 100% by auto
// roc 2009-06 0075a210  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a210
//
// 0075a210  56                   push esi
// 0075a211  8bf1                 mov esi, ecx
// 0075a213  e80c200f00           call 0x84c224
// 0075a218  c786ec00000000000000 mov dword ptr [esi + 0xec], 0
// 0075a222  c70624728f00         mov dword ptr [esi], 0x8f7224
// 0075a228  8bc6                 mov eax, esi
// 0075a22a  5e                   pop esi
// 0075a22b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ??0?$CXTPFrameWndBase@VCMDIFrameWnd@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
