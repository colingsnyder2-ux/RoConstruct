// from server: 100% by auto
// roc 2009-06 005af4d0  unit: RBX::TextureProxyBase  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005af4d0
//
// 005af4d0  55                   push ebp
// 005af4d1  8bec                 mov ebp, esp
// 005af4d3  51                   push ecx
// 005af4d4  894dfc               mov dword ptr [ebp - 4], ecx
// 005af4d7  8be5                 mov esp, ebp
// 005af4d9  5d                   pop ebp
// 005af4da  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?imbue@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEXABVlocale@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
