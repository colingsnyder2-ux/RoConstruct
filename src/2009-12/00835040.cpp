// from server: 100% by auto
// roc 2009-12 00835040  unit: CXTPMDIFrameWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00835040
//
// 00835040  56                   push esi
// 00835041  8bf1                 mov esi, ecx
// 00835043  e8beedfbff           call 0x7f3e06
// 00835048  c786e800000000000000 mov dword ptr [esi + 0xe8], 0
// 00835052  c7062c759f00         mov dword ptr [esi], 0x9f752c
// 00835058  8bc6                 mov eax, esi
// 0083505a  5e                   pop esi
// 0083505b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ??0?$CXTPFrameWndBase@VCFrameWnd@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
