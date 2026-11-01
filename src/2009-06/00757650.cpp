// from server: 100% by auto
// roc 2009-06 00757650  unit: CRobloxTreeCtrl  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757650
//
// 00757650  83790400             cmp dword ptr [ecx + 4], 0
// 00757654  7411                 je 0x757667
// 00757656  8b442404             mov eax, dword ptr [esp + 4]
// 0075765a  6a03                 push 3
// 0075765c  6a03                 push 3
// 0075765e  50                   push eax
// 0075765f  e86cfcffff           call 0x7572d0
// 00757664  c20400               ret 4
// 00757667  8b542404             mov edx, dword ptr [esp + 4]
// 0075766b  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0075766e  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00757671  52                   push edx
// 00757672  6a09                 push 9
// 00757674  680b110000           push 0x110b
// 00757679  50                   push eax
// 0075767a  ff1590ee8900         call dword ptr [0x89ee90]
// 00757680  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectItem@CXTPTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
