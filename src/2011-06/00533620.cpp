// from server: 100% by auto
// roc 2011-06 00533620  unit: seg_00530000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00533620
//
// 00533620  6aff                 push -1
// 00533622  6848e69d00           push 0x9de648
// 00533627  64a100000000         mov eax, dword ptr fs:[0]
// 0053362d  50                   push eax
// 0053362e  64892500000000       mov dword ptr fs:[0], esp
// 00533635  51                   push ecx
// 00533636  56                   push esi
// 00533637  8bf1                 mov esi, ecx
// 00533639  89742404             mov dword ptr [esp + 4], esi
// 0053363d  8b4608               mov eax, dword ptr [esi + 8]
// 00533640  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00533648  85c0                 test eax, eax
// 0053364a  7440                 je 0x53368c
// 0053364c  3d00020000           cmp eax, 0x200
// 00533651  7632                 jbe 0x533685
// 00533653  8b06                 mov eax, dword ptr [esi]
// 00533655  85c0                 test eax, eax
// 00533657  741f                 je 0x533678
// 00533659  8b48fc               mov ecx, dword ptr [eax - 4]
// 0053365c  57                   push edi
// 0053365d  8d78fc               lea edi, [eax - 4]
// 00533660  6840b68600           push 0x86b640
// 00533665  51                   push ecx
// 00533666  6a08                 push 8
// 00533668  50                   push eax
// 00533669  e86a7b2d00           call 0x80b1d8
// 0053366e  57                   push edi
// 0053366f  e8906c2d00           call 0x80a304
// 00533674  83c404               add esp, 4
// 00533677  5f                   pop edi
// 00533678  c7460800000000       mov dword ptr [esi + 8], 0
// 0053367f  c70600000000         mov dword ptr [esi], 0
// 00533685  c7460400000000       mov dword ptr [esi + 4], 0
// 0053368c  8bce                 mov ecx, esi
// 0053368e  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00533696  e885eaffff           call 0x532120
// 0053369b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0053369f  5e                   pop esi
// 005336a0  64890d00000000       mov dword ptr fs:[0], ecx
// 005336a7  83c410               add esp, 0x10
// 005336aa  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$RangeList@I@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
