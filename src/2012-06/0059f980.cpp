// roc 2012-06 0059f980  unit: seg_00590000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059f980
//
// 0059f980  6aff                 push -1
// 0059f982  68e816ab00           push 0xab16e8
// 0059f987  64a100000000         mov eax, dword ptr fs:[0]
// 0059f98d  50                   push eax
// 0059f98e  64892500000000       mov dword ptr fs:[0], esp
// 0059f995  51                   push ecx
// 0059f996  56                   push esi
// 0059f997  8bf1                 mov esi, ecx
// 0059f999  89742404             mov dword ptr [esp + 4], esi
// 0059f99d  8b4608               mov eax, dword ptr [esi + 8]
// 0059f9a0  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0059f9a8  85c0                 test eax, eax
// 0059f9aa  7440                 je 0x59f9ec
// 0059f9ac  3d00020000           cmp eax, 0x200
// 0059f9b1  7632                 jbe 0x59f9e5
// 0059f9b3  8b06                 mov eax, dword ptr [esi]
// 0059f9b5  85c0                 test eax, eax
// 0059f9b7  741f                 je 0x59f9d8
// 0059f9b9  8b48fc               mov ecx, dword ptr [eax - 4]
// 0059f9bc  57                   push edi
// 0059f9bd  8d78fc               lea edi, [eax - 4]
// 0059f9c0  6890a75900           push 0x59a790
// 0059f9c5  51                   push ecx
// 0059f9c6  6a08                 push 8
// 0059f9c8  50                   push eax
// 0059f9c9  e8a2383e00           call 0x983270
// 0059f9ce  57                   push edi
// 0059f9cf  e8e6293e00           call 0x9823ba
// 0059f9d4  83c404               add esp, 4
// 0059f9d7  5f                   pop edi
// 0059f9d8  c7460800000000       mov dword ptr [esi + 8], 0
// 0059f9df  c70600000000         mov dword ptr [esi], 0
// 0059f9e5  c7460400000000       mov dword ptr [esi + 4], 0
// 0059f9ec  8bce                 mov ecx, esi
// 0059f9ee  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0059f9f6  e815f9ffff           call 0x59f310
// 0059f9fb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0059f9ff  5e                   pop esi
// 0059fa00  64890d00000000       mov dword ptr fs:[0], ecx
// 0059fa07  83c410               add esp, 0x10
// 0059fa0a  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ??1?$RangeList@I@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
