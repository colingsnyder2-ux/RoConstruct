// from server: 100% by auto
// roc 2008-06 00502f40  unit: RBX::Render::RenderScene  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00502f40
//
// 00502f40  6a00                 push 0
// 00502f42  6a00                 push 0
// 00502f44  e877f6ffff           call 0x5025c0
// 00502f49  c3                   ret 
// library rbx2016-g3d/stringutils.cpp (function ?fastClear@?$Array@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@$09$0CA@@G3D@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d stringutils.cpp
