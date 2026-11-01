// from server: 100% by auto
// roc 2009-12 004c6670  unit: Ogre::istreamDataStream  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c6670
//
// 004c6670  8b4124               mov eax, dword ptr [ecx + 0x24]
// 004c6673  8b08                 mov ecx, dword ptr [eax]
// 004c6675  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6678  8b440208             mov eax, dword ptr [edx + eax + 8]
// 004c667c  83e001               and eax, 1
// 004c667f  c3                   ret 
// library ogre-1.6.4/OgreDataStream.cpp (function ?eof@FileStreamDataStream@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreDataStream.cpp
