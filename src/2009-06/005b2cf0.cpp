// from server: 100% by auto
// roc 2009-06 005b2cf0  unit: RBX::RenderNew::TextureProxy  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b2cf0
//
// 005b2cf0  55                   push ebp
// 005b2cf1  8bec                 mov ebp, esp
// 005b2cf3  51                   push ecx
// 005b2cf4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b2cf7  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b2cfa  83c010               add eax, 0x10
// 005b2cfd  8be5                 mov esp, ebp
// 005b2cff  5d                   pop ebp
// 005b2d00  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox2.cpp (function ?XMax@?$AxisAlignedBox2@N@Wml@@QAEAANXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox2.cpp
