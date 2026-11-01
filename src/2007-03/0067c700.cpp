// from server: 100% by auto
// roc 2007-03 0067c700  unit: seg_00670000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067c700
//
// 0067c700  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0067c704  8b542408             mov edx, dword ptr [esp + 8]
// 0067c708  50                   push eax
// 0067c709  8b442408             mov eax, dword ptr [esp + 8]
// 0067c70d  52                   push edx
// 0067c70e  6a00                 push 0
// 0067c710  50                   push eax
// 0067c711  e8dafaffff           call 0x67c1f0
// 0067c716  c20c00               ret 0xc
// library ogre-1.6.4/OgreCompositorSerializer.cpp (function ?addLexemeAction@CompositorScriptCompiler@Ogre@@IAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@Q812@AEXXZ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorSerializer.cpp
