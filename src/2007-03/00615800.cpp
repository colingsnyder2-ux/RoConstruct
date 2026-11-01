// from server: 100% by auto
// roc 2007-03 00615800  unit: seg_00610000  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00615800
//
// 00615800  8b442404             mov eax, dword ptr [esp + 4]
// 00615804  55                   push ebp
// 00615805  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00615809  56                   push esi
// 0061580a  50                   push eax
// 0061580b  8bc5                 mov eax, ebp
// 0061580d  8bf3                 mov esi, ebx
// 0061580f  e8ecf1ffff           call 0x614a00
// 00615814  83c404               add esp, 4
// 00615817  85c0                 test eax, eax
// 00615819  0f858a000000         jne 0x6158a9
// 0061581f  53                   push ebx
// 00615820  57                   push edi
// 00615821  e88afaffff           call 0x6152b0
// 00615826  8b542414             mov edx, dword ptr [esp + 0x14]
// 0061582a  83c408               add esp, 8
// 0061582d  83fa12               cmp edx, 0x12
// 00615830  8bf0                 mov esi, eax
// 00615832  7415                 je 0x615849
// 00615834  83fa14               cmp edx, 0x14
// 00615837  7410                 je 0x615849
// 00615839  55                   push ebp
// 0061583a  57                   push edi
// 0061583b  e870faffff           call 0x6152b0
// 00615840  8b542414             mov edx, dword ptr [esp + 0x14]
// 00615844  83c408               add esp, 8
// 00615847  eb02                 jmp 0x61584b
// 00615849  33c0                 xor eax, eax
// 0061584b  837d000c             cmp dword ptr [ebp], 0xc
// 0061584f  7517                 jne 0x615868
// 00615851  8b6d08               mov ebp, dword ptr [ebp + 8]
// 00615854  f7c500010000         test ebp, 0x100
// 0061585a  750c                 jne 0x615868
// 0061585c  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 00615860  3be9                 cmp ebp, ecx
// 00615862  7c04                 jl 0x615868
// 00615864  834724ff             add dword ptr [edi + 0x24], -1
// 00615868  833b0c               cmp dword ptr [ebx], 0xc
// 0061586b  7517                 jne 0x615884
// 0061586d  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00615870  f7c100010000         test ecx, 0x100
// 00615876  750c                 jne 0x615884
// 00615878  0fb66f32             movzx ebp, byte ptr [edi + 0x32]
// 0061587c  3bcd                 cmp ecx, ebp
// 0061587e  7c04                 jl 0x615884
// 00615880  834724ff             add dword ptr [edi + 0x24], -1
// 00615884  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00615887  8b4908               mov ecx, dword ptr [ecx + 8]
// 0061588a  c1e609               shl esi, 9
// 0061588d  0bf0                 or esi, eax
// 0061588f  c1e60e               shl esi, 0xe
// 00615892  0bf2                 or esi, edx
// 00615894  51                   push ecx
// 00615895  56                   push esi
// 00615896  8bf7                 mov esi, edi
// 00615898  e873f2ffff           call 0x614b10
// 0061589d  83c408               add esp, 8
// 006158a0  894308               mov dword ptr [ebx + 8], eax
// 006158a3  c7030b000000         mov dword ptr [ebx], 0xb
// 006158a9  5e                   pop esi
// 006158aa  5d                   pop ebp
// 006158ab  c3                   ret 
// library lua-5.1.1/lcode.c (function _codearith)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
