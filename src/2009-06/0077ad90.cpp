// from server: 100% by auto
// roc 2009-06 0077ad90  unit: CXTPTabClientWnd::CSingleWorkspace  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ad90
//
// 0077ad90  83c8ff               or eax, 0xffffffff
// 0077ad93  0bd0                 or edx, eax
// 0077ad95  52                   push edx
// 0077ad96  50                   push eax
// 0077ad97  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0077ad9a  50                   push eax
// 0077ad9b  83c158               add ecx, 0x58
// 0077ad9e  e8eda00700           call 0x7f4e90
// 0077ada3  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseLeave@CSingleWorkspace@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
