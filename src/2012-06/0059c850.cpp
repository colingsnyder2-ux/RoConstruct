// roc 2012-06 0059c850  unit: VAuthoringSettings::?$FactoryProduct  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0059c850
//
// 0059c850  8b4104               mov eax, dword ptr [ecx + 4]
// 0059c853  8b542404             mov edx, dword ptr [esp + 4]
// 0059c857  3bd0                 cmp edx, eax
// 0059c859  7324                 jae 0x59c87f
// 0059c85b  48                   dec eax
// 0059c85c  3bd0                 cmp edx, eax
// 0059c85e  731c                 jae 0x59c87c
// 0059c860  56                   push esi
// 0059c861  8b01                 mov eax, dword ptr [ecx]
// 0059c863  8b74d008             mov esi, dword ptr [eax + edx*8 + 8]
// 0059c867  8d04d0               lea eax, [eax + edx*8]
// 0059c86a  8930                 mov dword ptr [eax], esi
// 0059c86c  8b700c               mov esi, dword ptr [eax + 0xc]
// 0059c86f  897004               mov dword ptr [eax + 4], esi
// 0059c872  8b4104               mov eax, dword ptr [ecx + 4]
// 0059c875  42                   inc edx
// 0059c876  48                   dec eax
// 0059c877  3bd0                 cmp edx, eax
// 0059c879  72e6                 jb 0x59c861
// 0059c87b  5e                   pop esi
// 0059c87c  ff4904               dec dword ptr [ecx + 4]
// 0059c87f  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?RemoveAtIndex@?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
