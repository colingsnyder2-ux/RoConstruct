// from server: 100% by auto
// roc 2008-06 00681c30  unit: Ogre::RbxSceneNode  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00681c30
//
// 00681c30  64a100000000         mov eax, dword ptr fs:[0]
// 00681c36  6aff                 push -1
// 00681c38  6842e87d00           push 0x7de842
// 00681c3d  50                   push eax
// 00681c3e  64892500000000       mov dword ptr fs:[0], esp
// 00681c45  8b442418             mov eax, dword ptr [esp + 0x18]
// 00681c49  83ec48               sub esp, 0x48
// 00681c4c  80782100             cmp byte ptr [eax + 0x21], 0
// 00681c50  55                   push ebp
// 00681c51  8be9                 mov ebp, ecx
// 00681c53  7459                 je 0x681cae
// 00681c55  6870b28000           push 0x80b270
// 00681c5a  8d4c240c             lea ecx, [esp + 0xc]
// 00681c5e  ff1558248000         call dword ptr [0x802458]
// 00681c64  8d4c2424             lea ecx, [esp + 0x24]
// 00681c68  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00681c70  ff1598288000         call dword ptr [0x802898]
// 00681c76  8d442408             lea eax, [esp + 8]
// 00681c7a  50                   push eax
// 00681c7b  8d4c2434             lea ecx, [esp + 0x34]
// 00681c7f  c644245801           mov byte ptr [esp + 0x58], 1
// 00681c84  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 00681c8c  ff155c248000         call dword ptr [0x80245c]
// 00681c92  683c0c8d00           push 0x8d0c3c
// 00681c97  8d4c2428             lea ecx, [esp + 0x28]
// 00681c9b  51                   push ecx
// 00681c9c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00681ca1  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00681ca9  e8def80100           call 0x6a158c
// 00681cae  53                   push ebx
// 00681caf  56                   push esi
// 00681cb0  8bd8                 mov ebx, eax
// 00681cb2  57                   push edi
// 00681cb3  8d4c246c             lea ecx, [esp + 0x6c]
// 00681cb7  895c2410             mov dword ptr [esp + 0x10], ebx
// 00681cbb  e88055e5ff           call 0x4d7240
// 00681cc0  8b0b                 mov ecx, dword ptr [ebx]
// 00681cc2  80792100             cmp byte ptr [ecx + 0x21], 0
// 00681cc6  7405                 je 0x681ccd
// 00681cc8  8b7b08               mov edi, dword ptr [ebx + 8]
// 00681ccb  eb1b                 jmp 0x681ce8
// 00681ccd  8b5308               mov edx, dword ptr [ebx + 8]
// 00681cd0  807a2100             cmp byte ptr [edx + 0x21], 0
// 00681cd4  7404                 je 0x681cda
// 00681cd6  8bf9                 mov edi, ecx
// 00681cd8  eb0e                 jmp 0x681ce8
// 00681cda  8b442470             mov eax, dword ptr [esp + 0x70]
// 00681cde  8b7808               mov edi, dword ptr [eax + 8]
// 00681ce1  8d5008               lea edx, [eax + 8]
// 00681ce4  3bc3                 cmp eax, ebx
// 00681ce6  756b                 jne 0x681d53
// 00681ce8  807f2100             cmp byte ptr [edi + 0x21], 0
// 00681cec  8b7304               mov esi, dword ptr [ebx + 4]
// 00681cef  7503                 jne 0x681cf4
// 00681cf1  897704               mov dword ptr [edi + 4], esi
// 00681cf4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00681cf7  395804               cmp dword ptr [eax + 4], ebx
// 00681cfa  7505                 jne 0x681d01
// 00681cfc  897804               mov dword ptr [eax + 4], edi
// 00681cff  eb0b                 jmp 0x681d0c
// 00681d01  391e                 cmp dword ptr [esi], ebx
// 00681d03  7504                 jne 0x681d09
// 00681d05  893e                 mov dword ptr [esi], edi
// 00681d07  eb03                 jmp 0x681d0c
// 00681d09  897e08               mov dword ptr [esi + 8], edi
// 00681d0c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00681d0f  8b03                 mov eax, dword ptr [ebx]
// 00681d11  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00681d15  7515                 jne 0x681d2c
// 00681d17  807f2100             cmp byte ptr [edi + 0x21], 0
// 00681d1b  7404                 je 0x681d21
// 00681d1d  8bc6                 mov eax, esi
// 00681d1f  eb09                 jmp 0x681d2a
// 00681d21  57                   push edi
// 00681d22  e8d954e5ff           call 0x4d7200
// 00681d27  83c404               add esp, 4
// 00681d2a  8903                 mov dword ptr [ebx], eax
// 00681d2c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00681d2f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00681d33  394b08               cmp dword ptr [ebx + 8], ecx
// 00681d36  7577                 jne 0x681daf
// 00681d38  807f2100             cmp byte ptr [edi + 0x21], 0
// 00681d3c  7407                 je 0x681d45
// 00681d3e  8bc6                 mov eax, esi
// 00681d40  894308               mov dword ptr [ebx + 8], eax
// 00681d43  eb6a                 jmp 0x681daf
// 00681d45  57                   push edi
// 00681d46  e8d554e5ff           call 0x4d7220
// 00681d4b  83c404               add esp, 4
// 00681d4e  894308               mov dword ptr [ebx + 8], eax
// 00681d51  eb5c                 jmp 0x681daf
// 00681d53  894104               mov dword ptr [ecx + 4], eax
// 00681d56  8b0b                 mov ecx, dword ptr [ebx]
// 00681d58  8908                 mov dword ptr [eax], ecx
// 00681d5a  3b4308               cmp eax, dword ptr [ebx + 8]
// 00681d5d  7504                 jne 0x681d63
// 00681d5f  8bf0                 mov esi, eax
// 00681d61  eb19                 jmp 0x681d7c
// 00681d63  807f2100             cmp byte ptr [edi + 0x21], 0
// 00681d67  8b7004               mov esi, dword ptr [eax + 4]
// 00681d6a  7503                 jne 0x681d6f
// 00681d6c  897704               mov dword ptr [edi + 4], esi
// 00681d6f  893e                 mov dword ptr [esi], edi
// 00681d71  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00681d74  890a                 mov dword ptr [edx], ecx
// 00681d76  8b5308               mov edx, dword ptr [ebx + 8]
// 00681d79  894204               mov dword ptr [edx + 4], eax
// 00681d7c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00681d7f  395904               cmp dword ptr [ecx + 4], ebx
// 00681d82  7505                 jne 0x681d89
// 00681d84  894104               mov dword ptr [ecx + 4], eax
// 00681d87  eb0e                 jmp 0x681d97
// 00681d89  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00681d8c  3919                 cmp dword ptr [ecx], ebx
// 00681d8e  7504                 jne 0x681d94
// 00681d90  8901                 mov dword ptr [ecx], eax
// 00681d92  eb03                 jmp 0x681d97
// 00681d94  894108               mov dword ptr [ecx + 8], eax
// 00681d97  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00681d9a  894804               mov dword ptr [eax + 4], ecx
// 00681d9d  8d4b20               lea ecx, [ebx + 0x20]
// 00681da0  83c020               add eax, 0x20
// 00681da3  3bc1                 cmp eax, ecx
// 00681da5  7408                 je 0x681daf
// 00681da7  8a19                 mov bl, byte ptr [ecx]
// 00681da9  8a10                 mov dl, byte ptr [eax]
// 00681dab  8818                 mov byte ptr [eax], bl
// 00681dad  8811                 mov byte ptr [ecx], dl
// 00681daf  8b542410             mov edx, dword ptr [esp + 0x10]
// 00681db3  b301                 mov bl, 1
// 00681db5  385a20               cmp byte ptr [edx + 0x20], bl
// 00681db8  0f85fd000000         jne 0x681ebb
// 00681dbe  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00681dc1  3b7804               cmp edi, dword ptr [eax + 4]
// 00681dc4  0f84ee000000         je 0x681eb8
// 00681dca  8d9b00000000         lea ebx, [ebx]
// 00681dd0  385f20               cmp byte ptr [edi + 0x20], bl
// 00681dd3  0f85df000000         jne 0x681eb8
// 00681dd9  8b06                 mov eax, dword ptr [esi]
// 00681ddb  3bf8                 cmp edi, eax
// 00681ddd  7565                 jne 0x681e44
// 00681ddf  8b4608               mov eax, dword ptr [esi + 8]
// 00681de2  80782000             cmp byte ptr [eax + 0x20], 0
// 00681de6  7512                 jne 0x681dfa
// 00681de8  885820               mov byte ptr [eax + 0x20], bl
// 00681deb  56                   push esi
// 00681dec  8bcd                 mov ecx, ebp
// 00681dee  c6462000             mov byte ptr [esi + 0x20], 0
// 00681df2  e8f957e5ff           call 0x4d75f0
// 00681df7  8b4608               mov eax, dword ptr [esi + 8]
// 00681dfa  80782100             cmp byte ptr [eax + 0x21], 0
// 00681dfe  7574                 jne 0x681e74
// 00681e00  8b08                 mov ecx, dword ptr [eax]
// 00681e02  385920               cmp byte ptr [ecx + 0x20], bl
// 00681e05  7508                 jne 0x681e0f
// 00681e07  8b5008               mov edx, dword ptr [eax + 8]
// 00681e0a  385a20               cmp byte ptr [edx + 0x20], bl
// 00681e0d  7461                 je 0x681e70
// 00681e0f  8b4808               mov ecx, dword ptr [eax + 8]
// 00681e12  385920               cmp byte ptr [ecx + 0x20], bl
// 00681e15  7514                 jne 0x681e2b
// 00681e17  8b10                 mov edx, dword ptr [eax]
// 00681e19  885a20               mov byte ptr [edx + 0x20], bl
// 00681e1c  50                   push eax
// 00681e1d  8bcd                 mov ecx, ebp
// 00681e1f  c6402000             mov byte ptr [eax + 0x20], 0
// 00681e23  e89810f3ff           call 0x5b2ec0
// 00681e28  8b4608               mov eax, dword ptr [esi + 8]
// 00681e2b  8a4e20               mov cl, byte ptr [esi + 0x20]
// 00681e2e  884820               mov byte ptr [eax + 0x20], cl
// 00681e31  885e20               mov byte ptr [esi + 0x20], bl
// 00681e34  8b5008               mov edx, dword ptr [eax + 8]
// 00681e37  56                   push esi
// 00681e38  8bcd                 mov ecx, ebp
// 00681e3a  885a20               mov byte ptr [edx + 0x20], bl
// 00681e3d  e8ae57e5ff           call 0x4d75f0
// 00681e42  eb74                 jmp 0x681eb8
// 00681e44  80782000             cmp byte ptr [eax + 0x20], 0
// 00681e48  7511                 jne 0x681e5b
// 00681e4a  885820               mov byte ptr [eax + 0x20], bl
// 00681e4d  56                   push esi
// 00681e4e  8bcd                 mov ecx, ebp
// 00681e50  c6462000             mov byte ptr [esi + 0x20], 0
// 00681e54  e86710f3ff           call 0x5b2ec0
// 00681e59  8b06                 mov eax, dword ptr [esi]
// 00681e5b  80782100             cmp byte ptr [eax + 0x21], 0
// 00681e5f  7513                 jne 0x681e74
// 00681e61  8b4808               mov ecx, dword ptr [eax + 8]
// 00681e64  385920               cmp byte ptr [ecx + 0x20], bl
// 00681e67  751e                 jne 0x681e87
// 00681e69  8b10                 mov edx, dword ptr [eax]
// 00681e6b  385a20               cmp byte ptr [edx + 0x20], bl
// 00681e6e  7517                 jne 0x681e87
// 00681e70  c6402000             mov byte ptr [eax + 0x20], 0
// 00681e74  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00681e77  8bfe                 mov edi, esi
// 00681e79  8b7604               mov esi, dword ptr [esi + 4]
// 00681e7c  3b7804               cmp edi, dword ptr [eax + 4]
// 00681e7f  0f854bffffff         jne 0x681dd0
// 00681e85  eb31                 jmp 0x681eb8
// 00681e87  8b08                 mov ecx, dword ptr [eax]
// 00681e89  385920               cmp byte ptr [ecx + 0x20], bl
// 00681e8c  7514                 jne 0x681ea2
// 00681e8e  8b5008               mov edx, dword ptr [eax + 8]
// 00681e91  885a20               mov byte ptr [edx + 0x20], bl
// 00681e94  50                   push eax
// 00681e95  8bcd                 mov ecx, ebp
// 00681e97  c6402000             mov byte ptr [eax + 0x20], 0
// 00681e9b  e85057e5ff           call 0x4d75f0
// 00681ea0  8b06                 mov eax, dword ptr [esi]
// 00681ea2  8a4e20               mov cl, byte ptr [esi + 0x20]
// 00681ea5  884820               mov byte ptr [eax + 0x20], cl
// 00681ea8  885e20               mov byte ptr [esi + 0x20], bl
// 00681eab  8b10                 mov edx, dword ptr [eax]
// 00681ead  56                   push esi
// 00681eae  8bcd                 mov ecx, ebp
// 00681eb0  885a20               mov byte ptr [edx + 0x20], bl
// 00681eb3  e80810f3ff           call 0x5b2ec0
// 00681eb8  885f20               mov byte ptr [edi + 0x20], bl
// 00681ebb  8b442410             mov eax, dword ptr [esp + 0x10]
// 00681ebf  50                   push eax
// 00681ec0  e8b5e70100           call 0x6a067a
// 00681ec5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00681ec8  83c404               add esp, 4
// 00681ecb  5f                   pop edi
// 00681ecc  5e                   pop esi
// 00681ecd  5b                   pop ebx
// 00681ece  85c0                 test eax, eax
// 00681ed0  7604                 jbe 0x681ed6
// 00681ed2  48                   dec eax
// 00681ed3  89451c               mov dword ptr [ebp + 0x1c], eax
// 00681ed6  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00681eda  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00681ede  8b5500               mov edx, dword ptr [ebp]
// 00681ee1  894804               mov dword ptr [eax + 4], ecx
// 00681ee4  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00681ee8  8910                 mov dword ptr [eax], edx
// 00681eea  5d                   pop ebp
// 00681eeb  64890d00000000       mov dword ptr fs:[0], ecx
// 00681ef2  83c454               add esp, 0x54
// 00681ef5  c20c00               ret 0xc
// standard library set<pod20> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
