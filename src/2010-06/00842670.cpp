// from server: 100% by auto
// roc 2010-06 00842670  unit: CXTPShortcutManager  size: 341 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00842670
//
// 00842670  53                   push ebx
// 00842671  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00842675  56                   push esi
// 00842676  57                   push edi
// 00842677  33ff                 xor edi, edi
// 00842679  3bdf                 cmp ebx, edi
// 0084267b  8bf1                 mov esi, ecx
// 0084267d  7d05                 jge 0x842684
// 0084267f  e8c855f6ff           call 0x7a7c4c
// 00842684  8b442414             mov eax, dword ptr [esp + 0x14]
// 00842688  3bc7                 cmp eax, edi
// 0084268a  7c03                 jl 0x84268f
// 0084268c  894610               mov dword ptr [esi + 0x10], eax
// 0084268f  3bdf                 cmp ebx, edi
// 00842691  751f                 jne 0x8426b2
// 00842693  8b4604               mov eax, dword ptr [esi + 4]
// 00842696  3bc7                 cmp eax, edi
// 00842698  740c                 je 0x8426a6
// 0084269a  50                   push eax
// 0084269b  e8a655f6ff           call 0x7a7c46
// 008426a0  83c404               add esp, 4
// 008426a3  897e04               mov dword ptr [esi + 4], edi
// 008426a6  897e0c               mov dword ptr [esi + 0xc], edi
// 008426a9  897e08               mov dword ptr [esi + 8], edi
// 008426ac  5f                   pop edi
// 008426ad  5e                   pop esi
// 008426ae  5b                   pop ebx
// 008426af  c20800               ret 8
// 008426b2  8b5604               mov edx, dword ptr [esi + 4]
// 008426b5  55                   push ebp
// 008426b6  3bd7                 cmp edx, edi
// 008426b8  7531                 jne 0x8426eb
// 008426ba  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 008426bd  3bdd                 cmp ebx, ebp
// 008426bf  7e02                 jle 0x8426c3
// 008426c1  8beb                 mov ebp, ebx
// 008426c3  8d7c6d00             lea edi, [ebp + ebp*2]
// 008426c7  03ff                 add edi, edi
// 008426c9  57                   push edi
// 008426ca  e8b355f6ff           call 0x7a7c82
// 008426cf  57                   push edi
// 008426d0  6a00                 push 0
// 008426d2  50                   push eax
// 008426d3  894604               mov dword ptr [esi + 4], eax
// 008426d6  e80965f6ff           call 0x7a8be4
// 008426db  83c410               add esp, 0x10
// 008426de  896e0c               mov dword ptr [esi + 0xc], ebp
// 008426e1  5d                   pop ebp
// 008426e2  5f                   pop edi
// 008426e3  895e08               mov dword ptr [esi + 8], ebx
// 008426e6  5e                   pop esi
// 008426e7  5b                   pop ebx
// 008426e8  c20800               ret 8
// 008426eb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008426ee  3bd9                 cmp ebx, ecx
// 008426f0  7f2f                 jg 0x842721
// 008426f2  8b4e08               mov ecx, dword ptr [esi + 8]
// 008426f5  3bd9                 cmp ebx, ecx
// 008426f7  0f8ebe000000         jle 0x8427bb
// 008426fd  8bc3                 mov eax, ebx
// 008426ff  2bc1                 sub eax, ecx
// 00842701  8d0440               lea eax, [eax + eax*2]
// 00842704  03c0                 add eax, eax
// 00842706  50                   push eax
// 00842707  8d0c49               lea ecx, [ecx + ecx*2]
// 0084270a  8d144a               lea edx, [edx + ecx*2]
// 0084270d  57                   push edi
// 0084270e  52                   push edx
// 0084270f  e8d064f6ff           call 0x7a8be4
// 00842714  83c40c               add esp, 0xc
// 00842717  5d                   pop ebp
// 00842718  5f                   pop edi
// 00842719  895e08               mov dword ptr [esi + 8], ebx
// 0084271c  5e                   pop esi
// 0084271d  5b                   pop ebx
// 0084271e  c20800               ret 8
// 00842721  8b4610               mov eax, dword ptr [esi + 0x10]
// 00842724  3bc7                 cmp eax, edi
// 00842726  7524                 jne 0x84274c
// 00842728  8b4608               mov eax, dword ptr [esi + 8]
// 0084272b  99                   cdq 
// 0084272c  83e207               and edx, 7
// 0084272f  03c2                 add eax, edx
// 00842731  c1f803               sar eax, 3
// 00842734  83f804               cmp eax, 4
// 00842737  7d07                 jge 0x842740
// 00842739  b804000000           mov eax, 4
// 0084273e  eb0c                 jmp 0x84274c
// 00842740  3d00040000           cmp eax, 0x400
// 00842745  7e05                 jle 0x84274c
// 00842747  b800040000           mov eax, 0x400
// 0084274c  8d3c01               lea edi, [ecx + eax]
// 0084274f  3bdf                 cmp ebx, edi
// 00842751  7d06                 jge 0x842759
// 00842753  897c2414             mov dword ptr [esp + 0x14], edi
// 00842757  eb06                 jmp 0x84275f
// 00842759  895c2414             mov dword ptr [esp + 0x14], ebx
// 0084275d  8bfb                 mov edi, ebx
// 0084275f  3bf9                 cmp edi, ecx
// 00842761  7d05                 jge 0x842768
// 00842763  e8e454f6ff           call 0x7a7c4c
// 00842768  8d3c7f               lea edi, [edi + edi*2]
// 0084276b  03ff                 add edi, edi
// 0084276d  57                   push edi
// 0084276e  e80f55f6ff           call 0x7a7c82
// 00842773  8b4e04               mov ecx, dword ptr [esi + 4]
// 00842776  8be8                 mov ebp, eax
// 00842778  8b4608               mov eax, dword ptr [esi + 8]
// 0084277b  8d0440               lea eax, [eax + eax*2]
// 0084277e  03c0                 add eax, eax
// 00842780  50                   push eax
// 00842781  51                   push ecx
// 00842782  57                   push edi
// 00842783  55                   push ebp
// 00842784  e86704bcff           call 0x402bf0
// 00842789  8b4e08               mov ecx, dword ptr [esi + 8]
// 0084278c  8bc3                 mov eax, ebx
// 0084278e  2bc1                 sub eax, ecx
// 00842790  8d1440               lea edx, [eax + eax*2]
// 00842793  03d2                 add edx, edx
// 00842795  52                   push edx
// 00842796  8d0449               lea eax, [ecx + ecx*2]
// 00842799  8d4c4500             lea ecx, [ebp + eax*2]
// 0084279d  6a00                 push 0
// 0084279f  51                   push ecx
// 008427a0  e83f64f6ff           call 0x7a8be4
// 008427a5  8b5604               mov edx, dword ptr [esi + 4]
// 008427a8  52                   push edx
// 008427a9  e89854f6ff           call 0x7a7c46
// 008427ae  8b442438             mov eax, dword ptr [esp + 0x38]
// 008427b2  83c424               add esp, 0x24
// 008427b5  896e04               mov dword ptr [esi + 4], ebp
// 008427b8  89460c               mov dword ptr [esi + 0xc], eax
// 008427bb  5d                   pop ebp
// 008427bc  5f                   pop edi
// 008427bd  895e08               mov dword ptr [esi + 8], ebx
// 008427c0  5e                   pop esi
// 008427c1  5b                   pop ebx
// 008427c2  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?SetSize@?$CArray@UtagACCEL@@AAU1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPShortcutManager.cpp
