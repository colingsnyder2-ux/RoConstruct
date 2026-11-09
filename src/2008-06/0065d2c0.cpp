// from server: 100% by colin
// roc 2008-06 0065d2c0  unit: seg_00650000  size: 4376 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065d2c0
//
// 0065d2c0  55                   push ebp
// 0065d2c1  8bec                 mov ebp, esp
// 0065d2c3  83e4c0               and esp, 0xffffffc0
// 0065d2c6  83ec74               sub esp, 0x74
// 0065d2c9  53                   push ebx
// 0065d2ca  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0065d2cd  56                   push esi
// 0065d2ce  57                   push edi
// 0065d2cf  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 0065d2d2  8b4318               mov eax, dword ptr [ebx + 0x18]
// 0065d2d5  8b5104               mov edx, dword ptr [ecx + 4]
// 0065d2d8  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065d2db  89442410             mov dword ptr [esp + 0x10], eax
// 0065d2df  8b02                 mov eax, dword ptr [edx]
// 0065d2e1  8b5010               mov edx, dword ptr [eax + 0x10]
// 0065d2e4  8944241c             mov dword ptr [esp + 0x1c], eax
// 0065d2e8  8b4208               mov eax, dword ptr [edx + 8]
// 0065d2eb  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065d2ef  89442418             mov dword ptr [esp + 0x18], eax
// 0065d2f3  eb02                 jmp 0x65d2f7
// 0065d2f5  ddd8                 fstp st(0)
// 0065d2f7  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065d2fb  8b38                 mov edi, dword ptr [eax]
// 0065d2fd  83c004               add eax, 4
// 0065d300  89442410             mov dword ptr [esp + 0x10], eax
// 0065d304  8a4336               mov al, byte ptr [ebx + 0x36]
// 0065d307  a80c                 test al, 0xc
// 0065d309  742a                 je 0x65d335
// 0065d30b  83433cff             add dword ptr [ebx + 0x3c], -1
// 0065d30f  7404                 je 0x65d315
// 0065d311  a804                 test al, 4
// 0065d313  7420                 je 0x65d335
// 0065d315  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065d319  51                   push ecx
// 0065d31a  8bf3                 mov esi, ebx
// 0065d31c  e8fff3ffff           call 0x65c720
// 0065d321  83c404               add esp, 4
// 0065d324  807b0601             cmp byte ptr [ebx + 6], 1
// 0065d328  0f8401100000         je 0x65e32f
// 0065d32e  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065d331  89542414             mov dword ptr [esp + 0x14], edx
// 0065d335  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065d339  8bc7                 mov eax, edi
// 0065d33b  c1e806               shr eax, 6
// 0065d33e  25ff000000           and eax, 0xff
// 0065d343  8bc8                 mov ecx, eax
// 0065d345  89442424             mov dword ptr [esp + 0x24], eax
// 0065d349  c1e104               shl ecx, 4
// 0065d34c  8bc7                 mov eax, edi
// 0065d34e  83e03f               and eax, 0x3f
// 0065d351  8d3411               lea esi, [ecx + edx]
// 0065d354  894c2428             mov dword ptr [esp + 0x28], ecx
// 0065d358  89742420             mov dword ptr [esp + 0x20], esi
// 0065d35c  83f825               cmp eax, 0x25
// 0065d35f  7796                 ja 0x65d2f7
// 0065d361  ff248540e36500       jmp dword ptr [eax*4 + 0x65e340]
// 0065d368  c1ef17               shr edi, 0x17
// 0065d36b  c1e704               shl edi, 4
// 0065d36e  03fa                 add edi, edx
// 0065d370  8b07                 mov eax, dword ptr [edi]
// 0065d372  8906                 mov dword ptr [esi], eax
// 0065d374  8b4f04               mov ecx, dword ptr [edi + 4]
// 0065d377  894e04               mov dword ptr [esi + 4], ecx
// 0065d37a  8b5708               mov edx, dword ptr [edi + 8]
// 0065d37d  895608               mov dword ptr [esi + 8], edx
// 0065d380  e972ffffff           jmp 0x65d2f7
// 0065d385  c1ef0e               shr edi, 0xe
// 0065d388  c1e704               shl edi, 4
// 0065d38b  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d38f  ebdf                 jmp 0x65d370
// 0065d391  8bc7                 mov eax, edi
// 0065d393  c1e817               shr eax, 0x17
// 0065d396  8906                 mov dword ptr [esi], eax
// 0065d398  c7460801000000       mov dword ptr [esi + 8], 1
// 0065d39f  f7c700c07f00         test edi, 0x7fc000
// 0065d3a5  0f844cffffff         je 0x65d2f7
// 0065d3ab  8344241004           add dword ptr [esp + 0x10], 4
// 0065d3b0  e942ffffff           jmp 0x65d2f7
// 0065d3b5  c1ef17               shr edi, 0x17
// 0065d3b8  c1e704               shl edi, 4
// 0065d3bb  03fa                 add edi, edx
// 0065d3bd  33c0                 xor eax, eax
// 0065d3bf  90                   nop 
// 0065d3c0  894708               mov dword ptr [edi + 8], eax
// 0065d3c3  83ef10               sub edi, 0x10
// 0065d3c6  3bfe                 cmp edi, esi
// 0065d3c8  73f6                 jae 0x65d3c0
// 0065d3ca  e928ffffff           jmp 0x65d2f7
// 0065d3cf  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065d3d3  c1ef17               shr edi, 0x17
// 0065d3d6  8b54b914             mov edx, dword ptr [ecx + edi*4 + 0x14]
// 0065d3da  8b4208               mov eax, dword ptr [edx + 8]
// 0065d3dd  8b08                 mov ecx, dword ptr [eax]
// 0065d3df  890e                 mov dword ptr [esi], ecx
// 0065d3e1  8b5004               mov edx, dword ptr [eax + 4]
// 0065d3e4  895604               mov dword ptr [esi + 4], edx
// 0065d3e7  8b4008               mov eax, dword ptr [eax + 8]
// 0065d3ea  894608               mov dword ptr [esi + 8], eax
// 0065d3ed  e905ffffff           jmp 0x65d2f7
// 0065d3f2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065d3f6  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0065d3f9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065d3fd  c1ef0e               shr edi, 0xe
// 0065d400  c1e704               shl edi, 4
// 0065d403  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d407  56                   push esi
// 0065d408  57                   push edi
// 0065d409  8d4c2458             lea ecx, [esp + 0x58]
// 0065d40d  51                   push ecx
// 0065d40e  53                   push ebx
// 0065d40f  89542460             mov dword ptr [esp + 0x60], edx
// 0065d413  c744246805000000     mov dword ptr [esp + 0x68], 5
// 0065d41b  894318               mov dword ptr [ebx + 0x18], eax
// 0065d41e  e8bdf4ffff           call 0x65c8e0
// 0065d423  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065d426  83c410               add esp, 0x10
// 0065d429  89542414             mov dword ptr [esp + 0x14], edx
// 0065d42d  e9c5feffff           jmp 0x65d2f7
// 0065d432  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065d436  894318               mov dword ptr [ebx + 0x18], eax
// 0065d439  8bc7                 mov eax, edi
// 0065d43b  c1e80e               shr eax, 0xe
// 0065d43e  a900010000           test eax, 0x100
// 0065d443  740e                 je 0x65d453
// 0065d445  25ff000000           and eax, 0xff
// 0065d44a  c1e004               shl eax, 4
// 0065d44d  03442418             add eax, dword ptr [esp + 0x18]
// 0065d451  eb0a                 jmp 0x65d45d
// 0065d453  25ff010000           and eax, 0x1ff
// 0065d458  c1e004               shl eax, 4
// 0065d45b  03c2                 add eax, edx
// 0065d45d  c1ef17               shr edi, 0x17
// 0065d460  56                   push esi
// 0065d461  c1e704               shl edi, 4
// 0065d464  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d468  50                   push eax
// 0065d469  57                   push edi
// 0065d46a  53                   push ebx
// 0065d46b  e870f4ffff           call 0x65c8e0
// 0065d470  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065d473  83c410               add esp, 0x10
// 0065d476  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065d47a  e978feffff           jmp 0x65d2f7
// 0065d47f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065d483  8b420c               mov eax, dword ptr [edx + 0xc]
// 0065d486  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065d48a  c1ef0e               shr edi, 0xe
// 0065d48d  c1e704               shl edi, 4
// 0065d490  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d494  56                   push esi
// 0065d495  57                   push edi
// 0065d496  8d542468             lea edx, [esp + 0x68]
// 0065d49a  52                   push edx
// 0065d49b  53                   push ebx
// 0065d49c  89442470             mov dword ptr [esp + 0x70], eax
// 0065d4a0  c744247805000000     mov dword ptr [esp + 0x78], 5
// 0065d4a8  894b18               mov dword ptr [ebx + 0x18], ecx
// 0065d4ab  e820f5ffff           call 0x65c9d0
// 0065d4b0  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065d4b3  83c410               add esp, 0x10
// 0065d4b6  89442414             mov dword ptr [esp + 0x14], eax
// 0065d4ba  e938feffff           jmp 0x65d2f7
// 0065d4bf  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0065d4c3  8b16                 mov edx, dword ptr [esi]
// 0065d4c5  c1ef17               shr edi, 0x17
// 0065d4c8  8b7cb914             mov edi, dword ptr [ecx + edi*4 + 0x14]
// 0065d4cc  8b4708               mov eax, dword ptr [edi + 8]
// 0065d4cf  8910                 mov dword ptr [eax], edx
// 0065d4d1  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065d4d4  894804               mov dword ptr [eax + 4], ecx
// 0065d4d7  8b5608               mov edx, dword ptr [esi + 8]
// 0065d4da  895008               mov dword ptr [eax + 8], edx
// 0065d4dd  837e0804             cmp dword ptr [esi + 8], 4
// 0065d4e1  0f8c10feffff         jl 0x65d2f7
// 0065d4e7  8b36                 mov esi, dword ptr [esi]
// 0065d4e9  f6460503             test byte ptr [esi + 5], 3
// 0065d4ed  0f8404feffff         je 0x65d2f7
// 0065d4f3  f6470504             test byte ptr [edi + 5], 4
// 0065d4f7  0f84fafdffff         je 0x65d2f7
// 0065d4fd  56                   push esi
// 0065d4fe  57                   push edi
// 0065d4ff  53                   push ebx
// 0065d500  e87befffff           call 0x65c480
// 0065d505  83c40c               add esp, 0xc
// 0065d508  e9eafdffff           jmp 0x65d2f7
// 0065d50d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065d511  894318               mov dword ptr [ebx + 0x18], eax
// 0065d514  8bc7                 mov eax, edi
// 0065d516  c1e80e               shr eax, 0xe
// 0065d519  a900010000           test eax, 0x100
// 0065d51e  740e                 je 0x65d52e
// 0065d520  25ff000000           and eax, 0xff
// 0065d525  c1e004               shl eax, 4
// 0065d528  03442418             add eax, dword ptr [esp + 0x18]
// 0065d52c  eb0a                 jmp 0x65d538
// 0065d52e  25ff010000           and eax, 0x1ff
// 0065d533  c1e004               shl eax, 4
// 0065d536  03c2                 add eax, edx
// 0065d538  c1ef17               shr edi, 0x17
// 0065d53b  f7c700010000         test edi, 0x100
// 0065d541  740f                 je 0x65d552
// 0065d543  81e7ff000000         and edi, 0xff
// 0065d549  c1e704               shl edi, 4
// 0065d54c  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d550  eb05                 jmp 0x65d557
// 0065d552  c1e704               shl edi, 4
// 0065d555  03fa                 add edi, edx
// 0065d557  50                   push eax
// 0065d558  57                   push edi
// 0065d559  56                   push esi
// 0065d55a  53                   push ebx
// 0065d55b  e870f4ffff           call 0x65c9d0
// 0065d560  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065d563  83c410               add esp, 0x10
// 0065d566  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065d56a  e988fdffff           jmp 0x65d2f7
// 0065d56f  8bd7                 mov edx, edi
// 0065d571  c1ea0e               shr edx, 0xe
// 0065d574  81e2ff010000         and edx, 0x1ff
// 0065d57a  52                   push edx
// 0065d57b  e8a050fcff           call 0x622620
// 0065d580  83c404               add esp, 4
// 0065d583  50                   push eax
// 0065d584  c1ef17               shr edi, 0x17
// 0065d587  57                   push edi
// 0065d588  e89350fcff           call 0x622620
// 0065d58d  83c404               add esp, 4
// 0065d590  50                   push eax
// 0065d591  53                   push ebx
// 0065d592  e879130000           call 0x65e910
// 0065d597  8906                 mov dword ptr [esi], eax
// 0065d599  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065d59d  c7460805000000       mov dword ptr [esi + 8], 5
// 0065d5a4  83c40c               add esp, 0xc
// 0065d5a7  894318               mov dword ptr [ebx + 0x18], eax
// 0065d5aa  e9a00b0000           jmp 0x65e14f
// 0065d5af  8bc7                 mov eax, edi
// 0065d5b1  c1e817               shr eax, 0x17
// 0065d5b4  c1e004               shl eax, 4
// 0065d5b7  8b0c10               mov ecx, dword ptr [eax + edx]
// 0065d5ba  03c2                 add eax, edx
// 0065d5bc  894e10               mov dword ptr [esi + 0x10], ecx
// 0065d5bf  8b4804               mov ecx, dword ptr [eax + 4]
// 0065d5c2  894e14               mov dword ptr [esi + 0x14], ecx
// 0065d5c5  8b4808               mov ecx, dword ptr [eax + 8]
// 0065d5c8  894e18               mov dword ptr [esi + 0x18], ecx
// 0065d5cb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065d5cf  c1ef0e               shr edi, 0xe
// 0065d5d2  894b18               mov dword ptr [ebx + 0x18], ecx
// 0065d5d5  f7c700010000         test edi, 0x100
// 0065d5db  740f                 je 0x65d5ec
// 0065d5dd  81e7ff000000         and edi, 0xff
// 0065d5e3  c1e704               shl edi, 4
// 0065d5e6  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d5ea  eb0b                 jmp 0x65d5f7
// 0065d5ec  81e7ff010000         and edi, 0x1ff
// 0065d5f2  c1e704               shl edi, 4
// 0065d5f5  03fa                 add edi, edx
// 0065d5f7  56                   push esi
// 0065d5f8  57                   push edi
// 0065d5f9  50                   push eax
// 0065d5fa  53                   push ebx
// 0065d5fb  e8e0f2ffff           call 0x65c8e0
// 0065d600  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065d603  83c410               add esp, 0x10
// 0065d606  89542414             mov dword ptr [esp + 0x14], edx
// 0065d60a  e9e8fcffff           jmp 0x65d2f7
// 0065d60f  8bc7                 mov eax, edi
// 0065d611  c1e817               shr eax, 0x17
// 0065d614  a900010000           test eax, 0x100
// 0065d619  740e                 je 0x65d629
// 0065d61b  25ff000000           and eax, 0xff
// 0065d620  c1e004               shl eax, 4
// 0065d623  03442418             add eax, dword ptr [esp + 0x18]
// 0065d627  eb05                 jmp 0x65d62e
// 0065d629  c1e004               shl eax, 4
// 0065d62c  03c2                 add eax, edx
// 0065d62e  c1ef0e               shr edi, 0xe
// 0065d631  8bc8                 mov ecx, eax
// 0065d633  f7c700010000         test edi, 0x100
// 0065d639  740f                 je 0x65d64a
// 0065d63b  81e7ff000000         and edi, 0xff
// 0065d641  c1e704               shl edi, 4
// 0065d644  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d648  eb0b                 jmp 0x65d655
// 0065d64a  81e7ff010000         and edi, 0x1ff
// 0065d650  c1e704               shl edi, 4
// 0065d653  03fa                 add edi, edx
// 0065d655  b803000000           mov eax, 3
// 0065d65a  394108               cmp dword ptr [ecx + 8], eax
// 0065d65d  7513                 jne 0x65d672
// 0065d65f  394708               cmp dword ptr [edi + 8], eax
// 0065d662  750e                 jne 0x65d672
// 0065d664  dd07                 fld qword ptr [edi]
// 0065d666  dc01                 fadd qword ptr [ecx]
// 0065d668  894608               mov dword ptr [esi + 8], eax
// 0065d66b  dd1e                 fstp qword ptr [esi]
// 0065d66d  e985fcffff           jmp 0x65d2f7
// 0065d672  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065d676  894318               mov dword ptr [ebx + 0x18], eax
// 0065d679  6a05                 push 5
// 0065d67b  8bc7                 mov eax, edi
// 0065d67d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0065d681  53                   push ebx
// 0065d682  8bf1                 mov esi, ecx
// 0065d684  e877faffff           call 0x65d100
// 0065d689  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065d68c  83c408               add esp, 8
// 0065d68f  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065d693  e95ffcffff           jmp 0x65d2f7
// 0065d698  8bc7                 mov eax, edi
// 0065d69a  c1e817               shr eax, 0x17
// 0065d69d  a900010000           test eax, 0x100
// 0065d6a2  740e                 je 0x65d6b2
// 0065d6a4  25ff000000           and eax, 0xff
// 0065d6a9  c1e004               shl eax, 4
// 0065d6ac  03442418             add eax, dword ptr [esp + 0x18]
// 0065d6b0  eb05                 jmp 0x65d6b7
// 0065d6b2  c1e004               shl eax, 4
// 0065d6b5  03c2                 add eax, edx
// 0065d6b7  c1ef0e               shr edi, 0xe
// 0065d6ba  8bc8                 mov ecx, eax
// 0065d6bc  f7c700010000         test edi, 0x100
// 0065d6c2  740f                 je 0x65d6d3
// 0065d6c4  81e7ff000000         and edi, 0xff
// 0065d6ca  c1e704               shl edi, 4
// 0065d6cd  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d6d1  eb0b                 jmp 0x65d6de
// 0065d6d3  81e7ff010000         and edi, 0x1ff
// 0065d6d9  c1e704               shl edi, 4
// 0065d6dc  03fa                 add edi, edx
// 0065d6de  b803000000           mov eax, 3
// 0065d6e3  394108               cmp dword ptr [ecx + 8], eax
// 0065d6e6  7513                 jne 0x65d6fb
// 0065d6e8  394708               cmp dword ptr [edi + 8], eax
// 0065d6eb  750e                 jne 0x65d6fb
// 0065d6ed  dd01                 fld qword ptr [ecx]
// 0065d6ef  dc27                 fsub qword ptr [edi]
// 0065d6f1  894608               mov dword ptr [esi + 8], eax
// 0065d6f4  dd1e                 fstp qword ptr [esi]
// 0065d6f6  e9fcfbffff           jmp 0x65d2f7
// 0065d6fb  6a06                 push 6
// 0065d6fd  e9cd010000           jmp 0x65d8cf
// 0065d702  8bc7                 mov eax, edi
// 0065d704  c1e817               shr eax, 0x17
// 0065d707  a900010000           test eax, 0x100
// 0065d70c  740e                 je 0x65d71c
// 0065d70e  25ff000000           and eax, 0xff
// 0065d713  c1e004               shl eax, 4
// 0065d716  03442418             add eax, dword ptr [esp + 0x18]
// 0065d71a  eb05                 jmp 0x65d721
// 0065d71c  c1e004               shl eax, 4
// 0065d71f  03c2                 add eax, edx
// 0065d721  c1ef0e               shr edi, 0xe
// 0065d724  8bc8                 mov ecx, eax
// 0065d726  f7c700010000         test edi, 0x100
// 0065d72c  740f                 je 0x65d73d
// 0065d72e  81e7ff000000         and edi, 0xff
// 0065d734  c1e704               shl edi, 4
// 0065d737  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d73b  eb0b                 jmp 0x65d748
// 0065d73d  81e7ff010000         and edi, 0x1ff
// 0065d743  c1e704               shl edi, 4
// 0065d746  03fa                 add edi, edx
// 0065d748  b803000000           mov eax, 3
// 0065d74d  394108               cmp dword ptr [ecx + 8], eax
// 0065d750  7513                 jne 0x65d765
// 0065d752  394708               cmp dword ptr [edi + 8], eax
// 0065d755  750e                 jne 0x65d765
// 0065d757  dd07                 fld qword ptr [edi]
// 0065d759  dc09                 fmul qword ptr [ecx]
// 0065d75b  894608               mov dword ptr [esi + 8], eax
// 0065d75e  dd1e                 fstp qword ptr [esi]
// 0065d760  e992fbffff           jmp 0x65d2f7
// 0065d765  6a07                 push 7
// 0065d767  e963010000           jmp 0x65d8cf
// 0065d76c  8bc7                 mov eax, edi
// 0065d76e  c1e817               shr eax, 0x17
// 0065d771  a900010000           test eax, 0x100
// 0065d776  740e                 je 0x65d786
// 0065d778  25ff000000           and eax, 0xff
// 0065d77d  c1e004               shl eax, 4
// 0065d780  03442418             add eax, dword ptr [esp + 0x18]
// 0065d784  eb05                 jmp 0x65d78b
// 0065d786  c1e004               shl eax, 4
// 0065d789  03c2                 add eax, edx
// 0065d78b  c1ef0e               shr edi, 0xe
// 0065d78e  8bc8                 mov ecx, eax
// 0065d790  f7c700010000         test edi, 0x100
// 0065d796  740f                 je 0x65d7a7
// 0065d798  81e7ff000000         and edi, 0xff
// 0065d79e  c1e704               shl edi, 4
// 0065d7a1  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d7a5  eb0b                 jmp 0x65d7b2
// 0065d7a7  81e7ff010000         and edi, 0x1ff
// 0065d7ad  c1e704               shl edi, 4
// 0065d7b0  03fa                 add edi, edx
// 0065d7b2  b803000000           mov eax, 3
// 0065d7b7  394108               cmp dword ptr [ecx + 8], eax
// 0065d7ba  7513                 jne 0x65d7cf
// 0065d7bc  394708               cmp dword ptr [edi + 8], eax
// 0065d7bf  750e                 jne 0x65d7cf
// 0065d7c1  dd01                 fld qword ptr [ecx]
// 0065d7c3  dc37                 fdiv qword ptr [edi]
// 0065d7c5  894608               mov dword ptr [esi + 8], eax
// 0065d7c8  dd1e                 fstp qword ptr [esi]
// 0065d7ca  e928fbffff           jmp 0x65d2f7
// 0065d7cf  6a08                 push 8
// 0065d7d1  e9f9000000           jmp 0x65d8cf
// 0065d7d6  8bc7                 mov eax, edi
// 0065d7d8  c1e817               shr eax, 0x17
// 0065d7db  a900010000           test eax, 0x100
// 0065d7e0  740e                 je 0x65d7f0
// 0065d7e2  25ff000000           and eax, 0xff
// 0065d7e7  c1e004               shl eax, 4
// 0065d7ea  03442418             add eax, dword ptr [esp + 0x18]
// 0065d7ee  eb05                 jmp 0x65d7f5
// 0065d7f0  c1e004               shl eax, 4
// 0065d7f3  03c2                 add eax, edx
// 0065d7f5  c1ef0e               shr edi, 0xe
// 0065d7f8  8bc8                 mov ecx, eax
// 0065d7fa  f7c700010000         test edi, 0x100
// 0065d800  740f                 je 0x65d811
// 0065d802  81e7ff000000         and edi, 0xff
// 0065d808  c1e704               shl edi, 4
// 0065d80b  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d80f  eb0b                 jmp 0x65d81c
// 0065d811  81e7ff010000         and edi, 0x1ff
// 0065d817  c1e704               shl edi, 4
// 0065d81a  03fa                 add edi, edx
// 0065d81c  b803000000           mov eax, 3
// 0065d821  394108               cmp dword ptr [ecx + 8], eax
// 0065d824  7537                 jne 0x65d85d
// 0065d826  394708               cmp dword ptr [edi + 8], eax
// 0065d829  7532                 jne 0x65d85d
// 0065d82b  dd01                 fld qword ptr [ecx]
// 0065d82d  83ec08               sub esp, 8
// 0065d830  dd542430             fst qword ptr [esp + 0x30]
// 0065d834  dd07                 fld qword ptr [edi]
// 0065d836  dd542438             fst qword ptr [esp + 0x38]
// 0065d83a  def9                 fdivp st(1)
// 0065d83c  dd1c24               fstp qword ptr [esp]
// 0065d83f  e86c430400           call 0x6a1bb0
// 0065d844  dc4c2438             fmul qword ptr [esp + 0x38]
// 0065d848  83c408               add esp, 8
// 0065d84b  c7460803000000       mov dword ptr [esi + 8], 3
// 0065d852  dc6c2428             fsubr qword ptr [esp + 0x28]
// 0065d856  dd1e                 fstp qword ptr [esi]
// 0065d858  e99afaffff           jmp 0x65d2f7
// 0065d85d  6a09                 push 9
// 0065d85f  eb6e                 jmp 0x65d8cf
// 0065d861  8bc7                 mov eax, edi
// 0065d863  c1e817               shr eax, 0x17
// 0065d866  a900010000           test eax, 0x100
// 0065d86b  740e                 je 0x65d87b
// 0065d86d  25ff000000           and eax, 0xff
// 0065d872  c1e004               shl eax, 4
// 0065d875  03442418             add eax, dword ptr [esp + 0x18]
// 0065d879  eb05                 jmp 0x65d880
// 0065d87b  c1e004               shl eax, 4
// 0065d87e  03c2                 add eax, edx
// 0065d880  c1ef0e               shr edi, 0xe
// 0065d883  8bc8                 mov ecx, eax
// 0065d885  f7c700010000         test edi, 0x100
// 0065d88b  740f                 je 0x65d89c
// 0065d88d  81e7ff000000         and edi, 0xff
// 0065d893  c1e704               shl edi, 4
// 0065d896  037c2418             add edi, dword ptr [esp + 0x18]
// 0065d89a  eb0b                 jmp 0x65d8a7
// 0065d89c  81e7ff010000         and edi, 0x1ff
// 0065d8a2  c1e704               shl edi, 4
// 0065d8a5  03fa                 add edi, edx
// 0065d8a7  b803000000           mov eax, 3
// 0065d8ac  394108               cmp dword ptr [ecx + 8], eax
// 0065d8af  751c                 jne 0x65d8cd
// 0065d8b1  394708               cmp dword ptr [edi + 8], eax
// 0065d8b4  7517                 jne 0x65d8cd
// 0065d8b6  dd01                 fld qword ptr [ecx]
// 0065d8b8  dd07                 fld qword ptr [edi]
// 0065d8ba  e861430400           call 0x6a1c20
// 0065d8bf  dd1e                 fstp qword ptr [esi]
// 0065d8c1  c7460803000000       mov dword ptr [esi + 8], 3
// 0065d8c8  e92afaffff           jmp 0x65d2f7
// 0065d8cd  6a0a                 push 0xa
// 0065d8cf  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065d8d3  8bc7                 mov eax, edi
// 0065d8d5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0065d8d9  53                   push ebx
// 0065d8da  8bf1                 mov esi, ecx
// 0065d8dc  895318               mov dword ptr [ebx + 0x18], edx
// 0065d8df  e81cf8ffff           call 0x65d100
// 0065d8e4  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065d8e7  83c408               add esp, 8
// 0065d8ea  89442414             mov dword ptr [esp + 0x14], eax
// 0065d8ee  e904faffff           jmp 0x65d2f7
// 0065d8f3  c1ef17               shr edi, 0x17
// 0065d8f6  c1e704               shl edi, 4
// 0065d8f9  03fa                 add edi, edx
// 0065d8fb  b903000000           mov ecx, 3
// 0065d900  394f08               cmp dword ptr [edi + 8], ecx
// 0065d903  750e                 jne 0x65d913
// 0065d905  dd07                 fld qword ptr [edi]
// 0065d907  894e08               mov dword ptr [esi + 8], ecx
// 0065d90a  d9e0                 fchs 
// 0065d90c  dd1e                 fstp qword ptr [esi]
// 0065d90e  e9e4f9ffff           jmp 0x65d2f7
// 0065d913  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065d917  895318               mov dword ptr [ebx + 0x18], edx
// 0065d91a  8b4708               mov eax, dword ptr [edi + 8]
// 0065d91d  3bc1                 cmp eax, ecx
// 0065d91f  7506                 jne 0x65d927
// 0065d921  897c2424             mov dword ptr [esp + 0x24], edi
// 0065d925  eb34                 jmp 0x65d95b
// 0065d927  83f804               cmp eax, 4
// 0065d92a  7570                 jne 0x65d99c
// 0065d92c  8b0f                 mov ecx, dword ptr [edi]
// 0065d92e  8d442438             lea eax, [esp + 0x38]
// 0065d932  50                   push eax
// 0065d933  83c110               add ecx, 0x10
// 0065d936  51                   push ecx
// 0065d937  e8944dfcff           call 0x6226d0
// 0065d93c  83c408               add esp, 8
// 0065d93f  85c0                 test eax, eax
// 0065d941  7459                 je 0x65d99c
// 0065d943  dd442438             fld qword ptr [esp + 0x38]
// 0065d947  8d542470             lea edx, [esp + 0x70]
// 0065d94b  dd5c2470             fstp qword ptr [esp + 0x70]
// 0065d94f  c744247803000000     mov dword ptr [esp + 0x78], 3
// 0065d957  89542424             mov dword ptr [esp + 0x24], edx
// 0065d95b  8b4708               mov eax, dword ptr [edi + 8]
// 0065d95e  83f803               cmp eax, 3
// 0065d961  741c                 je 0x65d97f
// 0065d963  83f804               cmp eax, 4
// 0065d966  7534                 jne 0x65d99c
// 0065d968  8b0f                 mov ecx, dword ptr [edi]
// 0065d96a  8d442448             lea eax, [esp + 0x48]
// 0065d96e  50                   push eax
// 0065d96f  83c110               add ecx, 0x10
// 0065d972  51                   push ecx
// 0065d973  e8584dfcff           call 0x6226d0
// 0065d978  83c408               add esp, 8
// 0065d97b  85c0                 test eax, eax
// 0065d97d  741d                 je 0x65d99c
// 0065d97f  8b542424             mov edx, dword ptr [esp + 0x24]
// 0065d983  dd02                 fld qword ptr [edx]
// 0065d985  c7460803000000       mov dword ptr [esi + 8], 3
// 0065d98c  d9e0                 fchs 
// 0065d98e  dd1e                 fstp qword ptr [esi]
// 0065d990  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065d993  89442414             mov dword ptr [esp + 0x14], eax
// 0065d997  e95bf9ffff           jmp 0x65d2f7
// 0065d99c  6a0b                 push 0xb
// 0065d99e  57                   push edi
// 0065d99f  53                   push ebx
// 0065d9a0  e85becffff           call 0x65c600
// 0065d9a5  83c40c               add esp, 0xc
// 0065d9a8  83780800             cmp dword ptr [eax + 8], 0
// 0065d9ac  750c                 jne 0x65d9ba
// 0065d9ae  6a0b                 push 0xb
// 0065d9b0  57                   push edi
// 0065d9b1  53                   push ebx
// 0065d9b2  e849ecffff           call 0x65c600
// 0065d9b7  83c40c               add esp, 0xc
// 0065d9ba  83780806             cmp dword ptr [eax + 8], 6
// 0065d9be  751c                 jne 0x65d9dc
// 0065d9c0  50                   push eax
// 0065d9c1  53                   push ebx
// 0065d9c2  8bcf                 mov ecx, edi
// 0065d9c4  8bd7                 mov edx, edi
// 0065d9c6  8bc6                 mov eax, esi
// 0065d9c8  e8e3edffff           call 0x65c7b0
// 0065d9cd  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065d9d0  83c408               add esp, 8
// 0065d9d3  89442414             mov dword ptr [esp + 0x14], eax
// 0065d9d7  e91bf9ffff           jmp 0x65d2f7
// 0065d9dc  57                   push edi
// 0065d9dd  57                   push edi
// 0065d9de  53                   push ebx
// 0065d9df  e8cc60fcff           call 0x623ab0
// 0065d9e4  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065d9e7  83c40c               add esp, 0xc
// 0065d9ea  89442414             mov dword ptr [esp + 0x14], eax
// 0065d9ee  e904f9ffff           jmp 0x65d2f7
// 0065d9f3  c1ef17               shr edi, 0x17
// 0065d9f6  c1e704               shl edi, 4
// 0065d9f9  8b441708             mov eax, dword ptr [edi + edx + 8]
// 0065d9fd  03fa                 add edi, edx
// 0065d9ff  85c0                 test eax, eax
// 0065da01  741a                 je 0x65da1d
// 0065da03  83f801               cmp eax, 1
// 0065da06  7505                 jne 0x65da0d
// 0065da08  833f00               cmp dword ptr [edi], 0
// 0065da0b  7410                 je 0x65da1d
// 0065da0d  33c0                 xor eax, eax
// 0065da0f  8906                 mov dword ptr [esi], eax
// 0065da11  c7460801000000       mov dword ptr [esi + 8], 1
// 0065da18  e9daf8ffff           jmp 0x65d2f7
// 0065da1d  b801000000           mov eax, 1
// 0065da22  8906                 mov dword ptr [esi], eax
// 0065da24  894608               mov dword ptr [esi + 8], eax
// 0065da27  e9cbf8ffff           jmp 0x65d2f7
// 0065da2c  c1ef17               shr edi, 0x17
// 0065da2f  c1e704               shl edi, 4
// 0065da32  8b441708             mov eax, dword ptr [edi + edx + 8]
// 0065da36  03fa                 add edi, edx
// 0065da38  83e804               sub eax, 4
// 0065da3b  0f848f000000         je 0x65dad0
// 0065da41  83e801               sub eax, 1
// 0065da44  7469                 je 0x65daaf
// 0065da46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065da4a  6a0c                 push 0xc
// 0065da4c  57                   push edi
// 0065da4d  53                   push ebx
// 0065da4e  894b18               mov dword ptr [ebx + 0x18], ecx
// 0065da51  e8aaebffff           call 0x65c600
// 0065da56  83c40c               add esp, 0xc
// 0065da59  83780800             cmp dword ptr [eax + 8], 0
// 0065da5d  7510                 jne 0x65da6f
// 0065da5f  6a0c                 push 0xc
// 0065da61  6880488400           push 0x844880
// 0065da66  53                   push ebx
// 0065da67  e894ebffff           call 0x65c600
// 0065da6c  83c40c               add esp, 0xc
// 0065da6f  83780806             cmp dword ptr [eax + 8], 6
// 0065da73  751f                 jne 0x65da94
// 0065da75  50                   push eax
// 0065da76  53                   push ebx
// 0065da77  b980488400           mov ecx, 0x844880
// 0065da7c  8bd7                 mov edx, edi
// 0065da7e  8bc6                 mov eax, esi
// 0065da80  e82bedffff           call 0x65c7b0
// 0065da85  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065da88  83c408               add esp, 8
// 0065da8b  89542414             mov dword ptr [esp + 0x14], edx
// 0065da8f  e963f8ffff           jmp 0x65d2f7
// 0065da94  68bcc38400           push 0x84c3bc
// 0065da99  57                   push edi
// 0065da9a  53                   push ebx
// 0065da9b  e8605ffcff           call 0x623a00
// 0065daa0  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065daa3  83c40c               add esp, 0xc
// 0065daa6  89542414             mov dword ptr [esp + 0x14], edx
// 0065daaa  e948f8ffff           jmp 0x65d2f7
// 0065daaf  8b07                 mov eax, dword ptr [edi]
// 0065dab1  50                   push eax
// 0065dab2  e8f9110000           call 0x65ecb0
// 0065dab7  89442434             mov dword ptr [esp + 0x34], eax
// 0065dabb  db442434             fild dword ptr [esp + 0x34]
// 0065dabf  83c404               add esp, 4
// 0065dac2  c7460803000000       mov dword ptr [esi + 8], 3
// 0065dac9  dd1e                 fstp qword ptr [esi]
// 0065dacb  e927f8ffff           jmp 0x65d2f7
// 0065dad0  8b0f                 mov ecx, dword ptr [edi]
// 0065dad2  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0065dad5  db410c               fild dword ptr [ecx + 0xc]
// 0065dad8  85d2                 test edx, edx
// 0065dada  7d06                 jge 0x65dae2
// 0065dadc  dc0540128100         fadd qword ptr [0x811240]
// 0065dae2  dd1e                 fstp qword ptr [esi]
// 0065dae4  c7460803000000       mov dword ptr [esi + 8], 3
// 0065daeb  e907f8ffff           jmp 0x65d2f7
// 0065daf0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065daf4  8bf7                 mov esi, edi
// 0065daf6  c1ef0e               shr edi, 0xe
// 0065daf9  81e7ff010000         and edi, 0x1ff
// 0065daff  57                   push edi
// 0065db00  c1ee17               shr esi, 0x17
// 0065db03  2bfe                 sub edi, esi
// 0065db05  47                   inc edi
// 0065db06  57                   push edi
// 0065db07  53                   push ebx
// 0065db08  894318               mov dword ptr [ebx + 0x18], eax
// 0065db0b  e860f3ffff           call 0x65ce70
// 0065db10  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0065db13  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0065db16  83c40c               add esp, 0xc
// 0065db19  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0065db1c  7209                 jb 0x65db27
// 0065db1e  53                   push ebx
// 0065db1f  e86ce8ffff           call 0x65c390
// 0065db24  83c404               add esp, 4
// 0065db27  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065db2a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0065db2e  c1e604               shl esi, 4
// 0065db31  8b1406               mov edx, dword ptr [esi + eax]
// 0065db34  03f0                 add esi, eax
// 0065db36  891401               mov dword ptr [ecx + eax], edx
// 0065db39  8b5604               mov edx, dword ptr [esi + 4]
// 0065db3c  89540104             mov dword ptr [ecx + eax + 4], edx
// 0065db40  8b5608               mov edx, dword ptr [esi + 8]
// 0065db43  89442414             mov dword ptr [esp + 0x14], eax
// 0065db47  89540108             mov dword ptr [ecx + eax + 8], edx
// 0065db4b  e9a7f7ffff           jmp 0x65d2f7
// 0065db50  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065db54  c1ef0e               shr edi, 0xe
// 0065db57  8d8cb80400f8ff       lea ecx, [eax + edi*4 - 0x7fffc]
// 0065db5e  894c2410             mov dword ptr [esp + 0x10], ecx
// 0065db62  e990f7ffff           jmp 0x65d2f7
// 0065db67  8bc7                 mov eax, edi
// 0065db69  c1e817               shr eax, 0x17
// 0065db6c  a900010000           test eax, 0x100
// 0065db71  740e                 je 0x65db81
// 0065db73  25ff000000           and eax, 0xff
// 0065db78  c1e004               shl eax, 4
// 0065db7b  03442418             add eax, dword ptr [esp + 0x18]
// 0065db7f  eb05                 jmp 0x65db86
// 0065db81  c1e004               shl eax, 4
// 0065db84  03c2                 add eax, edx
// 0065db86  c1ef0e               shr edi, 0xe
// 0065db89  f7c700010000         test edi, 0x100
// 0065db8f  740f                 je 0x65dba0
// 0065db91  81e7ff000000         and edi, 0xff
// 0065db97  c1e704               shl edi, 4
// 0065db9a  037c2418             add edi, dword ptr [esp + 0x18]
// 0065db9e  eb0b                 jmp 0x65dbab
// 0065dba0  81e7ff010000         and edi, 0x1ff
// 0065dba6  c1e704               shl edi, 4
// 0065dba9  03fa                 add edi, edx
// 0065dbab  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065dbaf  895318               mov dword ptr [ebx + 0x18], edx
// 0065dbb2  8b4808               mov ecx, dword ptr [eax + 8]
// 0065dbb5  3b4f08               cmp ecx, dword ptr [edi + 8]
// 0065dbb8  7519                 jne 0x65dbd3
// 0065dbba  57                   push edi
// 0065dbbb  50                   push eax
// 0065dbbc  53                   push ebx
// 0065dbbd  e8cef1ffff           call 0x65cd90
// 0065dbc2  83c40c               add esp, 0xc
// 0065dbc5  85c0                 test eax, eax
// 0065dbc7  740a                 je 0x65dbd3
// 0065dbc9  b801000000           mov eax, 1
// 0065dbce  e9dc000000           jmp 0x65dcaf
// 0065dbd3  33c0                 xor eax, eax
// 0065dbd5  e9d5000000           jmp 0x65dcaf
// 0065dbda  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065dbde  894318               mov dword ptr [ebx + 0x18], eax
// 0065dbe1  8bc7                 mov eax, edi
// 0065dbe3  c1e80e               shr eax, 0xe
// 0065dbe6  a900010000           test eax, 0x100
// 0065dbeb  740e                 je 0x65dbfb
// 0065dbed  25ff000000           and eax, 0xff
// 0065dbf2  c1e004               shl eax, 4
// 0065dbf5  03442418             add eax, dword ptr [esp + 0x18]
// 0065dbf9  eb0a                 jmp 0x65dc05
// 0065dbfb  25ff010000           and eax, 0x1ff
// 0065dc00  c1e004               shl eax, 4
// 0065dc03  03c2                 add eax, edx
// 0065dc05  c1ef17               shr edi, 0x17
// 0065dc08  f7c700010000         test edi, 0x100
// 0065dc0e  740f                 je 0x65dc1f
// 0065dc10  81e7ff000000         and edi, 0xff
// 0065dc16  c1e704               shl edi, 4
// 0065dc19  037c2418             add edi, dword ptr [esp + 0x18]
// 0065dc1d  eb05                 jmp 0x65dc24
// 0065dc1f  c1e704               shl edi, 4
// 0065dc22  03fa                 add edi, edx
// 0065dc24  50                   push eax
// 0065dc25  57                   push edi
// 0065dc26  53                   push ebx
// 0065dc27  e834f0ffff           call 0x65cc60
// 0065dc2c  83c40c               add esp, 0xc
// 0065dc2f  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0065dc33  7514                 jne 0x65dc49
// 0065dc35  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065dc39  8b08                 mov ecx, dword ptr [eax]
// 0065dc3b  c1e90e               shr ecx, 0xe
// 0065dc3e  8d94880400f8ff       lea edx, [eax + ecx*4 - 0x7fffc]
// 0065dc45  89542410             mov dword ptr [esp + 0x10], edx
// 0065dc49  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065dc4c  8344241004           add dword ptr [esp + 0x10], 4
// 0065dc51  89442414             mov dword ptr [esp + 0x14], eax
// 0065dc55  e99df6ffff           jmp 0x65d2f7
// 0065dc5a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065dc5e  8bc7                 mov eax, edi
// 0065dc60  c1e80e               shr eax, 0xe
// 0065dc63  894b18               mov dword ptr [ebx + 0x18], ecx
// 0065dc66  a900010000           test eax, 0x100
// 0065dc6b  740e                 je 0x65dc7b
// 0065dc6d  25ff000000           and eax, 0xff
// 0065dc72  c1e004               shl eax, 4
// 0065dc75  03442418             add eax, dword ptr [esp + 0x18]
// 0065dc79  eb0a                 jmp 0x65dc85
// 0065dc7b  25ff010000           and eax, 0x1ff
// 0065dc80  c1e004               shl eax, 4
// 0065dc83  03c2                 add eax, edx
// 0065dc85  c1ef17               shr edi, 0x17
// 0065dc88  f7c700010000         test edi, 0x100
// 0065dc8e  740f                 je 0x65dc9f
// 0065dc90  81e7ff000000         and edi, 0xff
// 0065dc96  c1e704               shl edi, 4
// 0065dc99  037c2418             add edi, dword ptr [esp + 0x18]
// 0065dc9d  eb05                 jmp 0x65dca4
// 0065dc9f  c1e704               shl edi, 4
// 0065dca2  03fa                 add edi, edx
// 0065dca4  53                   push ebx
// 0065dca5  8bf0                 mov esi, eax
// 0065dca7  e844f0ffff           call 0x65ccf0
// 0065dcac  83c404               add esp, 4
// 0065dcaf  3b442424             cmp eax, dword ptr [esp + 0x24]
// 0065dcb3  7514                 jne 0x65dcc9
// 0065dcb5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065dcb9  8b10                 mov edx, dword ptr [eax]
// 0065dcbb  c1ea0e               shr edx, 0xe
// 0065dcbe  8d84900400f8ff       lea eax, [eax + edx*4 - 0x7fffc]
// 0065dcc5  89442410             mov dword ptr [esp + 0x10], eax
// 0065dcc9  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065dccc  8344241004           add dword ptr [esp + 0x10], 4
// 0065dcd1  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065dcd5  e91df6ffff           jmp 0x65d2f7
// 0065dcda  8b4608               mov eax, dword ptr [esi + 8]
// 0065dcdd  85c0                 test eax, eax
// 0065dcdf  740e                 je 0x65dcef
// 0065dce1  83f801               cmp eax, 1
// 0065dce4  7505                 jne 0x65dceb
// 0065dce6  833e00               cmp dword ptr [esi], 0
// 0065dce9  7404                 je 0x65dcef
// 0065dceb  33c0                 xor eax, eax
// 0065dced  eb05                 jmp 0x65dcf4
// 0065dcef  b801000000           mov eax, 1
// 0065dcf4  c1ef0e               shr edi, 0xe
// 0065dcf7  81e7ff010000         and edi, 0x1ff
// 0065dcfd  3bc7                 cmp eax, edi
// 0065dcff  0f84ab020000         je 0x65dfb0
// 0065dd05  e992020000           jmp 0x65df9c
// 0065dd0a  8bc7                 mov eax, edi
// 0065dd0c  c1e817               shr eax, 0x17
// 0065dd0f  c1e004               shl eax, 4
// 0065dd12  8b4c1008             mov ecx, dword ptr [eax + edx + 8]
// 0065dd16  03c2                 add eax, edx
// 0065dd18  85c9                 test ecx, ecx
// 0065dd1a  740e                 je 0x65dd2a
// 0065dd1c  83f901               cmp ecx, 1
// 0065dd1f  7505                 jne 0x65dd26
// 0065dd21  833800               cmp dword ptr [eax], 0
// 0065dd24  7404                 je 0x65dd2a
// 0065dd26  33c9                 xor ecx, ecx
// 0065dd28  eb05                 jmp 0x65dd2f
// 0065dd2a  b901000000           mov ecx, 1
// 0065dd2f  c1ef0e               shr edi, 0xe
// 0065dd32  81e7ff010000         and edi, 0x1ff
// 0065dd38  3bcf                 cmp ecx, edi
// 0065dd3a  7424                 je 0x65dd60
// 0065dd3c  8b08                 mov ecx, dword ptr [eax]
// 0065dd3e  890e                 mov dword ptr [esi], ecx
// 0065dd40  8b5004               mov edx, dword ptr [eax + 4]
// 0065dd43  895604               mov dword ptr [esi + 4], edx
// 0065dd46  8b4008               mov eax, dword ptr [eax + 8]
// 0065dd49  894608               mov dword ptr [esi + 8], eax
// 0065dd4c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065dd50  8b08                 mov ecx, dword ptr [eax]
// 0065dd52  c1e90e               shr ecx, 0xe
// 0065dd55  8d94880400f8ff       lea edx, [eax + ecx*4 - 0x7fffc]
// 0065dd5c  89542410             mov dword ptr [esp + 0x10], edx
// 0065dd60  8344241004           add dword ptr [esp + 0x10], 4
// 0065dd65  e98df5ffff           jmp 0x65d2f7
// 0065dd6a  8bc7                 mov eax, edi
// 0065dd6c  c1ef0e               shr edi, 0xe
// 0065dd6f  81e7ff010000         and edi, 0x1ff
// 0065dd75  c1e817               shr eax, 0x17
// 0065dd78  4f                   dec edi
// 0065dd79  85c0                 test eax, eax
// 0065dd7b  7408                 je 0x65dd85
// 0065dd7d  c1e004               shl eax, 4
// 0065dd80  03c6                 add eax, esi
// 0065dd82  894308               mov dword ptr [ebx + 8], eax
// 0065dd85  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065dd89  57                   push edi
// 0065dd8a  56                   push esi
// 0065dd8b  53                   push ebx
// 0065dd8c  894318               mov dword ptr [ebx + 0x18], eax
// 0065dd8f  e8ac43fcff           call 0x622140
// 0065dd94  83c40c               add esp, 0xc
// 0065dd97  83e800               sub eax, 0
// 0065dd9a  0f84a3040000         je 0x65e243
// 0065dda0  83e801               sub eax, 1
// 0065dda3  0f8590050000         jne 0x65e339
// 0065dda9  85ff                 test edi, edi
// 0065ddab  7c09                 jl 0x65ddb6
// 0065ddad  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 0065ddb0  8b5108               mov edx, dword ptr [ecx + 8]
// 0065ddb3  895308               mov dword ptr [ebx + 8], edx
// 0065ddb6  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065ddb9  89442414             mov dword ptr [esp + 0x14], eax
// 0065ddbd  e935f5ffff           jmp 0x65d2f7
// 0065ddc2  c1ef17               shr edi, 0x17
// 0065ddc5  85ff                 test edi, edi
// 0065ddc7  7408                 je 0x65ddd1
// 0065ddc9  c1e704               shl edi, 4
// 0065ddcc  03fe                 add edi, esi
// 0065ddce  897b08               mov dword ptr [ebx + 8], edi
// 0065ddd1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065ddd5  6aff                 push -1
// 0065ddd7  56                   push esi
// 0065ddd8  53                   push ebx
// 0065ddd9  894b18               mov dword ptr [ebx + 0x18], ecx
// 0065dddc  e85f43fcff           call 0x622140
// 0065dde1  83c40c               add esp, 0xc
// 0065dde4  83e800               sub eax, 0
// 0065dde7  0f845e040000         je 0x65e24b
// 0065dded  83e801               sub eax, 1
// 0065ddf0  0f8543050000         jne 0x65e339
// 0065ddf6  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065ddf9  89542414             mov dword ptr [esp + 0x14], edx
// 0065ddfd  e9f5f4ffff           jmp 0x65d2f7
// 0065de02  dd4620               fld qword ptr [esi + 0x20]
// 0065de05  d9c0                 fld st(0)
// 0065de07  dc06                 fadd qword ptr [esi]
// 0065de09  dd4610               fld qword ptr [esi + 0x10]
// 0065de0c  d9ca                 fxch st(2)
// 0065de0e  dc1da8878100         fcomp qword ptr [0x8187a8]
// 0065de14  dfe0                 fnstsw ax
// 0065de16  d8d1                 fcom st(1)
// 0065de18  f6c441               test ah, 0x41
// 0065de1b  dfe0                 fnstsw ax
// 0065de1d  ddd9                 fstp st(1)
// 0065de1f  750a                 jne 0x65de2b
// 0065de21  f6c441               test ah, 0x41
// 0065de24  7b0e                 jnp 0x65de34
// 0065de26  e9caf4ffff           jmp 0x65d2f5
// 0065de2b  f6c401               test ah, 1
// 0065de2e  0f85c1f4ffff         jne 0x65d2f5
// 0065de34  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065de38  dd16                 fst qword ptr [esi]
// 0065de3a  c1ef0e               shr edi, 0xe
// 0065de3d  8d8cb80400f8ff       lea ecx, [eax + edi*4 - 0x7fffc]
// 0065de44  b803000000           mov eax, 3
// 0065de49  894608               mov dword ptr [esi + 8], eax
// 0065de4c  dd5e30               fstp qword ptr [esi + 0x30]
// 0065de4f  894c2410             mov dword ptr [esp + 0x10], ecx
// 0065de53  894638               mov dword ptr [esi + 0x38], eax
// 0065de56  e99cf4ffff           jmp 0x65d2f7
// 0065de5b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065de5f  894318               mov dword ptr [ebx + 0x18], eax
// 0065de62  8b4608               mov eax, dword ptr [esi + 8]
// 0065de65  8d5620               lea edx, [esi + 0x20]
// 0065de68  89542420             mov dword ptr [esp + 0x20], edx
// 0065de6c  83f803               cmp eax, 3
// 0065de6f  7429                 je 0x65de9a
// 0065de71  83f804               cmp eax, 4
// 0065de74  7542                 jne 0x65deb8
// 0065de76  8b16                 mov edx, dword ptr [esi]
// 0065de78  8d4c2440             lea ecx, [esp + 0x40]
// 0065de7c  51                   push ecx
// 0065de7d  83c210               add edx, 0x10
// 0065de80  52                   push edx
// 0065de81  e84a48fcff           call 0x6226d0
// 0065de86  83c408               add esp, 8
// 0065de89  85c0                 test eax, eax
// 0065de8b  742b                 je 0x65deb8
// 0065de8d  dd442440             fld qword ptr [esp + 0x40]
// 0065de91  c7460803000000       mov dword ptr [esi + 8], 3
// 0065de98  dd1e                 fstp qword ptr [esi]
// 0065de9a  837e1803             cmp dword ptr [esi + 0x18], 3
// 0065de9e  741f                 je 0x65debf
// 0065dea0  8d4610               lea eax, [esi + 0x10]
// 0065dea3  50                   push eax
// 0065dea4  50                   push eax
// 0065dea5  e8b6e7ffff           call 0x65c660
// 0065deaa  83c408               add esp, 8
// 0065dead  85c0                 test eax, eax
// 0065deaf  750e                 jne 0x65debf
// 0065deb1  689cc38400           push 0x84c39c
// 0065deb6  eb28                 jmp 0x65dee0
// 0065deb8  6874c38400           push 0x84c374
// 0065debd  eb21                 jmp 0x65dee0
// 0065debf  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065dec3  83780803             cmp dword ptr [eax + 8], 3
// 0065dec7  7420                 je 0x65dee9
// 0065dec9  50                   push eax
// 0065deca  50                   push eax
// 0065decb  e890e7ffff           call 0x65c660
// 0065ded0  83c408               add esp, 8
// 0065ded3  89442420             mov dword ptr [esp + 0x20], eax
// 0065ded7  85c0                 test eax, eax
// 0065ded9  750e                 jne 0x65dee9
// 0065dedb  6858c38400           push 0x84c358
// 0065dee0  53                   push ebx
// 0065dee1  e8ea58fcff           call 0x6237d0
// 0065dee6  83c408               add esp, 8
// 0065dee9  dd06                 fld qword ptr [esi]
// 0065deeb  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065deef  dc21                 fsub qword ptr [ecx]
// 0065def1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065def5  c1ef0e               shr edi, 0xe
// 0065def8  8d84ba0400f8ff       lea eax, [edx + edi*4 - 0x7fffc]
// 0065deff  dd1e                 fstp qword ptr [esi]
// 0065df01  c7460803000000       mov dword ptr [esi + 8], 3
// 0065df08  89442410             mov dword ptr [esp + 0x10], eax
// 0065df0c  e9e6f3ffff           jmp 0x65d2f7
// 0065df11  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0065df14  894e50               mov dword ptr [esi + 0x50], ecx
// 0065df17  8b5624               mov edx, dword ptr [esi + 0x24]
// 0065df1a  8d4630               lea eax, [esi + 0x30]
// 0065df1d  895024               mov dword ptr [eax + 0x24], edx
// 0065df20  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 0065df23  894828               mov dword ptr [eax + 0x28], ecx
// 0065df26  8b5610               mov edx, dword ptr [esi + 0x10]
// 0065df29  895010               mov dword ptr [eax + 0x10], edx
// 0065df2c  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0065df2f  894814               mov dword ptr [eax + 0x14], ecx
// 0065df32  8b5618               mov edx, dword ptr [esi + 0x18]
// 0065df35  895018               mov dword ptr [eax + 0x18], edx
// 0065df38  8b0e                 mov ecx, dword ptr [esi]
// 0065df3a  8908                 mov dword ptr [eax], ecx
// 0065df3c  8b5604               mov edx, dword ptr [esi + 4]
// 0065df3f  895004               mov dword ptr [eax + 4], edx
// 0065df42  8b4e08               mov ecx, dword ptr [esi + 8]
// 0065df45  c1ef0e               shr edi, 0xe
// 0065df48  81e7ff010000         and edi, 0x1ff
// 0065df4e  894808               mov dword ptr [eax + 8], ecx
// 0065df51  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065df55  57                   push edi
// 0065df56  50                   push eax
// 0065df57  8d5030               lea edx, [eax + 0x30]
// 0065df5a  53                   push ebx
// 0065df5b  895308               mov dword ptr [ebx + 8], edx
// 0065df5e  894b18               mov dword ptr [ebx + 0x18], ecx
// 0065df61  e89a43fcff           call 0x622300
// 0065df66  8b5314               mov edx, dword ptr [ebx + 0x14]
// 0065df69  8b4208               mov eax, dword ptr [edx + 8]
// 0065df6c  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 0065df6f  894308               mov dword ptr [ebx + 8], eax
// 0065df72  8b442430             mov eax, dword ptr [esp + 0x30]
// 0065df76  83c003               add eax, 3
// 0065df79  c1e004               shl eax, 4
// 0065df7c  03c1                 add eax, ecx
// 0065df7e  83c40c               add esp, 0xc
// 0065df81  83780800             cmp dword ptr [eax + 8], 0
// 0065df85  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065df89  7425                 je 0x65dfb0
// 0065df8b  8b08                 mov ecx, dword ptr [eax]
// 0065df8d  8948f0               mov dword ptr [eax - 0x10], ecx
// 0065df90  8b5004               mov edx, dword ptr [eax + 4]
// 0065df93  8950f4               mov dword ptr [eax - 0xc], edx
// 0065df96  8b4808               mov ecx, dword ptr [eax + 8]
// 0065df99  8948f8               mov dword ptr [eax - 8], ecx
// 0065df9c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065dfa0  8b10                 mov edx, dword ptr [eax]
// 0065dfa2  c1ea0e               shr edx, 0xe
// 0065dfa5  8d84900400f8ff       lea eax, [eax + edx*4 - 0x7fffc]
// 0065dfac  89442410             mov dword ptr [esp + 0x10], eax
// 0065dfb0  8344241004           add dword ptr [esp + 0x10], 4
// 0065dfb5  e93df3ffff           jmp 0x65d2f7
// 0065dfba  8bc7                 mov eax, edi
// 0065dfbc  c1ef0e               shr edi, 0xe
// 0065dfbf  c1e817               shr eax, 0x17
// 0065dfc2  81e7ff010000         and edi, 0x1ff
// 0065dfc8  89442424             mov dword ptr [esp + 0x24], eax
// 0065dfcc  85c0                 test eax, eax
// 0065dfce  7516                 jne 0x65dfe6
// 0065dfd0  8b4308               mov eax, dword ptr [ebx + 8]
// 0065dfd3  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 0065dfd6  8b5108               mov edx, dword ptr [ecx + 8]
// 0065dfd9  2bc6                 sub eax, esi
// 0065dfdb  c1f804               sar eax, 4
// 0065dfde  48                   dec eax
// 0065dfdf  89442424             mov dword ptr [esp + 0x24], eax
// 0065dfe3  895308               mov dword ptr [ebx + 8], edx
// 0065dfe6  85ff                 test edi, edi
// 0065dfe8  750d                 jne 0x65dff7
// 0065dfea  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065dfee  8b39                 mov edi, dword ptr [ecx]
// 0065dff0  83c104               add ecx, 4
// 0065dff3  894c2410             mov dword ptr [esp + 0x10], ecx
// 0065dff7  837e0805             cmp dword ptr [esi + 8], 5
// 0065dffb  0f85f6f2ffff         jne 0x65d2f7
// 0065e001  8b16                 mov edx, dword ptr [esi]
// 0065e003  6bff32               imul edi, edi, 0x32
// 0065e006  8d4c07ce             lea ecx, [edi + eax - 0x32]
// 0065e00a  3b4a1c               cmp ecx, dword ptr [edx + 0x1c]
// 0065e00d  89542428             mov dword ptr [esp + 0x28], edx
// 0065e011  894c2420             mov dword ptr [esp + 0x20], ecx
// 0065e015  7e0f                 jle 0x65e026
// 0065e017  51                   push ecx
// 0065e018  52                   push edx
// 0065e019  53                   push ebx
// 0065e01a  e8d10e0000           call 0x65eef0
// 0065e01f  8b442430             mov eax, dword ptr [esp + 0x30]
// 0065e023  83c40c               add esp, 0xc
// 0065e026  85c0                 test eax, eax
// 0065e028  0f8ec9f2ffff         jle 0x65d2f7
// 0065e02e  8bf8                 mov edi, eax
// 0065e030  c1e704               shl edi, 4
// 0065e033  03fe                 add edi, esi
// 0065e035  8b742420             mov esi, dword ptr [esp + 0x20]
// 0065e039  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065e03d  56                   push esi
// 0065e03e  50                   push eax
// 0065e03f  53                   push ebx
// 0065e040  e87b0b0000           call 0x65ebc0
// 0065e045  8b0f                 mov ecx, dword ptr [edi]
// 0065e047  8908                 mov dword ptr [eax], ecx
// 0065e049  8b5704               mov edx, dword ptr [edi + 4]
// 0065e04c  895004               mov dword ptr [eax + 4], edx
// 0065e04f  8b4f08               mov ecx, dword ptr [edi + 8]
// 0065e052  4e                   dec esi
// 0065e053  83c40c               add esp, 0xc
// 0065e056  894808               mov dword ptr [eax + 8], ecx
// 0065e059  837f0804             cmp dword ptr [edi + 8], 4
// 0065e05d  89742420             mov dword ptr [esp + 0x20], esi
// 0065e061  7c1c                 jl 0x65e07f
// 0065e063  8b17                 mov edx, dword ptr [edi]
// 0065e065  f6420503             test byte ptr [edx + 5], 3
// 0065e069  7414                 je 0x65e07f
// 0065e06b  8b442428             mov eax, dword ptr [esp + 0x28]
// 0065e06f  f6400504             test byte ptr [eax + 5], 4
// 0065e073  740a                 je 0x65e07f
// 0065e075  50                   push eax
// 0065e076  53                   push ebx
// 0065e077  e844e4ffff           call 0x65c4c0
// 0065e07c  83c408               add esp, 8
// 0065e07f  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065e083  48                   dec eax
// 0065e084  83ef10               sub edi, 0x10
// 0065e087  89442424             mov dword ptr [esp + 0x24], eax
// 0065e08b  85c0                 test eax, eax
// 0065e08d  7fa6                 jg 0x65e035
// 0065e08f  e963f2ffff           jmp 0x65d2f7
// 0065e094  56                   push esi
// 0065e095  53                   push ebx
// 0065e096  e865150000           call 0x65f600
// 0065e09b  83c408               add esp, 8
// 0065e09e  e954f2ffff           jmp 0x65d2f7
// 0065e0a3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065e0a7  8b4810               mov ecx, dword ptr [eax + 0x10]
// 0065e0aa  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0065e0ad  8b400c               mov eax, dword ptr [eax + 0xc]
// 0065e0b0  c1ef0e               shr edi, 0xe
// 0065e0b3  8b3cba               mov edi, dword ptr [edx + edi*4]
// 0065e0b6  897c2430             mov dword ptr [esp + 0x30], edi
// 0065e0ba  0fb67f48             movzx edi, byte ptr [edi + 0x48]
// 0065e0be  50                   push eax
// 0065e0bf  57                   push edi
// 0065e0c0  53                   push ebx
// 0065e0c1  e8ca130000           call 0x65f490
// 0065e0c6  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0065e0ca  83c40c               add esp, 0xc
// 0065e0cd  89442420             mov dword ptr [esp + 0x20], eax
// 0065e0d1  894810               mov dword ptr [eax + 0x10], ecx
// 0065e0d4  85ff                 test edi, edi
// 0065e0d6  7e63                 jle 0x65e13b
// 0065e0d8  8bd0                 mov edx, eax
// 0065e0da  83c214               add edx, 0x14
// 0065e0dd  897c2428             mov dword ptr [esp + 0x28], edi
// 0065e0e1  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065e0e5  89542424             mov dword ptr [esp + 0x24], edx
// 0065e0e9  8da42400000000       lea esp, [esp]
// 0065e0f0  8b07                 mov eax, dword ptr [edi]
// 0065e0f2  8bc8                 mov ecx, eax
// 0065e0f4  80e13f               and cl, 0x3f
// 0065e0f7  c1e817               shr eax, 0x17
// 0065e0fa  80f904               cmp cl, 4
// 0065e0fd  7510                 jne 0x65e10f
// 0065e0ff  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0065e103  8b448214             mov eax, dword ptr [edx + eax*4 + 0x14]
// 0065e107  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0065e10b  8901                 mov dword ptr [ecx], eax
// 0065e10d  eb17                 jmp 0x65e126
// 0065e10f  c1e004               shl eax, 4
// 0065e112  03442414             add eax, dword ptr [esp + 0x14]
// 0065e116  50                   push eax
// 0065e117  53                   push ebx
// 0065e118  e813140000           call 0x65f530
// 0065e11d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0065e121  83c408               add esp, 8
// 0065e124  8902                 mov dword ptr [edx], eax
// 0065e126  8344242404           add dword ptr [esp + 0x24], 4
// 0065e12b  83c704               add edi, 4
// 0065e12e  836c242801           sub dword ptr [esp + 0x28], 1
// 0065e133  75bb                 jne 0x65e0f0
// 0065e135  897c2410             mov dword ptr [esp + 0x10], edi
// 0065e139  eb04                 jmp 0x65e13f
// 0065e13b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065e13f  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065e143  8906                 mov dword ptr [esi], eax
// 0065e145  c7460806000000       mov dword ptr [esi + 8], 6
// 0065e14c  897b18               mov dword ptr [ebx + 0x18], edi
// 0065e14f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0065e152  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0065e155  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0065e158  7209                 jb 0x65e163
// 0065e15a  53                   push ebx
// 0065e15b  e830e2ffff           call 0x65c390
// 0065e160  83c404               add esp, 4
// 0065e163  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0065e166  89542414             mov dword ptr [esp + 0x14], edx
// 0065e16a  e988f1ffff           jmp 0x65d2f7
// 0065e16f  8b5314               mov edx, dword ptr [ebx + 0x14]
// 0065e172  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0065e176  8b4010               mov eax, dword ptr [eax + 0x10]
// 0065e179  0fb64049             movzx eax, byte ptr [eax + 0x49]
// 0065e17d  c1ef17               shr edi, 0x17
// 0065e180  4f                   dec edi
// 0065e181  897c2424             mov dword ptr [esp + 0x24], edi
// 0065e185  8b3a                 mov edi, dword ptr [edx]
// 0065e187  2b7a04               sub edi, dword ptr [edx + 4]
// 0065e18a  89542430             mov dword ptr [esp + 0x30], edx
// 0065e18e  c1ff04               sar edi, 4
// 0065e191  2bf8                 sub edi, eax
// 0065e193  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065e197  4f                   dec edi
// 0065e198  83f8ff               cmp eax, -1
// 0065e19b  7545                 jne 0x65e1e2
// 0065e19d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065e1a1  8b731c               mov esi, dword ptr [ebx + 0x1c]
// 0065e1a4  2b7308               sub esi, dword ptr [ebx + 8]
// 0065e1a7  894318               mov dword ptr [ebx + 0x18], eax
// 0065e1aa  8bc7                 mov eax, edi
// 0065e1ac  c1e004               shl eax, 4
// 0065e1af  3bf0                 cmp esi, eax
// 0065e1b1  89442420             mov dword ptr [esp + 0x20], eax
// 0065e1b5  7f12                 jg 0x65e1c9
// 0065e1b7  57                   push edi
// 0065e1b8  53                   push ebx
// 0065e1b9  e89239fcff           call 0x621b50
// 0065e1be  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0065e1c2  8b542438             mov edx, dword ptr [esp + 0x38]
// 0065e1c6  83c408               add esp, 8
// 0065e1c9  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0065e1cc  8d3401               lea esi, [ecx + eax]
// 0065e1cf  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065e1d3  89442414             mov dword ptr [esp + 0x14], eax
// 0065e1d7  8bc7                 mov eax, edi
// 0065e1d9  03ce                 add ecx, esi
// 0065e1db  89442424             mov dword ptr [esp + 0x24], eax
// 0065e1df  894b08               mov dword ptr [ebx + 8], ecx
// 0065e1e2  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0065e1ea  85c0                 test eax, eax
// 0065e1ec  0f8e05f1ffff         jle 0x65d2f7
// 0065e1f2  8bcf                 mov ecx, edi
// 0065e1f4  f7d9                 neg ecx
// 0065e1f6  c1e104               shl ecx, 4
// 0065e1f9  83c608               add esi, 8
// 0065e1fc  eb06                 jmp 0x65e204
// 0065e1fe  8bff                 mov edi, edi
// 0065e200  8b542430             mov edx, dword ptr [esp + 0x30]
// 0065e204  397c2420             cmp dword ptr [esp + 0x20], edi
// 0065e208  7d1b                 jge 0x65e225
// 0065e20a  8b02                 mov eax, dword ptr [edx]
// 0065e20c  8b1408               mov edx, dword ptr [eax + ecx]
// 0065e20f  03c1                 add eax, ecx
// 0065e211  8956f8               mov dword ptr [esi - 8], edx
// 0065e214  8b5004               mov edx, dword ptr [eax + 4]
// 0065e217  8956fc               mov dword ptr [esi - 4], edx
// 0065e21a  8b4008               mov eax, dword ptr [eax + 8]
// 0065e21d  8906                 mov dword ptr [esi], eax
// 0065e21f  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065e223  eb06                 jmp 0x65e22b
// 0065e225  c70600000000         mov dword ptr [esi], 0
// 0065e22b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0065e22f  42                   inc edx
// 0065e230  83c110               add ecx, 0x10
// 0065e233  83c610               add esi, 0x10
// 0065e236  3bd0                 cmp edx, eax
// 0065e238  89542420             mov dword ptr [esp + 0x20], edx
// 0065e23c  7cc2                 jl 0x65e200
// 0065e23e  e9b4f0ffff           jmp 0x65d2f7
// 0065e243  ff450c               inc dword ptr [ebp + 0xc]
// 0065e246  e984f0ffff           jmp 0x65d2cf
// 0065e24b  8b7314               mov esi, dword ptr [ebx + 0x14]
// 0065e24e  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065e251  8b7eec               mov edi, dword ptr [esi - 0x14]
// 0065e254  83ee18               sub esi, 0x18
// 0065e257  837b6800             cmp dword ptr [ebx + 0x68], 0
// 0065e25b  894c2428             mov dword ptr [esp + 0x28], ecx
// 0065e25f  7410                 je 0x65e271
// 0065e261  8b0e                 mov ecx, dword ptr [esi]
// 0065e263  51                   push ecx
// 0065e264  53                   push ebx
// 0065e265  e896130000           call 0x65f600
// 0065e26a  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0065e26e  83c408               add esp, 8
// 0065e271  8b5618               mov edx, dword ptr [esi + 0x18]
// 0065e274  8b4604               mov eax, dword ptr [esi + 4]
// 0065e277  2bd1                 sub edx, ecx
// 0065e279  c1fa04               sar edx, 4
// 0065e27c  c1e204               shl edx, 4
// 0065e27f  03c2                 add eax, edx
// 0065e281  8906                 mov dword ptr [esi], eax
// 0065e283  33d2                 xor edx, edx
// 0065e285  89430c               mov dword ptr [ebx + 0xc], eax
// 0065e288  89542430             mov dword ptr [esp + 0x30], edx
// 0065e28c  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 0065e28f  732e                 jae 0x65e2bf
// 0065e291  33c0                 xor eax, eax
// 0065e293  8b11                 mov edx, dword ptr [ecx]
// 0065e295  891438               mov dword ptr [eax + edi], edx
// 0065e298  8b5104               mov edx, dword ptr [ecx + 4]
// 0065e29b  89543804             mov dword ptr [eax + edi + 4], edx
// 0065e29f  8b4908               mov ecx, dword ptr [ecx + 8]
// 0065e2a2  8b542430             mov edx, dword ptr [esp + 0x30]
// 0065e2a6  894c3808             mov dword ptr [eax + edi + 8], ecx
// 0065e2aa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0065e2ae  42                   inc edx
// 0065e2af  8bc2                 mov eax, edx
// 0065e2b1  c1e004               shl eax, 4
// 0065e2b4  03c8                 add ecx, eax
// 0065e2b6  89542430             mov dword ptr [esp + 0x30], edx
// 0065e2ba  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 0065e2bd  72d4                 jb 0x65e293
// 0065e2bf  c1e204               shl edx, 4
// 0065e2c2  8d043a               lea eax, [edx + edi]
// 0065e2c5  894308               mov dword ptr [ebx + 8], eax
// 0065e2c8  894608               mov dword ptr [esi + 8], eax
// 0065e2cb  8b5318               mov edx, dword ptr [ebx + 0x18]
// 0065e2ce  ff4614               inc dword ptr [esi + 0x14]
// 0065e2d1  89560c               mov dword ptr [esi + 0xc], edx
// 0065e2d4  834314e8             add dword ptr [ebx + 0x14], -0x18
// 0065e2d8  e9f2efffff           jmp 0x65d2cf
// 0065e2dd  c1ef17               shr edi, 0x17
// 0065e2e0  85ff                 test edi, edi
// 0065e2e2  740a                 je 0x65e2ee
// 0065e2e4  c1e704               shl edi, 4
// 0065e2e7  8d4437f0             lea eax, [edi + esi - 0x10]
// 0065e2eb  894308               mov dword ptr [ebx + 8], eax
// 0065e2ee  837b6800             cmp dword ptr [ebx + 0x68], 0
// 0065e2f2  740e                 je 0x65e302
// 0065e2f4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065e2f8  51                   push ecx
// 0065e2f9  53                   push ebx
// 0065e2fa  e801130000           call 0x65f600
// 0065e2ff  83c408               add esp, 8
// 0065e302  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065e306  56                   push esi
// 0065e307  53                   push ebx
// 0065e308  895318               mov dword ptr [ebx + 0x18], edx
// 0065e30b  e8a03afcff           call 0x621db0
// 0065e310  83c408               add esp, 8
// 0065e313  836d0c01             sub dword ptr [ebp + 0xc], 1
// 0065e317  7420                 je 0x65e339
// 0065e319  85c0                 test eax, eax
// 0065e31b  0f84aeefffff         je 0x65d2cf
// 0065e321  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0065e324  8b4808               mov ecx, dword ptr [eax + 8]
// 0065e327  894b08               mov dword ptr [ebx + 8], ecx
// 0065e32a  e9a0efffff           jmp 0x65d2cf
// 0065e32f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065e333  83c2fc               add edx, -4
// 0065e336  895318               mov dword ptr [ebx + 0x18], edx
// 0065e339  5f                   pop edi
// 0065e33a  5e                   pop esi
// 0065e33b  5b                   pop ebx
// 0065e33c  8be5                 mov esp, ebp
// 0065e33e  5d                   pop ebp
// 0065e33f  c3                   ret 
// 0065e340  68d3650085           push 0x850065d3
// 0065e345  d36500               shl dword ptr [ebp], cl
// 0065e348  91                   xchg ecx, eax
// 0065e349  d36500               shl dword ptr [ebp], cl
// 0065e34c  b5d3                 mov ch, 0xd3
// 0065e34e  6500cf               add bh, cl
// 0065e351  d36500               shl dword ptr [ebp], cl
// 0065e354  f2d36500             shl dword ptr [ebp], cl
// 0065e358  32d4                 xor dl, ah
// 0065e35a  65007fd4             add byte ptr gs:[edi - 0x2c], bh
// 0065e35e  6500bfd465000d       add byte ptr gs:[edi + 0xd0065d4], bh
// 0065e365  d565                 aad 0x65
// 0065e367  006fd5               add byte ptr [edi - 0x2b], ch
// 0065e36a  6500afd565000f       add byte ptr gs:[edi + 0xf0065d5], ch
// 0065e371  d6                   salc 
// 0065e372  650098d6650002       add byte ptr gs:[eax + 0x20065d6], bl
// 0065e379  d7                   xlatb 
// 0065e37a  65006cd765           add byte ptr gs:[edi + edx*8 + 0x65], ch
// 0065e37f  00d6                 add dh, dl
// 0065e381  d7                   xlatb 
// 0065e382  650061d8             add byte ptr gs:[ecx - 0x28], ah
// 0065e386  6500f3               add bl, dh
// 0065e389  d86500               fsub dword ptr [ebp]
// 0065e38c  f3d96500             fldenv [ebp]
// 0065e390  2cda                 sub al, 0xda
// 0065e392  6500f0               add al, dh
// 0065e395  da6500               fisub dword ptr [ebp]
// 0065e398  50                   push eax

void func_0065d2c0()
{
}

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1-dll lvm.c
