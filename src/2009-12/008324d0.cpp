// from server: 100% by auto
// roc 2009-12 008324d0  unit: CRobloxTreeCtrl  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008324d0
//
// 008324d0  83790400             cmp dword ptr [ecx + 4], 0
// 008324d4  7411                 je 0x8324e7
// 008324d6  8b442404             mov eax, dword ptr [esp + 4]
// 008324da  6a03                 push 3
// 008324dc  6a03                 push 3
// 008324de  50                   push eax
// 008324df  e86cfcffff           call 0x832150
// 008324e4  c20400               ret 4
// 008324e7  8b542404             mov edx, dword ptr [esp + 4]
// 008324eb  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 008324ee  8b4120               mov eax, dword ptr [ecx + 0x20]
// 008324f1  52                   push edx
// 008324f2  6a09                 push 9
// 008324f4  680b110000           push 0x110b
// 008324f9  50                   push eax
// 008324fa  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832500  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SelectItem@CXTPTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
