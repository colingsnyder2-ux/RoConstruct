// roc 2012-06 005c03c0  unit: RakNet::RakPeer  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c03c0
//
// 005c03c0  64a100000000         mov eax, dword ptr fs:[0]
// 005c03c6  6aff                 push -1
// 005c03c8  684b16ab00           push 0xab164b
// 005c03cd  50                   push eax
// 005c03ce  64892500000000       mov dword ptr fs:[0], esp
// 005c03d5  56                   push esi
// 005c03d6  8b742414             mov esi, dword ptr [esp + 0x14]
// 005c03da  57                   push edi
// 005c03db  85f6                 test esi, esi
// 005c03dd  7465                 je 0x5c0444
// 005c03df  33c9                 xor ecx, ecx
// 005c03e1  8bc6                 mov eax, esi
// 005c03e3  ba08120000           mov edx, 0x1208
// 005c03e8  f7e2                 mul edx
// 005c03ea  0f90c1               seto cl
// 005c03ed  f7d9                 neg ecx
// 005c03ef  0bc8                 or ecx, eax
// 005c03f1  33c0                 xor eax, eax
// 005c03f3  83c104               add ecx, 4
// 005c03f6  0f92c0               setb al
// 005c03f9  f7d8                 neg eax
// 005c03fb  0bc1                 or eax, ecx
// 005c03fd  50                   push eax
// 005c03fe  e8ed1f3c00           call 0x9823f0
// 005c0403  83c404               add esp, 4
// 005c0406  89442418             mov dword ptr [esp + 0x18], eax
// 005c040a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005c0412  85c0                 test eax, eax
// 005c0414  742e                 je 0x5c0444
// 005c0416  6860f25b00           push 0x5bf260
// 005c041b  68d0f15b00           push 0x5bf1d0
// 005c0420  56                   push esi
// 005c0421  8d7804               lea edi, [eax + 4]
// 005c0424  6808120000           push 0x1208
// 005c0429  57                   push edi
// 005c042a  8930                 mov dword ptr [eax], esi
// 005c042c  e8492f3c00           call 0x98337a
// 005c0431  8bc7                 mov eax, edi
// 005c0433  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c0437  64890d00000000       mov dword ptr fs:[0], ecx
// 005c043e  5f                   pop edi
// 005c043f  5e                   pop esi
// 005c0440  83c40c               add esp, 0xc
// 005c0443  c3                   ret 
// 005c0444  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c0448  5f                   pop edi
// 005c0449  33c0                 xor eax, eax
// 005c044b  64890d00000000       mov dword ptr fs:[0], ecx
// 005c0452  5e                   pop esi
// 005c0453  83c40c               add esp, 0xc
// 005c0456  c3                   ret 
// copied from an identical function in another client (function ??$OP_NEW_ARRAY@URemoteSystemStruct@RakPeer@RakNet@@@RakNet@@YAPAURemoteSystemStruct@RakPeer@0@HPBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp