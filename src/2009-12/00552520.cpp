// from server: 100% by auto
// roc 2009-12 00552520  unit: Exposer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00552520
//
// 00552520  8a442404             mov al, byte ptr [esp + 4]
// 00552524  884108               mov byte ptr [ecx + 8], al
// 00552527  c20400               ret 4
// library ogre-1.6.4/OgreAnimation.cpp (function ?setResetsEveryUpdate@RenderToVertexBuffer@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAnimation.cpp
