// roc 2009-12 007d2a30  unit: seg_007d0000  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2a30
//
// 007d2a30  83ec1c               sub esp, 0x1c
// 007d2a33  53                   push ebx
// 007d2a34  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 007d2a37  8bc7                 mov eax, edi
// 007d2a39  8bce                 mov ecx, esi
// 007d2a3b  895c2404             mov dword ptr [esp + 4], ebx
// 007d2a3f  e87cffffff           call 0x7d29c0
// 007d2a44  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d2a47  83e828               sub eax, 0x28
// 007d2a4a  3df6000000           cmp eax, 0xf6
// 007d2a4f  0f87ac010000         ja 0x7d2c01
// 007d2a55  55                   push ebp
// 007d2a56  eb08                 jmp 0x7d2a60
// 007d2a58  8da42400000000       lea esp, [esp]
// 007d2a5f  90                   nop 
// 007d2a60  0fb6801c2c7d00       movzx eax, byte ptr [eax + 0x7d2c1c]
// 007d2a67  ff2485082c7d00       jmp dword ptr [eax*4 + 0x7d2c08]
// 007d2a6e  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 007d2a71  57                   push edi
// 007d2a72  55                   push ebp
// 007d2a73  e818a20000           call 0x7dcc90
// 007d2a78  56                   push esi
// 007d2a79  e8b23c0000           call 0x7d6730
// 007d2a7e  83c40c               add esp, 0xc
// 007d2a81  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d2a88  7424                 je 0x7d2aae
// 007d2a8a  681d010000           push 0x11d
// 007d2a8f  56                   push esi
// 007d2a90  e8ab270000           call 0x7d5240
// 007d2a95  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007d2a98  50                   push eax
// 007d2a99  68d0ed9e00           push 0x9eedd0
// 007d2a9e  51                   push ecx
// 007d2a9f  e8dc7afcff           call 0x79a580
// 007d2aa4  50                   push eax
// 007d2aa5  56                   push esi
// 007d2aa6  e895280000           call 0x7d5340
// 007d2aab  83c41c               add esp, 0x1c
// 007d2aae  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007d2ab1  56                   push esi
// 007d2ab2  e8793c0000           call 0x7d6730
// 007d2ab7  8b5630               mov edx, dword ptr [esi + 0x30]
// 007d2aba  53                   push ebx
// 007d2abb  52                   push edx
// 007d2abc  e8df970000           call 0x7dc2a0
// 007d2ac1  89442420             mov dword ptr [esp + 0x20], eax
// 007d2ac5  8d442418             lea eax, [esp + 0x18]
// 007d2ac9  50                   push eax
// 007d2aca  83c9ff               or ecx, 0xffffffff
// 007d2acd  57                   push edi
// 007d2ace  55                   push ebp
// 007d2acf  894c2434             mov dword ptr [esp + 0x34], ecx
// 007d2ad3  894c2438             mov dword ptr [esp + 0x38], ecx
// 007d2ad7  c744242404000000     mov dword ptr [esp + 0x24], 4
// 007d2adf  e83ca70000           call 0x7dd220
// 007d2ae4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007d2ae8  83c418               add esp, 0x18
// 007d2aeb  e9ff000000           jmp 0x7d2bef
// 007d2af0  57                   push edi
// 007d2af1  53                   push ebx
// 007d2af2  e899a10000           call 0x7dcc90
// 007d2af7  56                   push esi
// 007d2af8  e8333c0000           call 0x7d6730
// 007d2afd  6a00                 push 0
// 007d2aff  8d4c241c             lea ecx, [esp + 0x1c]
// 007d2b03  51                   push ecx
// 007d2b04  56                   push esi
// 007d2b05  e8a6050000           call 0x7d30b0
// 007d2b0a  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d2b0d  8d542424             lea edx, [esp + 0x24]
// 007d2b11  52                   push edx
// 007d2b12  50                   push eax
// 007d2b13  e8c8a10000           call 0x7dcce0
// 007d2b18  83c420               add esp, 0x20
// 007d2b1b  837e105d             cmp dword ptr [esi + 0x10], 0x5d
// 007d2b1f  7421                 je 0x7d2b42
// 007d2b21  6a5d                 push 0x5d
// 007d2b23  56                   push esi
// 007d2b24  e817270000           call 0x7d5240
// 007d2b29  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007d2b2c  50                   push eax
// 007d2b2d  68d0ed9e00           push 0x9eedd0
// 007d2b32  51                   push ecx
// 007d2b33  e8487afcff           call 0x79a580
// 007d2b38  50                   push eax
// 007d2b39  56                   push esi
// 007d2b3a  e801280000           call 0x7d5340
// 007d2b3f  83c41c               add esp, 0x1c
// 007d2b42  56                   push esi
// 007d2b43  e8e83b0000           call 0x7d6730
// 007d2b48  8d542410             lea edx, [esp + 0x10]
// 007d2b4c  52                   push edx
// 007d2b4d  57                   push edi
// 007d2b4e  53                   push ebx
// 007d2b4f  e8cca60000           call 0x7dd220
// 007d2b54  83c410               add esp, 0x10
// 007d2b57  e993000000           jmp 0x7d2bef
// 007d2b5c  56                   push esi
// 007d2b5d  e8ce3b0000           call 0x7d6730
// 007d2b62  83c404               add esp, 4
// 007d2b65  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 007d2b6c  7424                 je 0x7d2b92
// 007d2b6e  681d010000           push 0x11d
// 007d2b73  56                   push esi
// 007d2b74  e8c7260000           call 0x7d5240
// 007d2b79  50                   push eax
// 007d2b7a  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d2b7d  68d0ed9e00           push 0x9eedd0
// 007d2b82  50                   push eax
// 007d2b83  e8f879fcff           call 0x79a580
// 007d2b88  50                   push eax
// 007d2b89  56                   push esi
// 007d2b8a  e8b1270000           call 0x7d5340
// 007d2b8f  83c41c               add esp, 0x1c
// 007d2b92  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007d2b95  56                   push esi
// 007d2b96  e8953b0000           call 0x7d6730
// 007d2b9b  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 007d2b9e  53                   push ebx
// 007d2b9f  51                   push ecx
// 007d2ba0  e8fb960000           call 0x7dc2a0
// 007d2ba5  8d542418             lea edx, [esp + 0x18]
// 007d2ba9  52                   push edx
// 007d2baa  89442424             mov dword ptr [esp + 0x24], eax
// 007d2bae  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d2bb2  83c9ff               or ecx, 0xffffffff
// 007d2bb5  57                   push edi
// 007d2bb6  50                   push eax
// 007d2bb7  894c2434             mov dword ptr [esp + 0x34], ecx
// 007d2bbb  894c2438             mov dword ptr [esp + 0x38], ecx
// 007d2bbf  c744242404000000     mov dword ptr [esp + 0x24], 4
// 007d2bc7  e824a30000           call 0x7dcef0
// 007d2bcc  57                   push edi
// 007d2bcd  8bc6                 mov eax, esi
// 007d2bcf  e8acfcffff           call 0x7d2880
// 007d2bd4  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007d2bd8  83c41c               add esp, 0x1c
// 007d2bdb  eb12                 jmp 0x7d2bef
// 007d2bdd  57                   push edi
// 007d2bde  53                   push ebx
// 007d2bdf  e82ca00000           call 0x7dcc10
// 007d2be4  57                   push edi
// 007d2be5  8bc6                 mov eax, esi
// 007d2be7  e894fcffff           call 0x7d2880
// 007d2bec  83c40c               add esp, 0xc
// 007d2bef  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d2bf2  83e828               sub eax, 0x28
// 007d2bf5  3df6000000           cmp eax, 0xf6
// 007d2bfa  0f8660feffff         jbe 0x7d2a60
// 007d2c00  5d                   pop ebp
// 007d2c01  5b                   pop ebx
// 007d2c02  83c41c               add esp, 0x1c
// 007d2c05  c3                   ret 
// 007d2c06  8bff                 mov edi, edi
// library lua-5.1/lparser.c (function _primaryexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
