// from server: 100% by auto
// roc 2010-06 0042e450  unit: CRobloxTreeCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042e450
//
// 0042e450  8b442404             mov eax, dword ptr [esp + 4]
// 0042e454  8b542408             mov edx, dword ptr [esp + 8]
// 0042e458  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0042e45b  50                   push eax
// 0042e45c  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0042e45f  52                   push edx
// 0042e460  680a110000           push 0x110a
// 0042e465  50                   push eax
// 0042e466  ff1554ba9e00         call dword ptr [0x9eba54]
// 0042e46c  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTShellTreeBase.cpp (function ?GetNextItem@CXTTreeBase@@UBEPAU_TREEITEM@@PAU2@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeBase.cpp
