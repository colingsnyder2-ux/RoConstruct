// from server: 100% by auto
// roc 2009-06 0041ef80  unit: CRobloxTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041ef80
//
// 0041ef80  8b442404             mov eax, dword ptr [esp + 4]
// 0041ef84  8b542408             mov edx, dword ptr [esp + 8]
// 0041ef88  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0041ef8b  50                   push eax
// 0041ef8c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0041ef8f  52                   push edx
// 0041ef90  680a110000           push 0x110a
// 0041ef95  50                   push eax
// 0041ef96  ff1590ee8900         call dword ptr [0x89ee90]
// 0041ef9c  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeBase.cpp (function ?GetNextItem@CXTPTreeBase@@UBEPAU_TREEITEM@@PAU2@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeBase.cpp
