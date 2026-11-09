// from server: 100% by auto
// roc 2009-12 00566ff0  unit: RakPeer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00566ff0
//
// 00566ff0  8b5104               mov edx, dword ptr [ecx + 4]
// 00566ff3  8b442404             mov eax, dword ptr [esp + 4]
// 00566ff7  3bc2                 cmp eax, edx
// 00566ff9  731e                 jae 0x567019
// 00566ffb  4a                   dec edx
// 00566ffc  3bc2                 cmp eax, edx
// 00566ffe  7316                 jae 0x567016
// 00567000  56                   push esi
// 00567001  8b11                 mov edx, dword ptr [ecx]
// 00567003  8b748204             mov esi, dword ptr [edx + eax*4 + 4]
// 00567007  8d1482               lea edx, [edx + eax*4]
// 0056700a  8932                 mov dword ptr [edx], esi
// 0056700c  8b5104               mov edx, dword ptr [ecx + 4]
// 0056700f  40                   inc eax
// 00567010  4a                   dec edx
// 00567011  3bc2                 cmp eax, edx
// 00567013  72ec                 jb 0x567001
// 00567015  5e                   pop esi
// 00567016  ff4904               dec dword ptr [ecx + 4]
// 00567019  c20400               ret 4
// library raknet-4.081/CloudServer.cpp (function ?RemoveAtIndex@?$List@PAVCloudServerQueryFilter@RakNet@@@DataStructures@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 CloudServer.cpp
