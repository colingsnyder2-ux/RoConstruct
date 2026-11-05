// from server: 100% by auto
// roc 2009-06 005b6070  unit: seg_005b0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b6070
//
// 005b6070  55                   push ebp
// 005b6071  8bec                 mov ebp, esp
// 005b6073  51                   push ecx
// 005b6074  894dfc               mov dword ptr [ebp - 4], ecx
// 005b6077  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b607a  e851080000           call 0x5b68d0
// 005b607f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b6082  8be5                 mov esp, ebp
// 005b6084  5d                   pop ebp
// 005b6085  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
