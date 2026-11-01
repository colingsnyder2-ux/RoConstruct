// from server: 100% by auto
// roc 2010-06 00820e10  unit: CXTPReportColumns  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00820e10
//
// 00820e10  56                   push esi
// 00820e11  8bf1                 mov esi, ecx
// 00820e13  e8e8ffffff           call 0x820e00
// 00820e18  50                   push eax
// 00820e19  8bce                 mov ecx, esi
// 00820e1b  e8708d0700           call 0x899b90
// 00820e20  c7065444a600         mov dword ptr [esi], 0xa64454
// 00820e26  c746544444a600       mov dword ptr [esi + 0x54], 0xa64444
// 00820e2d  c786ac00000000000000 mov dword ptr [esi + 0xac], 0
// 00820e37  8bc6                 mov eax, esi
// 00820e39  5e                   pop esi
// 00820e3a  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaption.cpp (function ??0CXTCaptionButton@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaption.cpp
