// from server: 100% by auto
// roc 2009-12 0052bad0  unit: PluginInterface  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0052bad0
//
// 0052bad0  8a442404             mov al, byte ptr [esp + 4]
// 0052bad4  888130010000         mov byte ptr [ecx + 0x130], al
// 0052bada  c20400               ret 4
// library ogre-1.6.4/OgrePass.cpp (function ?setPointSpritesEnabled@Pass@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgrePass.cpp
