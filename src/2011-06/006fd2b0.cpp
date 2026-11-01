// from server: 100% by auto
// roc 2011-06 006fd2b0  unit: RBX::VFlagStandService::?$FactoryProduct  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006fd2b0
//
// 006fd2b0  53                   push ebx
// 006fd2b1  56                   push esi
// 006fd2b2  57                   push edi
// 006fd2b3  8bb9a0000000         mov edi, dword ptr [ecx + 0xa0]
// 006fd2b9  8db19c000000         lea esi, [ecx + 0x9c]
// 006fd2bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 006fd2c2  8d442410             lea eax, [esp + 0x10]
// 006fd2c6  50                   push eax
// 006fd2c7  51                   push ecx
// 006fd2c8  57                   push edi
// 006fd2c9  8bce                 mov ecx, esi
// 006fd2cb  e8e009f1ff           call 0x60dcb0
// 006fd2d0  6a01                 push 1
// 006fd2d2  8bce                 mov ecx, esi
// 006fd2d4  8bd8                 mov ebx, eax
// 006fd2d6  e88544feff           call 0x6e1760
// 006fd2db  895f04               mov dword ptr [edi + 4], ebx
// 006fd2de  8b5304               mov edx, dword ptr [ebx + 4]
// 006fd2e1  5f                   pop edi
// 006fd2e2  5e                   pop esi
// 006fd2e3  891a                 mov dword ptr [edx], ebx
// 006fd2e5  5b                   pop ebx
// 006fd2e6  c20400               ret 4
// library ogre-1.7.0/OgreResource.cpp (function ?addListener@Resource@Ogre@@UAEXPAVListener@12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResource.cpp
