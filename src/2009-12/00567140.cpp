// from server: 100% by auto
// roc 2009-12 00567140  unit: RakPeer  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00567140
//
// 00567140  53                   push ebx
// 00567141  56                   push esi
// 00567142  57                   push edi
// 00567143  6a0c                 push 0xc
// 00567145  8bf1                 mov esi, ecx
// 00567147  e814c72800           call 0x7f3860
// 0056714c  33db                 xor ebx, ebx
// 0056714e  83c404               add esp, 4
// 00567151  3bc3                 cmp eax, ebx
// 00567153  7405                 je 0x56715a
// 00567155  885804               mov byte ptr [eax + 4], bl
// 00567158  eb02                 jmp 0x56715c
// 0056715a  33c0                 xor eax, eax
// 0056715c  6a0c                 push 0xc
// 0056715e  894608               mov dword ptr [esi + 8], eax
// 00567161  89460c               mov dword ptr [esi + 0xc], eax
// 00567164  e8f7c62800           call 0x7f3860
// 00567169  83c404               add esp, 4
// 0056716c  3bc3                 cmp eax, ebx
// 0056716e  7405                 je 0x567175
// 00567170  885804               mov byte ptr [eax + 4], bl
// 00567173  eb02                 jmp 0x567177
// 00567175  33c0                 xor eax, eax
// 00567177  8b4e08               mov ecx, dword ptr [esi + 8]
// 0056717a  894108               mov dword ptr [ecx + 8], eax
// 0056717d  bf06000000           mov edi, 6
// 00567182  8b5608               mov edx, dword ptr [esi + 8]
// 00567185  8b4208               mov eax, dword ptr [edx + 8]
// 00567188  6a0c                 push 0xc
// 0056718a  894608               mov dword ptr [esi + 8], eax
// 0056718d  e8cec62800           call 0x7f3860
// 00567192  83c404               add esp, 4
// 00567195  3bc3                 cmp eax, ebx
// 00567197  7405                 je 0x56719e
// 00567199  885804               mov byte ptr [eax + 4], bl
// 0056719c  eb02                 jmp 0x5671a0
// 0056719e  33c0                 xor eax, eax
// 005671a0  83ef01               sub edi, 1
// 005671a3  8b4e08               mov ecx, dword ptr [esi + 8]
// 005671a6  894108               mov dword ptr [ecx + 8], eax
// 005671a9  75d7                 jne 0x567182
// 005671ab  8b5608               mov edx, dword ptr [esi + 8]
// 005671ae  8b4208               mov eax, dword ptr [edx + 8]
// 005671b1  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005671b4  894808               mov dword ptr [eax + 8], ecx
// 005671b7  8b460c               mov eax, dword ptr [esi + 0xc]
// 005671ba  894608               mov dword ptr [esi + 8], eax
// 005671bd  8906                 mov dword ptr [esi], eax
// 005671bf  894604               mov dword ptr [esi + 4], eax
// 005671c2  5f                   pop edi
// 005671c3  895e14               mov dword ptr [esi + 0x14], ebx
// 005671c6  895e10               mov dword ptr [esi + 0x10], ebx
// 005671c9  8bc6                 mov eax, esi
// 005671cb  5e                   pop esi
// 005671cc  5b                   pop ebx
// 005671cd  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ??0?$SingleProducerConsumer@PAD@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
