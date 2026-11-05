// from server: 100% by auto
// roc 2008-06 0054ad50  unit: RBX::RenderBase::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054ad50
//
// 0054ad50  55                   push ebp
// 0054ad51  8bec                 mov ebp, esp
// 0054ad53  51                   push ecx
// 0054ad54  894dfc               mov dword ptr [ebp - 4], ecx
// 0054ad57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ad5a  e811120000           call 0x54bf70
// 0054ad5f  8be5                 mov esp, ebp
// 0054ad61  5d                   pop ebp
// 0054ad62  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
