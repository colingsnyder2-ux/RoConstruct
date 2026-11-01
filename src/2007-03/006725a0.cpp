// from server: 100% by auto
// roc 2007-03 006725a0  unit: seg_00670000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006725a0
//
// 006725a0  8b01                 mov eax, dword ptr [ecx]
// 006725a2  8b506c               mov edx, dword ptr [eax + 0x6c]
// 006725a5  ffd2                 call edx
// 006725a7  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?OnControlAdded@CXTPControls@@MAEXPAVCXTPControl@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
