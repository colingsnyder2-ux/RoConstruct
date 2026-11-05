// from server: 100% by auto
// roc 2007-08 005c5b40  unit: lua_exception  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c5b40
//
// 005c5b40  83ec64               sub esp, 0x64
// 005c5b43  56                   push esi
// 005c5b44  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005c5b48  8b4640               mov eax, dword ptr [esi + 0x40]
// 005c5b4b  85c0                 test eax, eax
// 005c5b4d  8944246c             mov dword ptr [esp + 0x6c], eax
// 005c5b51  0f84bc000000         je 0x5c5c13
// 005c5b57  807e3700             cmp byte ptr [esi + 0x37], 0
// 005c5b5b  0f84b2000000         je 0x5c5c13
// 005c5b61  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005c5b64  8b4614               mov eax, dword ptr [esi + 0x14]
// 005c5b67  8b542474             mov edx, dword ptr [esp + 0x74]
// 005c5b6b  53                   push ebx
// 005c5b6c  8b5e08               mov ebx, dword ptr [esi + 8]
// 005c5b6f  55                   push ebp
// 005c5b70  8b6808               mov ebp, dword ptr [eax + 8]
// 005c5b73  57                   push edi
// 005c5b74  8bfb                 mov edi, ebx
// 005c5b76  2bf9                 sub edi, ecx
// 005c5b78  2be9                 sub ebp, ecx
// 005c5b7a  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 005c5b7e  83f904               cmp ecx, 4
// 005c5b81  894c2410             mov dword ptr [esp + 0x10], ecx
// 005c5b85  89542424             mov dword ptr [esp + 0x24], edx
// 005c5b89  750a                 jne 0x5c5b95
// 005c5b8b  c744247000000000     mov dword ptr [esp + 0x70], 0
// 005c5b93  eb1a                 jmp 0x5c5baf
// 005c5b95  2b4628               sub eax, dword ptr [esi + 0x28]
// 005c5b98  8bc8                 mov ecx, eax
// 005c5b9a  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005c5b9f  f7e9                 imul ecx
// 005c5ba1  c1fa02               sar edx, 2
// 005c5ba4  8bc2                 mov eax, edx
// 005c5ba6  c1e81f               shr eax, 0x1f
// 005c5ba9  03c2                 add eax, edx
// 005c5bab  89442470             mov dword ptr [esp + 0x70], eax
// 005c5baf  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005c5bb2  2bcb                 sub ecx, ebx
// 005c5bb4  81f940010000         cmp ecx, 0x140
// 005c5bba  7f1b                 jg 0x5c5bd7
// 005c5bbc  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c5bbf  83f814               cmp eax, 0x14
// 005c5bc2  7c06                 jl 0x5c5bca
// 005c5bc4  8d1400               lea edx, [eax + eax]
// 005c5bc7  52                   push edx
// 005c5bc8  eb04                 jmp 0x5c5bce
// 005c5bca  83c014               add eax, 0x14
// 005c5bcd  50                   push eax
// 005c5bce  56                   push esi
// 005c5bcf  e85cfeffff           call 0x5c5a30
// 005c5bd4  83c408               add esp, 8
// 005c5bd7  8b4608               mov eax, dword ptr [esi + 8]
// 005c5bda  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c5bdd  8d542410             lea edx, [esp + 0x10]
// 005c5be1  0540010000           add eax, 0x140
// 005c5be6  52                   push edx
// 005c5be7  894108               mov dword ptr [ecx + 8], eax
// 005c5bea  56                   push esi
// 005c5beb  c6463700             mov byte ptr [esi + 0x37], 0
// 005c5bef  ff942480000000       call dword ptr [esp + 0x80]
// 005c5bf6  8b4620               mov eax, dword ptr [esi + 0x20]
// 005c5bf9  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005c5bfc  03c5                 add eax, ebp
// 005c5bfe  83c408               add esp, 8
// 005c5c01  c6463701             mov byte ptr [esi + 0x37], 1
// 005c5c05  894108               mov dword ptr [ecx + 8], eax
// 005c5c08  8b5620               mov edx, dword ptr [esi + 0x20]
// 005c5c0b  03d7                 add edx, edi
// 005c5c0d  5f                   pop edi
// 005c5c0e  5d                   pop ebp
// 005c5c0f  895608               mov dword ptr [esi + 8], edx
// 005c5c12  5b                   pop ebx
// 005c5c13  5e                   pop esi
// 005c5c14  83c464               add esp, 0x64
// 005c5c17  c3                   ret 
// library lua-5.1.2/ldo.c (function _luaD_callhook)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
