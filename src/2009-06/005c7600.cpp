// from server: 100% by auto
// roc 2009-06 005c7600  unit: seg_005c0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c7600
//
// 005c7600  55                   push ebp
// 005c7601  8bec                 mov ebp, esp
// 005c7603  51                   push ecx
// 005c7604  894dfc               mov dword ptr [ebp - 4], ecx
// 005c7607  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c760a  e841030000           call 0x5c7950
// 005c760f  8be5                 mov esp, ebp
// 005c7611  5d                   pop ebp
// 005c7612  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
