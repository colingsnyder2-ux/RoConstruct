// from server: 100% by auto
// roc 2007-03 005ac7c0  unit: seg_005a0000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ac7c0
//
// 005ac7c0  8d442404             lea eax, [esp + 4]
// 005ac7c4  50                   push eax
// 005ac7c5  83c124               add ecx, 0x24
// 005ac7c8  e823feffff           call 0x5ac5f0
// 005ac7cd  c20400               ret 4
// library ogre-1.6.4/OgreScriptCompiler.cpp (function ?addTranslatorManager@ScriptCompilerManager@Ogre@@QAEXPAVScriptTranslatorManager@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreScriptCompiler.cpp
