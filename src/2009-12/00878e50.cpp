// from server: 100% by auto
// roc 2009-12 00878e50  unit: CXTPControlGallery  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00878e50
//
// 00878e50  56                   push esi
// 00878e51  8bf1                 mov esi, ecx
// 00878e53  e8c807f8ff           call 0x7f9620
// 00878e58  c706ac1ba000         mov dword ptr [esi], 0xa01bac
// 00878e5e  c746549c1ba000       mov dword ptr [esi + 0x54], 0xa01b9c
// 00878e65  c7465c3c1ba000       mov dword ptr [esi + 0x5c], 0xa01b3c
// 00878e6c  8bc6                 mov eax, esi
// 00878e6e  5e                   pop esi
// 00878e6f  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ??0CXTPControlFontComboBoxList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
