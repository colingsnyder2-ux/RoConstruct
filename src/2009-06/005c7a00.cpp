// from server: 100% by auto
// roc 2009-06 005c7a00  unit: seg_005c0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c7a00
//
// 005c7a00  55                   push ebp
// 005c7a01  8bec                 mov ebp, esp
// 005c7a03  51                   push ecx
// 005c7a04  894dfc               mov dword ptr [ebp - 4], ecx
// 005c7a07  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c7a0a  e8a1b9ffff           call 0x5c33b0
// 005c7a0f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c7a12  8be5                 mov esp, ebp
// 005c7a14  5d                   pop ebp
// 005c7a15  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
