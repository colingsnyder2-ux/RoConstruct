// from server: 100% by auto
// roc 2009-06 005b3600  unit: RBX::RenderNew::TextureProxy  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3600
//
// 005b3600  55                   push ebp
// 005b3601  8bec                 mov ebp, esp
// 005b3603  51                   push ecx
// 005b3604  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3607  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b360a  e821f4ffff           call 0x5b2a30
// 005b360f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b3612  8be5                 mov esp, ebp
// 005b3614  5d                   pop ebp
// 005b3615  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
