// from server: 100% by auto
// roc 2009-12 00835060  unit: CXTPMDIFrameWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00835060
//
// 00835060  56                   push esi
// 00835061  8bf1                 mov esi, ecx
// 00835063  e828170f00           call 0x926790
// 00835068  c786ec00000000000000 mov dword ptr [esi + 0xec], 0
// 00835072  c706cc769f00         mov dword ptr [esi], 0x9f76cc
// 00835078  8bc6                 mov eax, esi
// 0083507a  5e                   pop esi
// 0083507b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ??0?$CXTPFrameWndBase@VCMDIFrameWnd@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
