// from server: 100% by auto
// roc 2009-06 005c5eb0  unit: seg_005c0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c5eb0
//
// 005c5eb0  55                   push ebp
// 005c5eb1  8bec                 mov ebp, esp
// 005c5eb3  51                   push ecx
// 005c5eb4  894dfc               mov dword ptr [ebp - 4], ecx
// 005c5eb7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c5eba  e8119effff           call 0x5bfcd0
// 005c5ebf  8be5                 mov esp, ebp
// 005c5ec1  5d                   pop ebp
// 005c5ec2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
