// roc 2012-06 005bf1d0  unit: RakNet::RakPeer  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bf1d0
//
// 005bf1d0  6aff                 push -1
// 005bf1d2  681e2bab00           push 0xab2b1e
// 005bf1d7  64a100000000         mov eax, dword ptr fs:[0]
// 005bf1dd  50                   push eax
// 005bf1de  64892500000000       mov dword ptr fs:[0], esp
// 005bf1e5  51                   push ecx
// 005bf1e6  53                   push ebx
// 005bf1e7  56                   push esi
// 005bf1e8  57                   push edi
// 005bf1e9  8bf9                 mov edi, ecx
// 005bf1eb  8d4f04               lea ecx, [edi + 4]
// 005bf1ee  897c240c             mov dword ptr [esp + 0xc], edi
// 005bf1f2  e83928faff           call 0x561a30
// 005bf1f7  8d4f18               lea ecx, [edi + 0x18]
// 005bf1fa  e83128faff           call 0x561a30
// 005bf1ff  8d772c               lea esi, [edi + 0x2c]
// 005bf202  bb09000000           mov ebx, 9
// 005bf207  8bce                 mov ecx, esi
// 005bf209  e82228faff           call 0x561a30
// 005bf20e  83c614               add esi, 0x14
// 005bf211  83eb01               sub ebx, 1
// 005bf214  79f1                 jns 0x5bf207
// 005bf216  8d8ff8000000         lea ecx, [edi + 0xf8]
// 005bf21c  e8ef07feff           call 0x59fa10
// 005bf221  33f6                 xor esi, esi
// 005bf223  8d8fe0110000         lea ecx, [edi + 0x11e0]
// 005bf229  89742418             mov dword ptr [esp + 0x18], esi
// 005bf22d  e8ae2afaff           call 0x561ce0
// 005bf232  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005bf236  89b7f4110000         mov dword ptr [edi + 0x11f4], esi
// 005bf23c  89b7f8110000         mov dword ptr [edi + 0x11f8], esi
// 005bf242  8bc7                 mov eax, edi
// 005bf244  5f                   pop edi
// 005bf245  5e                   pop esi
// 005bf246  5b                   pop ebx
// 005bf247  64890d00000000       mov dword ptr fs:[0], ecx
// 005bf24e  83c410               add esp, 0x10
// 005bf251  c3                   ret 
// copied from an identical function in another client (function ??0RemoteSystemStruct@RakPeer@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp