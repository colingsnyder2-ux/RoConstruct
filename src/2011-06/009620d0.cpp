// from server: 100% by auto
// roc 2011-06 009620d0  unit: Ogre::RbxManualTextureLoader  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009620d0
//
// 009620d0  51                   push ecx
// 009620d1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 009620d5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 009620d9  8b542414             mov edx, dword ptr [esp + 0x14]
// 009620dd  56                   push esi
// 009620de  8b74240c             mov esi, dword ptr [esp + 0xc]
// 009620e2  50                   push eax
// 009620e3  8b442418             mov eax, dword ptr [esp + 0x18]
// 009620e7  51                   push ecx
// 009620e8  52                   push edx
// 009620e9  50                   push eax
// 009620ea  6a06                 push 6
// 009620ec  8bce                 mov ecx, esi
// 009620ee  c744241800000000     mov dword ptr [esp + 0x18], 0
// 009620f6  ff15f415a400         call dword ptr [0xa415f4]
// 009620fc  8bc6                 mov eax, esi
// 009620fe  5e                   pop esi
// 009620ff  59                   pop ecx
// 00962100  c3                   ret 
// library ogre-1.7.0/OgreConfigFile.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVFileNotFoundException@2@U?$ExceptionCodeType@$05@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
