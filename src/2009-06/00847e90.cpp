// from server: 100% by auto
// roc 2009-06 00847e90  unit: RBX::RbxG3D::Material  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00847e90
//
// 00847e90  8b442404             mov eax, dword ptr [esp + 4]
// 00847e94  6bc02c               imul eax, eax, 0x2c
// 00847e97  03410c               add eax, dword ptr [ecx + 0xc]
// 00847e9a  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?Get@?$UnorderedSet@VMTTriangle@Wml@@@Wml@@QBEABVMTTriangle@2@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
