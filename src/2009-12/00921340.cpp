// from server: 100% by auto
// roc 2009-12 00921340  unit: seg_00920000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00921340
//
// 00921340  55                   push ebp
// 00921341  8bec                 mov ebp, esp
// 00921343  83ec14               sub esp, 0x14
// 00921346  894dec               mov dword ptr [ebp - 0x14], ecx
// 00921349  6a00                 push 0
// 0092134b  8b4508               mov eax, dword ptr [ebp + 8]
// 0092134e  50                   push eax
// 0092134f  e82c130000           call 0x922680
// 00921354  83c408               add esp, 8
// 00921357  8be5                 mov esp, ebp
// 00921359  5d                   pop ebp
// 0092135a  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?allocate@?$allocator@U_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@@std@@QAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
