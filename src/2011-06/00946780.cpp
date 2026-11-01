// from server: 100% by auto
// roc 2011-06 00946780  unit: Ogre::RbxSceneNode  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00946780
//
// 00946780  51                   push ecx
// 00946781  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00946785  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00946789  8b542414             mov edx, dword ptr [esp + 0x14]
// 0094678d  56                   push esi
// 0094678e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00946792  50                   push eax
// 00946793  8b442418             mov eax, dword ptr [esp + 0x18]
// 00946797  51                   push ecx
// 00946798  52                   push edx
// 00946799  50                   push eax
// 0094679a  6a07                 push 7
// 0094679c  8bce                 mov ecx, esi
// 0094679e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 009467a6  ff157c14a400         call dword ptr [0xa4147c]
// 009467ac  8bc6                 mov eax, esi
// 009467ae  5e                   pop esi
// 009467af  59                   pop ecx
// 009467b0  c3                   ret 
// library ogre-1.7.0/OgreDataStream.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVInternalErrorException@2@U?$ExceptionCodeType@$06@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreDataStream.cpp
