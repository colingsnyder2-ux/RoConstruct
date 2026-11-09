// from server: 100% by auto
// roc 2008-06 00541290  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00541290
//
// 00541290  55                   push ebp
// 00541291  8bec                 mov ebp, esp
// 00541293  51                   push ecx
// 00541294  894dfc               mov dword ptr [ebp - 4], ecx
// 00541297  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054129a  e841b20000           call 0x54c4e0
// 0054129f  8be5                 mov esp, ebp
// 005412a1  5d                   pop ebp
// 005412a2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
