// roc 2012-06 00a99030  unit: RBX::AdornBillboarder  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a99030
//
// 00a99030  55                   push ebp
// 00a99031  8bec                 mov ebp, esp
// 00a99033  51                   push ecx
// 00a99034  894dfc               mov dword ptr [ebp - 4], ecx
// 00a99037  8be5                 mov esp, ebp
// 00a99039  5d                   pop ebp
// 00a9903a  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnVertexInsert@VETMesh@Wml@@UAEXH_NAAPAX@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lib: wildmagic-2-core Meshes/WmlVETMesh.cpp