// from server: 100% by auto
// roc 2010-06 00429050  unit: CPatchedControlComboBox  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00429050
//
// 00429050  8b442404             mov eax, dword ptr [esp + 4]
// 00429054  85c0                 test eax, eax
// 00429056  7c0e                 jl 0x429066
// 00429058  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 0042905b  7d09                 jge 0x429066
// 0042905d  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00429060  8b0481               mov eax, dword ptr [ecx + eax*4]
// 00429063  c20400               ret 4
// 00429066  33c0                 xor eax, eax
// 00429068  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPControls@@QBEPAVCXTPControl@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
