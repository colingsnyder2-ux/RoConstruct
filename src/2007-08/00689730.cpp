// from server: 100% by auto
// roc 2007-08 00689730  unit: CXTPTabClientWnd::CWorkspace  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689730
//
// 00689730  8b898c000000         mov ecx, dword ptr [ecx + 0x8c]
// 00689736  8b01                 mov eax, dword ptr [ecx]
// 00689738  8b8070010000         mov eax, dword ptr [eax + 0x170]
// 0068973e  ffe0                 jmp eax
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnBeforeItemClick@CWorkspace@CXTPTabClientWnd@@MAEHPAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
