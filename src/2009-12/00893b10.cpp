// from server: 100% by auto
// roc 2009-12 00893b10  unit: CXTPMenuBar::CControlMDISysMenuPopup  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00893b10
//
// 00893b10  8b442404             mov eax, dword ptr [esp + 4]
// 00893b14  6a01                 push 1
// 00893b16  6a01                 push 1
// 00893b18  50                   push eax
// 00893b19  ff1558ca9800         call dword ptr [0x98ca58]
// 00893b1f  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?AdjustExcludeRect@CControlMDISysMenuPopup@CXTPMenuBar@@UAEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
