// from server: 100% by EspClaude
// roc 2009-06 004e6220  unit: RBX::Network::Replicator::ChangePropertyItem  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e6220
//
// 004e6220  83ec10               sub esp, 0x10
// 004e6223  55                   push ebp
// 004e6224  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004e6228  56                   push esi
// 004e6229  8bf1                 mov esi, ecx
// 004e622b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e622e  8b4104               mov eax, dword ptr [ecx + 4]
// 004e6231  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004e6235  57                   push edi
// 004e6236  8bf9                 mov edi, ecx
// 004e6238  751a                 jne 0x4e6254
// 004e623a  8b4d00               mov ecx, dword ptr [ebp]
// 004e623d  8d4900               lea ecx, [ecx]
// 004e6240  39480c               cmp dword ptr [eax + 0xc], ecx
// 004e6243  7305                 jae 0x4e624a
// 004e6245  8b4008               mov eax, dword ptr [eax + 8]
// 004e6248  eb04                 jmp 0x4e624e
// 004e624a  8bf8                 mov edi, eax
// 004e624c  8b00                 mov eax, dword ptr [eax]
// 004e624e  80782d00             cmp byte ptr [eax + 0x2d], 0
// 004e6252  74ec                 je 0x4e6240
// 004e6254  8b06                 mov eax, dword ptr [esi]
// 004e6256  53                   push ebx
// 004e6257  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004e625a  897c2414             mov dword ptr [esp + 0x14], edi
// 004e625e  89442410             mov dword ptr [esp + 0x10], eax
// 004e6262  85c0                 test eax, eax
// 004e6264  7404                 je 0x4e626a
// 004e6266  3bc0                 cmp eax, eax
// 004e6268  7406                 je 0x4e6270
// 004e626a  ff15ace98900         call dword ptr [0x89e9ac]
// 004e6270  3bfb                 cmp edi, ebx
// 004e6272  5b                   pop ebx
// 004e6273  740e                 je 0x4e6283
// 004e6275  8b4500               mov eax, dword ptr [ebp]
// 004e6278  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004e627b  7206                 jb 0x4e6283
// 004e627d  8d4c240c             lea ecx, [esp + 0xc]
// 004e6281  eb11                 jmp 0x4e6294
// 004e6283  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e6286  8b16                 mov edx, dword ptr [esi]
// 004e6288  894c2418             mov dword ptr [esp + 0x18], ecx
// 004e628c  89542414             mov dword ptr [esp + 0x14], edx
// 004e6290  8d4c2414             lea ecx, [esp + 0x14]
// 004e6294  8b11                 mov edx, dword ptr [ecx]
// 004e6296  8b442420             mov eax, dword ptr [esp + 0x20]
// 004e629a  8b4904               mov ecx, dword ptr [ecx + 4]
// 004e629d  5f                   pop edi
// 004e629e  5e                   pop esi
// 004e629f  8910                 mov dword ptr [eax], edx
// 004e62a1  894804               mov dword ptr [eax + 4], ecx
// 004e62a4  5d                   pop ebp
// 004e62a5  83c410               add esp, 0x10
// 004e62a8  c20800               ret 8
// copied from an identical function in another client (function ?find@?$_Tree@V?$_Tmap_traits@IV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@I@2@V?$allocator@U?$pair@$$CBIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@QBE?AVconst_iterator@12@ABI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreCompiler2Pass.cpp