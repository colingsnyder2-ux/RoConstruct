// from server: 100% by auto
// roc 2010-06 007e9250  unit: VCFrameWnd::?$CXTPFrameWndBase  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9250
//
// 007e9250  56                   push esi
// 007e9251  8bf1                 mov esi, ecx
// 007e9253  e8743e1900           call 0x97d0cc
// 007e9258  c786ec00000000000000 mov dword ptr [esi + 0xec], 0
// 007e9262  c706b4b9a500         mov dword ptr [esi], 0xa5b9b4
// 007e9268  8bc6                 mov eax, esi
// 007e926a  5e                   pop esi
// 007e926b  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ??0?$CXTPFrameWndBase@VCMDIFrameWnd@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPFrameWnd.cpp
