// roc 2012-06 00598fa0  unit: RBX::Network::ServerReplicator  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00598fa0
//
// 00598fa0  6aff                 push -1
// 00598fa2  685b0aab00           push 0xab0a5b
// 00598fa7  64a100000000         mov eax, dword ptr fs:[0]
// 00598fad  50                   push eax
// 00598fae  64892500000000       mov dword ptr fs:[0], esp
// 00598fb5  81ec24010000         sub esp, 0x124
// 00598fbb  56                   push esi
// 00598fbc  57                   push edi
// 00598fbd  0fb6bc2448010000     movzx edi, byte ptr [esp + 0x148]
// 00598fc5  68208e5900           push 0x598e20
// 00598fca  8bf1                 mov esi, ecx
// 00598fcc  8d44240f             lea eax, [esp + 0xf]
// 00598fd0  50                   push eax
// 00598fd1  8d4c2414             lea ecx, [esp + 0x14]
// 00598fd5  51                   push ecx
// 00598fd6  8bce                 mov ecx, esi
// 00598fd8  897c2418             mov dword ptr [esp + 0x18], edi
// 00598fdc  e8ff290000           call 0x59b9e0
// 00598fe1  807c240b00           cmp byte ptr [esp + 0xb], 0
// 00598fe6  0f84e5000000         je 0x5990d1
// 00598fec  55                   push ebp
// 00598fed  68208e5900           push 0x598e20
// 00598ff2  8d542413             lea edx, [esp + 0x13]
// 00598ff6  52                   push edx
// 00598ff7  8d442418             lea eax, [esp + 0x18]
// 00598ffb  50                   push eax
// 00598ffc  8bce                 mov ecx, esi
// 00598ffe  897c241c             mov dword ptr [esp + 0x1c], edi
// 00599002  e8d9290000           call 0x59b9e0
// 00599007  8b0e                 mov ecx, dword ptr [esi]
// 00599009  8bb42440010000       mov esi, dword ptr [esp + 0x140]
// 00599010  8b6cc104             mov ebp, dword ptr [ecx + eax*8 + 4]
// 00599014  8d44c104             lea eax, [ecx + eax*8 + 4]
// 00599018  85f6                 test esi, esi
// 0059901a  751a                 jne 0x599036
// 0059901c  8b8c2448010000       mov ecx, dword ptr [esp + 0x148]
// 00599023  8d542418             lea edx, [esp + 0x18]
// 00599027  52                   push edx
// 00599028  8974241c             mov dword ptr [esp + 0x1c], esi
// 0059902c  e86ff5fcff           call 0x5685a0
// 00599031  e99a000000           jmp 0x5990d0
// 00599036  8d4c241c             lea ecx, [esp + 0x1c]
// 0059903a  e861e5fcff           call 0x5675a0
// 0059903f  8bbc2444010000       mov edi, dword ptr [esp + 0x144]
// 00599046  c784243801000000000000 mov dword ptr [esp + 0x138], 0
// 00599051  85ff                 test edi, edi
// 00599053  7e1d                 jle 0x599072
// 00599055  8bc6                 mov eax, esi
// 00599057  8d5001               lea edx, [eax + 1]
// 0059905a  8d9b00000000         lea ebx, [ebx]
// 00599060  8a08                 mov cl, byte ptr [eax]
// 00599062  40                   inc eax
// 00599063  84c9                 test cl, cl
// 00599065  75f9                 jne 0x599060
// 00599067  2bc2                 sub eax, edx
// 00599069  3bc7                 cmp eax, edi
// 0059906b  7c05                 jl 0x599072
// 0059906d  8d47ff               lea eax, [edi - 1]
// 00599070  eb0e                 jmp 0x599080
// 00599072  8bc6                 mov eax, esi
// 00599074  8d5001               lea edx, [eax + 1]
// 00599077  8a08                 mov cl, byte ptr [eax]
// 00599079  40                   inc eax
// 0059907a  84c9                 test cl, cl
// 0059907c  75f9                 jne 0x599077
// 0059907e  2bc2                 sub eax, edx
// 00599080  8d4c241c             lea ecx, [esp + 0x1c]
// 00599084  51                   push ecx
// 00599085  50                   push eax
// 00599086  56                   push esi
// 00599087  8bcd                 mov ecx, ebp
// 00599089  e872eb0200           call 0x5c7c00
// 0059908e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00599092  8bb42448010000       mov esi, dword ptr [esp + 0x148]
// 00599099  8d442414             lea eax, [esp + 0x14]
// 0059909d  50                   push eax
// 0059909e  8bce                 mov ecx, esi
// 005990a0  89542418             mov dword ptr [esp + 0x18], edx
// 005990a4  e8f7f4fcff           call 0x5685a0
// 005990a9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005990ad  8b542428             mov edx, dword ptr [esp + 0x28]
// 005990b1  6a01                 push 1
// 005990b3  51                   push ecx
// 005990b4  52                   push edx
// 005990b5  8bce                 mov ecx, esi
// 005990b7  e8d4ecfcff           call 0x567d90
// 005990bc  8d4c241c             lea ecx, [esp + 0x1c]
// 005990c0  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 005990cb  e8e0e5fcff           call 0x5676b0
// 005990d0  5d                   pop ebp
// 005990d1  8b8c242c010000       mov ecx, dword ptr [esp + 0x12c]
// 005990d8  5f                   pop edi
// 005990d9  5e                   pop esi
// 005990da  64890d00000000       mov dword ptr fs:[0], ecx
// 005990e1  81c430010000         add esp, 0x130
// 005990e7  c21000               ret 0x10
// copied from an identical function in another client (function ?EncodeString@StringCompressor@RakNet@@QAEXPBDHPAVBitStream@2@E@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp