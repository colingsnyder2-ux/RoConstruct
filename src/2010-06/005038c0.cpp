// from server: 100% by auto
// roc 2010-06 005038c0  unit: RBX::Network::ClientReplicator  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005038c0
//
// 005038c0  8b4104               mov eax, dword ptr [ecx + 4]
// 005038c3  8b542404             mov edx, dword ptr [esp + 4]
// 005038c7  3bd0                 cmp edx, eax
// 005038c9  7324                 jae 0x5038ef
// 005038cb  48                   dec eax
// 005038cc  3bd0                 cmp edx, eax
// 005038ce  731c                 jae 0x5038ec
// 005038d0  56                   push esi
// 005038d1  8b01                 mov eax, dword ptr [ecx]
// 005038d3  8b74d008             mov esi, dword ptr [eax + edx*8 + 8]
// 005038d7  8d04d0               lea eax, [eax + edx*8]
// 005038da  8930                 mov dword ptr [eax], esi
// 005038dc  8b700c               mov esi, dword ptr [eax + 0xc]
// 005038df  897004               mov dword ptr [eax + 4], esi
// 005038e2  8b4104               mov eax, dword ptr [ecx + 4]
// 005038e5  42                   inc edx
// 005038e6  48                   dec eax
// 005038e7  3bd0                 cmp edx, eax
// 005038e9  72e6                 jb 0x5038d1
// 005038eb  5e                   pop esi
// 005038ec  ff4904               dec dword ptr [ecx + 4]
// 005038ef  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?RemoveAtIndex@?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
