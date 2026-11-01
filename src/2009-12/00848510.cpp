// from server: 100% by auto
// roc 2009-12 00848510  unit: CXTPControls  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00848510
//
// 00848510  8b442404             mov eax, dword ptr [esp + 4]
// 00848514  85c0                 test eax, eax
// 00848516  7c14                 jl 0x84852c
// 00848518  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 0084851b  7d0f                 jge 0x84852c
// 0084851d  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00848520  8b0482               mov eax, dword ptr [edx + eax*4]
// 00848523  89442404             mov dword ptr [esp + 4], eax
// 00848527  e964ffffff           jmp 0x848490
// 0084852c  33c0                 xor eax, eax
// 0084852e  89442404             mov dword ptr [esp + 4], eax
// 00848532  e959ffffff           jmp 0x848490
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetControlType@CXTPControls@@QAEPAVCXTPControl@@HW4XTPControlType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
