// from server: 100% by EspClaude
// roc 2009-06 008389f0  unit: RBX::RenderNew::TextureProxy  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008389f0
//
// 008389f0  83ec10               sub esp, 0x10
// 008389f3  55                   push ebp
// 008389f4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 008389f8  56                   push esi
// 008389f9  8bf1                 mov esi, ecx
// 008389fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008389fe  8b4104               mov eax, dword ptr [ecx + 4]
// 00838a01  80782100             cmp byte ptr [eax + 0x21], 0
// 00838a05  57                   push edi
// 00838a06  8bf9                 mov edi, ecx
// 00838a08  751a                 jne 0x838a24
// 00838a0a  8b4d00               mov ecx, dword ptr [ebp]
// 00838a0d  8d4900               lea ecx, [ecx]
// 00838a10  39480c               cmp dword ptr [eax + 0xc], ecx
// 00838a13  7305                 jae 0x838a1a
// 00838a15  8b4008               mov eax, dword ptr [eax + 8]
// 00838a18  eb04                 jmp 0x838a1e
// 00838a1a  8bf8                 mov edi, eax
// 00838a1c  8b00                 mov eax, dword ptr [eax]
// 00838a1e  80782100             cmp byte ptr [eax + 0x21], 0
// 00838a22  74ec                 je 0x838a10
// 00838a24  8b06                 mov eax, dword ptr [esi]
// 00838a26  53                   push ebx
// 00838a27  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00838a2a  897c2414             mov dword ptr [esp + 0x14], edi
// 00838a2e  89442410             mov dword ptr [esp + 0x10], eax
// 00838a32  85c0                 test eax, eax
// 00838a34  7404                 je 0x838a3a
// 00838a36  3bc0                 cmp eax, eax
// 00838a38  7406                 je 0x838a40
// 00838a3a  ff15ace98900         call dword ptr [0x89e9ac]
// 00838a40  3bfb                 cmp edi, ebx
// 00838a42  5b                   pop ebx
// 00838a43  740e                 je 0x838a53
// 00838a45  8b4500               mov eax, dword ptr [ebp]
// 00838a48  3b470c               cmp eax, dword ptr [edi + 0xc]
// 00838a4b  7206                 jb 0x838a53
// 00838a4d  8d4c240c             lea ecx, [esp + 0xc]
// 00838a51  eb11                 jmp 0x838a64
// 00838a53  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00838a56  8b16                 mov edx, dword ptr [esi]
// 00838a58  894c2418             mov dword ptr [esp + 0x18], ecx
// 00838a5c  89542414             mov dword ptr [esp + 0x14], edx
// 00838a60  8d4c2414             lea ecx, [esp + 0x14]
// 00838a64  8b11                 mov edx, dword ptr [ecx]
// 00838a66  8b442420             mov eax, dword ptr [esp + 0x20]
// 00838a6a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00838a6d  5f                   pop edi
// 00838a6e  5e                   pop esi
// 00838a6f  8910                 mov dword ptr [eax], edx
// 00838a71  894804               mov dword ptr [eax + 4], ecx
// 00838a74  5d                   pop ebp
// 00838a75  83c410               add esp, 0x10
// 00838a78  c20800               ret 8
// copied from an identical function in another client (function ?find@?$_Tree@V?$_Tmap_traits@IVVector4@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVVector4@Ogre@@@std@@@4@$0A@@std@@@std@@QBE?AVconst_iterator@12@ABI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp