// from server: 100% by auto
// roc 2009-06 0071aeb0  unit: CXTPEdit  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071aeb0
//
// 0071aeb0  56                   push esi
// 0071aeb1  8bf1                 mov esi, ecx
// 0071aeb3  e898810700           call 0x793050
// 0071aeb8  33c0                 xor eax, eax
// 0071aeba  894608               mov dword ptr [esi + 8], eax
// 0071aebd  89460c               mov dword ptr [esi + 0xc], eax
// 0071aec0  c70650138f00         mov dword ptr [esi], 0x8f1350
// 0071aec6  8bc6                 mov eax, esi
// 0071aec8  5e                   pop esi
// 0071aec9  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??0CXTPControlComboBoxAutoCompleteWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
