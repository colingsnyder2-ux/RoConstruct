// roc 2012-06 0066f4b0  unit: RBX::CRenderSettings  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0066f4b0
//
// 0066f4b0  55                   push ebp
// 0066f4b1  8bec                 mov ebp, esp
// 0066f4b3  51                   push ecx
// 0066f4b4  894dfc               mov dword ptr [ebp - 4], ecx
// 0066f4b7  8be5                 mov esp, ebp
// 0066f4b9  5d                   pop ebp
// 0066f4ba  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?imbue@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEXABVlocale@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
