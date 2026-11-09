// from server: 100% by auto
// roc 2010-06 004a0390  unit: seg_004a0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a0390
//
// 004a0390  55                   push ebp
// 004a0391  8bec                 mov ebp, esp
// 004a0393  83ec14               sub esp, 0x14
// 004a0396  894dec               mov dword ptr [ebp - 0x14], ecx
// 004a0399  6a00                 push 0
// 004a039b  8b4508               mov eax, dword ptr [ebp + 8]
// 004a039e  50                   push eax
// 004a039f  e88c0b0000           call 0x4a0f30
// 004a03a4  83c408               add esp, 8
// 004a03a7  8be5                 mov esp, ebp
// 004a03a9  5d                   pop ebp
// 004a03aa  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?allocate@?$allocator@U_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@@std@@QAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
