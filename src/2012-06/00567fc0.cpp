// roc 2012-06 00567fc0  unit: RBX::VInstance::?$GuidItem::VRegistry::?$sp_counted_impl_p  size: 467 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00567fc0
//
// 00567fc0  53                   push ebx
// 00567fc1  55                   push ebp
// 00567fc2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00567fc6  56                   push esi
// 00567fc7  57                   push edi
// 00567fc8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00567fcc  c1ef03               shr edi, 3
// 00567fcf  4f                   dec edi
// 00567fd0  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 00567fd5  8bf1                 mov esi, ecx
// 00567fd7  0f95c3               setne bl
// 00567fda  fecb                 dec bl
// 00567fdc  85ff                 test edi, edi
// 00567fde  763c                 jbe 0x56801c
// 00567fe0  8bce                 mov ecx, esi
// 00567fe2  381c2f               cmp byte ptr [edi + ebp], bl
// 00567fe5  0f8581000000         jne 0x56806c
// 00567feb  6a01                 push 1
// 00567fed  e87ef9ffff           call 0x567970
// 00567ff2  8b06                 mov eax, dword ptr [esi]
// 00567ff4  8bc8                 mov ecx, eax
// 00567ff6  c1e803               shr eax, 3
// 00567ff9  83e107               and ecx, 7
// 00567ffc  7509                 jne 0x568007
// 00567ffe  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00568001  c6040880             mov byte ptr [eax + ecx], 0x80
// 00568005  eb0e                 jmp 0x568015
// 00568007  8b560c               mov edx, dword ptr [esi + 0xc]
// 0056800a  03c2                 add eax, edx
// 0056800c  ba80000000           mov edx, 0x80
// 00568011  d3fa                 sar edx, cl
// 00568013  0810                 or byte ptr [eax], dl
// 00568015  ff06                 inc dword ptr [esi]
// 00568017  83ef01               sub edi, 1
// 0056801a  75c4                 jne 0x567fe0
// 0056801c  03fd                 add edi, ebp
// 0056801e  807c241c00           cmp byte ptr [esp + 0x1c], 0
// 00568023  746f                 je 0x568094
// 00568025  f607f0               test byte ptr [edi], 0xf0
// 00568028  7474                 je 0x56809e
// 0056802a  8d54241c             lea edx, [esp + 0x1c]
// 0056802e  52                   push edx
// 0056802f  8bce                 mov ecx, esi
// 00568031  c644242000           mov byte ptr [esp + 0x20], 0
// 00568036  e875feffff           call 0x567eb0
// 0056803b  bb08000000           mov ebx, 8
// 00568040  53                   push ebx
// 00568041  8bce                 mov ecx, esi
// 00568043  e828f9ffff           call 0x567970
// 00568048  8b06                 mov eax, dword ptr [esi]
// 0056804a  8bd0                 mov edx, eax
// 0056804c  83e207               and edx, 7
// 0056804f  89542418             mov dword ptr [esp + 0x18], edx
// 00568053  0f85d6000000         jne 0x56812f
// 00568059  8a0f                 mov cl, byte ptr [edi]
// 0056805b  c1e803               shr eax, 3
// 0056805e  03460c               add eax, dword ptr [esi + 0xc]
// 00568061  8808                 mov byte ptr [eax], cl
// 00568063  011e                 add dword ptr [esi], ebx
// 00568065  5f                   pop edi
// 00568066  5e                   pop esi
// 00568067  5d                   pop ebp
// 00568068  5b                   pop ebx
// 00568069  c20c00               ret 0xc
// 0056806c  8d44241c             lea eax, [esp + 0x1c]
// 00568070  50                   push eax
// 00568071  c644242000           mov byte ptr [esp + 0x20], 0
// 00568076  e835feffff           call 0x567eb0
// 0056807b  6a01                 push 1
// 0056807d  8d0cfd08000000       lea ecx, [edi*8 + 8]
// 00568084  51                   push ecx
// 00568085  55                   push ebp
// 00568086  8bce                 mov ecx, esi
// 00568088  e803fdffff           call 0x567d90
// 0056808d  5f                   pop edi
// 0056808e  5e                   pop esi
// 0056808f  5d                   pop ebp
// 00568090  5b                   pop ebx
// 00568091  c20c00               ret 0xc
// 00568094  8a17                 mov dl, byte ptr [edi]
// 00568096  80e2f0               and dl, 0xf0
// 00568099  80faf0               cmp dl, 0xf0
// 0056809c  758c                 jne 0x56802a
// 0056809e  8d44241c             lea eax, [esp + 0x1c]
// 005680a2  50                   push eax
// 005680a3  8bce                 mov ecx, esi
// 005680a5  c644242001           mov byte ptr [esp + 0x20], 1
// 005680aa  e801feffff           call 0x567eb0
// 005680af  bb04000000           mov ebx, 4
// 005680b4  53                   push ebx
// 005680b5  8bce                 mov ecx, esi
// 005680b7  895c2420             mov dword ptr [esp + 0x20], ebx
// 005680bb  e8b0f8ffff           call 0x567970
// 005680c0  8b16                 mov edx, dword ptr [esi]
// 005680c2  83e207               and edx, 7
// 005680c5  8bef                 mov ebp, edi
// 005680c7  8a4500               mov al, byte ptr [ebp]
// 005680ca  45                   inc ebp
// 005680cb  83fb08               cmp ebx, 8
// 005680ce  7306                 jae 0x5680d6
// 005680d0  b108                 mov cl, 8
// 005680d2  2acb                 sub cl, bl
// 005680d4  d2e0                 shl al, cl
// 005680d6  8b0e                 mov ecx, dword ptr [esi]
// 005680d8  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005680db  c1e903               shr ecx, 3
// 005680de  85d2                 test edx, edx
// 005680e0  7505                 jne 0x5680e7
// 005680e2  880439               mov byte ptr [ecx + edi], al
// 005680e5  eb2c                 jmp 0x568113
// 005680e7  03f9                 add edi, ecx
// 005680e9  8ad8                 mov bl, al
// 005680eb  8aca                 mov cl, dl
// 005680ed  d2eb                 shr bl, cl
// 005680ef  b908000000           mov ecx, 8
// 005680f4  2bca                 sub ecx, edx
// 005680f6  081f                 or byte ptr [edi], bl
// 005680f8  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 005680fc  83f908               cmp ecx, 8
// 005680ff  7312                 jae 0x568113
// 00568101  3bcb                 cmp ecx, ebx
// 00568103  730e                 jae 0x568113
// 00568105  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00568108  d2e0                 shl al, cl
// 0056810a  8b0e                 mov ecx, dword ptr [esi]
// 0056810c  c1e903               shr ecx, 3
// 0056810f  88443901             mov byte ptr [ecx + edi + 1], al
// 00568113  83fb08               cmp ebx, 8
// 00568116  0f8247ffffff         jb 0x568063
// 0056811c  830608               add dword ptr [esi], 8
// 0056811f  83eb08               sub ebx, 8
// 00568122  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00568126  759f                 jne 0x5680c7
// 00568128  5f                   pop edi
// 00568129  5e                   pop esi
// 0056812a  5d                   pop ebp
// 0056812b  5b                   pop ebx
// 0056812c  c20c00               ret 0xc
// 0056812f  8bef                 mov ebp, edi
// 00568131  8a4500               mov al, byte ptr [ebp]
// 00568134  45                   inc ebp
// 00568135  83fb08               cmp ebx, 8
// 00568138  7306                 jae 0x568140
// 0056813a  b108                 mov cl, 8
// 0056813c  2acb                 sub cl, bl
// 0056813e  d2e0                 shl al, cl
// 00568140  8b0e                 mov ecx, dword ptr [esi]
// 00568142  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00568145  c1e903               shr ecx, 3
// 00568148  03f9                 add edi, ecx
// 0056814a  8ac8                 mov cl, al
// 0056814c  884c241c             mov byte ptr [esp + 0x1c], cl
// 00568150  8aca                 mov cl, dl
// 00568152  8ad0                 mov dl, al
// 00568154  d2ea                 shr dl, cl
// 00568156  b908000000           mov ecx, 8
// 0056815b  2b4c2418             sub ecx, dword ptr [esp + 0x18]
// 0056815f  0817                 or byte ptr [edi], dl
// 00568161  83f908               cmp ecx, 8
// 00568164  7312                 jae 0x568178
// 00568166  3bcb                 cmp ecx, ebx
// 00568168  730e                 jae 0x568178
// 0056816a  8b16                 mov edx, dword ptr [esi]
// 0056816c  d2e0                 shl al, cl
// 0056816e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00568171  c1ea03               shr edx, 3
// 00568174  88440a01             mov byte ptr [edx + ecx + 1], al
// 00568178  83fb08               cmp ebx, 8
// 0056817b  0f82e2feffff         jb 0x568063
// 00568181  830608               add dword ptr [esi], 8
// 00568184  83eb08               sub ebx, 8
// 00568187  0f84d8feffff         je 0x568065
// 0056818d  8b542418             mov edx, dword ptr [esp + 0x18]
// 00568191  eb9e                 jmp 0x568131
// copied from an identical function in another client (function ?WriteCompressed@BitStream@RakNet@@AAEXPBEI_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 BitStream.cpp