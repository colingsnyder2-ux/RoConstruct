// from server: 100% by auto
// roc 2008-06 00541160  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00541160
//
// 00541160  55                   push ebp
// 00541161  8bec                 mov ebp, esp
// 00541163  51                   push ecx
// 00541164  894dfc               mov dword ptr [ebp - 4], ecx
// 00541167  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054116a  e8c1170000           call 0x542930
// 0054116f  8b45fc               mov eax, dword ptr [ebp - 4]
// 00541172  8be5                 mov esp, ebp
// 00541174  5d                   pop ebp
// 00541175  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
