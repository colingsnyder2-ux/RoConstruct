// from server: 100% by auto
// roc 2007-03 006202d0  unit: seg_00620000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006202d0
//
// 006202d0  8b4108               mov eax, dword ptr [ecx + 8]
// 006202d3  85c0                 test eax, eax
// 006202d5  7409                 je 0x6202e0
// 006202d7  6a00                 push 0
// 006202d9  50                   push eax
// 006202da  ff1510ee7700         call dword ptr [0x77ee10]
// 006202e0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?CloseWindow@CXTPControlComboBoxAutoCompleteWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlComboBox.cpp
