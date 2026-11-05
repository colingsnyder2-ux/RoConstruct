// from server: 100% by auto
// roc 2010-06 00847d10  unit: CXTPMenuBar::CControlMDISysMenuPopup  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847d10
//
// 00847d10  8b442404             mov eax, dword ptr [esp + 4]
// 00847d14  6a01                 push 1
// 00847d16  6a01                 push 1
// 00847d18  50                   push eax
// 00847d19  ff15dcbb9e00         call dword ptr [0x9ebbdc]
// 00847d1f  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?AdjustExcludeRect@CControlMDISysMenuPopup@CXTPMenuBar@@UAEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMenuBar.cpp
