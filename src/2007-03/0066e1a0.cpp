// from server: 100% by auto
// roc 2007-03 0066e1a0  unit: seg_00660000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e1a0
//
// 0066e1a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066e1a4  8b542408             mov edx, dword ptr [esp + 8]
// 0066e1a8  50                   push eax
// 0066e1a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0066e1ac  52                   push edx
// 0066e1ad  50                   push eax
// 0066e1ae  83c158               add ecx, 0x58
// 0066e1b1  e8fa8e0700           call 0x6e70b0
// 0066e1b6  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMouseMove@CSingleWorkspace@CXTPTabClientWnd@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
