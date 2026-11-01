// from server: 100% by auto
// roc 2011-06 00a2eac0  unit: seg_00a20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a2eac0
//
// 00a2eac0  a1ec08a400           mov eax, dword ptr [0xa408ec]
// 00a2eac5  a39061cd00           mov dword ptr [0xcd6190], eax
// 00a2eaca  c3                   ret 
// library ogre-1.7.0/OgreOptimisedUtilGeneral.cpp (function ??__FmsOptimisedUtilGeneral@?1??_getOptimisedUtilGeneral@Ogre@@YAPAVOptimisedUtil@1@XZ@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreOptimisedUtilGeneral.cpp
