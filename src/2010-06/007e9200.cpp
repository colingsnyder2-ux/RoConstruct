// from server: 100% by auto
// roc 2010-06 007e9200  unit: CXTPMDIFrameWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e9200
//
// 007e9200  56                   push esi
// 007e9201  8bf1                 mov esi, ecx
// 007e9203  e844edfbff           call 0x7a7f4c
// 007e9208  c786e800000000000000 mov dword ptr [esi + 0xe8], 0
// 007e9212  c70614b8a500         mov dword ptr [esi], 0xa5b814
// 007e9218  8bc6                 mov eax, esi
// 007e921a  5e                   pop esi
// 007e921b  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ??0?$CXTPFrameWndBase@VCFrameWnd@@@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPFrameWnd.cpp
