// from server: 100% by auto
// roc 2008-06 00542640  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00542640
//
// 00542640  55                   push ebp
// 00542641  8bec                 mov ebp, esp
// 00542643  51                   push ecx
// 00542644  894dfc               mov dword ptr [ebp - 4], ecx
// 00542647  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054264a  e8011d0000           call 0x544350
// 0054264f  8be5                 mov esp, ebp
// 00542651  5d                   pop ebp
// 00542652  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
