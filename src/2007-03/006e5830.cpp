// from server: 100% by auto
// roc 2007-03 006e5830  unit: seg_006e0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e5830
//
// 006e5830  8b442404             mov eax, dword ptr [esp + 4]
// 006e5834  83780402             cmp dword ptr [eax + 4], 2
// 006e5838  7512                 jne 0x6e584c
// 006e583a  8b4104               mov eax, dword ptr [ecx + 4]
// 006e583d  85c0                 test eax, eax
// 006e583f  7406                 je 0x6e5847
// 006e5841  8b4068               mov eax, dword ptr [eax + 0x68]
// 006e5844  c20400               ret 4
// 006e5847  33c0                 xor eax, eax
// 006e5849  c20400               ret 4
// 006e584c  b801000000           mov eax, 1
// 006e5851  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?IsNavigateButtonAutomaticVisible@CXTPTabManager@@MAEHPAVCXTPTabManagerNavigateButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
