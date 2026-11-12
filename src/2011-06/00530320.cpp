// from server: 100% by auto
// roc 2011-06 00530320  unit: RBX::Network::ProfiledRakPeer  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00530320
//
// 00530320  8b4104               mov eax, dword ptr [ecx + 4]
// 00530323  8b542404             mov edx, dword ptr [esp + 4]
// 00530327  3bd0                 cmp edx, eax
// 00530329  7324                 jae 0x53034f
// 0053032b  48                   dec eax
// 0053032c  3bd0                 cmp edx, eax
// 0053032e  731c                 jae 0x53034c
// 00530330  56                   push esi
// 00530331  8b01                 mov eax, dword ptr [ecx]
// 00530333  8b74d008             mov esi, dword ptr [eax + edx*8 + 8]
// 00530337  8d04d0               lea eax, [eax + edx*8]
// 0053033a  8930                 mov dword ptr [eax], esi
// 0053033c  8b700c               mov esi, dword ptr [eax + 0xc]
// 0053033f  897004               mov dword ptr [eax + 4], esi
// 00530342  8b4104               mov eax, dword ptr [ecx + 4]
// 00530345  42                   inc edx
// 00530346  48                   dec eax
// 00530347  3bd0                 cmp edx, eax
// 00530349  72e6                 jb 0x530331
// 0053034b  5e                   pop esi
// 0053034c  ff4904               dec dword ptr [ecx + 4]
// 0053034f  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?RemoveAtIndex@?$List@U?$RangeNode@I@DataStructures@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
