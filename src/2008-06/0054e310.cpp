// from server: 100% by auto
// roc 2008-06 0054e310  unit: RBX::RenderBase::Mesh  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054e310
//
// 0054e310  55                   push ebp
// 0054e311  8bec                 mov ebp, esp
// 0054e313  51                   push ecx
// 0054e314  894dfc               mov dword ptr [ebp - 4], ecx
// 0054e317  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054e31a  8be5                 mov esp, ebp
// 0054e31c  5d                   pop ebp
// 0054e31d  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMin@?$AxisAlignedBox2@M@Wml@@QAEAAMXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
