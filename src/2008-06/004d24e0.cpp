// from server: 100% by auto
// roc 2008-06 004d24e0  unit: seg_004d0000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d24e0
//
// 004d24e0  6aff                 push -1
// 004d24e2  68189b7c00           push 0x7c9b18
// 004d24e7  64a100000000         mov eax, dword ptr fs:[0]
// 004d24ed  50                   push eax
// 004d24ee  64892500000000       mov dword ptr fs:[0], esp
// 004d24f5  51                   push ecx
// 004d24f6  56                   push esi
// 004d24f7  8bf1                 mov esi, ecx
// 004d24f9  89742404             mov dword ptr [esp + 4], esi
// 004d24fd  8b4608               mov eax, dword ptr [esi + 8]
// 004d2500  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004d2508  85c0                 test eax, eax
// 004d250a  7440                 je 0x4d254c
// 004d250c  3d00020000           cmp eax, 0x200
// 004d2511  7632                 jbe 0x4d2545
// 004d2513  8b06                 mov eax, dword ptr [esi]
// 004d2515  85c0                 test eax, eax
// 004d2517  741f                 je 0x4d2538
// 004d2519  8b48fc               mov ecx, dword ptr [eax - 4]
// 004d251c  57                   push edi
// 004d251d  8d78fc               lea edi, [eax - 4]
// 004d2520  6810d44700           push 0x47d410
// 004d2525  51                   push ecx
// 004d2526  6a08                 push 8
// 004d2528  50                   push eax
// 004d2529  e82df11c00           call 0x6a165b
// 004d252e  57                   push edi
// 004d252f  e846e11c00           call 0x6a067a
// 004d2534  83c404               add esp, 4
// 004d2537  5f                   pop edi
// 004d2538  c7460800000000       mov dword ptr [esi + 8], 0
// 004d253f  c70600000000         mov dword ptr [esi], 0
// 004d2545  c7460400000000       mov dword ptr [esi + 4], 0
// 004d254c  8bce                 mov ecx, esi
// 004d254e  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004d2556  e8e5f3ffff           call 0x4d1940
// 004d255b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004d255f  5e                   pop esi
// 004d2560  64890d00000000       mov dword ptr fs:[0], ecx
// 004d2567  83c410               add esp, 0x10
// 004d256a  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$RangeList@I@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
