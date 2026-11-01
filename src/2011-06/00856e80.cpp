// from server: 100% by auto
// roc 2011-06 00856e80  unit: CXTPControls  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00856e80
//
// 00856e80  8b442404             mov eax, dword ptr [esp + 4]
// 00856e84  85c0                 test eax, eax
// 00856e86  7c0d                 jl 0x856e95
// 00856e88  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 00856e8b  7d08                 jge 0x856e95
// 00856e8d  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00856e90  8b0482               mov eax, dword ptr [edx + eax*4]
// 00856e93  eb02                 jmp 0x856e97
// 00856e95  33c0                 xor eax, eax
// 00856e97  8b11                 mov edx, dword ptr [ecx]
// 00856e99  89442404             mov dword ptr [esp + 4], eax
// 00856e9d  8b4258               mov eax, dword ptr [edx + 0x58]
// 00856ea0  ffe0                 jmp eax
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?Remove@CXTPControls@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
