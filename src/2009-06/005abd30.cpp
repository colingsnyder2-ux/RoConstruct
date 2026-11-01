// from server: 100% by auto
// roc 2009-06 005abd30  unit: RBX::Mesh  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005abd30
//
// 005abd30  55                   push ebp
// 005abd31  8bec                 mov ebp, esp
// 005abd33  51                   push ecx
// 005abd34  894dfc               mov dword ptr [ebp - 4], ecx
// 005abd37  8b45fc               mov eax, dword ptr [ebp - 4]
// 005abd3a  8b4004               mov eax, dword ptr [eax + 4]
// 005abd3d  8be5                 mov esp, ebp
// 005abd3f  5d                   pop ebp
// 005abd40  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ?GetType@?$ConvexHull3@M@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
