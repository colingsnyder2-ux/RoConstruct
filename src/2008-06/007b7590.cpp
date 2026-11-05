// from server: 100% by auto
// roc 2008-06 007b7590  unit: RBX::Render::Material  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007b7590
//
// 007b7590  8b442404             mov eax, dword ptr [esp + 4]
// 007b7594  6bc02c               imul eax, eax, 0x2c
// 007b7597  03410c               add eax, dword ptr [ecx + 0xc]
// 007b759a  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?Get@?$UnorderedSet@VMTTriangle@Wml@@@Wml@@QBEABVMTTriangle@2@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
