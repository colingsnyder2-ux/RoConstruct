// from server: 100% by auto
// roc 2009-12 004ecb70  unit: seg_004e0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ecb70
//
// 004ecb70  55                   push ebp
// 004ecb71  8bec                 mov ebp, esp
// 004ecb73  83ec14               sub esp, 0x14
// 004ecb76  894dec               mov dword ptr [ebp - 0x14], ecx
// 004ecb79  6a00                 push 0
// 004ecb7b  8b4508               mov eax, dword ptr [ebp + 8]
// 004ecb7e  50                   push eax
// 004ecb7f  e88c0b0000           call 0x4ed710
// 004ecb84  83c408               add esp, 8
// 004ecb87  8be5                 mov esp, ebp
// 004ecb89  5d                   pop ebp
// 004ecb8a  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?allocate@?$allocator@U_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@@std@@QAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
