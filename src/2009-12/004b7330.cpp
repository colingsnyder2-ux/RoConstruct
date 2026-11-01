// from server: 100% by auto
// roc 2009-12 004b7330  unit: Ogre::RbxMaterialAdapter  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b7330
//
// 004b7330  51                   push ecx
// 004b7331  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b7335  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b7339  8b542414             mov edx, dword ptr [esp + 0x14]
// 004b733d  56                   push esi
// 004b733e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004b7342  50                   push eax
// 004b7343  8b442418             mov eax, dword ptr [esp + 0x18]
// 004b7347  51                   push ecx
// 004b7348  52                   push edx
// 004b7349  50                   push eax
// 004b734a  6a06                 push 6
// 004b734c  8bce                 mov ecx, esi
// 004b734e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004b7356  ff15c0c19800         call dword ptr [0x98c1c0]
// 004b735c  8bc6                 mov eax, esi
// 004b735e  5e                   pop esi
// 004b735f  59                   pop ecx
// 004b7360  c3                   ret 
// library ogre-1.7.0/OgreConfigFile.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVFileNotFoundException@2@U?$ExceptionCodeType@$05@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
