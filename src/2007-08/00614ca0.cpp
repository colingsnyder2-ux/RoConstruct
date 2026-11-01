// from server: 100% by auto
// roc 2007-08 00614ca0  unit: seg_00610000  size: 739 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00614ca0
//
// 00614ca0  83ec1c               sub esp, 0x1c
// 00614ca3  53                   push ebx
// 00614ca4  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 00614ca7  8bc7                 mov eax, edi
// 00614ca9  8bce                 mov ecx, esi
// 00614cab  895c2404             mov dword ptr [esp + 4], ebx
// 00614caf  e87cffffff           call 0x614c30
// 00614cb4  8b4610               mov eax, dword ptr [esi + 0x10]
// 00614cb7  83e828               sub eax, 0x28
// 00614cba  3df6000000           cmp eax, 0xf6
// 00614cbf  0f87ac010000         ja 0x614e71
// 00614cc5  55                   push ebp
// 00614cc6  eb08                 jmp 0x614cd0
// 00614cc8  8da42400000000       lea esp, [esp]
// 00614ccf  90                   nop 
// 00614cd0  0fb6808c4e6100       movzx eax, byte ptr [eax + 0x614e8c]
// 00614cd7  ff2485784e6100       jmp dword ptr [eax*4 + 0x614e78]
// 00614cde  8b6e30               mov ebp, dword ptr [esi + 0x30]
// 00614ce1  57                   push edi
// 00614ce2  55                   push ebp
// 00614ce3  e828470100           call 0x629410
// 00614ce8  56                   push esi
// 00614ce9  e8023d0000           call 0x6189f0
// 00614cee  83c40c               add esp, 0xc
// 00614cf1  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 00614cf8  7424                 je 0x614d1e
// 00614cfa  681d010000           push 0x11d
// 00614cff  56                   push esi
// 00614d00  e8bb270000           call 0x6174c0
// 00614d05  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00614d08  50                   push eax
// 00614d09  6870337c00           push 0x7c3370
// 00614d0e  51                   push ecx
// 00614d0f  e87ca1ffff           call 0x60ee90
// 00614d14  50                   push eax
// 00614d15  56                   push esi
// 00614d16  e8a5280000           call 0x6175c0
// 00614d1b  83c41c               add esp, 0x1c
// 00614d1e  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00614d21  56                   push esi
// 00614d22  e8c93c0000           call 0x6189f0
// 00614d27  8b5630               mov edx, dword ptr [esi + 0x30]
// 00614d2a  53                   push ebx
// 00614d2b  52                   push edx
// 00614d2c  e8bf3c0100           call 0x6289f0
// 00614d31  89442420             mov dword ptr [esp + 0x20], eax
// 00614d35  8d442418             lea eax, [esp + 0x18]
// 00614d39  50                   push eax
// 00614d3a  83c9ff               or ecx, 0xffffffff
// 00614d3d  57                   push edi
// 00614d3e  55                   push ebp
// 00614d3f  894c2434             mov dword ptr [esp + 0x34], ecx
// 00614d43  894c2438             mov dword ptr [esp + 0x38], ecx
// 00614d47  c744242404000000     mov dword ptr [esp + 0x24], 4
// 00614d4f  e85c4c0100           call 0x6299b0
// 00614d54  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00614d58  83c418               add esp, 0x18
// 00614d5b  e9ff000000           jmp 0x614e5f
// 00614d60  57                   push edi
// 00614d61  53                   push ebx
// 00614d62  e8a9460100           call 0x629410
// 00614d67  56                   push esi
// 00614d68  e8833c0000           call 0x6189f0
// 00614d6d  6a00                 push 0
// 00614d6f  8d4c241c             lea ecx, [esp + 0x1c]
// 00614d73  51                   push ecx
// 00614d74  56                   push esi
// 00614d75  e8a6050000           call 0x615320
// 00614d7a  8b4630               mov eax, dword ptr [esi + 0x30]
// 00614d7d  8d542424             lea edx, [esp + 0x24]
// 00614d81  52                   push edx
// 00614d82  50                   push eax
// 00614d83  e8d8460100           call 0x629460
// 00614d88  83c420               add esp, 0x20
// 00614d8b  837e105d             cmp dword ptr [esi + 0x10], 0x5d
// 00614d8f  7421                 je 0x614db2
// 00614d91  6a5d                 push 0x5d
// 00614d93  56                   push esi
// 00614d94  e827270000           call 0x6174c0
// 00614d99  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00614d9c  50                   push eax
// 00614d9d  6870337c00           push 0x7c3370
// 00614da2  51                   push ecx
// 00614da3  e8e8a0ffff           call 0x60ee90
// 00614da8  50                   push eax
// 00614da9  56                   push esi
// 00614daa  e811280000           call 0x6175c0
// 00614daf  83c41c               add esp, 0x1c
// 00614db2  56                   push esi
// 00614db3  e8383c0000           call 0x6189f0
// 00614db8  8d542410             lea edx, [esp + 0x10]
// 00614dbc  52                   push edx
// 00614dbd  57                   push edi
// 00614dbe  53                   push ebx
// 00614dbf  e8ec4b0100           call 0x6299b0
// 00614dc4  83c410               add esp, 0x10
// 00614dc7  e993000000           jmp 0x614e5f
// 00614dcc  56                   push esi
// 00614dcd  e81e3c0000           call 0x6189f0
// 00614dd2  83c404               add esp, 4
// 00614dd5  817e101d010000       cmp dword ptr [esi + 0x10], 0x11d
// 00614ddc  7424                 je 0x614e02
// 00614dde  681d010000           push 0x11d
// 00614de3  56                   push esi
// 00614de4  e8d7260000           call 0x6174c0
// 00614de9  50                   push eax
// 00614dea  8b4634               mov eax, dword ptr [esi + 0x34]
// 00614ded  6870337c00           push 0x7c3370
// 00614df2  50                   push eax
// 00614df3  e898a0ffff           call 0x60ee90
// 00614df8  50                   push eax
// 00614df9  56                   push esi
// 00614dfa  e8c1270000           call 0x6175c0
// 00614dff  83c41c               add esp, 0x1c
// 00614e02  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00614e05  56                   push esi
// 00614e06  e8e53b0000           call 0x6189f0
// 00614e0b  8b4e30               mov ecx, dword ptr [esi + 0x30]
// 00614e0e  53                   push ebx
// 00614e0f  51                   push ecx
// 00614e10  e8db3b0100           call 0x6289f0
// 00614e15  8d542418             lea edx, [esp + 0x18]
// 00614e19  52                   push edx
// 00614e1a  89442424             mov dword ptr [esp + 0x24], eax
// 00614e1e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00614e22  83c9ff               or ecx, 0xffffffff
// 00614e25  57                   push edi
// 00614e26  50                   push eax
// 00614e27  894c2434             mov dword ptr [esp + 0x34], ecx
// 00614e2b  894c2438             mov dword ptr [esp + 0x38], ecx
// 00614e2f  c744242404000000     mov dword ptr [esp + 0x24], 4
// 00614e37  e834480100           call 0x629670
// 00614e3c  57                   push edi
// 00614e3d  8bc6                 mov eax, esi
// 00614e3f  e8acfcffff           call 0x614af0
// 00614e44  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00614e48  83c41c               add esp, 0x1c
// 00614e4b  eb12                 jmp 0x614e5f
// 00614e4d  57                   push edi
// 00614e4e  53                   push ebx
// 00614e4f  e83c450100           call 0x629390
// 00614e54  57                   push edi
// 00614e55  8bc6                 mov eax, esi
// 00614e57  e894fcffff           call 0x614af0
// 00614e5c  83c40c               add esp, 0xc
// 00614e5f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00614e62  83e828               sub eax, 0x28
// 00614e65  3df6000000           cmp eax, 0xf6
// 00614e6a  0f8660feffff         jbe 0x614cd0
// 00614e70  5d                   pop ebp
// 00614e71  5b                   pop ebx
// 00614e72  83c41c               add esp, 0x1c
// 00614e75  c3                   ret 
// 00614e76  8bff                 mov edi, edi
// 00614e78  4d                   dec ebp
// 00614e79  4e                   dec esi
// 00614e7a  61                   popal 
// 00614e7b  00de                 add dh, bl
// 00614e7d  4c                   dec esp
// 00614e7e  61                   popal 
// 00614e7f  00cc                 add ah, cl
// 00614e81  4d                   dec ebp
// 00614e82  61                   popal 
// 00614e83  00604d               add byte ptr [eax + 0x4d], ah
// 00614e86  61                   popal 
// 00614e87  00704e               add byte ptr [eax + 0x4e], dh
// 00614e8a  61                   popal 
// 00614e8b  0000                 add byte ptr [eax], al
// 00614e8d  0404                 add al, 4
// 00614e8f  0404                 add al, 4
// 00614e91  0401                 add al, 1
// 00614e93  0404                 add al, 4
// 00614e95  0404                 add al, 4
// 00614e97  0404                 add al, 4
// 00614e99  0404                 add al, 4
// 00614e9b  0404                 add al, 4
// 00614e9d  0402                 add al, 2
// 00614e9f  0404                 add al, 4
// 00614ea1  0404                 add al, 4
// 00614ea3  0404                 add al, 4
// 00614ea5  0404                 add al, 4
// 00614ea7  0404                 add al, 4
// 00614ea9  0404                 add al, 4
// 00614eab  0404                 add al, 4
// 00614ead  0404                 add al, 4
// 00614eaf  0404                 add al, 4
// 00614eb1  0404                 add al, 4
// 00614eb3  0404                 add al, 4
// 00614eb5  0404                 add al, 4
// 00614eb7  0404                 add al, 4
// 00614eb9  0404                 add al, 4
// 00614ebb  0404                 add al, 4
// 00614ebd  0404                 add al, 4
// 00614ebf  030404               add eax, dword ptr [esp + eax]
// 00614ec2  0404                 add al, 4
// 00614ec4  0404                 add al, 4
// 00614ec6  0404                 add al, 4
// 00614ec8  0404                 add al, 4
// 00614eca  0404                 add al, 4
// 00614ecc  0404                 add al, 4
// 00614ece  0404                 add al, 4
// 00614ed0  0404                 add al, 4
// 00614ed2  0404                 add al, 4
// 00614ed4  0404                 add al, 4
// 00614ed6  0404                 add al, 4
// 00614ed8  0404                 add al, 4
// 00614eda  0404                 add al, 4
// 00614edc  0404                 add al, 4
// 00614ede  0400                 add al, 0
// 00614ee0  0404                 add al, 4
// 00614ee2  0404                 add al, 4
// 00614ee4  0404                 add al, 4
// 00614ee6  0404                 add al, 4
// 00614ee8  0404                 add al, 4
// 00614eea  0404                 add al, 4
// 00614eec  0404                 add al, 4
// 00614eee  0404                 add al, 4
// 00614ef0  0404                 add al, 4
// 00614ef2  0404                 add al, 4
// 00614ef4  0404                 add al, 4
// 00614ef6  0404                 add al, 4
// 00614ef8  0404                 add al, 4
// 00614efa  0404                 add al, 4
// 00614efc  0404                 add al, 4
// 00614efe  0404                 add al, 4
// 00614f00  0404                 add al, 4
// 00614f02  0404                 add al, 4
// 00614f04  0404                 add al, 4
// 00614f06  0404                 add al, 4
// 00614f08  0404                 add al, 4
// 00614f0a  0404                 add al, 4
// 00614f0c  0404                 add al, 4
// 00614f0e  0404                 add al, 4
// 00614f10  0404                 add al, 4
// 00614f12  0404                 add al, 4
// 00614f14  0404                 add al, 4
// 00614f16  0404                 add al, 4
// 00614f18  0404                 add al, 4
// 00614f1a  0404                 add al, 4
// 00614f1c  0404                 add al, 4
// 00614f1e  0404                 add al, 4
// 00614f20  0404                 add al, 4
// 00614f22  0404                 add al, 4
// 00614f24  0404                 add al, 4
// 00614f26  0404                 add al, 4
// 00614f28  0404                 add al, 4
// 00614f2a  0404                 add al, 4
// 00614f2c  0404                 add al, 4
// 00614f2e  0404                 add al, 4
// 00614f30  0404                 add al, 4
// 00614f32  0404                 add al, 4
// 00614f34  0404                 add al, 4
// 00614f36  0404                 add al, 4
// 00614f38  0404                 add al, 4
// 00614f3a  0404                 add al, 4
// 00614f3c  0404                 add al, 4
// 00614f3e  0404                 add al, 4
// 00614f40  0404                 add al, 4
// 00614f42  0404                 add al, 4
// 00614f44  0404                 add al, 4
// 00614f46  0404                 add al, 4
// 00614f48  0404                 add al, 4
// 00614f4a  0404                 add al, 4
// 00614f4c  0404                 add al, 4
// 00614f4e  0404                 add al, 4
// 00614f50  0404                 add al, 4
// 00614f52  0404                 add al, 4
// 00614f54  0404                 add al, 4
// 00614f56  0404                 add al, 4
// 00614f58  0404                 add al, 4
// 00614f5a  0404                 add al, 4
// 00614f5c  0404                 add al, 4
// 00614f5e  0404                 add al, 4
// 00614f60  0404                 add al, 4
// 00614f62  0404                 add al, 4
// 00614f64  0404                 add al, 4
// 00614f66  0404                 add al, 4
// 00614f68  0404                 add al, 4
// 00614f6a  0404                 add al, 4
// 00614f6c  0404                 add al, 4
// 00614f6e  0404                 add al, 4
// 00614f70  0404                 add al, 4
// 00614f72  0404                 add al, 4
// 00614f74  0404                 add al, 4
// 00614f76  0404                 add al, 4
// 00614f78  0404                 add al, 4
// 00614f7a  0404                 add al, 4
// 00614f7c  0404                 add al, 4
// 00614f7e  0404                 add al, 4
// 00614f80  0404                 add al, 4
// library lua-5.1/lparser.c (function _primaryexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
