// from server: 100% by auto
// roc 2009-06 005c4380  unit: seg_005c0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c4380
//
// 005c4380  55                   push ebp
// 005c4381  8bec                 mov ebp, esp
// 005c4383  51                   push ecx
// 005c4384  894dfc               mov dword ptr [ebp - 4], ecx
// 005c4387  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c438a  e8e1ebffff           call 0x5c2f70
// 005c438f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c4392  8be5                 mov esp, ebp
// 005c4394  5d                   pop ebp
// 005c4395  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
