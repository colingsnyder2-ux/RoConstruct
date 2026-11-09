// from server: 100% by auto
// roc 2010-06 008260a0  unit: CXTPControlGallery  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008260a0
//
// 008260a0  56                   push esi
// 008260a1  8bf1                 mov esi, ecx
// 008260a3  e8c8e2f8ff           call 0x7b4370
// 008260a8  c7066453a600         mov dword ptr [esi], 0xa65364
// 008260ae  c746545453a600       mov dword ptr [esi + 0x54], 0xa65354
// 008260b5  c7465cf452a600       mov dword ptr [esi + 0x5c], 0xa652f4
// 008260bc  8bc6                 mov eax, esi
// 008260be  5e                   pop esi
// 008260bf  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBoxExt.cpp (function ??0CXTPControlFontComboBoxList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBoxExt.cpp
