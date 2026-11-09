// from server: 100% by auto
// roc 2009-06 005c5df0  unit: seg_005c0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c5df0
//
// 005c5df0  55                   push ebp
// 005c5df1  8bec                 mov ebp, esp
// 005c5df3  51                   push ecx
// 005c5df4  894dfc               mov dword ptr [ebp - 4], ecx
// 005c5df7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c5dfa  e811040000           call 0x5c6210
// 005c5dff  8be5                 mov esp, ebp
// 005c5e01  5d                   pop ebp
// 005c5e02  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
