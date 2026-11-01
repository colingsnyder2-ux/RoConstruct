// from server: 100% by auto
// roc 2009-12 008349a0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008349a0
//
// 008349a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008349a4  8b542408             mov edx, dword ptr [esp + 8]
// 008349a8  50                   push eax
// 008349a9  8b442408             mov eax, dword ptr [esp + 8]
// 008349ad  52                   push edx
// 008349ae  50                   push eax
// 008349af  83c160               add ecx, 0x60
// 008349b2  e829eaffff           call 0x8333e0
// 008349b7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
