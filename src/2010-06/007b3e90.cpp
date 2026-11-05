// from server: 100% by auto
// roc 2010-06 007b3e90  unit: CXTPEdit  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3e90
//
// 007b3e90  56                   push esi
// 007b3e91  8bf1                 mov esi, ecx
// 007b3e93  e8e8ca0800           call 0x840980
// 007b3e98  33c0                 xor eax, eax
// 007b3e9a  894608               mov dword ptr [esi + 8], eax
// 007b3e9d  89460c               mov dword ptr [esi + 0xc], eax
// 007b3ea0  c706c45fa500         mov dword ptr [esi], 0xa55fc4
// 007b3ea6  8bc6                 mov eax, esi
// 007b3ea8  5e                   pop esi
// 007b3ea9  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??0CXTPControlComboBoxAutoCompleteWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
