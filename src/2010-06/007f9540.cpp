// from server: 100% by auto
// roc 2010-06 007f9540  unit: CXTPControls  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f9540
//
// 007f9540  8b442404             mov eax, dword ptr [esp + 4]
// 007f9544  85c0                 test eax, eax
// 007f9546  7c0d                 jl 0x7f9555
// 007f9548  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 007f954b  7d08                 jge 0x7f9555
// 007f954d  8b5128               mov edx, dword ptr [ecx + 0x28]
// 007f9550  8b0482               mov eax, dword ptr [edx + eax*4]
// 007f9553  eb02                 jmp 0x7f9557
// 007f9555  33c0                 xor eax, eax
// 007f9557  8b11                 mov edx, dword ptr [ecx]
// 007f9559  89442404             mov dword ptr [esp + 4], eax
// 007f955d  8b4258               mov eax, dword ptr [edx + 0x58]
// 007f9560  ffe0                 jmp eax
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControls.cpp (function ?Remove@CXTPControls@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControls.cpp
