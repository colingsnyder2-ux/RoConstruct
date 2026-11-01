// from server: 100% by auto
// roc 2010-06 0049d2a0  unit: G3D::VertexAndPixelShader  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0049d2a0
//
// 0049d2a0  55                   push ebp
// 0049d2a1  8bec                 mov ebp, esp
// 0049d2a3  51                   push ecx
// 0049d2a4  894dfc               mov dword ptr [ebp - 4], ecx
// 0049d2a7  8b45fc               mov eax, dword ptr [ebp - 4]
// 0049d2aa  83c048               add eax, 0x48
// 0049d2ad  8be5                 mov esp, ebp
// 0049d2af  5d                   pop ebp
// 0049d2b0  c3                   ret 
// library wildmagic-2-core/Geometry\WmlCircle3.cpp (function ?Center@?$Circle3@N@Wml@@QBEABV?$Vector3@N@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlCircle3.cpp
