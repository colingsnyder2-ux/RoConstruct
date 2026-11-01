// from server: 100% by auto
// roc 2009-12 007f90c0  unit: CXTPEdit  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f90c0
//
// 007f90c0  56                   push esi
// 007f90c1  8bf1                 mov esi, ecx
// 007f90c3  e8d8730700           call 0x8704a0
// 007f90c8  33c0                 xor eax, eax
// 007f90ca  894608               mov dword ptr [esi + 8], eax
// 007f90cd  89460c               mov dword ptr [esi + 0xc], eax
// 007f90d0  c706401b9f00         mov dword ptr [esi], 0x9f1b40
// 007f90d6  8bc6                 mov eax, esi
// 007f90d8  5e                   pop esi
// 007f90d9  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??0CXTPControlComboBoxAutoCompleteWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
