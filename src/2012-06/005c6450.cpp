// roc 2012-06 005c6450  unit: RakNet::RakPeer  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c6450
//
// 005c6450  55                   push ebp
// 005c6451  56                   push esi
// 005c6452  8bf1                 mov esi, ecx
// 005c6454  57                   push edi
// 005c6455  8d4e14               lea ecx, [esi + 0x14]
// 005c6458  e8032be5ff           call 0x418f60
// 005c645d  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c6461  33ff                 xor edi, edi
// 005c6463  53                   push ebx
// 005c6464  8b5630               mov edx, dword ptr [esi + 0x30]
// 005c6467  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 005c646a  3bd1                 cmp edx, ecx
// 005c646c  7706                 ja 0x5c6474
// 005c646e  2bca                 sub ecx, edx
// 005c6470  8bc1                 mov eax, ecx
// 005c6472  eb07                 jmp 0x5c647b
// 005c6474  8b4638               mov eax, dword ptr [esi + 0x38]
// 005c6477  2bc2                 sub eax, edx
// 005c6479  03c1                 add eax, ecx
// 005c647b  3bf8                 cmp edi, eax
// 005c647d  737e                 jae 0x5c64fd
// 005c647f  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005c6482  8bc2                 mov eax, edx
// 005c6484  8d1438               lea edx, [eax + edi]
// 005c6487  3bd1                 cmp edx, ecx
// 005c6489  720c                 jb 0x5c6497
// 005c648b  2bc1                 sub eax, ecx
// 005c648d  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 005c6490  03c7                 add eax, edi
// 005c6492  8d0481               lea eax, [ecx + eax*4]
// 005c6495  eb06                 jmp 0x5c649d
// 005c6497  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c649a  8d0490               lea eax, [eax + edx*4]
// 005c649d  8b00                 mov eax, dword ptr [eax]
// 005c649f  83780800             cmp dword ptr [eax + 8], 0
// 005c64a3  7623                 jbe 0x5c64c8
// 005c64a5  8b00                 mov eax, dword ptr [eax]
// 005c64a7  85c0                 test eax, eax
// 005c64a9  741d                 je 0x5c64c8
// 005c64ab  8b48fc               mov ecx, dword ptr [eax - 4]
// 005c64ae  8d58fc               lea ebx, [eax - 4]
// 005c64b1  68e0ed5b00           push 0x5bede0
// 005c64b6  51                   push ecx
// 005c64b7  6a08                 push 8
// 005c64b9  50                   push eax
// 005c64ba  e8b1cd3b00           call 0x983270
// 005c64bf  53                   push ebx
// 005c64c0  e8f5be3b00           call 0x9823ba
// 005c64c5  83c404               add esp, 4
// 005c64c8  8b4630               mov eax, dword ptr [esi + 0x30]
// 005c64cb  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 005c64ce  8d1438               lea edx, [eax + edi]
// 005c64d1  3bd1                 cmp edx, ecx
// 005c64d3  720c                 jb 0x5c64e1
// 005c64d5  8b562c               mov edx, dword ptr [esi + 0x2c]
// 005c64d8  2bc1                 sub eax, ecx
// 005c64da  03c7                 add eax, edi
// 005c64dc  8d0482               lea eax, [edx + eax*4]
// 005c64df  eb06                 jmp 0x5c64e7
// 005c64e1  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c64e4  8d0490               lea eax, [eax + edx*4]
// 005c64e7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c64eb  8b10                 mov edx, dword ptr [eax]
// 005c64ed  55                   push ebp
// 005c64ee  51                   push ecx
// 005c64ef  52                   push edx
// 005c64f0  8bce                 mov ecx, esi
// 005c64f2  e80969ffff           call 0x5bce00
// 005c64f7  47                   inc edi
// 005c64f8  e967ffffff           jmp 0x5c6464
// 005c64fd  8b4638               mov eax, dword ptr [esi + 0x38]
// 005c6500  33ff                 xor edi, edi
// 005c6502  5b                   pop ebx
// 005c6503  3bc7                 cmp eax, edi
// 005c6505  741a                 je 0x5c6521
// 005c6507  83f820               cmp eax, 0x20
// 005c650a  760f                 jbe 0x5c651b
// 005c650c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c650f  50                   push eax
// 005c6510  e8a5be3b00           call 0x9823ba
// 005c6515  83c404               add esp, 4
// 005c6518  897e38               mov dword ptr [esi + 0x38], edi
// 005c651b  897e30               mov dword ptr [esi + 0x30], edi
// 005c651e  897e34               mov dword ptr [esi + 0x34], edi
// 005c6521  8d7e14               lea edi, [esi + 0x14]
// 005c6524  8bcf                 mov ecx, edi
// 005c6526  e8452ae5ff           call 0x418f70
// 005c652b  8bcf                 mov ecx, edi
// 005c652d  e82e2ae5ff           call 0x418f60
// 005c6532  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005c6536  55                   push ebp
// 005c6537  51                   push ecx
// 005c6538  8bce                 mov ecx, esi
// 005c653a  e8c140fdff           call 0x59a600
// 005c653f  8bcf                 mov ecx, edi
// 005c6541  e82a2ae5ff           call 0x418f70
// 005c6546  5f                   pop edi
// 005c6547  5e                   pop esi
// 005c6548  5d                   pop ebp
// 005c6549  c20800               ret 8
// copied from an identical function in another client (function ?Clear@?$ThreadsafeAllocatingQueue@USocketQueryOutput@RakPeer@RakNet@@@DataStructures@@QAEXPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp