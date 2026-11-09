// roc 2012-06 005bf260  unit: RakNet::RakPeer  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bf260
//
// 005bf260  6aff                 push -1
// 005bf262  681e2bab00           push 0xab2b1e
// 005bf267  64a100000000         mov eax, dword ptr fs:[0]
// 005bf26d  50                   push eax
// 005bf26e  64892500000000       mov dword ptr fs:[0], esp
// 005bf275  51                   push ecx
// 005bf276  56                   push esi
// 005bf277  8bf1                 mov esi, ecx
// 005bf279  89742404             mov dword ptr [esp + 4], esi
// 005bf27d  8b86f8110000         mov eax, dword ptr [esi + 0x11f8]
// 005bf283  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005bf28b  85c0                 test eax, eax
// 005bf28d  7436                 je 0x5bf2c5
// 005bf28f  ff08                 dec dword ptr [eax]
// 005bf291  833800               cmp dword ptr [eax], 0
// 005bf294  752f                 jne 0x5bf2c5
// 005bf296  57                   push edi
// 005bf297  8bbef4110000         mov edi, dword ptr [esi + 0x11f4]
// 005bf29d  85ff                 test edi, edi
// 005bf29f  7410                 je 0x5bf2b1
// 005bf2a1  8bcf                 mov ecx, edi
// 005bf2a3  e838a10000           call 0x5c93e0
// 005bf2a8  57                   push edi
// 005bf2a9  e8662e3c00           call 0x982114
// 005bf2ae  83c404               add esp, 4
// 005bf2b1  8b86f8110000         mov eax, dword ptr [esi + 0x11f8]
// 005bf2b7  5f                   pop edi
// 005bf2b8  85c0                 test eax, eax
// 005bf2ba  7409                 je 0x5bf2c5
// 005bf2bc  50                   push eax
// 005bf2bd  e8522e3c00           call 0x982114
// 005bf2c2  83c404               add esp, 4
// 005bf2c5  8d8ef8000000         lea ecx, [esi + 0xf8]
// 005bf2cb  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 005bf2d3  e8c819feff           call 0x5a0ca0
// 005bf2d8  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005bf2dc  5e                   pop esi
// 005bf2dd  64890d00000000       mov dword ptr fs:[0], ecx
// 005bf2e4  83c410               add esp, 0x10
// 005bf2e7  c3                   ret 
// copied from an identical function in another client (function ??1RemoteSystemStruct@RakPeer@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp