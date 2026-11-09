// from server: 100% by auto
// roc 2010-06 00808cf0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808cf0
//
// 00808cf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00808cf4  8b542408             mov edx, dword ptr [esp + 8]
// 00808cf8  50                   push eax
// 00808cf9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00808cfc  52                   push edx
// 00808cfd  50                   push eax
// 00808cfe  83c158               add ecx, 0x58
// 00808d01  e81aaf0700           call 0x883c20
// 00808d06  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseMove@CSingleWorkspace@CXTPTabClientWnd@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
