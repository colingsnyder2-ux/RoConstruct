// from server: 100% by auto
// roc 2008-06 0068c7b0  unit: Ogre::RbxSceneManager  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068c7b0
//
// 0068c7b0  51                   push ecx
// 0068c7b1  53                   push ebx
// 0068c7b2  55                   push ebp
// 0068c7b3  56                   push esi
// 0068c7b4  8bf1                 mov esi, ecx
// 0068c7b6  8b4634               mov eax, dword ptr [esi + 0x34]
// 0068c7b9  8b4864               mov ecx, dword ptr [eax + 0x64]
// 0068c7bc  f7410800000100       test dword ptr [ecx + 8], 0x10000
// 0068c7c3  740f                 je 0x68c7d4
// 0068c7c5  bd05000000           mov ebp, 5
// 0068c7ca  c744240c06000000     mov dword ptr [esp + 0xc], 6
// 0068c7d2  eb0d                 jmp 0x68c7e1
// 0068c7d4  bd03000000           mov ebp, 3
// 0068c7d9  c744240c04000000     mov dword ptr [esp + 0xc], 4
// 0068c7e1  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 0068c7e6  8a5c2418             mov bl, byte ptr [esp + 0x18]
// 0068c7ea  750b                 jne 0x68c7f7
// 0068c7ec  807c241400           cmp byte ptr [esp + 0x14], 0
// 0068c7f1  7557                 jne 0x68c84a
// 0068c7f3  84db                 test bl, bl
// 0068c7f5  7557                 jne 0x68c84e
// 0068c7f7  33c9                 xor ecx, ecx
// 0068c7f9  384c241c             cmp byte ptr [esp + 0x1c], cl
// 0068c7fd  57                   push edi
// 0068c7fe  0f94c1               sete cl
// 0068c801  8bf8                 mov edi, eax
// 0068c803  8b07                 mov eax, dword ptr [edi]
// 0068c805  8b90d4000000         mov edx, dword ptr [eax + 0xd4]
// 0068c80b  41                   inc ecx
// 0068c80c  51                   push ecx
// 0068c80d  8bcf                 mov ecx, edi
// 0068c80f  ffd2                 call edx
// 0068c811  8b542420             mov edx, dword ptr [esp + 0x20]
// 0068c815  52                   push edx
// 0068c816  33d2                 xor edx, edx
// 0068c818  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0068c81b  84db                 test bl, bl
// 0068c81d  0f95c2               setne dl
// 0068c820  8b01                 mov eax, dword ptr [ecx]
// 0068c822  8b802c010000         mov eax, dword ptr [eax + 0x12c]
// 0068c828  4a                   dec edx
// 0068c829  23d5                 and edx, ebp
// 0068c82b  52                   push edx
// 0068c82c  0fb6d3               movzx edx, bl
// 0068c82f  f7da                 neg edx
// 0068c831  1bd2                 sbb edx, edx
// 0068c833  23542418             and edx, dword ptr [esp + 0x18]
// 0068c837  52                   push edx
// 0068c838  6a00                 push 0
// 0068c83a  6aff                 push -1
// 0068c83c  6a00                 push 0
// 0068c83e  6a01                 push 1
// 0068c840  ffd0                 call eax
// 0068c842  5f                   pop edi
// 0068c843  5e                   pop esi
// 0068c844  5d                   pop ebp
// 0068c845  5b                   pop ebx
// 0068c846  59                   pop ecx
// 0068c847  c20c00               ret 0xc
// 0068c84a  84db                 test bl, bl
// 0068c84c  75a9                 jne 0x68c7f7
// 0068c84e  8bc8                 mov ecx, eax
// 0068c850  8b11                 mov edx, dword ptr [ecx]
// 0068c852  8b82d4000000         mov eax, dword ptr [edx + 0xd4]
// 0068c858  6a03                 push 3
// 0068c85a  ffd0                 call eax
// 0068c85c  33c0                 xor eax, eax
// 0068c85e  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0068c861  84db                 test bl, bl
// 0068c863  0f95c0               setne al
// 0068c866  8b11                 mov edx, dword ptr [ecx]
// 0068c868  8b922c010000         mov edx, dword ptr [edx + 0x12c]
// 0068c86e  6a00                 push 0
// 0068c870  48                   dec eax
// 0068c871  23442410             and eax, dword ptr [esp + 0x10]
// 0068c875  50                   push eax
// 0068c876  0fb6c3               movzx eax, bl
// 0068c879  f7d8                 neg eax
// 0068c87b  1bc0                 sbb eax, eax
// 0068c87d  23c5                 and eax, ebp
// 0068c87f  50                   push eax
// 0068c880  6a00                 push 0
// 0068c882  6aff                 push -1
// 0068c884  6a00                 push 0
// 0068c886  6a01                 push 1
// 0068c888  ffd2                 call edx
// 0068c88a  5e                   pop esi
// 0068c88b  5d                   pop ebp
// 0068c88c  5b                   pop ebx
// 0068c88d  59                   pop ecx
// 0068c88e  c20c00               ret 0xc
// library ogre-1.4.9/OgreSceneManager.cpp (function ?setShadowVolumeStencilState@SceneManager@Ogre@@MAEX_N00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
