// from server: 100% by auto
// roc 2009-12 00565c70  unit: RakPeer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00565c70
//
// 00565c70  8a442404             mov al, byte ptr [esp + 4]
// 00565c74  884106               mov byte ptr [ecx + 6], al
// 00565c77  c20400               ret 4
// library ogre-1.6.4/OgreAutoParamDataSource.cpp (function ?setShadowCastersCannotBeReceivers@RenderPriorityGroup@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAutoParamDataSource.cpp
