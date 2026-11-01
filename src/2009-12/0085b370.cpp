// from server: 100% by auto
// roc 2009-12 0085b370  unit: CXTPStatusBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085b370
//
// 0085b370  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0085b374  8b542408             mov edx, dword ptr [esp + 8]
// 0085b378  50                   push eax
// 0085b379  8b442408             mov eax, dword ptr [esp + 8]
// 0085b37d  52                   push edx
// 0085b37e  6a00                 push 0
// 0085b380  50                   push eax
// 0085b381  e81afaffff           call 0x85ada0
// 0085b386  c20c00               ret 0xc
// library ogre-1.6.4/OgreCompositorSerializer.cpp (function ?addLexemeAction@CompositorScriptCompiler@Ogre@@IAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@Q812@AEXXZ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorSerializer.cpp
