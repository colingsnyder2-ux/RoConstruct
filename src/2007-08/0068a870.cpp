// from server: 100% by auto
// roc 2007-08 0068a870  unit: CXTPTabClientWnd::CSingleWorkspace  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068a870
//
// 0068a870  83c8ff               or eax, 0xffffffff
// 0068a873  0bd0                 or edx, eax
// 0068a875  52                   push edx
// 0068a876  50                   push eax
// 0068a877  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0068a87a  50                   push eax
// 0068a87b  83c158               add ecx, 0x58
// 0068a87e  e86d430700           call 0x6febf0
// 0068a883  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseLeave@CSingleWorkspace@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
