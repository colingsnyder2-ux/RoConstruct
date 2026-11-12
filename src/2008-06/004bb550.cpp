// from server: 100% by auto
// roc 2008-06 004bb550  unit: RakPeerInterface  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb550
//
// 004bb550  56                   push esi
// 004bb551  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004bb555  57                   push edi
// 004bb556  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004bb55a  56                   push esi
// 004bb55b  8bcf                 mov ecx, edi
// 004bb55d  e81ee3feff           call 0x4a9880
// 004bb562  84c0                 test al, al
// 004bb564  7406                 je 0x4bb56c
// 004bb566  5f                   pop edi
// 004bb567  83c8ff               or eax, 0xffffffff
// 004bb56a  5e                   pop esi
// 004bb56b  c3                   ret 
// 004bb56c  56                   push esi
// 004bb56d  8bcf                 mov ecx, edi
// 004bb56f  e8ace2feff           call 0x4a9820
// 004bb574  33c9                 xor ecx, ecx
// 004bb576  84c0                 test al, al
// 004bb578  0f94c1               sete cl
// 004bb57b  5f                   pop edi
// 004bb57c  5e                   pop esi
// 004bb57d  8bc1                 mov eax, ecx
// 004bb57f  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?SystemAddressAndIndexComp@@YAHABUSystemAddress@@ABUSystemAddressAndIndex@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
