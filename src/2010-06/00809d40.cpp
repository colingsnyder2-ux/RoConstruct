// from server: 100% by auto
// roc 2010-06 00809d40  unit: CXTPTabClientWnd::CSingleWorkspace  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809d40
//
// 00809d40  83c8ff               or eax, 0xffffffff
// 00809d43  0bd0                 or edx, eax
// 00809d45  52                   push edx
// 00809d46  50                   push eax
// 00809d47  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00809d4a  50                   push eax
// 00809d4b  83c158               add ecx, 0x58
// 00809d4e  e8cd9e0700           call 0x883c20
// 00809d53  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseLeave@CSingleWorkspace@CXTPTabClientWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
