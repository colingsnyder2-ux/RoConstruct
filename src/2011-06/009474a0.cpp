// from server: 100% by auto
// roc 2011-06 009474a0  unit: Ogre::RbxSubEntity  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009474a0
//
// 009474a0  51                   push ecx
// 009474a1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 009474a5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009474a9  8b542414             mov edx, dword ptr [esp + 0x14]
// 009474ad  56                   push esi
// 009474ae  8b74240c             mov esi, dword ptr [esp + 0xc]
// 009474b2  50                   push eax
// 009474b3  8b442418             mov eax, dword ptr [esp + 0x18]
// 009474b7  51                   push ecx
// 009474b8  52                   push edx
// 009474b9  50                   push eax
// 009474ba  6a02                 push 2
// 009474bc  8bce                 mov ecx, esi
// 009474be  c744241800000000     mov dword ptr [esp + 0x18], 0
// 009474c6  ff153815a400         call dword ptr [0xa41538]
// 009474cc  8bc6                 mov eax, esi
// 009474ce  5e                   pop esi
// 009474cf  59                   pop ecx
// 009474d0  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVInvalidParametersException@2@U?$ExceptionCodeType@$01@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
