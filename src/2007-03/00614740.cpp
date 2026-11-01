// from server: 100% by auto
// roc 2007-03 00614740  unit: seg_00610000  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614740
//
// 00614740  51                   push ecx
// 00614741  8b5304               mov edx, dword ptr [ebx + 4]
// 00614744  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00614747  55                   push ebp
// 00614748  56                   push esi
// 00614749  57                   push edi
// 0061474a  51                   push ecx
// 0061474b  52                   push edx
// 0061474c  50                   push eax
// 0061474d  89442418             mov dword ptr [esp + 0x18], eax
// 00614751  e81a78feff           call 0x5fbf70
// 00614756  8b33                 mov esi, dword ptr [ebx]
// 00614758  8b6e28               mov ebp, dword ptr [esi + 0x28]
// 0061475b  b903000000           mov ecx, 3
// 00614760  83c40c               add esp, 0xc
// 00614763  394808               cmp dword ptr [eax + 8], ecx
// 00614766  8d7e28               lea edi, [esi + 0x28]
// 00614769  750d                 jne 0x614778
// 0061476b  dd00                 fld qword ptr [eax]
// 0061476d  5f                   pop edi
// 0061476e  5e                   pop esi
// 0061476f  5d                   pop ebp
// 00614770  83c404               add esp, 4
// 00614773  e988aa0000           jmp 0x61f200
// 00614778  db4328               fild dword ptr [ebx + 0x28]
// 0061477b  894808               mov dword ptr [eax + 8], ecx
// 0061477e  dd18                 fstp qword ptr [eax]
// 00614780  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00614783  83c001               add eax, 1
// 00614786  3b07                 cmp eax, dword ptr [edi]
// 00614788  7e21                 jle 0x6147ab
// 0061478a  8b4e08               mov ecx, dword ptr [esi + 8]
// 0061478d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00614791  680c057c00           push 0x7c050c
// 00614796  68ffff0300           push 0x3ffff
// 0061479b  6a10                 push 0x10
// 0061479d  57                   push edi
// 0061479e  51                   push ecx
// 0061479f  52                   push edx
// 006147a0  e84b8cfeff           call 0x5fd3f0
// 006147a5  83c418               add esp, 0x18
// 006147a8  894608               mov dword ptr [esi + 8], eax
// 006147ab  3b2f                 cmp ebp, dword ptr [edi]
// 006147ad  7d18                 jge 0x6147c7
// 006147af  8bc5                 mov eax, ebp
// 006147b1  c1e004               shl eax, 4
// 006147b4  33c9                 xor ecx, ecx
// 006147b6  8b5608               mov edx, dword ptr [esi + 8]
// 006147b9  894c1008             mov dword ptr [eax + edx + 8], ecx
// 006147bd  83c501               add ebp, 1
// 006147c0  83c010               add eax, 0x10
// 006147c3  3b2f                 cmp ebp, dword ptr [edi]
// 006147c5  7cef                 jl 0x6147b6
// 006147c7  8b4328               mov eax, dword ptr [ebx + 0x28]
// 006147ca  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006147ce  8b11                 mov edx, dword ptr [ecx]
// 006147d0  c1e004               shl eax, 4
// 006147d3  034608               add eax, dword ptr [esi + 8]
// 006147d6  8910                 mov dword ptr [eax], edx
// 006147d8  8b5104               mov edx, dword ptr [ecx + 4]
// 006147db  895004               mov dword ptr [eax + 4], edx
// 006147de  8b5108               mov edx, dword ptr [ecx + 8]
// 006147e1  895008               mov dword ptr [eax + 8], edx
// 006147e4  b804000000           mov eax, 4
// 006147e9  394108               cmp dword ptr [ecx + 8], eax
// 006147ec  7c1c                 jl 0x61480a
// 006147ee  8b09                 mov ecx, dword ptr [ecx]
// 006147f0  f6410503             test byte ptr [ecx + 5], 3
// 006147f4  7414                 je 0x61480a
// 006147f6  844605               test byte ptr [esi + 5], al
// 006147f9  740f                 je 0x61480a
// 006147fb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006147ff  51                   push ecx
// 00614800  56                   push esi
// 00614801  50                   push eax
// 00614802  e89950feff           call 0x5f98a0
// 00614807  83c40c               add esp, 0xc
// 0061480a  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0061480d  5f                   pop edi
// 0061480e  8d4801               lea ecx, [eax + 1]
// 00614811  5e                   pop esi
// 00614812  894b28               mov dword ptr [ebx + 0x28], ecx
// 00614815  5d                   pop ebp
// 00614816  59                   pop ecx
// 00614817  c3                   ret 
// library lua-5.1.1/lcode.c (function _addk)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
