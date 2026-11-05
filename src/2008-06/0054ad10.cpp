// from server: 100% by auto
// roc 2008-06 0054ad10  unit: RBX::RenderBase::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054ad10
//
// 0054ad10  55                   push ebp
// 0054ad11  8bec                 mov ebp, esp
// 0054ad13  51                   push ecx
// 0054ad14  894dfc               mov dword ptr [ebp - 4], ecx
// 0054ad17  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ad1a  e871160000           call 0x54c390
// 0054ad1f  8be5                 mov esp, ebp
// 0054ad21  5d                   pop ebp
// 0054ad22  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
