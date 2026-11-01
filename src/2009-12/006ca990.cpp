// from server: 100% by auto
// roc 2009-12 006ca990  unit: RBX::Profiling::Profiler  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ca990
//
// 006ca990  8a442404             mov al, byte ptr [esp + 4]
// 006ca994  a22026b900           mov byte ptr [0xb92620], al
// 006ca999  c3                   ret 
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?setIgnoreHidden@FileSystemArchive@Ogre@@SAX_N@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
