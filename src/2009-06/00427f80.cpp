// from server: 100% by auto
// roc 2009-06 00427f80  unit: CPatchedControlComboBox  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00427f80
//
// 00427f80  8b442404             mov eax, dword ptr [esp + 4]
// 00427f84  85c0                 test eax, eax
// 00427f86  7c0e                 jl 0x427f96
// 00427f88  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 00427f8b  7d09                 jge 0x427f96
// 00427f8d  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00427f90  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00427f93  c20400               ret 4
// 00427f96  33c0                 xor eax, eax
// 00427f98  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPControls@@QBEPAVCXTPControl@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
