// from server: 100% by auto
// roc 2008-06 004c4d50  unit: ProfiledRakPeer  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c4d50
//
// 004c4d50  6aff                 push -1
// 004c4d52  6875947c00           push 0x7c9475
// 004c4d57  64a100000000         mov eax, dword ptr fs:[0]
// 004c4d5d  50                   push eax
// 004c4d5e  64892500000000       mov dword ptr fs:[0], esp
// 004c4d65  51                   push ecx
// 004c4d66  56                   push esi
// 004c4d67  8bf1                 mov esi, ecx
// 004c4d69  89742404             mov dword ptr [esp + 4], esi
// 004c4d6d  c706ac648200         mov dword ptr [esi], 0x8264ac
// 004c4d73  c74424100d000000     mov dword ptr [esp + 0x10], 0xd
// 004c4d7b  e8e083ffff           call 0x4bd160
// 004c4d80  6a00                 push 0
// 004c4d82  6a00                 push 0
// 004c4d84  8bce                 mov ecx, esi
// 004c4d86  e805f0ffff           call 0x4c3d90
// 004c4d8b  e8405cffff           call 0x4ba9d0
// 004c4d90  e80bf50000           call 0x4d42a0
// 004c4d95  8b8664020000         mov eax, dword ptr [esi + 0x264]
// 004c4d9b  50                   push eax
// 004c4d9c  ff1534228000         call dword ptr [0x802234]
// 004c4da2  83befc08000000       cmp dword ptr [esi + 0x8fc], 0
// 004c4da9  c64424100c           mov byte ptr [esp + 0x10], 0xc
// 004c4dae  760f                 jbe 0x4c4dbf
// 004c4db0  8b86f0080000         mov eax, dword ptr [esi + 0x8f0]
// 004c4db6  50                   push eax
// 004c4db7  e8beb81d00           call 0x6a067a
// 004c4dbc  83c404               add esp, 4
// 004c4dbf  8d8ed8080000         lea ecx, [esi + 0x8d8]
// 004c4dc5  c64424100b           mov byte ptr [esp + 0x10], 0xb
// 004c4dca  e8b177ffff           call 0x4bc580
// 004c4dcf  8d8e44070000         lea ecx, [esi + 0x744]
// 004c4dd5  e8868affff           call 0x4bd860
// 004c4dda  8d8efc060000         lea ecx, [esi + 0x6fc]
// 004c4de0  c644241009           mov byte ptr [esp + 0x10], 9
// 004c4de5  e836f10000           call 0x4d3f20
// 004c4dea  8d8ee4060000         lea ecx, [esi + 0x6e4]
// 004c4df0  c644241008           mov byte ptr [esp + 0x10], 8
// 004c4df5  e80676ffff           call 0x4bc400
// 004c4dfa  8d8eb4020000         lea ecx, [esi + 0x2b4]
// 004c4e00  c644241007           mov byte ptr [esp + 0x10], 7
// 004c4e05  e83674ffff           call 0x4bc240
// 004c4e0a  83beb002000000       cmp dword ptr [esi + 0x2b0], 0
// 004c4e11  c644241006           mov byte ptr [esp + 0x10], 6
// 004c4e16  760f                 jbe 0x4c4e27
// 004c4e18  8b86a8020000         mov eax, dword ptr [esi + 0x2a8]
// 004c4e1e  50                   push eax
// 004c4e1f  e856b81d00           call 0x6a067a
// 004c4e24  83c404               add esp, 4
// 004c4e27  83bea402000000       cmp dword ptr [esi + 0x2a4], 0
// 004c4e2e  c644241005           mov byte ptr [esp + 0x10], 5
// 004c4e33  760f                 jbe 0x4c4e44
// 004c4e35  8b869c020000         mov eax, dword ptr [esi + 0x29c]
// 004c4e3b  50                   push eax
// 004c4e3c  e839b81d00           call 0x6a067a
// 004c4e41  83c404               add esp, 4
// 004c4e44  8d8e84020000         lea ecx, [esi + 0x284]
// 004c4e4a  c644241004           mov byte ptr [esp + 0x10], 4
// 004c4e4f  e8ecdaf6ff           call 0x432940
// 004c4e54  8d8e6c020000         lea ecx, [esi + 0x26c]
// 004c4e5a  c644241003           mov byte ptr [esp + 0x10], 3
// 004c4e5f  e8dcdaf6ff           call 0x432940
// 004c4e64  6840294300           push 0x432940
// 004c4e69  6a01                 push 1
// 004c4e6b  6a18                 push 0x18
// 004c4e6d  8d8e3c020000         lea ecx, [esi + 0x23c]
// 004c4e73  51                   push ecx
// 004c4e74  c644242002           mov byte ptr [esp + 0x20], 2
// 004c4e79  e8ddc71d00           call 0x6a165b
// 004c4e7e  8d8e30020000         lea ecx, [esi + 0x230]
// 004c4e84  c644241001           mov byte ptr [esp + 0x10], 1
// 004c4e89  e87255ffff           call 0x4ba400
// 004c4e8e  8d4e0c               lea ecx, [esi + 0xc]
// 004c4e91  c644241000           mov byte ptr [esp + 0x10], 0
// 004c4e96  e80503feff           call 0x4a51a0
// 004c4e9b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c4e9f  c70694638200         mov dword ptr [esi], 0x826394
// 004c4ea5  5e                   pop esi
// 004c4ea6  64890d00000000       mov dword ptr fs:[0], ecx
// 004c4ead  83c410               add esp, 0x10
// 004c4eb0  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??1RakPeer@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
