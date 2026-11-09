// from server: 100% by auto
// roc 2009-06 006b9ec0  unit: RBX::UniversalTool  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9ec0
//
// 006b9ec0  8b442408             mov eax, dword ptr [esp + 8]
// 006b9ec4  57                   push edi
// 006b9ec5  8b7c2408             mov edi, dword ptr [esp + 8]
// 006b9ec9  8bcf                 mov ecx, edi
// 006b9ecb  e800edffff           call 0x6b8bd0
// 006b9ed0  83780806             cmp dword ptr [eax + 8], 6
// 006b9ed4  7404                 je 0x6b9eda
// 006b9ed6  33c0                 xor eax, eax
// 006b9ed8  5f                   pop edi
// 006b9ed9  c3                   ret 
// 006b9eda  8b08                 mov ecx, dword ptr [eax]
// 006b9edc  80790600             cmp byte ptr [ecx + 6], 0
// 006b9ee0  8b542410             mov edx, dword ptr [esp + 0x10]
// 006b9ee4  56                   push esi
// 006b9ee5  741b                 je 0x6b9f02
// 006b9ee7  83fa01               cmp edx, 1
// 006b9eea  7c7d                 jl 0x6b9f69
// 006b9eec  0fb67107             movzx esi, byte ptr [ecx + 7]
// 006b9ef0  3bd6                 cmp edx, esi
// 006b9ef2  7f75                 jg 0x6b9f69
// 006b9ef4  c1e204               shl edx, 4
// 006b9ef7  8d4c0a08             lea ecx, [edx + ecx + 8]
// 006b9efb  be16d28a00           mov esi, 0x8ad216
// 006b9f00  eb22                 jmp 0x6b9f24
// 006b9f02  83fa01               cmp edx, 1
// 006b9f05  8b7110               mov esi, dword ptr [ecx + 0x10]
// 006b9f08  7c5f                 jl 0x6b9f69
// 006b9f0a  3b5624               cmp edx, dword ptr [esi + 0x24]
// 006b9f0d  7f5a                 jg 0x6b9f69
// 006b9f0f  8b761c               mov esi, dword ptr [esi + 0x1c]
// 006b9f12  8b7496fc             mov esi, dword ptr [esi + edx*4 - 4]
// 006b9f16  8b4c9110             mov ecx, dword ptr [ecx + edx*4 + 0x10]
// 006b9f1a  8b4908               mov ecx, dword ptr [ecx + 8]
// 006b9f1d  83c610               add esi, 0x10
// 006b9f20  85f6                 test esi, esi
// 006b9f22  7440                 je 0x6b9f64
// 006b9f24  834708f0             add dword ptr [edi + 8], -0x10
// 006b9f28  8b5708               mov edx, dword ptr [edi + 8]
// 006b9f2b  53                   push ebx
// 006b9f2c  8b1a                 mov ebx, dword ptr [edx]
// 006b9f2e  8919                 mov dword ptr [ecx], ebx
// 006b9f30  8b5a04               mov ebx, dword ptr [edx + 4]
// 006b9f33  895904               mov dword ptr [ecx + 4], ebx
// 006b9f36  8b5208               mov edx, dword ptr [edx + 8]
// 006b9f39  895108               mov dword ptr [ecx + 8], edx
// 006b9f3c  8b4f08               mov ecx, dword ptr [edi + 8]
// 006b9f3f  ba04000000           mov edx, 4
// 006b9f44  395108               cmp dword ptr [ecx + 8], edx
// 006b9f47  5b                   pop ebx
// 006b9f48  7c1a                 jl 0x6b9f64
// 006b9f4a  8b09                 mov ecx, dword ptr [ecx]
// 006b9f4c  f6410503             test byte ptr [ecx + 5], 3
// 006b9f50  7412                 je 0x6b9f64
// 006b9f52  8b00                 mov eax, dword ptr [eax]
// 006b9f54  845005               test byte ptr [eax + 5], dl
// 006b9f57  740b                 je 0x6b9f64
// 006b9f59  51                   push ecx
// 006b9f5a  50                   push eax
// 006b9f5b  57                   push edi
// 006b9f5c  e84ffd0200           call 0x6e9cb0
// 006b9f61  83c40c               add esp, 0xc
// 006b9f64  8bc6                 mov eax, esi
// 006b9f66  5e                   pop esi
// 006b9f67  5f                   pop edi
// 006b9f68  c3                   ret 
// 006b9f69  5e                   pop esi
// 006b9f6a  33c0                 xor eax, eax
// 006b9f6c  5f                   pop edi
// 006b9f6d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
