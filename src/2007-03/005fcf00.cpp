// from server: 100% by auto
// roc 2007-03 005fcf00  unit: seg_005f0000  size: 311 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fcf00
//
// 005fcf00  55                   push ebp
// 005fcf01  8bec                 mov ebp, esp
// 005fcf03  83e4f8               and esp, 0xfffffff8
// 005fcf06  83ec14               sub esp, 0x14
// 005fcf09  53                   push ebx
// 005fcf0a  56                   push esi
// 005fcf0b  8bf0                 mov esi, eax
// 005fcf0d  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fcf11  8b4508               mov eax, dword ptr [ebp + 8]
// 005fcf14  57                   push edi
// 005fcf15  8b7828               mov edi, dword ptr [eax + 0x28]
// 005fcf18  897c2414             mov dword ptr [esp + 0x14], edi
// 005fcf1c  7519                 jne 0x5fcf37
// 005fcf1e  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fcf21  8b06                 mov eax, dword ptr [esi]
// 005fcf23  51                   push ecx
// 005fcf24  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fcf27  6a04                 push 4
// 005fcf29  8d54241c             lea edx, [esp + 0x1c]
// 005fcf2d  52                   push edx
// 005fcf2e  50                   push eax
// 005fcf2f  ffd1                 call ecx
// 005fcf31  83c410               add esp, 0x10
// 005fcf34  894610               mov dword ptr [esi + 0x10], eax
// 005fcf37  85ff                 test edi, edi
// 005fcf39  0f8ea4000000         jle 0x5fcfe3
// 005fcf3f  33db                 xor ebx, ebx
// 005fcf41  897c2414             mov dword ptr [esp + 0x14], edi
// 005fcf45  8b5508               mov edx, dword ptr [ebp + 8]
// 005fcf48  8b7a08               mov edi, dword ptr [edx + 8]
// 005fcf4b  8a441f08             mov al, byte ptr [edi + ebx + 8]
// 005fcf4f  03fb                 add edi, ebx
// 005fcf51  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fcf55  88442413             mov byte ptr [esp + 0x13], al
// 005fcf59  7519                 jne 0x5fcf74
// 005fcf5b  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fcf5e  8b06                 mov eax, dword ptr [esi]
// 005fcf60  51                   push ecx
// 005fcf61  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fcf64  6a01                 push 1
// 005fcf66  8d54241b             lea edx, [esp + 0x1b]
// 005fcf6a  52                   push edx
// 005fcf6b  50                   push eax
// 005fcf6c  ffd1                 call ecx
// 005fcf6e  83c410               add esp, 0x10
// 005fcf71  894610               mov dword ptr [esi + 0x10], eax
// 005fcf74  8b4708               mov eax, dword ptr [edi + 8]
// 005fcf77  83e801               sub eax, 1
// 005fcf7a  7434                 je 0x5fcfb0
// 005fcf7c  83e802               sub eax, 2
// 005fcf7f  740e                 je 0x5fcf8f
// 005fcf81  83e801               sub eax, 1
// 005fcf84  754f                 jne 0x5fcfd5
// 005fcf86  8b07                 mov eax, dword ptr [edi]
// 005fcf88  e8e3feffff           call 0x5fce70
// 005fcf8d  eb46                 jmp 0x5fcfd5
// 005fcf8f  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fcf93  dd07                 fld qword ptr [edi]
// 005fcf95  dd5c2418             fstp qword ptr [esp + 0x18]
// 005fcf99  753a                 jne 0x5fcfd5
// 005fcf9b  8b5608               mov edx, dword ptr [esi + 8]
// 005fcf9e  8b0e                 mov ecx, dword ptr [esi]
// 005fcfa0  52                   push edx
// 005fcfa1  8b5604               mov edx, dword ptr [esi + 4]
// 005fcfa4  6a08                 push 8
// 005fcfa6  8d442420             lea eax, [esp + 0x20]
// 005fcfaa  50                   push eax
// 005fcfab  51                   push ecx
// 005fcfac  ffd2                 call edx
// 005fcfae  eb1f                 jmp 0x5fcfcf
// 005fcfb0  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fcfb4  8a07                 mov al, byte ptr [edi]
// 005fcfb6  88442413             mov byte ptr [esp + 0x13], al
// 005fcfba  7519                 jne 0x5fcfd5
// 005fcfbc  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fcfbf  8b06                 mov eax, dword ptr [esi]
// 005fcfc1  51                   push ecx
// 005fcfc2  8b4e04               mov ecx, dword ptr [esi + 4]
// 005fcfc5  6a01                 push 1
// 005fcfc7  8d54241b             lea edx, [esp + 0x1b]
// 005fcfcb  52                   push edx
// 005fcfcc  50                   push eax
// 005fcfcd  ffd1                 call ecx
// 005fcfcf  894610               mov dword ptr [esi + 0x10], eax
// 005fcfd2  83c410               add esp, 0x10
// 005fcfd5  83c310               add ebx, 0x10
// 005fcfd8  836c241401           sub dword ptr [esp + 0x14], 1
// 005fcfdd  0f8562ffffff         jne 0x5fcf45
// 005fcfe3  837e1000             cmp dword ptr [esi + 0x10], 0
// 005fcfe7  8b5508               mov edx, dword ptr [ebp + 8]
// 005fcfea  8b5a34               mov ebx, dword ptr [edx + 0x34]
// 005fcfed  895c2414             mov dword ptr [esp + 0x14], ebx
// 005fcff1  7519                 jne 0x5fd00c
// 005fcff3  8b4608               mov eax, dword ptr [esi + 8]
// 005fcff6  8b16                 mov edx, dword ptr [esi]
// 005fcff8  50                   push eax
// 005fcff9  8b4604               mov eax, dword ptr [esi + 4]
// 005fcffc  6a04                 push 4
// 005fcffe  8d4c241c             lea ecx, [esp + 0x1c]
// 005fd002  51                   push ecx
// 005fd003  52                   push edx
// 005fd004  ffd0                 call eax
// 005fd006  83c410               add esp, 0x10
// 005fd009  894610               mov dword ptr [esi + 0x10], eax
// 005fd00c  33ff                 xor edi, edi
// 005fd00e  85db                 test ebx, ebx
// 005fd010  7e1e                 jle 0x5fd030
// 005fd012  8b4508               mov eax, dword ptr [ebp + 8]
// 005fd015  8b4820               mov ecx, dword ptr [eax + 0x20]
// 005fd018  8b5010               mov edx, dword ptr [eax + 0x10]
// 005fd01b  8b04ba               mov eax, dword ptr [edx + edi*4]
// 005fd01e  56                   push esi
// 005fd01f  51                   push ecx
// 005fd020  50                   push eax
// 005fd021  e86a010000           call 0x5fd190
// 005fd026  83c701               add edi, 1
// 005fd029  83c40c               add esp, 0xc
// 005fd02c  3bfb                 cmp edi, ebx
// 005fd02e  7ce2                 jl 0x5fd012
// 005fd030  5f                   pop edi
// 005fd031  5e                   pop esi
// 005fd032  5b                   pop ebx
// 005fd033  8be5                 mov esp, ebp
// 005fd035  5d                   pop ebp
// 005fd036  c3                   ret 
// library lua-5.1.1/ldump.c (function _DumpConstants)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldump.c
