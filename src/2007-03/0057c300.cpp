// from server: 100% by auto
// roc 2007-03 0057c300  unit: seg_00570000  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0057c300
//
// 0057c300  8d442404             lea eax, [esp + 4]
// 0057c304  50                   push eax
// 0057c305  83c178               add ecx, 0x78
// 0057c308  e8e3020300           call 0x5ac5f0
// 0057c30d  c20400               ret 4
// library ogre-1.6.4/OgreRenderTarget.cpp (function ?addListener@RenderTarget@Ogre@@UAEXPAVRenderTargetListener@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreRenderTarget.cpp
