// from server: 100% by auto
// roc 2010-06 0090c170  unit: Ogre::istreamDataStream  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0090c170
//
// 0090c170  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0090c173  8b08                 mov ecx, dword ptr [eax]
// 0090c175  8b5104               mov edx, dword ptr [ecx + 4]
// 0090c178  8b440208             mov eax, dword ptr [edx + eax + 8]
// 0090c17c  83e001               and eax, 1
// 0090c17f  c3                   ret 
// library ogre-1.6.4/OgreDataStream.cpp (function ?eof@FileStreamDataStream@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDataStream.cpp
