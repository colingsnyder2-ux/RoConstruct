// from server: 100% by auto
// roc 2010-06 00515bc0  unit: RakPeer  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00515bc0
//
// 00515bc0  53                   push ebx
// 00515bc1  56                   push esi
// 00515bc2  57                   push edi
// 00515bc3  6a0c                 push 0xc
// 00515bc5  8bf1                 mov esi, ecx
// 00515bc7  e8d41d2900           call 0x7a79a0
// 00515bcc  33db                 xor ebx, ebx
// 00515bce  83c404               add esp, 4
// 00515bd1  3bc3                 cmp eax, ebx
// 00515bd3  7405                 je 0x515bda
// 00515bd5  885804               mov byte ptr [eax + 4], bl
// 00515bd8  eb02                 jmp 0x515bdc
// 00515bda  33c0                 xor eax, eax
// 00515bdc  6a0c                 push 0xc
// 00515bde  894608               mov dword ptr [esi + 8], eax
// 00515be1  89460c               mov dword ptr [esi + 0xc], eax
// 00515be4  e8b71d2900           call 0x7a79a0
// 00515be9  83c404               add esp, 4
// 00515bec  3bc3                 cmp eax, ebx
// 00515bee  7405                 je 0x515bf5
// 00515bf0  885804               mov byte ptr [eax + 4], bl
// 00515bf3  eb02                 jmp 0x515bf7
// 00515bf5  33c0                 xor eax, eax
// 00515bf7  8b4e08               mov ecx, dword ptr [esi + 8]
// 00515bfa  894108               mov dword ptr [ecx + 8], eax
// 00515bfd  bf06000000           mov edi, 6
// 00515c02  8b5608               mov edx, dword ptr [esi + 8]
// 00515c05  8b4208               mov eax, dword ptr [edx + 8]
// 00515c08  6a0c                 push 0xc
// 00515c0a  894608               mov dword ptr [esi + 8], eax
// 00515c0d  e88e1d2900           call 0x7a79a0
// 00515c12  83c404               add esp, 4
// 00515c15  3bc3                 cmp eax, ebx
// 00515c17  7405                 je 0x515c1e
// 00515c19  885804               mov byte ptr [eax + 4], bl
// 00515c1c  eb02                 jmp 0x515c20
// 00515c1e  33c0                 xor eax, eax
// 00515c20  83ef01               sub edi, 1
// 00515c23  8b4e08               mov ecx, dword ptr [esi + 8]
// 00515c26  894108               mov dword ptr [ecx + 8], eax
// 00515c29  75d7                 jne 0x515c02
// 00515c2b  8b5608               mov edx, dword ptr [esi + 8]
// 00515c2e  8b4208               mov eax, dword ptr [edx + 8]
// 00515c31  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00515c34  894808               mov dword ptr [eax + 8], ecx
// 00515c37  8b460c               mov eax, dword ptr [esi + 0xc]
// 00515c3a  894608               mov dword ptr [esi + 8], eax
// 00515c3d  8906                 mov dword ptr [esi], eax
// 00515c3f  894604               mov dword ptr [esi + 4], eax
// 00515c42  5f                   pop edi
// 00515c43  895e14               mov dword ptr [esi + 0x14], ebx
// 00515c46  895e10               mov dword ptr [esi + 0x10], ebx
// 00515c49  8bc6                 mov eax, esi
// 00515c4b  5e                   pop esi
// 00515c4c  5b                   pop ebx
// 00515c4d  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ??0?$SingleProducerConsumer@PAD@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
