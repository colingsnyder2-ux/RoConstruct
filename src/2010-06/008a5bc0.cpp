// from server: 100% by auto
// roc 2010-06 008a5bc0  unit: CXTPRibbonControlSystemPopupBarButton  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a5bc0
//
// 008a5bc0  56                   push esi
// 008a5bc1  8bf1                 mov esi, ecx
// 008a5bc3  e898e7f9ff           call 0x844360
// 008a5bc8  c706742fa700         mov dword ptr [esi], 0xa72f74
// 008a5bce  c74620142fa700       mov dword ptr [esi + 0x20], 0xa72f14
// 008a5bd5  8bc6                 mov eax, esi
// 008a5bd7  5e                   pop esi
// 008a5bd8  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
