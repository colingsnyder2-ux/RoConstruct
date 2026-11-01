// from server: 100% by auto
// roc 2007-03 0062c030  unit: seg_00620000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062c030
//
// 0062c030  8b442404             mov eax, dword ptr [esp + 4]
// 0062c034  85c0                 test eax, eax
// 0062c036  7c14                 jl 0x62c04c
// 0062c038  3b8184000000         cmp eax, dword ptr [ecx + 0x84]
// 0062c03e  7d0c                 jge 0x62c04c
// 0062c040  8b8980000000         mov ecx, dword ptr [ecx + 0x80]
// 0062c046  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0062c049  c20400               ret 4
// 0062c04c  33c0                 xor eax, eax
// 0062c04e  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?GetAt@CXTPCommandBars@@QBEPAVCXTPToolBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
