// from server: 100% by auto
// roc 2009-06 005c1650  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c1650
//
// 005c1650  55                   push ebp
// 005c1651  8bec                 mov ebp, esp
// 005c1653  51                   push ecx
// 005c1654  894dfc               mov dword ptr [ebp - 4], ecx
// 005c1657  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c165a  e8811c0000           call 0x5c32e0
// 005c165f  8be5                 mov esp, ebp
// 005c1661  5d                   pop ebp
// 005c1662  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
