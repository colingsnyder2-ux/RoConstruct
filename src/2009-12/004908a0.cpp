// from server: 100% by auto
// roc 2009-12 004908a0  unit: Ogre::RbxSubEntity  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004908a0
//
// 004908a0  51                   push ecx
// 004908a1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004908a5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004908a9  8b542414             mov edx, dword ptr [esp + 0x14]
// 004908ad  56                   push esi
// 004908ae  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004908b2  50                   push eax
// 004908b3  8b442418             mov eax, dword ptr [esp + 0x18]
// 004908b7  51                   push ecx
// 004908b8  52                   push edx
// 004908b9  50                   push eax
// 004908ba  6a02                 push 2
// 004908bc  8bce                 mov ecx, esi
// 004908be  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004908c6  ff1544c69800         call dword ptr [0x98c644]
// 004908cc  8bc6                 mov eax, esi
// 004908ce  5e                   pop esi
// 004908cf  59                   pop ecx
// 004908d0  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVInvalidParametersException@2@U?$ExceptionCodeType@$01@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
