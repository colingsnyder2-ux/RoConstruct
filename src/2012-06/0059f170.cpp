// roc 2012-06 0059f170  unit: seg_00590000  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059f170
//
// 0059f170  56                   push esi
// 0059f171  8bf1                 mov esi, ecx
// 0059f173  8b4608               mov eax, dword ptr [esi + 8]
// 0059f176  85c0                 test eax, eax
// 0059f178  7440                 je 0x59f1ba
// 0059f17a  3d00020000           cmp eax, 0x200
// 0059f17f  7632                 jbe 0x59f1b3
// 0059f181  8b06                 mov eax, dword ptr [esi]
// 0059f183  85c0                 test eax, eax
// 0059f185  741f                 je 0x59f1a6
// 0059f187  8b48fc               mov ecx, dword ptr [eax - 4]
// 0059f18a  57                   push edi
// 0059f18b  8d78fc               lea edi, [eax - 4]
// 0059f18e  6890a75900           push 0x59a790
// 0059f193  51                   push ecx
// 0059f194  6a08                 push 8
// 0059f196  50                   push eax
// 0059f197  e8d4403e00           call 0x983270
// 0059f19c  57                   push edi
// 0059f19d  e818323e00           call 0x9823ba
// 0059f1a2  83c404               add esp, 4
// 0059f1a5  5f                   pop edi
// 0059f1a6  c7460800000000       mov dword ptr [esi + 8], 0
// 0059f1ad  c70600000000         mov dword ptr [esi], 0
// 0059f1b3  c7460400000000       mov dword ptr [esi + 4], 0
// 0059f1ba  5e                   pop esi
// 0059f1bb  c3                   ret 
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Clear@?$OrderedList@IU?$RangeNode@I@DataStructures@@$1??$RangeNodeComp@I@2@YAHABIABU12@@Z@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
