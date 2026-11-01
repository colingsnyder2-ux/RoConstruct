// from server: 100% by auto
// roc 2009-06 004d60f0  unit: PluginInterface  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d60f0
//
// 004d60f0  8a442404             mov al, byte ptr [esp + 4]
// 004d60f4  888124010000         mov byte ptr [ecx + 0x124], al
// 004d60fa  c20400               ret 4
// library ogre-1.6.4/OgreFontManager.cpp (function ?setAntialiasColour@Font@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreFontManager.cpp
