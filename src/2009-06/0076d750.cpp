// from server: 100% by auto
// roc 2009-06 0076d750  unit: CXTPControls  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076d750
//
// 0076d750  8b442404             mov eax, dword ptr [esp + 4]
// 0076d754  85c0                 test eax, eax
// 0076d756  7c14                 jl 0x76d76c
// 0076d758  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 0076d75b  7d0f                 jge 0x76d76c
// 0076d75d  8b5128               mov edx, dword ptr [ecx + 0x28]
// 0076d760  8b0482               mov eax, dword ptr [edx + eax*4]
// 0076d763  89442404             mov dword ptr [esp + 4], eax
// 0076d767  e964ffffff           jmp 0x76d6d0
// 0076d76c  33c0                 xor eax, eax
// 0076d76e  89442404             mov dword ptr [esp + 4], eax
// 0076d772  e959ffffff           jmp 0x76d6d0
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetControlType@CXTPControls@@QAEPAVCXTPControl@@HW4XTPControlType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
