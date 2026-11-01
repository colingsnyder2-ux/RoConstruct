// from server: 100% by auto
// roc 2007-03 00698960  unit: seg_00690000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00698960
//
// 00698960  8b442404             mov eax, dword ptr [esp + 4]
// 00698964  6a01                 push 1
// 00698966  6a01                 push 1
// 00698968  50                   push eax
// 00698969  ff159ced7700         call dword ptr [0x77ed9c]
// 0069896f  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?AdjustExcludeRect@CControlMDISysMenuPopup@CXTPMenuBar@@UAEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
