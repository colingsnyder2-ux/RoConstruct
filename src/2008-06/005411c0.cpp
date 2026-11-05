// from server: 100% by auto
// roc 2008-06 005411c0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005411c0
//
// 005411c0  55                   push ebp
// 005411c1  8bec                 mov ebp, esp
// 005411c3  51                   push ecx
// 005411c4  894dfc               mov dword ptr [ebp - 4], ecx
// 005411c7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005411ca  e8b1030000           call 0x541580
// 005411cf  8be5                 mov esp, ebp
// 005411d1  5d                   pop ebp
// 005411d2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
