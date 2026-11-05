// roc 2012-06 005bb350  unit: RakNet::RakPeer  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb350
//
// 005bb350  83b92c02000000       cmp dword ptr [ecx + 0x22c], 0
// 005bb357  743e                 je 0x5bb397
// 005bb359  8a4104               mov al, byte ptr [ecx + 4]
// 005bb35c  3c01                 cmp al, 1
// 005bb35e  7437                 je 0x5bb397
// 005bb360  8b9134020000         mov edx, dword ptr [ecx + 0x234]
// 005bb366  33c0                 xor eax, eax
// 005bb368  85d2                 test edx, edx
// 005bb36a  762d                 jbe 0x5bb399
// 005bb36c  56                   push esi
// 005bb36d  8bb130020000         mov esi, dword ptr [ecx + 0x230]
// 005bb373  8b0e                 mov ecx, dword ptr [esi]
// 005bb375  803900               cmp byte ptr [ecx], 0
// 005bb378  7413                 je 0x5bb38d
// 005bb37a  83b90012000007       cmp dword ptr [ecx + 0x1200], 7
// 005bb381  750a                 jne 0x5bb38d
// 005bb383  80b96011000000       cmp byte ptr [ecx + 0x1160], 0
// 005bb38a  7501                 jne 0x5bb38d
// 005bb38c  40                   inc eax
// 005bb38d  83c604               add esi, 4
// 005bb390  83ea01               sub edx, 1
// 005bb393  75de                 jne 0x5bb373
// 005bb395  5e                   pop esi
// 005bb396  c3                   ret 
// 005bb397  33c0                 xor eax, eax
// 005bb399  c3                   ret 
// copied from an identical function in another client (function ?GetNumberOfRemoteInitiatedConnections@RakPeer@RakNet@@IBEGXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp