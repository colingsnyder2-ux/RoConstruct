// from server: 100% by auto
// roc 2009-06 005b3b30  unit: seg_005b0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3b30
//
// 005b3b30  55                   push ebp
// 005b3b31  8bec                 mov ebp, esp
// 005b3b33  51                   push ecx
// 005b3b34  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3b37  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b3b3a  8be5                 mov esp, ebp
// 005b3b3c  5d                   pop ebp
// 005b3b3d  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMin@?$AxisAlignedBox2@M@Wml@@QAEAAMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
