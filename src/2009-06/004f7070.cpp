// from server: 100% by auto
// roc 2009-06 004f7070  unit: RBX::Network::ClientReplicator  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f7070
//
// 004f7070  8b4104               mov eax, dword ptr [ecx + 4]
// 004f7073  8b542404             mov edx, dword ptr [esp + 4]
// 004f7077  3bd0                 cmp edx, eax
// 004f7079  7324                 jae 0x4f709f
// 004f707b  48                   dec eax
// 004f707c  3bd0                 cmp edx, eax
// 004f707e  731c                 jae 0x4f709c
// 004f7080  56                   push esi
// 004f7081  8b01                 mov eax, dword ptr [ecx]
// 004f7083  8b74d008             mov esi, dword ptr [eax + edx*8 + 8]
// 004f7087  8d04d0               lea eax, [eax + edx*8]
// 004f708a  8930                 mov dword ptr [eax], esi
// 004f708c  8b700c               mov esi, dword ptr [eax + 0xc]
// 004f708f  897004               mov dword ptr [eax + 4], esi
// 004f7092  8b4104               mov eax, dword ptr [ecx + 4]
// 004f7095  42                   inc edx
// 004f7096  48                   dec eax
// 004f7097  3bd0                 cmp edx, eax
// 004f7099  72e6                 jb 0x4f7081
// 004f709b  5e                   pop esi
// 004f709c  ff4904               dec dword ptr [ecx + 4]
// 004f709f  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?RemoveAtIndex@?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
