// from server: 100% by auto
// roc 2007-03 00614590  unit: seg_00610000  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614590
//
// 00614590  51                   push ecx
// 00614591  55                   push ebp
// 00614592  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00614596  57                   push edi
// 00614597  8bf8                 mov edi, eax
// 00614599  83ffff               cmp edi, -1
// 0061459c  0f84a6000000         je 0x614648
// 006145a2  53                   push ebx
// 006145a3  56                   push esi
// 006145a4  eb0a                 jmp 0x6145b0
// 006145a6  8da42400000000       lea esp, [esp]
// 006145ad  8d4900               lea ecx, [ecx]
// 006145b0  8b4500               mov eax, dword ptr [ebp]
// 006145b3  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006145b6  8d34bd00000000       lea esi, [edi*4]
// 006145bd  8b040e               mov eax, dword ptr [esi + ecx]
// 006145c0  c1e80e               shr eax, 0xe
// 006145c3  2dffff0100           sub eax, 0x1ffff
// 006145c8  83f8ff               cmp eax, -1
// 006145cb  7506                 jne 0x6145d3
// 006145cd  89442410             mov dword ptr [esp + 0x10], eax
// 006145d1  eb08                 jmp 0x6145db
// 006145d3  8d543801             lea edx, [eax + edi + 1]
// 006145d7  89542410             mov dword ptr [esp + 0x10], edx
// 006145db  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006145df  8bc7                 mov eax, edi
// 006145e1  8bd5                 mov edx, ebp
// 006145e3  e898feffff           call 0x614480
// 006145e8  85c0                 test eax, eax
// 006145ea  8b4500               mov eax, dword ptr [ebp]
// 006145ed  8b580c               mov ebx, dword ptr [eax + 0xc]
// 006145f0  7408                 je 0x6145fa
// 006145f2  03de                 add ebx, esi
// 006145f4  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006145f8  eb06                 jmp 0x614600
// 006145fa  03de                 add ebx, esi
// 006145fc  8b742424             mov esi, dword ptr [esp + 0x24]
// 00614600  2bf7                 sub esi, edi
// 00614602  83ee01               sub esi, 1
// 00614605  8bc6                 mov eax, esi
// 00614607  99                   cdq 
// 00614608  33c2                 xor eax, edx
// 0061460a  2bc2                 sub eax, edx
// 0061460c  3dffff0100           cmp eax, 0x1ffff
// 00614611  7e11                 jle 0x614624
// 00614613  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00614616  6878207c00           push 0x7c2078
// 0061461b  51                   push ecx
// 0061461c  e84fc9feff           call 0x600f70
// 00614621  83c408               add esp, 8
// 00614624  8b13                 mov edx, dword ptr [ebx]
// 00614626  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061462a  81c6ffff0100         add esi, 0x1ffff
// 00614630  81e2ff3f0000         and edx, 0x3fff
// 00614636  c1e60e               shl esi, 0xe
// 00614639  33f2                 xor esi, edx
// 0061463b  83ffff               cmp edi, -1
// 0061463e  8933                 mov dword ptr [ebx], esi
// 00614640  0f856affffff         jne 0x6145b0
// 00614646  5e                   pop esi
// 00614647  5b                   pop ebx
// 00614648  5f                   pop edi
// 00614649  5d                   pop ebp
// 0061464a  59                   pop ecx
// 0061464b  c3                   ret 
// library lua-5.1.1/lcode.c (function _patchlistaux)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
