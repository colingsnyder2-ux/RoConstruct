// from server: 100% by auto
// roc 2009-06 00606c70  unit: RBX::DataModel  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00606c70
//
// 00606c70  8a442404             mov al, byte ptr [esp + 4]
// 00606c74  888168010000         mov byte ptr [ecx + 0x168], al
// 00606c7a  c20400               ret 4
// library ogre-1.6.4/OgreAnimation.cpp (function ?setAutoBuildEdgeLists@Mesh@Ogre@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAnimation.cpp
