// from server: 100% by auto
// roc 2009-12 00855e10  unit: CXTPTabClientWnd::CSingleWorkspace  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00855e10
//
// 00855e10  83c8ff               or eax, 0xffffffff
// 00855e13  0bd0                 or edx, eax
// 00855e15  52                   push edx
// 00855e16  50                   push eax
// 00855e17  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00855e1a  50                   push eax
// 00855e1b  83c158               add ecx, 0x58
// 00855e1e  e81d9c0700           call 0x8cfa40
// 00855e23  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseLeave@CSingleWorkspace@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
