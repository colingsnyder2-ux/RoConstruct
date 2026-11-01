// from server: 100% by auto
// roc 2007-03 004316d0  unit: seg_00430000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004316d0
//
// 004316d0  8b442404             mov eax, dword ptr [esp + 4]
// 004316d4  85c0                 test eax, eax
// 004316d6  7c0e                 jl 0x4316e6
// 004316d8  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 004316db  7d09                 jge 0x4316e6
// 004316dd  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 004316e0  8b0481               mov eax, dword ptr [ecx + eax*4]
// 004316e3  c20400               ret 4
// 004316e6  33c0                 xor eax, eax
// 004316e8  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPControls@@QBEPAVCXTPControl@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
