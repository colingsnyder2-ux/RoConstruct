// roc 2012-06 005bd440  unit: RakNet::RakPeer  size: 273 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bd440
//
// 005bd440  64a100000000         mov eax, dword ptr fs:[0]
// 005bd446  6aff                 push -1
// 005bd448  68a02aab00           push 0xab2aa0
// 005bd44d  50                   push eax
// 005bd44e  64892500000000       mov dword ptr fs:[0], esp
// 005bd455  83ec18               sub esp, 0x18
// 005bd458  55                   push ebp
// 005bd459  57                   push edi
// 005bd45a  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005bd45e  33ed                 xor ebp, ebp
// 005bd460  3bfd                 cmp edi, ebp
// 005bd462  0f84d4000000         je 0x5bd53c
// 005bd468  39a92c020000         cmp dword ptr [ecx + 0x22c], ebp
// 005bd46e  0f84c3000000         je 0x5bd537
// 005bd474  8a4104               mov al, byte ptr [ecx + 4]
// 005bd477  3c01                 cmp al, 1
// 005bd479  0f84b8000000         je 0x5bd537
// 005bd47f  53                   push ebx
// 005bd480  896c2414             mov dword ptr [esp + 0x14], ebp
// 005bd484  896c240c             mov dword ptr [esp + 0xc], ebp
// 005bd488  896c2410             mov dword ptr [esp + 0x10], ebp
// 005bd48c  896c242c             mov dword ptr [esp + 0x2c], ebp
// 005bd490  896c2420             mov dword ptr [esp + 0x20], ebp
// 005bd494  896c2418             mov dword ptr [esp + 0x18], ebp
// 005bd498  896c241c             mov dword ptr [esp + 0x1c], ebp
// 005bd49c  8b11                 mov edx, dword ptr [ecx]
// 005bd49e  8b9280000000         mov edx, dword ptr [edx + 0x80]
// 005bd4a4  8d442418             lea eax, [esp + 0x18]
// 005bd4a8  50                   push eax
// 005bd4a9  8d442410             lea eax, [esp + 0x10]
// 005bd4ad  50                   push eax
// 005bd4ae  c644243401           mov byte ptr [esp + 0x34], 1
// 005bd4b3  ffd2                 call edx
// 005bd4b5  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 005bd4b9  3bdd                 cmp ebx, ebp
// 005bd4bb  7436                 je 0x5bd4f3
// 005bd4bd  56                   push esi
// 005bd4be  33c0                 xor eax, eax
// 005bd4c0  33f6                 xor esi, esi
// 005bd4c2  663b07               cmp ax, word ptr [edi]
// 005bd4c5  7326                 jae 0x5bd4ed
// 005bd4c7  0fb7c6               movzx eax, si
// 005bd4ca  3b442414             cmp eax, dword ptr [esp + 0x14]
// 005bd4ce  731d                 jae 0x5bd4ed
// 005bd4d0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005bd4d4  8d0480               lea eax, [eax + eax*4]
// 005bd4d7  03c0                 add eax, eax
// 005bd4d9  03c0                 add eax, eax
// 005bd4db  8d1408               lea edx, [eax + ecx]
// 005bd4de  52                   push edx
// 005bd4df  8d0c18               lea ecx, [eax + ebx]
// 005bd4e2  e82943faff           call 0x561810
// 005bd4e7  46                   inc esi
// 005bd4e8  663b37               cmp si, word ptr [edi]
// 005bd4eb  72da                 jb 0x5bd4c7
// 005bd4ed  668937               mov word ptr [edi], si
// 005bd4f0  5e                   pop esi
// 005bd4f1  eb08                 jmp 0x5bd4fb
// 005bd4f3  668b442410           mov ax, word ptr [esp + 0x10]
// 005bd4f8  668907               mov word ptr [edi], ax
// 005bd4fb  5b                   pop ebx
// 005bd4fc  396c241c             cmp dword ptr [esp + 0x1c], ebp
// 005bd500  760d                 jbe 0x5bd50f
// 005bd502  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005bd506  51                   push ecx
// 005bd507  e8ae4e3c00           call 0x9823ba
// 005bd50c  83c404               add esp, 4
// 005bd50f  396c2410             cmp dword ptr [esp + 0x10], ebp
// 005bd513  760d                 jbe 0x5bd522
// 005bd515  8b542408             mov edx, dword ptr [esp + 8]
// 005bd519  52                   push edx
// 005bd51a  e89b4e3c00           call 0x9823ba
// 005bd51f  83c404               add esp, 4
// 005bd522  5f                   pop edi
// 005bd523  b001                 mov al, 1
// 005bd525  5d                   pop ebp
// 005bd526  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005bd52a  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd531  83c424               add esp, 0x24
// 005bd534  c20800               ret 8
// 005bd537  33c0                 xor eax, eax
// 005bd539  668907               mov word ptr [edi], ax
// 005bd53c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005bd540  5f                   pop edi
// 005bd541  32c0                 xor al, al
// 005bd543  5d                   pop ebp
// 005bd544  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd54b  83c424               add esp, 0x24
// 005bd54e  c20800               ret 8
// copied from an identical function in another client (function ?GetConnectionList@RakPeer@RakNet@@UBE_NPAUSystemAddress@2@PAG@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp