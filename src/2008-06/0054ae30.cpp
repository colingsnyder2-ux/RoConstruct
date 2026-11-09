// from server: 100% by auto
// roc 2008-06 0054ae30  unit: RBX::RenderBase::Mesh  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054ae30
//
// 0054ae30  55                   push ebp
// 0054ae31  8bec                 mov ebp, esp
// 0054ae33  51                   push ecx
// 0054ae34  894dfc               mov dword ptr [ebp - 4], ecx
// 0054ae37  8b4508               mov eax, dword ptr [ebp + 8]
// 0054ae3a  50                   push eax
// 0054ae3b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ae3e  e82dffffff           call 0x54ad70
// 0054ae43  8be5                 mov esp, ebp
// 0054ae45  5d                   pop ebp
// 0054ae46  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
