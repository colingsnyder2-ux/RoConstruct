// from server: 100% by auto
// roc 2009-06 005c0030  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c0030
//
// 005c0030  55                   push ebp
// 005c0031  8bec                 mov ebp, esp
// 005c0033  51                   push ecx
// 005c0034  894dfc               mov dword ptr [ebp - 4], ecx
// 005c0037  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c003a  e8a1490b00           call 0x6749e0
// 005c003f  8be5                 mov esp, ebp
// 005c0041  5d                   pop ebp
// 005c0042  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
