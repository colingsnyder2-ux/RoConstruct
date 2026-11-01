// from server: 100% by auto
// roc 2009-12 0054fc80  unit: RBX::Network::IdSerializer  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054fc80
//
// 0054fc80  6aff                 push -1
// 0054fc82  6868ab9300           push 0x93ab68
// 0054fc87  64a100000000         mov eax, dword ptr fs:[0]
// 0054fc8d  50                   push eax
// 0054fc8e  64892500000000       mov dword ptr fs:[0], esp
// 0054fc95  51                   push ecx
// 0054fc96  53                   push ebx
// 0054fc97  56                   push esi
// 0054fc98  8bf1                 mov esi, ecx
// 0054fc9a  57                   push edi
// 0054fc9b  8974240c             mov dword ptr [esp + 0xc], esi
// 0054fc9f  33db                 xor ebx, ebx
// 0054fca1  33ff                 xor edi, edi
// 0054fca3  895c2418             mov dword ptr [esp + 0x18], ebx
// 0054fca7  395e04               cmp dword ptr [esi + 4], ebx
// 0054fcaa  7625                 jbe 0x54fcd1
// 0054fcac  55                   push ebp
// 0054fcad  8d4900               lea ecx, [ecx]
// 0054fcb0  8b06                 mov eax, dword ptr [esi]
// 0054fcb2  8b6cf804             mov ebp, dword ptr [eax + edi*8 + 4]
// 0054fcb6  3beb                 cmp ebp, ebx
// 0054fcb8  7410                 je 0x54fcca
// 0054fcba  8bcd                 mov ecx, ebp
// 0054fcbc  e80f560100           call 0x5652d0
// 0054fcc1  55                   push ebp
// 0054fcc2  e8933b2a00           call 0x7f385a
// 0054fcc7  83c404               add esp, 4
// 0054fcca  47                   inc edi
// 0054fccb  3b7e04               cmp edi, dword ptr [esi + 4]
// 0054fcce  72e0                 jb 0x54fcb0
// 0054fcd0  5d                   pop ebp
// 0054fcd1  885e14               mov byte ptr [esi + 0x14], bl
// 0054fcd4  395e08               cmp dword ptr [esi + 8], ebx
// 0054fcd7  7439                 je 0x54fd12
// 0054fcd9  8b0e                 mov ecx, dword ptr [esi]
// 0054fcdb  51                   push ecx
// 0054fcdc  e8253e2a00           call 0x7f3b06
// 0054fce1  83c404               add esp, 4
// 0054fce4  895e08               mov dword ptr [esi + 8], ebx
// 0054fce7  891e                 mov dword ptr [esi], ebx
// 0054fce9  895e04               mov dword ptr [esi + 4], ebx
// 0054fcec  3bdb                 cmp ebx, ebx
// 0054fcee  7422                 je 0x54fd12
// 0054fcf0  8bd3                 mov edx, ebx
// 0054fcf2  52                   push edx
// 0054fcf3  e80e3e2a00           call 0x7f3b06
// 0054fcf8  83c404               add esp, 4
// 0054fcfb  895e08               mov dword ptr [esi + 8], ebx
// 0054fcfe  891e                 mov dword ptr [esi], ebx
// 0054fd00  895e04               mov dword ptr [esi + 4], ebx
// 0054fd03  3bdb                 cmp ebx, ebx
// 0054fd05  760b                 jbe 0x54fd12
// 0054fd07  8bc3                 mov eax, ebx
// 0054fd09  50                   push eax
// 0054fd0a  e8f73d2a00           call 0x7f3b06
// 0054fd0f  83c404               add esp, 4
// 0054fd12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0054fd16  5f                   pop edi
// 0054fd17  5e                   pop esi
// 0054fd18  5b                   pop ebx
// 0054fd19  64890d00000000       mov dword ptr fs:[0], ecx
// 0054fd20  83c410               add esp, 0x10
// 0054fd23  c3                   ret 
// library raknet-4.081/StringCompressor.cpp (function ??1StringCompressor@RakNet@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 StringCompressor.cpp
