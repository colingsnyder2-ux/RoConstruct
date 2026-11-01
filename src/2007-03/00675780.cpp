// from server: 100% by auto
// roc 2007-03 00675780  unit: seg_00670000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00675780
//
// 00675780  8b442404             mov eax, dword ptr [esp + 4]
// 00675784  85c0                 test eax, eax
// 00675786  7c14                 jl 0x67579c
// 00675788  3b412c               cmp eax, dword ptr [ecx + 0x2c]
// 0067578b  7d0f                 jge 0x67579c
// 0067578d  8b5128               mov edx, dword ptr [ecx + 0x28]
// 00675790  8b0482               mov eax, dword ptr [edx + eax*4]
// 00675793  89442404             mov dword ptr [esp + 4], eax
// 00675797  e964ffffff           jmp 0x675700
// 0067579c  33c0                 xor eax, eax
// 0067579e  89442404             mov dword ptr [esp + 4], eax
// 006757a2  e959ffffff           jmp 0x675700
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetControlType@CXTPControls@@QAEPAVCXTPControl@@HW4XTPControlType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
