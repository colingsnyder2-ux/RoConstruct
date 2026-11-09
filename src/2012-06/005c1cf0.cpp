// roc 2012-06 005c1cf0  unit: RakNet::RakPeer  size: 289 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c1cf0
//
// 005c1cf0  64a100000000         mov eax, dword ptr fs:[0]
// 005c1cf6  6aff                 push -1
// 005c1cf8  68d82bab00           push 0xab2bd8
// 005c1cfd  50                   push eax
// 005c1cfe  64892500000000       mov dword ptr fs:[0], esp
// 005c1d05  53                   push ebx
// 005c1d06  56                   push esi
// 005c1d07  57                   push edi
// 005c1d08  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 005c1d0c  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005c1d14  85db                 test ebx, ebx
// 005c1d16  0f849c000000         je 0x5c1db8
// 005c1d1c  8a4104               mov al, byte ptr [ecx + 4]
// 005c1d1f  84c0                 test al, al
// 005c1d21  0f8591000000         jne 0x5c1db8
// 005c1d27  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005c1d2b  85ff                 test edi, edi
// 005c1d2d  0f8485000000         je 0x5c1db8
// 005c1d33  8b542428             mov edx, dword ptr [esp + 0x28]
// 005c1d37  81faff000000         cmp edx, 0xff
// 005c1d3d  7e05                 jle 0x5c1d44
// 005c1d3f  baff000000           mov edx, 0xff
// 005c1d44  8b742424             mov esi, dword ptr [esp + 0x24]
// 005c1d48  85f6                 test esi, esi
// 005c1d4a  7502                 jne 0x5c1d4e
// 005c1d4c  33d2                 xor edx, edx
// 005c1d4e  83ec08               sub esp, 8
// 005c1d51  8bc4                 mov eax, esp
// 005c1d53  8938                 mov dword ptr [eax], edi
// 005c1d55  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 005c1d59  897804               mov dword ptr [eax + 4], edi
// 005c1d5c  8b442438             mov eax, dword ptr [esp + 0x38]
// 005c1d60  89642424             mov dword ptr [esp + 0x24], esp
// 005c1d64  85c0                 test eax, eax
// 005c1d66  7402                 je 0x5c1d6a
// 005c1d68  ff00                 inc dword ptr [eax]
// 005c1d6a  8b442448             mov eax, dword ptr [esp + 0x48]
// 005c1d6e  50                   push eax
// 005c1d6f  8b442448             mov eax, dword ptr [esp + 0x48]
// 005c1d73  50                   push eax
// 005c1d74  8b442448             mov eax, dword ptr [esp + 0x48]
// 005c1d78  50                   push eax
// 005c1d79  8b442448             mov eax, dword ptr [esp + 0x48]
// 005c1d7d  6a00                 push 0
// 005c1d7f  6a00                 push 0
// 005c1d81  50                   push eax
// 005c1d82  52                   push edx
// 005c1d83  8b542444             mov edx, dword ptr [esp + 0x44]
// 005c1d87  56                   push esi
// 005c1d88  52                   push edx
// 005c1d89  53                   push ebx
// 005c1d8a  e811f9ffff           call 0x5c16a0
// 005c1d8f  8d4c242c             lea ecx, [esp + 0x2c]
// 005c1d93  8bf0                 mov esi, eax
// 005c1d95  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005c1d9d  e83ed0ffff           call 0x5bede0
// 005c1da2  8bc6                 mov eax, esi
// 005c1da4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c1da8  64890d00000000       mov dword ptr fs:[0], ecx
// 005c1daf  5f                   pop edi
// 005c1db0  5e                   pop esi
// 005c1db1  5b                   pop ebx
// 005c1db2  83c40c               add esp, 0xc
// 005c1db5  c22800               ret 0x28
// 005c1db8  8b442430             mov eax, dword ptr [esp + 0x30]
// 005c1dbc  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005c1dc4  85c0                 test eax, eax
// 005c1dc6  7430                 je 0x5c1df8
// 005c1dc8  ff08                 dec dword ptr [eax]
// 005c1dca  833800               cmp dword ptr [eax], 0
// 005c1dcd  7529                 jne 0x5c1df8
// 005c1dcf  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005c1dd3  8bf1                 mov esi, ecx
// 005c1dd5  85c9                 test ecx, ecx
// 005c1dd7  740e                 je 0x5c1de7
// 005c1dd9  e802760000           call 0x5c93e0
// 005c1dde  56                   push esi
// 005c1ddf  e830033c00           call 0x982114
// 005c1de4  83c404               add esp, 4
// 005c1de7  8b442430             mov eax, dword ptr [esp + 0x30]
// 005c1deb  85c0                 test eax, eax
// 005c1ded  7409                 je 0x5c1df8
// 005c1def  50                   push eax
// 005c1df0  e81f033c00           call 0x982114
// 005c1df5  83c404               add esp, 4
// 005c1df8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c1dfc  5f                   pop edi
// 005c1dfd  5e                   pop esi
// 005c1dfe  b801000000           mov eax, 1
// 005c1e03  64890d00000000       mov dword ptr fs:[0], ecx
// 005c1e0a  5b                   pop ebx
// 005c1e0b  83c40c               add esp, 0xc
// 005c1e0e  c22800               ret 0x28
// copied from an identical function in another client (function ?ConnectWithSocket@RakPeer@RakNet@@UAE?AW4ConnectionAttemptResult@2@PBDG0HV?$RakNetSmartPtr@URakNetSocket@RakNet@@@2@PAUPublicKey@2@III@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp