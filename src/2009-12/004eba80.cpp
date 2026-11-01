// from server: 100% by auto
// roc 2009-12 004eba80  unit: seg_004e0000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004eba80
//
// 004eba80  55                   push ebp
// 004eba81  8bec                 mov ebp, esp
// 004eba83  51                   push ecx
// 004eba84  894dfc               mov dword ptr [ebp - 4], ecx
// 004eba87  8b45fc               mov eax, dword ptr [ebp - 4]
// 004eba8a  8be5                 mov esp, ebp
// 004eba8c  5d                   pop ebp
// 004eba8d  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMin@?$AxisAlignedBox2@M@Wml@@QAEAAMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
