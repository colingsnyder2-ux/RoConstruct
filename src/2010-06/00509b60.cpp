// from server: 100% by auto
// roc 2010-06 00509b60  unit: RBX::Network::ServerReplicator  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00509b60
//
// 00509b60  64a100000000         mov eax, dword ptr fs:[0]
// 00509b66  6aff                 push -1
// 00509b68  68e22f9a00           push 0x9a2fe2
// 00509b6d  50                   push eax
// 00509b6e  64892500000000       mov dword ptr fs:[0], esp
// 00509b75  8b442418             mov eax, dword ptr [esp + 0x18]
// 00509b79  83ec48               sub esp, 0x48
// 00509b7c  80782900             cmp byte ptr [eax + 0x29], 0
// 00509b80  55                   push ebp
// 00509b81  8be9                 mov ebp, ecx
// 00509b83  7459                 je 0x509bde
// 00509b85  688c00a000           push 0xa0008c
// 00509b8a  8d4c240c             lea ecx, [esp + 0xc]
// 00509b8e  ff1510a49e00         call dword ptr [0x9ea410]
// 00509b94  8d4c2424             lea ecx, [esp + 0x24]
// 00509b98  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00509ba0  ff1518a99e00         call dword ptr [0x9ea918]
// 00509ba6  8d442408             lea eax, [esp + 8]
// 00509baa  50                   push eax
// 00509bab  8d4c2434             lea ecx, [esp + 0x34]
// 00509baf  c644245801           mov byte ptr [esp + 0x58], 1
// 00509bb4  c74424282c00a000     mov dword ptr [esp + 0x28], 0xa0002c
// 00509bbc  ff150ca49e00         call dword ptr [0x9ea40c]
// 00509bc2  68081bb000           push 0xb01b08
// 00509bc7  8d4c2428             lea ecx, [esp + 0x28]
// 00509bcb  51                   push ecx
// 00509bcc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00509bd1  c744242c4400a000     mov dword ptr [esp + 0x2c], 0xa00044
// 00509bd9  e8d4ed2900           call 0x7a89b2
// 00509bde  53                   push ebx
// 00509bdf  56                   push esi
// 00509be0  8bd8                 mov ebx, eax
// 00509be2  57                   push edi
// 00509be3  8d4c246c             lea ecx, [esp + 0x6c]
// 00509be7  895c2410             mov dword ptr [esp + 0x10], ebx
// 00509beb  e8c0592600           call 0x76f5b0
// 00509bf0  8b0b                 mov ecx, dword ptr [ebx]
// 00509bf2  80792900             cmp byte ptr [ecx + 0x29], 0
// 00509bf6  7405                 je 0x509bfd
// 00509bf8  8b7b08               mov edi, dword ptr [ebx + 8]
// 00509bfb  eb1b                 jmp 0x509c18
// 00509bfd  8b5308               mov edx, dword ptr [ebx + 8]
// 00509c00  807a2900             cmp byte ptr [edx + 0x29], 0
// 00509c04  7404                 je 0x509c0a
// 00509c06  8bf9                 mov edi, ecx
// 00509c08  eb0e                 jmp 0x509c18
// 00509c0a  8b442470             mov eax, dword ptr [esp + 0x70]
// 00509c0e  8b7808               mov edi, dword ptr [eax + 8]
// 00509c11  8d5008               lea edx, [eax + 8]
// 00509c14  3bc3                 cmp eax, ebx
// 00509c16  756b                 jne 0x509c83
// 00509c18  807f2900             cmp byte ptr [edi + 0x29], 0
// 00509c1c  8b7304               mov esi, dword ptr [ebx + 4]
// 00509c1f  7503                 jne 0x509c24
// 00509c21  897704               mov dword ptr [edi + 4], esi
// 00509c24  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00509c27  395804               cmp dword ptr [eax + 4], ebx
// 00509c2a  7505                 jne 0x509c31
// 00509c2c  897804               mov dword ptr [eax + 4], edi
// 00509c2f  eb0b                 jmp 0x509c3c
// 00509c31  391e                 cmp dword ptr [esi], ebx
// 00509c33  7504                 jne 0x509c39
// 00509c35  893e                 mov dword ptr [esi], edi
// 00509c37  eb03                 jmp 0x509c3c
// 00509c39  897e08               mov dword ptr [esi + 8], edi
// 00509c3c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00509c3f  8b03                 mov eax, dword ptr [ebx]
// 00509c41  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00509c45  7515                 jne 0x509c5c
// 00509c47  807f2900             cmp byte ptr [edi + 0x29], 0
// 00509c4b  7404                 je 0x509c51
// 00509c4d  8bc6                 mov eax, esi
// 00509c4f  eb09                 jmp 0x509c5a
// 00509c51  57                   push edi
// 00509c52  e8d9ce0100           call 0x526b30
// 00509c57  83c404               add esp, 4
// 00509c5a  8903                 mov dword ptr [ebx], eax
// 00509c5c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 00509c5f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00509c63  394b08               cmp dword ptr [ebx + 8], ecx
// 00509c66  7577                 jne 0x509cdf
// 00509c68  807f2900             cmp byte ptr [edi + 0x29], 0
// 00509c6c  7407                 je 0x509c75
// 00509c6e  8bc6                 mov eax, esi
// 00509c70  894308               mov dword ptr [ebx + 8], eax
// 00509c73  eb6a                 jmp 0x509cdf
// 00509c75  57                   push edi
// 00509c76  e815290200           call 0x52c590
// 00509c7b  83c404               add esp, 4
// 00509c7e  894308               mov dword ptr [ebx + 8], eax
// 00509c81  eb5c                 jmp 0x509cdf
// 00509c83  894104               mov dword ptr [ecx + 4], eax
// 00509c86  8b0b                 mov ecx, dword ptr [ebx]
// 00509c88  8908                 mov dword ptr [eax], ecx
// 00509c8a  3b4308               cmp eax, dword ptr [ebx + 8]
// 00509c8d  7504                 jne 0x509c93
// 00509c8f  8bf0                 mov esi, eax
// 00509c91  eb19                 jmp 0x509cac
// 00509c93  807f2900             cmp byte ptr [edi + 0x29], 0
// 00509c97  8b7004               mov esi, dword ptr [eax + 4]
// 00509c9a  7503                 jne 0x509c9f
// 00509c9c  897704               mov dword ptr [edi + 4], esi
// 00509c9f  893e                 mov dword ptr [esi], edi
// 00509ca1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00509ca4  890a                 mov dword ptr [edx], ecx
// 00509ca6  8b5308               mov edx, dword ptr [ebx + 8]
// 00509ca9  894204               mov dword ptr [edx + 4], eax
// 00509cac  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00509caf  395904               cmp dword ptr [ecx + 4], ebx
// 00509cb2  7505                 jne 0x509cb9
// 00509cb4  894104               mov dword ptr [ecx + 4], eax
// 00509cb7  eb0e                 jmp 0x509cc7
// 00509cb9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00509cbc  3919                 cmp dword ptr [ecx], ebx
// 00509cbe  7504                 jne 0x509cc4
// 00509cc0  8901                 mov dword ptr [ecx], eax
// 00509cc2  eb03                 jmp 0x509cc7
// 00509cc4  894108               mov dword ptr [ecx + 8], eax
// 00509cc7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00509cca  894804               mov dword ptr [eax + 4], ecx
// 00509ccd  8d4b28               lea ecx, [ebx + 0x28]
// 00509cd0  83c028               add eax, 0x28
// 00509cd3  3bc1                 cmp eax, ecx
// 00509cd5  7408                 je 0x509cdf
// 00509cd7  8a19                 mov bl, byte ptr [ecx]
// 00509cd9  8a10                 mov dl, byte ptr [eax]
// 00509cdb  8818                 mov byte ptr [eax], bl
// 00509cdd  8811                 mov byte ptr [ecx], dl
// 00509cdf  8b542410             mov edx, dword ptr [esp + 0x10]
// 00509ce3  b301                 mov bl, 1
// 00509ce5  385a28               cmp byte ptr [edx + 0x28], bl
// 00509ce8  0f85fd000000         jne 0x509deb
// 00509cee  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00509cf1  3b7804               cmp edi, dword ptr [eax + 4]
// 00509cf4  0f84ee000000         je 0x509de8
// 00509cfa  8d9b00000000         lea ebx, [ebx]
// 00509d00  385f28               cmp byte ptr [edi + 0x28], bl
// 00509d03  0f85df000000         jne 0x509de8
// 00509d09  8b06                 mov eax, dword ptr [esi]
// 00509d0b  3bf8                 cmp edi, eax
// 00509d0d  7565                 jne 0x509d74
// 00509d0f  8b4608               mov eax, dword ptr [esi + 8]
// 00509d12  80782800             cmp byte ptr [eax + 0x28], 0
// 00509d16  7512                 jne 0x509d2a
// 00509d18  885828               mov byte ptr [eax + 0x28], bl
// 00509d1b  56                   push esi
// 00509d1c  8bcd                 mov ecx, ebp
// 00509d1e  c6462800             mov byte ptr [esi + 0x28], 0
// 00509d22  e8a9d20100           call 0x526fd0
// 00509d27  8b4608               mov eax, dword ptr [esi + 8]
// 00509d2a  80782900             cmp byte ptr [eax + 0x29], 0
// 00509d2e  7574                 jne 0x509da4
// 00509d30  8b08                 mov ecx, dword ptr [eax]
// 00509d32  385928               cmp byte ptr [ecx + 0x28], bl
// 00509d35  7508                 jne 0x509d3f
// 00509d37  8b5008               mov edx, dword ptr [eax + 8]
// 00509d3a  385a28               cmp byte ptr [edx + 0x28], bl
// 00509d3d  7461                 je 0x509da0
// 00509d3f  8b4808               mov ecx, dword ptr [eax + 8]
// 00509d42  385928               cmp byte ptr [ecx + 0x28], bl
// 00509d45  7514                 jne 0x509d5b
// 00509d47  8b10                 mov edx, dword ptr [eax]
// 00509d49  885a28               mov byte ptr [edx + 0x28], bl
// 00509d4c  50                   push eax
// 00509d4d  8bcd                 mov ecx, ebp
// 00509d4f  c6402800             mov byte ptr [eax + 0x28], 0
// 00509d53  e818d20100           call 0x526f70
// 00509d58  8b4608               mov eax, dword ptr [esi + 8]
// 00509d5b  8a4e28               mov cl, byte ptr [esi + 0x28]
// 00509d5e  884828               mov byte ptr [eax + 0x28], cl
// 00509d61  885e28               mov byte ptr [esi + 0x28], bl
// 00509d64  8b5008               mov edx, dword ptr [eax + 8]
// 00509d67  56                   push esi
// 00509d68  8bcd                 mov ecx, ebp
// 00509d6a  885a28               mov byte ptr [edx + 0x28], bl
// 00509d6d  e85ed20100           call 0x526fd0
// 00509d72  eb74                 jmp 0x509de8
// 00509d74  80782800             cmp byte ptr [eax + 0x28], 0
// 00509d78  7511                 jne 0x509d8b
// 00509d7a  885828               mov byte ptr [eax + 0x28], bl
// 00509d7d  56                   push esi
// 00509d7e  8bcd                 mov ecx, ebp
// 00509d80  c6462800             mov byte ptr [esi + 0x28], 0
// 00509d84  e8e7d10100           call 0x526f70
// 00509d89  8b06                 mov eax, dword ptr [esi]
// 00509d8b  80782900             cmp byte ptr [eax + 0x29], 0
// 00509d8f  7513                 jne 0x509da4
// 00509d91  8b4808               mov ecx, dword ptr [eax + 8]
// 00509d94  385928               cmp byte ptr [ecx + 0x28], bl
// 00509d97  751e                 jne 0x509db7
// 00509d99  8b10                 mov edx, dword ptr [eax]
// 00509d9b  385a28               cmp byte ptr [edx + 0x28], bl
// 00509d9e  7517                 jne 0x509db7
// 00509da0  c6402800             mov byte ptr [eax + 0x28], 0
// 00509da4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00509da7  8bfe                 mov edi, esi
// 00509da9  8b7604               mov esi, dword ptr [esi + 4]
// 00509dac  3b7804               cmp edi, dword ptr [eax + 4]
// 00509daf  0f854bffffff         jne 0x509d00
// 00509db5  eb31                 jmp 0x509de8
// 00509db7  8b08                 mov ecx, dword ptr [eax]
// 00509db9  385928               cmp byte ptr [ecx + 0x28], bl
// 00509dbc  7514                 jne 0x509dd2
// 00509dbe  8b5008               mov edx, dword ptr [eax + 8]
// 00509dc1  885a28               mov byte ptr [edx + 0x28], bl
// 00509dc4  50                   push eax
// 00509dc5  8bcd                 mov ecx, ebp
// 00509dc7  c6402800             mov byte ptr [eax + 0x28], 0
// 00509dcb  e800d20100           call 0x526fd0
// 00509dd0  8b06                 mov eax, dword ptr [esi]
// 00509dd2  8a4e28               mov cl, byte ptr [esi + 0x28]
// 00509dd5  884828               mov byte ptr [eax + 0x28], cl
// 00509dd8  885e28               mov byte ptr [esi + 0x28], bl
// 00509ddb  8b10                 mov edx, dword ptr [eax]
// 00509ddd  56                   push esi
// 00509dde  8bcd                 mov ecx, ebp
// 00509de0  885a28               mov byte ptr [edx + 0x28], bl
// 00509de3  e888d10100           call 0x526f70
// 00509de8  885f28               mov byte ptr [edi + 0x28], bl
// 00509deb  8b442410             mov eax, dword ptr [esp + 0x10]
// 00509def  50                   push eax
// 00509df0  e8a5db2900           call 0x7a799a
// 00509df5  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00509df8  83c404               add esp, 4
// 00509dfb  5f                   pop edi
// 00509dfc  5e                   pop esi
// 00509dfd  5b                   pop ebx
// 00509dfe  85c0                 test eax, eax
// 00509e00  7604                 jbe 0x509e06
// 00509e02  48                   dec eax
// 00509e03  89451c               mov dword ptr [ebp + 0x1c], eax
// 00509e06  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00509e0a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00509e0e  8b5500               mov edx, dword ptr [ebp]
// 00509e11  894804               mov dword ptr [eax + 4], ecx
// 00509e14  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00509e18  8910                 mov dword ptr [eax], edx
// 00509e1a  5d                   pop ebp
// 00509e1b  64890d00000000       mov dword ptr fs:[0], ecx
// 00509e22  83c454               add esp, 0x54
// 00509e25  c20c00               ret 0xc
// standard library set<pod28> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<pod28>
struct E { int v[7]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
