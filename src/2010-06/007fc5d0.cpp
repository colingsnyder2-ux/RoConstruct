// from server: 100% by auto
// roc 2010-06 007fc5d0  unit: CXTPControls  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007fc5d0
//
// 007fc5d0  8b442404             mov eax, dword ptr [esp + 4]
// 007fc5d4  85c0                 test eax, eax
// 007fc5d6  7c14                 jl 0x7fc5ec
// 007fc5d8  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 007fc5db  7d0f                 jge 0x7fc5ec
// 007fc5dd  8b5128               mov edx, dword ptr [ecx + 0x28]
// 007fc5e0  8b0482               mov eax, dword ptr [edx + eax*4]
// 007fc5e3  89442404             mov dword ptr [esp + 4], eax
// 007fc5e7  e964ffffff           jmp 0x7fc550
// 007fc5ec  33c0                 xor eax, eax
// 007fc5ee  89442404             mov dword ptr [esp + 4], eax
// 007fc5f2  e959ffffff           jmp 0x7fc550
// library xtp-13.2.1/Source\CommandBars\XTPControls.cpp (function ?SetControlType@CXTPControls@@QAEPAVCXTPControl@@HW4XTPControlType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControls.cpp
