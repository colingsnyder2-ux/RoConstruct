// from server: 100% by auto
// roc 2007-03 005fb8c0  unit: seg_005f0000  size: 183 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fb8c0
//
// 005fb8c0  8b4708               mov eax, dword ptr [edi + 8]
// 005fb8c3  83ec0c               sub esp, 0xc
// 005fb8c6  85c0                 test eax, eax
// 005fb8c8  55                   push ebp
// 005fb8c9  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005fb8cd  7508                 jne 0x5fb8d7
// 005fb8cf  83c8ff               or eax, 0xffffffff
// 005fb8d2  5d                   pop ebp
// 005fb8d3  83c40c               add esp, 0xc
// 005fb8d6  c3                   ret 
// 005fb8d7  83f803               cmp eax, 3
// 005fb8da  7532                 jne 0x5fb90e
// 005fb8dc  dd07                 fld qword ptr [edi]
// 005fb8de  dd5c2408             fstp qword ptr [esp + 8]
// 005fb8e2  dd442408             fld qword ptr [esp + 8]
// 005fb8e6  db5c2404             fistp dword ptr [esp + 4]
// 005fb8ea  db442404             fild dword ptr [esp + 4]
// 005fb8ee  dc5c2408             fcomp qword ptr [esp + 8]
// 005fb8f2  dfe0                 fnstsw ax
// 005fb8f4  f6c444               test ah, 0x44
// 005fb8f7  7a15                 jp 0x5fb90e
// 005fb8f9  8b442404             mov eax, dword ptr [esp + 4]
// 005fb8fd  85c0                 test eax, eax
// 005fb8ff  7e0d                 jle 0x5fb90e
// 005fb901  3b451c               cmp eax, dword ptr [ebp + 0x1c]
// 005fb904  7f08                 jg 0x5fb90e
// 005fb906  83c0ff               add eax, -1
// 005fb909  5d                   pop ebp
// 005fb90a  83c40c               add esp, 0xc
// 005fb90d  c3                   ret 
// 005fb90e  56                   push esi
// 005fb90f  8bd7                 mov edx, edi
// 005fb911  8bc5                 mov eax, ebp
// 005fb913  e818ffffff           call 0x5fb830
// 005fb918  8bf0                 mov esi, eax
// 005fb91a  53                   push ebx
// 005fb91b  eb03                 jmp 0x5fb920
// 005fb91d  8d4900               lea ecx, [ecx]
// 005fb920  8d5e10               lea ebx, [esi + 0x10]
// 005fb923  57                   push edi
// 005fb924  53                   push ebx
// 005fb925  e806cbffff           call 0x5f8430
// 005fb92a  83c408               add esp, 8
// 005fb92d  85c0                 test eax, eax
// 005fb92f  7534                 jne 0x5fb965
// 005fb931  837e180b             cmp dword ptr [esi + 0x18], 0xb
// 005fb935  750c                 jne 0x5fb943
// 005fb937  837f0804             cmp dword ptr [edi + 8], 4
// 005fb93b  7c06                 jl 0x5fb943
// 005fb93d  8b03                 mov eax, dword ptr [ebx]
// 005fb93f  3b07                 cmp eax, dword ptr [edi]
// 005fb941  7422                 je 0x5fb965
// 005fb943  8b761c               mov esi, dword ptr [esi + 0x1c]
// 005fb946  85f6                 test esi, esi
// 005fb948  75d6                 jne 0x5fb920
// 005fb94a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005fb94e  6890037c00           push 0x7c0390
// 005fb953  51                   push ecx
// 005fb954  e85777fcff           call 0x5c30b0
// 005fb959  83c408               add esp, 8
// 005fb95c  5b                   pop ebx
// 005fb95d  5e                   pop esi
// 005fb95e  33c0                 xor eax, eax
// 005fb960  5d                   pop ebp
// 005fb961  83c40c               add esp, 0xc
// 005fb964  c3                   ret 
// 005fb965  8bc6                 mov eax, esi
// 005fb967  2b4510               sub eax, dword ptr [ebp + 0x10]
// 005fb96a  5b                   pop ebx
// 005fb96b  c1f805               sar eax, 5
// 005fb96e  03451c               add eax, dword ptr [ebp + 0x1c]
// 005fb971  5e                   pop esi
// 005fb972  5d                   pop ebp
// 005fb973  83c40c               add esp, 0xc
// 005fb976  c3                   ret 
// library lua-5.1.1/ltable.c (function _findindex)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
