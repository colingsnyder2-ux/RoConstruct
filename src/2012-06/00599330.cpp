// roc 2012-06 00599330  unit: RBX::Network::ServerReplicator  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00599330
//
// 00599330  6aff                 push -1
// 00599332  685815ab00           push 0xab1558
// 00599337  64a100000000         mov eax, dword ptr fs:[0]
// 0059933d  50                   push eax
// 0059933e  64892500000000       mov dword ptr fs:[0], esp
// 00599345  51                   push ecx
// 00599346  53                   push ebx
// 00599347  56                   push esi
// 00599348  8bf1                 mov esi, ecx
// 0059934a  57                   push edi
// 0059934b  8974240c             mov dword ptr [esp + 0xc], esi
// 0059934f  33db                 xor ebx, ebx
// 00599351  33ff                 xor edi, edi
// 00599353  895c2418             mov dword ptr [esp + 0x18], ebx
// 00599357  395e04               cmp dword ptr [esi + 4], ebx
// 0059935a  7625                 jbe 0x599381
// 0059935c  55                   push ebp
// 0059935d  8d4900               lea ecx, [ecx]
// 00599360  8b06                 mov eax, dword ptr [esi]
// 00599362  8b6cf804             mov ebp, dword ptr [eax + edi*8 + 4]
// 00599366  3beb                 cmp ebp, ebx
// 00599368  7410                 je 0x59937a
// 0059936a  8bcd                 mov ecx, ebp
// 0059936c  e8efec0200           call 0x5c8060
// 00599371  55                   push ebp
// 00599372  e89d8d3e00           call 0x982114
// 00599377  83c404               add esp, 4
// 0059937a  47                   inc edi
// 0059937b  3b7e04               cmp edi, dword ptr [esi + 4]
// 0059937e  72e0                 jb 0x599360
// 00599380  5d                   pop ebp
// 00599381  885e14               mov byte ptr [esi + 0x14], bl
// 00599384  395e08               cmp dword ptr [esi + 8], ebx
// 00599387  7439                 je 0x5993c2
// 00599389  8b0e                 mov ecx, dword ptr [esi]
// 0059938b  51                   push ecx
// 0059938c  e829903e00           call 0x9823ba
// 00599391  83c404               add esp, 4
// 00599394  895e08               mov dword ptr [esi + 8], ebx
// 00599397  891e                 mov dword ptr [esi], ebx
// 00599399  895e04               mov dword ptr [esi + 4], ebx
// 0059939c  3bdb                 cmp ebx, ebx
// 0059939e  7422                 je 0x5993c2
// 005993a0  8bd3                 mov edx, ebx
// 005993a2  52                   push edx
// 005993a3  e812903e00           call 0x9823ba
// 005993a8  83c404               add esp, 4
// 005993ab  895e08               mov dword ptr [esi + 8], ebx
// 005993ae  891e                 mov dword ptr [esi], ebx
// 005993b0  895e04               mov dword ptr [esi + 4], ebx
// 005993b3  3bdb                 cmp ebx, ebx
// 005993b5  760b                 jbe 0x5993c2
// 005993b7  8bc3                 mov eax, ebx
// 005993b9  50                   push eax
// 005993ba  e8fb8f3e00           call 0x9823ba
// 005993bf  83c404               add esp, 4
// 005993c2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005993c6  5f                   pop edi
// 005993c7  5e                   pop esi
// 005993c8  5b                   pop ebx
// 005993c9  64890d00000000       mov dword ptr fs:[0], ecx
// 005993d0  83c410               add esp, 0x10
// 005993d3  c3                   ret 
// copied from an identical function in another client (function ??1StringCompressor@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp