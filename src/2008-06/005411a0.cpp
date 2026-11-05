// from server: 100% by auto
// roc 2008-06 005411a0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005411a0
//
// 005411a0  55                   push ebp
// 005411a1  8bec                 mov ebp, esp
// 005411a3  51                   push ecx
// 005411a4  894dfc               mov dword ptr [ebp - 4], ecx
// 005411a7  8b4508               mov eax, dword ptr [ebp + 8]
// 005411aa  50                   push eax
// 005411ab  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005411ae  e84d330000           call 0x544500
// 005411b3  8be5                 mov esp, ebp
// 005411b5  5d                   pop ebp
// 005411b6  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
