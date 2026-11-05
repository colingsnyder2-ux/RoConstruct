// from server: 100% by auto
// roc 2008-06 00691f90  unit: Ogre::RbxSceneManager  size: 712 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00691f90
//
// 00691f90  64a100000000         mov eax, dword ptr fs:[0]
// 00691f96  6aff                 push -1
// 00691f98  6842e87d00           push 0x7de842
// 00691f9d  50                   push eax
// 00691f9e  64892500000000       mov dword ptr fs:[0], esp
// 00691fa5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00691fa9  83ec48               sub esp, 0x48
// 00691fac  80780e00             cmp byte ptr [eax + 0xe], 0
// 00691fb0  55                   push ebp
// 00691fb1  8be9                 mov ebp, ecx
// 00691fb3  7459                 je 0x69200e
// 00691fb5  6870b28000           push 0x80b270
// 00691fba  8d4c240c             lea ecx, [esp + 0xc]
// 00691fbe  ff1558248000         call dword ptr [0x802458]
// 00691fc4  8d4c2424             lea ecx, [esp + 0x24]
// 00691fc8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00691fd0  ff1598288000         call dword ptr [0x802898]
// 00691fd6  8d442408             lea eax, [esp + 8]
// 00691fda  50                   push eax
// 00691fdb  8d4c2434             lea ecx, [esp + 0x34]
// 00691fdf  c644245801           mov byte ptr [esp + 0x58], 1
// 00691fe4  c744242810b18000     mov dword ptr [esp + 0x28], 0x80b110
// 00691fec  ff155c248000         call dword ptr [0x80245c]
// 00691ff2  683c0c8d00           push 0x8d0c3c
// 00691ff7  8d4c2428             lea ecx, [esp + 0x28]
// 00691ffb  51                   push ecx
// 00691ffc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00692001  c744242c28b18000     mov dword ptr [esp + 0x2c], 0x80b128
// 00692009  e87ef50000           call 0x6a158c
// 0069200e  53                   push ebx
// 0069200f  56                   push esi
// 00692010  8bd8                 mov ebx, eax
// 00692012  57                   push edi
// 00692013  8d4c246c             lea ecx, [esp + 0x6c]
// 00692017  895c2410             mov dword ptr [esp + 0x10], ebx
// 0069201b  e8c0b3ffff           call 0x68d3e0
// 00692020  8b0b                 mov ecx, dword ptr [ebx]
// 00692022  80790e00             cmp byte ptr [ecx + 0xe], 0
// 00692026  7405                 je 0x69202d
// 00692028  8b7b08               mov edi, dword ptr [ebx + 8]
// 0069202b  eb1b                 jmp 0x692048
// 0069202d  8b5308               mov edx, dword ptr [ebx + 8]
// 00692030  807a0e00             cmp byte ptr [edx + 0xe], 0
// 00692034  7404                 je 0x69203a
// 00692036  8bf9                 mov edi, ecx
// 00692038  eb0e                 jmp 0x692048
// 0069203a  8b442470             mov eax, dword ptr [esp + 0x70]
// 0069203e  8b7808               mov edi, dword ptr [eax + 8]
// 00692041  8d5008               lea edx, [eax + 8]
// 00692044  3bc3                 cmp eax, ebx
// 00692046  756b                 jne 0x6920b3
// 00692048  807f0e00             cmp byte ptr [edi + 0xe], 0
// 0069204c  8b7304               mov esi, dword ptr [ebx + 4]
// 0069204f  7503                 jne 0x692054
// 00692051  897704               mov dword ptr [edi + 4], esi
// 00692054  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00692057  395804               cmp dword ptr [eax + 4], ebx
// 0069205a  7505                 jne 0x692061
// 0069205c  897804               mov dword ptr [eax + 4], edi
// 0069205f  eb0b                 jmp 0x69206c
// 00692061  391e                 cmp dword ptr [esi], ebx
// 00692063  7504                 jne 0x692069
// 00692065  893e                 mov dword ptr [esi], edi
// 00692067  eb03                 jmp 0x69206c
// 00692069  897e08               mov dword ptr [esi + 8], edi
// 0069206c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0069206f  8b03                 mov eax, dword ptr [ebx]
// 00692071  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00692075  7515                 jne 0x69208c
// 00692077  807f0e00             cmp byte ptr [edi + 0xe], 0
// 0069207b  7404                 je 0x692081
// 0069207d  8bc6                 mov eax, esi
// 0069207f  eb09                 jmp 0x69208a
// 00692081  57                   push edi
// 00692082  e819b2ffff           call 0x68d2a0
// 00692087  83c404               add esp, 4
// 0069208a  8903                 mov dword ptr [ebx], eax
// 0069208c  8b5d18               mov ebx, dword ptr [ebp + 0x18]
// 0069208f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00692093  394b08               cmp dword ptr [ebx + 8], ecx
// 00692096  7577                 jne 0x69210f
// 00692098  807f0e00             cmp byte ptr [edi + 0xe], 0
// 0069209c  7407                 je 0x6920a5
// 0069209e  8bc6                 mov eax, esi
// 006920a0  894308               mov dword ptr [ebx + 8], eax
// 006920a3  eb6a                 jmp 0x69210f
// 006920a5  57                   push edi
// 006920a6  e8d5b1ffff           call 0x68d280
// 006920ab  83c404               add esp, 4
// 006920ae  894308               mov dword ptr [ebx + 8], eax
// 006920b1  eb5c                 jmp 0x69210f
// 006920b3  894104               mov dword ptr [ecx + 4], eax
// 006920b6  8b0b                 mov ecx, dword ptr [ebx]
// 006920b8  8908                 mov dword ptr [eax], ecx
// 006920ba  3b4308               cmp eax, dword ptr [ebx + 8]
// 006920bd  7504                 jne 0x6920c3
// 006920bf  8bf0                 mov esi, eax
// 006920c1  eb19                 jmp 0x6920dc
// 006920c3  807f0e00             cmp byte ptr [edi + 0xe], 0
// 006920c7  8b7004               mov esi, dword ptr [eax + 4]
// 006920ca  7503                 jne 0x6920cf
// 006920cc  897704               mov dword ptr [edi + 4], esi
// 006920cf  893e                 mov dword ptr [esi], edi
// 006920d1  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006920d4  890a                 mov dword ptr [edx], ecx
// 006920d6  8b5308               mov edx, dword ptr [ebx + 8]
// 006920d9  894204               mov dword ptr [edx + 4], eax
// 006920dc  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 006920df  395904               cmp dword ptr [ecx + 4], ebx
// 006920e2  7505                 jne 0x6920e9
// 006920e4  894104               mov dword ptr [ecx + 4], eax
// 006920e7  eb0e                 jmp 0x6920f7
// 006920e9  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006920ec  3919                 cmp dword ptr [ecx], ebx
// 006920ee  7504                 jne 0x6920f4
// 006920f0  8901                 mov dword ptr [ecx], eax
// 006920f2  eb03                 jmp 0x6920f7
// 006920f4  894108               mov dword ptr [ecx + 8], eax
// 006920f7  8b4b04               mov ecx, dword ptr [ebx + 4]
// 006920fa  894804               mov dword ptr [eax + 4], ecx
// 006920fd  8d4b0d               lea ecx, [ebx + 0xd]
// 00692100  83c00d               add eax, 0xd
// 00692103  3bc1                 cmp eax, ecx
// 00692105  7408                 je 0x69210f
// 00692107  8a19                 mov bl, byte ptr [ecx]
// 00692109  8a10                 mov dl, byte ptr [eax]
// 0069210b  8818                 mov byte ptr [eax], bl
// 0069210d  8811                 mov byte ptr [ecx], dl
// 0069210f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00692113  b301                 mov bl, 1
// 00692115  385a0d               cmp byte ptr [edx + 0xd], bl
// 00692118  0f85fd000000         jne 0x69221b
// 0069211e  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00692121  3b7804               cmp edi, dword ptr [eax + 4]
// 00692124  0f84ee000000         je 0x692218
// 0069212a  8d9b00000000         lea ebx, [ebx]
// 00692130  385f0d               cmp byte ptr [edi + 0xd], bl
// 00692133  0f85df000000         jne 0x692218
// 00692139  8b06                 mov eax, dword ptr [esi]
// 0069213b  3bf8                 cmp edi, eax
// 0069213d  7565                 jne 0x6921a4
// 0069213f  8b4608               mov eax, dword ptr [esi + 8]
// 00692142  80780d00             cmp byte ptr [eax + 0xd], 0
// 00692146  7512                 jne 0x69215a
// 00692148  88580d               mov byte ptr [eax + 0xd], bl
// 0069214b  56                   push esi
// 0069214c  8bcd                 mov ecx, ebp
// 0069214e  c6460d00             mov byte ptr [esi + 0xd], 0
// 00692152  e86987dfff           call 0x48a8c0
// 00692157  8b4608               mov eax, dword ptr [esi + 8]
// 0069215a  80780e00             cmp byte ptr [eax + 0xe], 0
// 0069215e  7574                 jne 0x6921d4
// 00692160  8b08                 mov ecx, dword ptr [eax]
// 00692162  38590d               cmp byte ptr [ecx + 0xd], bl
// 00692165  7508                 jne 0x69216f
// 00692167  8b5008               mov edx, dword ptr [eax + 8]
// 0069216a  385a0d               cmp byte ptr [edx + 0xd], bl
// 0069216d  7461                 je 0x6921d0
// 0069216f  8b4808               mov ecx, dword ptr [eax + 8]
// 00692172  38590d               cmp byte ptr [ecx + 0xd], bl
// 00692175  7514                 jne 0x69218b
// 00692177  8b10                 mov edx, dword ptr [eax]
// 00692179  885a0d               mov byte ptr [edx + 0xd], bl
// 0069217c  50                   push eax
// 0069217d  8bcd                 mov ecx, ebp
// 0069217f  c6400d00             mov byte ptr [eax + 0xd], 0
// 00692183  e8487adfff           call 0x489bd0
// 00692188  8b4608               mov eax, dword ptr [esi + 8]
// 0069218b  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 0069218e  88480d               mov byte ptr [eax + 0xd], cl
// 00692191  885e0d               mov byte ptr [esi + 0xd], bl
// 00692194  8b5008               mov edx, dword ptr [eax + 8]
// 00692197  56                   push esi
// 00692198  8bcd                 mov ecx, ebp
// 0069219a  885a0d               mov byte ptr [edx + 0xd], bl
// 0069219d  e81e87dfff           call 0x48a8c0
// 006921a2  eb74                 jmp 0x692218
// 006921a4  80780d00             cmp byte ptr [eax + 0xd], 0
// 006921a8  7511                 jne 0x6921bb
// 006921aa  88580d               mov byte ptr [eax + 0xd], bl
// 006921ad  56                   push esi
// 006921ae  8bcd                 mov ecx, ebp
// 006921b0  c6460d00             mov byte ptr [esi + 0xd], 0
// 006921b4  e8177adfff           call 0x489bd0
// 006921b9  8b06                 mov eax, dword ptr [esi]
// 006921bb  80780e00             cmp byte ptr [eax + 0xe], 0
// 006921bf  7513                 jne 0x6921d4
// 006921c1  8b4808               mov ecx, dword ptr [eax + 8]
// 006921c4  38590d               cmp byte ptr [ecx + 0xd], bl
// 006921c7  751e                 jne 0x6921e7
// 006921c9  8b10                 mov edx, dword ptr [eax]
// 006921cb  385a0d               cmp byte ptr [edx + 0xd], bl
// 006921ce  7517                 jne 0x6921e7
// 006921d0  c6400d00             mov byte ptr [eax + 0xd], 0
// 006921d4  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006921d7  8bfe                 mov edi, esi
// 006921d9  8b7604               mov esi, dword ptr [esi + 4]
// 006921dc  3b7804               cmp edi, dword ptr [eax + 4]
// 006921df  0f854bffffff         jne 0x692130
// 006921e5  eb31                 jmp 0x692218
// 006921e7  8b08                 mov ecx, dword ptr [eax]
// 006921e9  38590d               cmp byte ptr [ecx + 0xd], bl
// 006921ec  7514                 jne 0x692202
// 006921ee  8b5008               mov edx, dword ptr [eax + 8]
// 006921f1  885a0d               mov byte ptr [edx + 0xd], bl
// 006921f4  50                   push eax
// 006921f5  8bcd                 mov ecx, ebp
// 006921f7  c6400d00             mov byte ptr [eax + 0xd], 0
// 006921fb  e8c086dfff           call 0x48a8c0
// 00692200  8b06                 mov eax, dword ptr [esi]
// 00692202  8a4e0d               mov cl, byte ptr [esi + 0xd]
// 00692205  88480d               mov byte ptr [eax + 0xd], cl
// 00692208  885e0d               mov byte ptr [esi + 0xd], bl
// 0069220b  8b10                 mov edx, dword ptr [eax]
// 0069220d  56                   push esi
// 0069220e  8bcd                 mov ecx, ebp
// 00692210  885a0d               mov byte ptr [edx + 0xd], bl
// 00692213  e8b879dfff           call 0x489bd0
// 00692218  885f0d               mov byte ptr [edi + 0xd], bl
// 0069221b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0069221f  50                   push eax
// 00692220  e855e40000           call 0x6a067a
// 00692225  8b451c               mov eax, dword ptr [ebp + 0x1c]
// 00692228  83c404               add esp, 4
// 0069222b  5f                   pop edi
// 0069222c  5e                   pop esi
// 0069222d  5b                   pop ebx
// 0069222e  85c0                 test eax, eax
// 00692230  7604                 jbe 0x692236
// 00692232  48                   dec eax
// 00692233  89451c               mov dword ptr [ebp + 0x1c], eax
// 00692236  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0069223a  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0069223e  8b5500               mov edx, dword ptr [ebp]
// 00692241  894804               mov dword ptr [eax + 4], ecx
// 00692244  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00692248  8910                 mov dword ptr [eax], edx
// 0069224a  5d                   pop ebp
// 0069224b  64890d00000000       mov dword ptr fs:[0], ecx
// 00692252  83c454               add esp, 0x54
// 00692255  c20c00               ret 0xc
// standard library set<char> (function ?erase@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@@Z)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
