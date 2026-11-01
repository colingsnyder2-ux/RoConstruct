// from server: 100% by auto
// roc 2011-06 00583cd0  unit: RBX::CRenderSettings  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00583cd0
//
// 00583cd0  55                   push ebp
// 00583cd1  8bec                 mov ebp, esp
// 00583cd3  51                   push ecx
// 00583cd4  894dfc               mov dword ptr [ebp - 4], ecx
// 00583cd7  8be5                 mov esp, ebp
// 00583cd9  5d                   pop ebp
// 00583cda  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?imbue@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAEXABVlocale@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
