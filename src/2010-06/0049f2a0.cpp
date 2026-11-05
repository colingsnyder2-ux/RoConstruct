// from server: 100% by auto
// roc 2010-06 0049f2a0  unit: seg_00490000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0049f2a0
//
// 0049f2a0  55                   push ebp
// 0049f2a1  8bec                 mov ebp, esp
// 0049f2a3  51                   push ecx
// 0049f2a4  894dfc               mov dword ptr [ebp - 4], ecx
// 0049f2a7  8b45fc               mov eax, dword ptr [ebp - 4]
// 0049f2aa  8be5                 mov esp, ebp
// 0049f2ac  5d                   pop ebp
// 0049f2ad  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMin@?$AxisAlignedBox2@M@Wml@@QAEAAMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
