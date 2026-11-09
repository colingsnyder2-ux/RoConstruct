// from server: 100% by auto
// roc 2009-12 009215d0  unit: seg_00920000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009215d0
//
// 009215d0  55                   push ebp
// 009215d1  8bec                 mov ebp, esp
// 009215d3  83ec14               sub esp, 0x14
// 009215d6  894dec               mov dword ptr [ebp - 0x14], ecx
// 009215d9  6a00                 push 0
// 009215db  8b4508               mov eax, dword ptr [ebp + 8]
// 009215de  50                   push eax
// 009215df  e86c110000           call 0x922750
// 009215e4  83c408               add esp, 8
// 009215e7  8be5                 mov esp, ebp
// 009215e9  5d                   pop ebp
// 009215ea  c20400               ret 4
// library wildmagic-2-core/Containment\WmlContSeparatePoints3.cpp (function ?allocate@?$allocator@U_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@std@@@std@@QAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@U?$pair@HH@std@@U?$less@U?$pair@HH@std@@@2@V?$allocator@U?$pair@HH@std@@@2@$0A@@std@@@2@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContSeparatePoints3.cpp
