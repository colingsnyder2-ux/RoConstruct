// from server: 100% by auto
// roc 2007-03 006201d0  unit: seg_00620000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006201d0
//
// 006201d0  56                   push esi
// 006201d1  8bf1                 mov esi, ecx
// 006201d3  e828c30600           call 0x68c500
// 006201d8  33c0                 xor eax, eax
// 006201da  894608               mov dword ptr [esi + 8], eax
// 006201dd  89460c               mov dword ptr [esi + 0xc], eax
// 006201e0  c70624267c00         mov dword ptr [esi], 0x7c2624
// 006201e6  8bc6                 mov eax, esi
// 006201e8  5e                   pop esi
// 006201e9  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??0CXTPControlComboBoxAutoCompleteWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
