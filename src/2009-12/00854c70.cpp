// from server: 100% by auto
// roc 2009-12 00854c70  unit: CXTPTabClientWnd::CSingleWorkspace  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00854c70
//
// 00854c70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00854c74  8b542408             mov edx, dword ptr [esp + 8]
// 00854c78  50                   push eax
// 00854c79  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00854c7c  52                   push edx
// 00854c7d  50                   push eax
// 00854c7e  83c158               add ecx, 0x58
// 00854c81  e8baad0700           call 0x8cfa40
// 00854c86  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseMove@CSingleWorkspace@CXTPTabClientWnd@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
