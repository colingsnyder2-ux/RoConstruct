// from server: 100% by auto
// roc 2009-06 00779ef0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00779ef0
//
// 00779ef0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00779ef4  8b542408             mov edx, dword ptr [esp + 8]
// 00779ef8  50                   push eax
// 00779ef9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00779efc  52                   push edx
// 00779efd  50                   push eax
// 00779efe  83c158               add ecx, 0x58
// 00779f01  e88aaf0700           call 0x7f4e90
// 00779f06  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseMove@CSingleWorkspace@CXTPTabClientWnd@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
