// from server: 100% by auto
// roc 2010-06 008e4ab0  unit: Ogre::RbxSubEntity  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e4ab0
//
// 008e4ab0  51                   push ecx
// 008e4ab1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e4ab5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008e4ab9  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e4abd  56                   push esi
// 008e4abe  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008e4ac2  50                   push eax
// 008e4ac3  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e4ac7  51                   push ecx
// 008e4ac8  52                   push edx
// 008e4ac9  50                   push eax
// 008e4aca  6a02                 push 2
// 008e4acc  8bce                 mov ecx, esi
// 008e4ace  c744241800000000     mov dword ptr [esp + 0x18], 0
// 008e4ad6  ff1558b79e00         call dword ptr [0x9eb758]
// 008e4adc  8bc6                 mov eax, esi
// 008e4ade  5e                   pop esi
// 008e4adf  59                   pop ecx
// 008e4ae0  c3                   ret 
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVInvalidParametersException@2@U?$ExceptionCodeType@$01@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
