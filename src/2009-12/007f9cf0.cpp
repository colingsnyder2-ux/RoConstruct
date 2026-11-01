// from server: 100% by auto
// roc 2009-12 007f9cf0  unit: CXTPControlComboBoxList  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9cf0
//
// 007f9cf0  56                   push esi
// 007f9cf1  8bf1                 mov esi, ecx
// 007f9cf3  e850a4ffff           call 0x7f4148
// 007f9cf8  33c0                 xor eax, eax
// 007f9cfa  894654               mov dword ptr [esi + 0x54], eax
// 007f9cfd  894658               mov dword ptr [esi + 0x58], eax
// 007f9d00  89465c               mov dword ptr [esi + 0x5c], eax
// 007f9d03  c706ec239f00         mov dword ptr [esi], 0x9f23ec
// 007f9d09  8bc6                 mov eax, esi
// 007f9d0b  5e                   pop esi
// 007f9d0c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
