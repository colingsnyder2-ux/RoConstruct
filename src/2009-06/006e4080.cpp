// from server: 100% by EspClaude
// roc 2009-06 006e4080  unit: RBX::ScoreHud  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e4080
//
// 006e4080  53                   push ebx
// 006e4081  55                   push ebp
// 006e4082  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006e4088  56                   push esi
// 006e4089  57                   push edi
// 006e408a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006e408e  8bf1                 mov esi, ecx
// 006e4090  c70700000000         mov dword ptr [edi], 0
// 006e4096  85f6                 test esi, esi
// 006e4098  740e                 je 0x6e40a8
// 006e409a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e409e  39460c               cmp dword ptr [esi + 0xc], eax
// 006e40a1  7705                 ja 0x6e40a8
// 006e40a3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 006e40a6  7606                 jbe 0x6e40ae
// 006e40a8  ffd5                 call ebp
// 006e40aa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e40ae  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006e40b2  8b0e                 mov ecx, dword ptr [esi]
// 006e40b4  890f                 mov dword ptr [edi], ecx
// 006e40b6  894704               mov dword ptr [edi + 4], eax
// 006e40b9  395e0c               cmp dword ptr [esi + 0xc], ebx
// 006e40bc  7705                 ja 0x6e40c3
// 006e40be  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 006e40c1  7606                 jbe 0x6e40c9
// 006e40c3  ffd5                 call ebp
// 006e40c5  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006e40c9  8b07                 mov eax, dword ptr [edi]
// 006e40cb  8b0e                 mov ecx, dword ptr [esi]
// 006e40cd  85c0                 test eax, eax
// 006e40cf  7404                 je 0x6e40d5
// 006e40d1  3bc1                 cmp eax, ecx
// 006e40d3  7402                 je 0x6e40d7
// 006e40d5  ffd5                 call ebp
// 006e40d7  8b4f04               mov ecx, dword ptr [edi + 4]
// 006e40da  3bcb                 cmp ecx, ebx
// 006e40dc  743a                 je 0x6e4118
// 006e40de  8b4610               mov eax, dword ptr [esi + 0x10]
// 006e40e1  c644241400           mov byte ptr [esp + 0x14], 0
// 006e40e6  8b542414             mov edx, dword ptr [esp + 0x14]
// 006e40ea  52                   push edx
// 006e40eb  8b542418             mov edx, dword ptr [esp + 0x18]
// 006e40ef  52                   push edx
// 006e40f0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006e40f4  52                   push edx
// 006e40f5  51                   push ecx
// 006e40f6  50                   push eax
// 006e40f7  53                   push ebx
// 006e40f8  e863e8ffff           call 0x6e2960
// 006e40fd  8b5610               mov edx, dword ptr [esi + 0x10]
// 006e4100  8bd8                 mov ebx, eax
// 006e4102  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e4106  50                   push eax
// 006e4107  8d4e08               lea ecx, [esi + 8]
// 006e410a  51                   push ecx
// 006e410b  52                   push edx
// 006e410c  53                   push ebx
// 006e410d  e8deecffff           call 0x6e2df0
// 006e4112  83c428               add esp, 0x28
// 006e4115  895e10               mov dword ptr [esi + 0x10], ebx
// 006e4118  8bc7                 mov eax, edi
// 006e411a  5f                   pop edi
// 006e411b  5e                   pop esi
// 006e411c  5d                   pop ebp
// 006e411d  5b                   pop ebx
// 006e411e  c21400               ret 0x14
// copied from an identical function in another client (function ?erase@?$vector@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@std@@QAE?AV?$_Vector_iterator@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@2@V?$_Vector_const_iterator@VParameterDef@Ogre@@V?$allocator@VParameterDef@Ogre@@@std@@@2@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp