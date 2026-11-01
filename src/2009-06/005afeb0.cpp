// from server: 100% by auto
// roc 2009-06 005afeb0  unit: RBX::RenderNew::TextureProxy  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005afeb0
//
// 005afeb0  55                   push ebp
// 005afeb1  8bec                 mov ebp, esp
// 005afeb3  51                   push ecx
// 005afeb4  894dfc               mov dword ptr [ebp - 4], ecx
// 005afeb7  8b45fc               mov eax, dword ptr [ebp - 4]
// 005afeba  83c020               add eax, 0x20
// 005afebd  8be5                 mov esp, ebp
// 005afebf  5d                   pop ebp
// 005afec0  c3                   ret 
// library wildmagic-2-core/Geometry\WmlAxisAlignedBox3.cpp (function ?YMax@?$AxisAlignedBox3@N@Wml@@QAEAANXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlAxisAlignedBox3.cpp
