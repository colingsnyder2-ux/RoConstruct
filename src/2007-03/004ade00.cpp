// from server: 100% by auto
// roc 2007-03 004ade00  unit: seg_004a0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004ade00
//
// 004ade00  8a442404             mov al, byte ptr [esp + 4]
// 004ade04  884106               mov byte ptr [ecx + 6], al
// 004ade07  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?setShadowCastersCannotBeReceivers@RenderPriorityGroup@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
