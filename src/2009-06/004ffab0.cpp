// from server: 100% by auto
// roc 2009-06 004ffab0  unit: RakPeer  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ffab0
//
// 004ffab0  53                   push ebx
// 004ffab1  56                   push esi
// 004ffab2  57                   push edi
// 004ffab3  6a0c                 push 0xc
// 004ffab5  8bf1                 mov esi, ecx
// 004ffab7  e87c8f2100           call 0x718a38
// 004ffabc  33db                 xor ebx, ebx
// 004ffabe  83c404               add esp, 4
// 004ffac1  3bc3                 cmp eax, ebx
// 004ffac3  7405                 je 0x4ffaca
// 004ffac5  885804               mov byte ptr [eax + 4], bl
// 004ffac8  eb02                 jmp 0x4ffacc
// 004ffaca  33c0                 xor eax, eax
// 004ffacc  6a0c                 push 0xc
// 004fface  894608               mov dword ptr [esi + 8], eax
// 004ffad1  89460c               mov dword ptr [esi + 0xc], eax
// 004ffad4  e85f8f2100           call 0x718a38
// 004ffad9  83c404               add esp, 4
// 004ffadc  3bc3                 cmp eax, ebx
// 004ffade  7405                 je 0x4ffae5
// 004ffae0  885804               mov byte ptr [eax + 4], bl
// 004ffae3  eb02                 jmp 0x4ffae7
// 004ffae5  33c0                 xor eax, eax
// 004ffae7  8b4e08               mov ecx, dword ptr [esi + 8]
// 004ffaea  894108               mov dword ptr [ecx + 8], eax
// 004ffaed  bf06000000           mov edi, 6
// 004ffaf2  8b5608               mov edx, dword ptr [esi + 8]
// 004ffaf5  8b4208               mov eax, dword ptr [edx + 8]
// 004ffaf8  6a0c                 push 0xc
// 004ffafa  894608               mov dword ptr [esi + 8], eax
// 004ffafd  e8368f2100           call 0x718a38
// 004ffb02  83c404               add esp, 4
// 004ffb05  3bc3                 cmp eax, ebx
// 004ffb07  7405                 je 0x4ffb0e
// 004ffb09  885804               mov byte ptr [eax + 4], bl
// 004ffb0c  eb02                 jmp 0x4ffb10
// 004ffb0e  33c0                 xor eax, eax
// 004ffb10  83ef01               sub edi, 1
// 004ffb13  8b4e08               mov ecx, dword ptr [esi + 8]
// 004ffb16  894108               mov dword ptr [ecx + 8], eax
// 004ffb19  75d7                 jne 0x4ffaf2
// 004ffb1b  8b5608               mov edx, dword ptr [esi + 8]
// 004ffb1e  8b4208               mov eax, dword ptr [edx + 8]
// 004ffb21  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004ffb24  894808               mov dword ptr [eax + 8], ecx
// 004ffb27  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ffb2a  894608               mov dword ptr [esi + 8], eax
// 004ffb2d  8906                 mov dword ptr [esi], eax
// 004ffb2f  894604               mov dword ptr [esi + 4], eax
// 004ffb32  5f                   pop edi
// 004ffb33  895e14               mov dword ptr [esi + 0x14], ebx
// 004ffb36  895e10               mov dword ptr [esi + 0x10], ebx
// 004ffb39  8bc6                 mov eax, esi
// 004ffb3b  5e                   pop esi
// 004ffb3c  5b                   pop ebx
// 004ffb3d  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ??0?$SingleProducerConsumer@PAD@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
