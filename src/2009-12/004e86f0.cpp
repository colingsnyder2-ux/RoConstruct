// from server: 100% by auto
// roc 2009-12 004e86f0  unit: seg_004e0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e86f0
//
// 004e86f0  55                   push ebp
// 004e86f1  8bec                 mov ebp, esp
// 004e86f3  83ec14               sub esp, 0x14
// 004e86f6  894dec               mov dword ptr [ebp - 0x14], ecx
// 004e86f9  6a00                 push 0
// 004e86fb  8b4508               mov eax, dword ptr [ebp + 8]
// 004e86fe  50                   push eax
// 004e86ff  e87c070000           call 0x4e8e80
// 004e8704  83c408               add esp, 8
// 004e8707  8be5                 mov esp, ebp
// 004e8709  5d                   pop ebp
// 004e870a  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?allocate@?$allocator@U_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@@std@@QAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
