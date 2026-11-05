// from server: 100% by auto
// roc 2011-06 00588480  unit: seg_00580000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00588480
//
// 00588480  55                   push ebp
// 00588481  8bec                 mov ebp, esp
// 00588483  51                   push ecx
// 00588484  894dfc               mov dword ptr [ebp - 4], ecx
// 00588487  8b45fc               mov eax, dword ptr [ebp - 4]
// 0058848a  8be5                 mov esp, ebp
// 0058848c  5d                   pop ebp
// 0058848d  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMin@?$AxisAlignedBox2@M@Wml@@QAEAAMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
