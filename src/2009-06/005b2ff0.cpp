// from server: 100% by auto
// roc 2009-06 005b2ff0  unit: RBX::RenderNew::TextureProxy  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b2ff0
//
// 005b2ff0  55                   push ebp
// 005b2ff1  8bec                 mov ebp, esp
// 005b2ff3  51                   push ecx
// 005b2ff4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b2ff7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b2ffa  e8710d0000           call 0x5b3d70
// 005b2fff  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b3002  8be5                 mov esp, ebp
// 005b3004  5d                   pop ebp
// 005b3005  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
