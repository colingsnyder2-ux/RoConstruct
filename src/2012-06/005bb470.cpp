// roc 2012-06 005bb470  unit: RakNet::RakPeer  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb470
//
// 005bb470  51                   push ecx
// 005bb471  55                   push ebp
// 005bb472  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005bb476  56                   push esi
// 005bb477  8bf1                 mov esi, ecx
// 005bb479  68f815d900           push 0xd915f8
// 005bb47e  8bcd                 mov ecx, ebp
// 005bb480  8974240c             mov dword ptr [esp + 0xc], esi
// 005bb484  e8a768faff           call 0x561d30
// 005bb489  84c0                 test al, al
// 005bb48b  7414                 je 0x5bb4a1
// 005bb48d  81c658040000         add esi, 0x458
// 005bb493  56                   push esi
// 005bb494  8bcd                 mov ecx, ebp
// 005bb496  e87568faff           call 0x561d10
// 005bb49b  5e                   pop esi
// 005bb49c  5d                   pop ebp
// 005bb49d  59                   pop ecx
// 005bb49e  c20800               ret 8
// 005bb4a1  53                   push ebx
// 005bb4a2  8a5c2418             mov bl, byte ptr [esp + 0x18]
// 005bb4a6  57                   push edi
// 005bb4a7  33ff                 xor edi, edi
// 005bb4a9  81c698040000         add esi, 0x498
// 005bb4af  90                   nop 
// 005bb4b0  684c69e200           push 0xe2694c
// 005bb4b5  8bce                 mov ecx, esi
// 005bb4b7  e81464faff           call 0x5618d0
// 005bb4bc  84c0                 test al, al
// 005bb4be  7429                 je 0x5bb4e9
// 005bb4c0  84db                 test bl, bl
// 005bb4c2  740d                 je 0x5bb4d1
// 005bb4c4  8d4510               lea eax, [ebp + 0x10]
// 005bb4c7  50                   push eax
// 005bb4c8  8bce                 mov ecx, esi
// 005bb4ca  e8d163faff           call 0x5618a0
// 005bb4cf  eb0b                 jmp 0x5bb4dc
// 005bb4d1  8d4d10               lea ecx, [ebp + 0x10]
// 005bb4d4  51                   push ecx
// 005bb4d5  8bce                 mov ecx, esi
// 005bb4d7  e86463faff           call 0x561840
// 005bb4dc  84c0                 test al, al
// 005bb4de  752f                 jne 0x5bb50f
// 005bb4e0  47                   inc edi
// 005bb4e1  83c614               add esi, 0x14
// 005bb4e4  83ff0a               cmp edi, 0xa
// 005bb4e7  7cc7                 jl 0x5bb4b0
// 005bb4e9  80fb01               cmp bl, 1
// 005bb4ec  752b                 jne 0x5bb519
// 005bb4ee  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bb4f2  81c270040000         add edx, 0x470
// 005bb4f8  52                   push edx
// 005bb4f9  8d4d10               lea ecx, [ebp + 0x10]
// 005bb4fc  e89f63faff           call 0x5618a0
// 005bb501  84c0                 test al, al
// 005bb503  752e                 jne 0x5bb533
// 005bb505  5f                   pop edi
// 005bb506  5b                   pop ebx
// 005bb507  5e                   pop esi
// 005bb508  33c0                 xor eax, eax
// 005bb50a  5d                   pop ebp
// 005bb50b  59                   pop ecx
// 005bb50c  c20800               ret 8
// 005bb50f  5f                   pop edi
// 005bb510  5b                   pop ebx
// 005bb511  5e                   pop esi
// 005bb512  b001                 mov al, 1
// 005bb514  5d                   pop ebp
// 005bb515  59                   pop ecx
// 005bb516  c20800               ret 8
// 005bb519  84db                 test bl, bl
// 005bb51b  75e8                 jne 0x5bb505
// 005bb51d  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bb521  0570040000           add eax, 0x470
// 005bb526  50                   push eax
// 005bb527  8d4d10               lea ecx, [ebp + 0x10]
// 005bb52a  e81163faff           call 0x561840
// 005bb52f  84c0                 test al, al
// 005bb531  74d2                 je 0x5bb505
// 005bb533  5f                   pop edi
// 005bb534  5b                   pop ebx
// 005bb535  5e                   pop esi
// 005bb536  b801000000           mov eax, 1
// 005bb53b  5d                   pop ebp
// 005bb53c  59                   pop ecx
// 005bb53d  c20800               ret 8
// copied from an identical function in another client (function ?IsLoopbackAddress@RakPeer@RakNet@@IBE_NABUAddressOrGUID@2@_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp