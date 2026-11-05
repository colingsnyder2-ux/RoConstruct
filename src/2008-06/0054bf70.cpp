// from server: 100% by auto
// roc 2008-06 0054bf70  unit: RBX::RenderBase::Mesh  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054bf70
//
// 0054bf70  55                   push ebp
// 0054bf71  8bec                 mov ebp, esp
// 0054bf73  51                   push ecx
// 0054bf74  894dfc               mov dword ptr [ebp - 4], ecx
// 0054bf77  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054bf7a  8b4004               mov eax, dword ptr [eax + 4]
// 0054bf7d  8be5                 mov esp, ebp
// 0054bf7f  5d                   pop ebp
// 0054bf80  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ?GetType@?$ConvexHull3@M@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
