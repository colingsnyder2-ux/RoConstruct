// from server: 100% by auto
// roc 2009-12 006de370  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006de370
//
// 006de370  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006de374  8b542408             mov edx, dword ptr [esp + 8]
// 006de378  50                   push eax
// 006de379  8b442408             mov eax, dword ptr [esp + 8]
// 006de37d  52                   push edx
// 006de37e  6a00                 push 0
// 006de380  50                   push eax
// 006de381  e8daf9ffff           call 0x6ddd60
// 006de386  c20c00               ret 0xc
// library ogre-1.6.4/OgreCompositorSerializer.cpp (function ?addLexemeAction@CompositorScriptCompiler@Ogre@@IAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@Q812@AEXXZ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorSerializer.cpp
