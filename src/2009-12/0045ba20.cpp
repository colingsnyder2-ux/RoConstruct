// from server: 100% by auto
// roc 2009-12 0045ba20  unit: CRobloxDoc  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045ba20
//
// 0045ba20  8a442404             mov al, byte ptr [esp + 4]
// 0045ba24  a211b8b700           mov byte ptr [0xb7b811], al
// 0045ba29  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?setIgnoreHidden@FileSystemArchive@Ogre@@SAX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
