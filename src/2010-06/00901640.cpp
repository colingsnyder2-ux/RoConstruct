// from server: 100% by auto
// roc 2010-06 00901640  unit: Ogre::RbxManualTextureLoader  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901640
//
// 00901640  51                   push ecx
// 00901641  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00901645  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00901649  8b542414             mov edx, dword ptr [esp + 0x14]
// 0090164d  56                   push esi
// 0090164e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00901652  50                   push eax
// 00901653  8b442418             mov eax, dword ptr [esp + 0x18]
// 00901657  51                   push ecx
// 00901658  52                   push edx
// 00901659  50                   push eax
// 0090165a  6a06                 push 6
// 0090165c  8bce                 mov ecx, esi
// 0090165e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00901666  ff1548ad9e00         call dword ptr [0x9ead48]
// 0090166c  8bc6                 mov eax, esi
// 0090166e  5e                   pop esi
// 0090166f  59                   pop ecx
// 00901670  c3                   ret 
// library ogre-1.7.0/OgreConfigFile.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVFileNotFoundException@2@U?$ExceptionCodeType@$05@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
