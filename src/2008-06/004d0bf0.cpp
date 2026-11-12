// from server: 100% by auto
// roc 2008-06 004d0bf0  unit: RBX::Network::PhysicsSender  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d0bf0
//
// 004d0bf0  8b4104               mov eax, dword ptr [ecx + 4]
// 004d0bf3  8b542404             mov edx, dword ptr [esp + 4]
// 004d0bf7  3bd0                 cmp edx, eax
// 004d0bf9  7324                 jae 0x4d0c1f
// 004d0bfb  48                   dec eax
// 004d0bfc  3bd0                 cmp edx, eax
// 004d0bfe  731c                 jae 0x4d0c1c
// 004d0c00  56                   push esi
// 004d0c01  8b01                 mov eax, dword ptr [ecx]
// 004d0c03  8b74d008             mov esi, dword ptr [eax + edx*8 + 8]
// 004d0c07  8d04d0               lea eax, [eax + edx*8]
// 004d0c0a  8930                 mov dword ptr [eax], esi
// 004d0c0c  8b700c               mov esi, dword ptr [eax + 0xc]
// 004d0c0f  897004               mov dword ptr [eax + 4], esi
// 004d0c12  8b4104               mov eax, dword ptr [ecx + 4]
// 004d0c15  42                   inc edx
// 004d0c16  48                   dec eax
// 004d0c17  3bd0                 cmp edx, eax
// 004d0c19  72e6                 jb 0x4d0c01
// 004d0c1b  5e                   pop esi
// 004d0c1c  ff4904               dec dword ptr [ecx + 4]
// 004d0c1f  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?RemoveAtIndex@?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
