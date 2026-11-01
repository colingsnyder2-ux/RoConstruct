// from server: 100% by auto
// roc 2010-06 008e3da0  unit: RBX::RbxTextureProxy  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e3da0
//
// 008e3da0  51                   push ecx
// 008e3da1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e3da5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008e3da9  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e3dad  56                   push esi
// 008e3dae  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008e3db2  50                   push eax
// 008e3db3  8b442418             mov eax, dword ptr [esp + 0x18]
// 008e3db7  51                   push ecx
// 008e3db8  52                   push edx
// 008e3db9  50                   push eax
// 008e3dba  6a07                 push 7
// 008e3dbc  8bce                 mov ecx, esi
// 008e3dbe  c744241800000000     mov dword ptr [esp + 0x18], 0
// 008e3dc6  ff15ccb69e00         call dword ptr [0x9eb6cc]
// 008e3dcc  8bc6                 mov eax, esi
// 008e3dce  5e                   pop esi
// 008e3dcf  59                   pop ecx
// 008e3dd0  c3                   ret 
// library ogre-1.7.0/OgreDataStream.cpp (function ?create@ExceptionFactory@Ogre@@SA?AVInternalErrorException@2@U?$ExceptionCodeType@$06@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@1PBDJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreDataStream.cpp
