// from server: 100% by auto
// roc 2011-06 00531f80  unit: seg_00530000  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00531f80
//
// 00531f80  56                   push esi
// 00531f81  8bf1                 mov esi, ecx
// 00531f83  8b4608               mov eax, dword ptr [esi + 8]
// 00531f86  85c0                 test eax, eax
// 00531f88  7440                 je 0x531fca
// 00531f8a  3d00020000           cmp eax, 0x200
// 00531f8f  7632                 jbe 0x531fc3
// 00531f91  8b06                 mov eax, dword ptr [esi]
// 00531f93  85c0                 test eax, eax
// 00531f95  741f                 je 0x531fb6
// 00531f97  8b48fc               mov ecx, dword ptr [eax - 4]
// 00531f9a  57                   push edi
// 00531f9b  8d78fc               lea edi, [eax - 4]
// 00531f9e  6840b68600           push 0x86b640
// 00531fa3  51                   push ecx
// 00531fa4  6a08                 push 8
// 00531fa6  50                   push eax
// 00531fa7  e82c922d00           call 0x80b1d8
// 00531fac  57                   push edi
// 00531fad  e852832d00           call 0x80a304
// 00531fb2  83c404               add esp, 4
// 00531fb5  5f                   pop edi
// 00531fb6  c7460800000000       mov dword ptr [esi + 8], 0
// 00531fbd  c70600000000         mov dword ptr [esi], 0
// 00531fc3  c7460400000000       mov dword ptr [esi + 4], 0
// 00531fca  5e                   pop esi
// 00531fcb  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Clear@?$OrderedList@IU?$RangeNode@I@DataStructures@@$1??$RangeNodeComp@I@2@YAHABIABU12@@Z@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
