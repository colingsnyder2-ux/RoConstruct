// from server: 100% by auto
// roc 2009-06 005bfe40  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfe40
//
// 005bfe40  55                   push ebp
// 005bfe41  8bec                 mov ebp, esp
// 005bfe43  51                   push ecx
// 005bfe44  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfe47  8b4508               mov eax, dword ptr [ebp + 8]
// 005bfe4a  50                   push eax
// 005bfe4b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfe4e  e84d160000           call 0x5c14a0
// 005bfe53  0fb6c0               movzx eax, al
// 005bfe56  f7d8                 neg eax
// 005bfe58  1bc0                 sbb eax, eax
// 005bfe5a  83c001               add eax, 1
// 005bfe5d  8be5                 mov esp, ebp
// 005bfe5f  5d                   pop ebp
// 005bfe60  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??9SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
