// from server: 100% by auto
// roc 2009-12 00428c50  unit: CPatchedControlComboBox  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00428c50
//
// 00428c50  8b442404             mov eax, dword ptr [esp + 4]
// 00428c54  85c0                 test eax, eax
// 00428c56  7c0e                 jl 0x428c66
// 00428c58  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 00428c5b  7d09                 jge 0x428c66
// 00428c5d  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00428c60  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00428c63  c20400               ret 4
// 00428c66  33c0                 xor eax, eax
// 00428c68  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPControls@@QBEPAVCXTPControl@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
