// from server: 100% by auto
// roc 2008-06 00541180  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00541180
//
// 00541180  55                   push ebp
// 00541181  8bec                 mov ebp, esp
// 00541183  51                   push ecx
// 00541184  894dfc               mov dword ptr [ebp - 4], ecx
// 00541187  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054118a  e801180000           call 0x542990
// 0054118f  8be5                 mov esp, ebp
// 00541191  5d                   pop ebp
// 00541192  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
