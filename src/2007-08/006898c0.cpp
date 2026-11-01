// from server: 100% by auto
// roc 2007-08 006898c0  unit: CXTPTabClientWnd::CSingleWorkspace  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006898c0
//
// 006898c0  8b91e4000000         mov edx, dword ptr [ecx + 0xe4]
// 006898c6  b801000000           mov eax, 1
// 006898cb  89425c               mov dword ptr [edx + 0x5c], eax
// 006898ce  8b91e4000000         mov edx, dword ptr [ecx + 0xe4]
// 006898d4  894258               mov dword ptr [edx + 0x58], eax
// 006898d7  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006898db  8b542408             mov edx, dword ptr [esp + 8]
// 006898df  6a00                 push 0
// 006898e1  50                   push eax
// 006898e2  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006898e5  52                   push edx
// 006898e6  50                   push eax
// 006898e7  83c158               add ecx, 0x58
// 006898ea  e8d15e0700           call 0x6ff7c0
// 006898ef  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnLButtonDown@CSingleWorkspace@CXTPTabClientWnd@@QAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
