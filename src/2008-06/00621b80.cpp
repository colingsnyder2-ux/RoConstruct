// from server: 100% by auto
// roc 2008-06 00621b80  unit: lua_exception  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00621b80
//
// 00621b80  83ec64               sub esp, 0x64
// 00621b83  56                   push esi
// 00621b84  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00621b88  8b4640               mov eax, dword ptr [esi + 0x40]
// 00621b8b  8944246c             mov dword ptr [esp + 0x6c], eax
// 00621b8f  85c0                 test eax, eax
// 00621b91  0f84bc000000         je 0x621c53
// 00621b97  807e3700             cmp byte ptr [esi + 0x37], 0
// 00621b9b  0f84b2000000         je 0x621c53
// 00621ba1  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00621ba4  8b4614               mov eax, dword ptr [esi + 0x14]
// 00621ba7  8b542474             mov edx, dword ptr [esp + 0x74]
// 00621bab  53                   push ebx
// 00621bac  8b5e08               mov ebx, dword ptr [esi + 8]
// 00621baf  55                   push ebp
// 00621bb0  8b6808               mov ebp, dword ptr [eax + 8]
// 00621bb3  57                   push edi
// 00621bb4  8bfb                 mov edi, ebx
// 00621bb6  2bf9                 sub edi, ecx
// 00621bb8  2be9                 sub ebp, ecx
// 00621bba  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 00621bbe  894c2410             mov dword ptr [esp + 0x10], ecx
// 00621bc2  89542424             mov dword ptr [esp + 0x24], edx
// 00621bc6  83f904               cmp ecx, 4
// 00621bc9  750a                 jne 0x621bd5
// 00621bcb  c744247000000000     mov dword ptr [esp + 0x70], 0
// 00621bd3  eb1a                 jmp 0x621bef
// 00621bd5  2b4628               sub eax, dword ptr [esi + 0x28]
// 00621bd8  8bc8                 mov ecx, eax
// 00621bda  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00621bdf  f7e9                 imul ecx
// 00621be1  c1fa02               sar edx, 2
// 00621be4  8bc2                 mov eax, edx
// 00621be6  c1e81f               shr eax, 0x1f
// 00621be9  03c2                 add eax, edx
// 00621beb  89442470             mov dword ptr [esp + 0x70], eax
// 00621bef  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00621bf2  2bcb                 sub ecx, ebx
// 00621bf4  81f940010000         cmp ecx, 0x140
// 00621bfa  7f1b                 jg 0x621c17
// 00621bfc  8b462c               mov eax, dword ptr [esi + 0x2c]
// 00621bff  83f814               cmp eax, 0x14
// 00621c02  7c06                 jl 0x621c0a
// 00621c04  8d1400               lea edx, [eax + eax]
// 00621c07  52                   push edx
// 00621c08  eb04                 jmp 0x621c0e
// 00621c0a  83c014               add eax, 0x14
// 00621c0d  50                   push eax
// 00621c0e  56                   push esi
// 00621c0f  e85cfeffff           call 0x621a70
// 00621c14  83c408               add esp, 8
// 00621c17  8b4608               mov eax, dword ptr [esi + 8]
// 00621c1a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00621c1d  8d542410             lea edx, [esp + 0x10]
// 00621c21  0540010000           add eax, 0x140
// 00621c26  52                   push edx
// 00621c27  894108               mov dword ptr [ecx + 8], eax
// 00621c2a  56                   push esi
// 00621c2b  c6463700             mov byte ptr [esi + 0x37], 0
// 00621c2f  ff942480000000       call dword ptr [esp + 0x80]
// 00621c36  8b4620               mov eax, dword ptr [esi + 0x20]
// 00621c39  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00621c3c  03c5                 add eax, ebp
// 00621c3e  83c408               add esp, 8
// 00621c41  c6463701             mov byte ptr [esi + 0x37], 1
// 00621c45  894108               mov dword ptr [ecx + 8], eax
// 00621c48  8b5620               mov edx, dword ptr [esi + 0x20]
// 00621c4b  03d7                 add edx, edi
// 00621c4d  5f                   pop edi
// 00621c4e  5d                   pop ebp
// 00621c4f  895608               mov dword ptr [esi + 8], edx
// 00621c52  5b                   pop ebx
// 00621c53  5e                   pop esi
// 00621c54  83c464               add esp, 0x64
// 00621c57  c3                   ret 
// library lua-5.1.2/ldo.c (function _luaD_callhook)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 ldo.c
