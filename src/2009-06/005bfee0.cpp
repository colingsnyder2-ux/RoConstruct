// from server: 100% by auto
// roc 2009-06 005bfee0  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfee0
//
// 005bfee0  55                   push ebp
// 005bfee1  8bec                 mov ebp, esp
// 005bfee3  51                   push ecx
// 005bfee4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfee7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfeea  e861cffeff           call 0x5ace50
// 005bfeef  8be5                 mov esp, ebp
// 005bfef1  5d                   pop ebp
// 005bfef2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
