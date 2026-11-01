// from server: 100% by auto
// roc 2007-03 0065a090  unit: seg_00650000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065a090
//
// 0065a090  8b442404             mov eax, dword ptr [esp + 4]
// 0065a094  85c0                 test eax, eax
// 0065a096  7416                 je 0x65a0ae
// 0065a098  8d4820               lea ecx, [eax + 0x20]
// 0065a09b  8b01                 mov eax, dword ptr [ecx]
// 0065a09d  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0065a0a0  ffd2                 call edx
// 0065a0a2  85c0                 test eax, eax
// 0065a0a4  7408                 je 0x65a0ae
// 0065a0a6  b801000000           mov eax, 1
// 0065a0ab  c20400               ret 4
// 0065a0ae  33c0                 xor eax, eax
// 0065a0b0  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneHidden@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
