// from server: 100% by auto
// roc 2009-06 007b6930  unit: CXTPMenuBar::CControlMDISysMenuPopup  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b6930
//
// 007b6930  8b442404             mov eax, dword ptr [esp + 4]
// 007b6934  6a01                 push 1
// 007b6936  6a01                 push 1
// 007b6938  50                   push eax
// 007b6939  ff15bced8900         call dword ptr [0x89edbc]
// 007b693f  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPMenuBar.cpp (function ?AdjustExcludeRect@CControlMDISysMenuPopup@CXTPMenuBar@@UAEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMenuBar.cpp
