// from server: 100% by auto
// roc 2007-03 005b8b50  unit: seg_005b0000  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8b50
//
// 005b8b50  56                   push esi
// 005b8b51  8b742408             mov esi, dword ptr [esp + 8]
// 005b8b55  57                   push edi
// 005b8b56  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b8b5a  81ffefd8ffff         cmp edi, 0xffffd8ef
// 005b8b60  7516                 jne 0x5b8b78
// 005b8b62  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b8b65  3b4628               cmp eax, dword ptr [esi + 0x28]
// 005b8b68  750e                 jne 0x5b8b78
// 005b8b6a  6804917b00           push 0x7b9104
// 005b8b6f  56                   push esi
// 005b8b70  e83ba50000           call 0x5c30b0
// 005b8b75  83c408               add esp, 8
// 005b8b78  8bc7                 mov eax, edi
// 005b8b7a  8bce                 mov ecx, esi
// 005b8b7c  e82ffdffff           call 0x5b88b0
// 005b8b81  81ffefd8ffff         cmp edi, 0xffffd8ef
// 005b8b87  7529                 jne 0x5b8bb2
// 005b8b89  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005b8b8c  8b5104               mov edx, dword ptr [ecx + 4]
// 005b8b8f  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b8b92  8b02                 mov eax, dword ptr [edx]
// 005b8b94  8b51f0               mov edx, dword ptr [ecx - 0x10]
// 005b8b97  89500c               mov dword ptr [eax + 0xc], edx
// 005b8b9a  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b8b9d  ba04000000           mov edx, 4
// 005b8ba2  3951f8               cmp dword ptr [ecx - 8], edx
// 005b8ba5  7c58                 jl 0x5b8bff
// 005b8ba7  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005b8baa  f6410503             test byte ptr [ecx + 5], 3
// 005b8bae  744f                 je 0x5b8bff
// 005b8bb0  eb3d                 jmp 0x5b8bef
// 005b8bb2  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b8bb5  8b51f0               mov edx, dword ptr [ecx - 0x10]
// 005b8bb8  83e910               sub ecx, 0x10
// 005b8bbb  81ffeed8ffff         cmp edi, 0xffffd8ee
// 005b8bc1  8910                 mov dword ptr [eax], edx
// 005b8bc3  8b5104               mov edx, dword ptr [ecx + 4]
// 005b8bc6  895004               mov dword ptr [eax + 4], edx
// 005b8bc9  8b4908               mov ecx, dword ptr [ecx + 8]
// 005b8bcc  894808               mov dword ptr [eax + 8], ecx
// 005b8bcf  7d2e                 jge 0x5b8bff
// 005b8bd1  8b4608               mov eax, dword ptr [esi + 8]
// 005b8bd4  ba04000000           mov edx, 4
// 005b8bd9  3950f8               cmp dword ptr [eax - 8], edx
// 005b8bdc  7c21                 jl 0x5b8bff
// 005b8bde  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 005b8be1  f6410503             test byte ptr [ecx + 5], 3
// 005b8be5  7418                 je 0x5b8bff
// 005b8be7  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b8bea  8b4004               mov eax, dword ptr [eax + 4]
// 005b8bed  8b00                 mov eax, dword ptr [eax]
// 005b8bef  845005               test byte ptr [eax + 5], dl
// 005b8bf2  740b                 je 0x5b8bff
// 005b8bf4  51                   push ecx
// 005b8bf5  50                   push eax
// 005b8bf6  56                   push esi
// 005b8bf7  e8a40c0400           call 0x5f98a0
// 005b8bfc  83c40c               add esp, 0xc
// 005b8bff  834608f0             add dword ptr [esi + 8], -0x10
// 005b8c03  5f                   pop edi
// 005b8c04  5e                   pop esi
// 005b8c05  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_replace)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
