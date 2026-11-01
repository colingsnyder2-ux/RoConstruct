// from server: 100% by auto
// roc 2009-12 0048fba0  unit: RBX::RbxTextureProxy  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048fba0
//
// 0048fba0  51                   push ecx
// 0048fba1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048fba5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048fba9  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048fbad  56                   push esi
// 0048fbae  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0048fbb2  50                   push eax
// 0048fbb3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048fbb7  51                   push ecx
// 0048fbb8  52                   push edx
// 0048fbb9  50                   push eax
// 0048fbba  6a07                 push 7
// 0048fbbc  8bce                 mov ecx, esi
// 0048fbbe  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0048fbc6  ff15bcbe9800         call dword ptr [0x98bebc]
// 0048fbcc  8bc6                 mov eax, esi
// 0048fbce  5e                   pop esi
// 0048fbcf  59                   pop ecx
// 0048fbd0  c3                   ret 
// library ogre-1.7.0/OgreDataStream.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVInternalErrorException@2@U?$ExceptionCodeType@$06@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreDataStream.cpp
