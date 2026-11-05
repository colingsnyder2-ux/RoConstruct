// from server: 100% by auto
// roc 2008-06 0068e940  unit: Ogre::RbxSceneManager  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068e940
//
// 0068e940  8a442404             mov al, byte ptr [esp + 4]
// 0068e944  8881188a0000         mov byte ptr [ecx + 0x8a18], al
// 0068e94a  c20400               ret 4
// library ogre-1.4.9/OgreAutoParamDataSource.cpp (function ?setShowDebugShadows@SceneManager@Ogre@@UAEX_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAutoParamDataSource.cpp
