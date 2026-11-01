// from server: 100% by auto
// roc 2011-06 0096ac80  unit: Ogre::istreamDataStream  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0096ac80
//
// 0096ac80  8b4128               mov eax, dword ptr [ecx + 0x28]
// 0096ac83  8b08                 mov ecx, dword ptr [eax]
// 0096ac85  8b5104               mov edx, dword ptr [ecx + 4]
// 0096ac88  8b440208             mov eax, dword ptr [edx + eax + 8]
// 0096ac8c  83e001               and eax, 1
// 0096ac8f  c3                   ret 
// library ogre-1.7.0/OgreDataStream.cpp (function ?eof@FileStreamDataStream@Ogre@@UBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreDataStream.cpp
