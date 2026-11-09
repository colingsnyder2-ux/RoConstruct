// from server: 100% by auto
// roc 2008-06 0054db80  unit: RBX::RenderBase::Mesh  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054db80
//
// 0054db80  55                   push ebp
// 0054db81  8bec                 mov ebp, esp
// 0054db83  51                   push ecx
// 0054db84  894dfc               mov dword ptr [ebp - 4], ecx
// 0054db87  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054db8a  e8d1140000           call 0x54f060
// 0054db8f  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054db92  8be5                 mov esp, ebp
// 0054db94  5d                   pop ebp
// 0054db95  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
