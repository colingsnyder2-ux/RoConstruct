// from server: 100% by auto
// roc 2010-06 0085aed0  unit: CXTPReportNavigator  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085aed0
//
// 0085aed0  56                   push esi
// 0085aed1  8bf1                 mov esi, ecx
// 0085aed3  e8b0d3f4ff           call 0x7a8288
// 0085aed8  33c0                 xor eax, eax
// 0085aeda  894654               mov dword ptr [esi + 0x54], eax
// 0085aedd  894658               mov dword ptr [esi + 0x58], eax
// 0085aee0  89465c               mov dword ptr [esi + 0x5c], eax
// 0085aee3  c70664a2a600         mov dword ptr [esi], 0xa6a264
// 0085aee9  8bc6                 mov eax, esi
// 0085aeeb  5e                   pop esi
// 0085aeec  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
