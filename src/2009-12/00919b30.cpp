// from server: 100% by auto
// roc 2009-12 00919b30  unit: RBX::AggregateChunk  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00919b30
//
// 00919b30  55                   push ebp
// 00919b31  8bec                 mov ebp, esp
// 00919b33  51                   push ecx
// 00919b34  894dfc               mov dword ptr [ebp - 4], ecx
// 00919b37  8b45fc               mov eax, dword ptr [ebp - 4]
// 00919b3a  83c078               add eax, 0x78
// 00919b3d  8be5                 mov esp, ebp
// 00919b3f  5d                   pop ebp
// 00919b40  c3                   ret 
// library wildmagic-2-core/Geometry\WmlFrustum3.cpp (function ?DMax@?$Frustum3@N@Wml@@QBEABNXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlFrustum3.cpp
