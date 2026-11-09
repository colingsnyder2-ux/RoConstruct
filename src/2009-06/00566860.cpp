// from server: 100% by auto
// roc 2009-06 00566860  unit: RBX::RbxG3D::RenderScene  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00566860
//
// 00566860  6a00                 push 0
// 00566862  6a00                 push 0
// 00566864  e8d7f6ffff           call 0x565f40
// 00566869  c3                   ret 
// library rbx2016-g3d/stringutils.cpp (function ?fastClear@?$Array@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$09$0CA@@G3D@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d stringutils.cpp
