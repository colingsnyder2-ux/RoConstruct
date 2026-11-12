// from server: 100% by auto
// roc 2008-06 004bb760  unit: ProfiledRakPeer  size: 218 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb760
//
// 004bb760  83b92c02000000       cmp dword ptr [ecx + 0x22c], 0
// 004bb767  0f84bf000000         je 0x4bb82c
// 004bb76d  8a4104               mov al, byte ptr [ecx + 4]
// 004bb770  3c01                 cmp al, 1
// 004bb772  0f84b4000000         je 0x4bb82c
// 004bb778  53                   push ebx
// 004bb779  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004bb77d  56                   push esi
// 004bb77e  33d2                 xor edx, edx
// 004bb780  57                   push edi
// 004bb781  85db                 test ebx, ebx
// 004bb783  746c                 je 0x4bb7f1
// 004bb785  33c0                 xor eax, eax
// 004bb787  33ff                 xor edi, edi
// 004bb789  663b4108             cmp ax, word ptr [ecx + 8]
// 004bb78d  0f838a000000         jae 0x4bb81d
// 004bb793  33f6                 xor esi, esi
// 004bb795  55                   push ebp
// 004bb796  eb08                 jmp 0x4bb7a0
// 004bb798  8da42400000000       lea esp, [esp]
// 004bb79f  90                   nop 
// 004bb7a0  8b812c020000         mov eax, dword ptr [ecx + 0x22c]
// 004bb7a6  03c6                 add eax, esi
// 004bb7a8  803800               cmp byte ptr [eax], 0
// 004bb7ab  7425                 je 0x4bb7d2
// 004bb7ad  83b84808000008       cmp dword ptr [eax + 0x848], 8
// 004bb7b4  751c                 jne 0x4bb7d2
// 004bb7b6  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004bb7ba  0fb76d00             movzx ebp, word ptr [ebp]
// 004bb7be  3bd5                 cmp edx, ebp
// 004bb7c0  7d0f                 jge 0x4bb7d1
// 004bb7c2  8b6804               mov ebp, dword ptr [eax + 4]
// 004bb7c5  892cd3               mov dword ptr [ebx + edx*8], ebp
// 004bb7c8  668b4008             mov ax, word ptr [eax + 8]
// 004bb7cc  668944d304           mov word ptr [ebx + edx*8 + 4], ax
// 004bb7d1  42                   inc edx
// 004bb7d2  0fb74108             movzx eax, word ptr [ecx + 8]
// 004bb7d6  47                   inc edi
// 004bb7d7  81c650080000         add esi, 0x850
// 004bb7dd  3bf8                 cmp edi, eax
// 004bb7df  7cbf                 jl 0x4bb7a0
// 004bb7e1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bb7e5  5d                   pop ebp
// 004bb7e6  5f                   pop edi
// 004bb7e7  5e                   pop esi
// 004bb7e8  668911               mov word ptr [ecx], dx
// 004bb7eb  5b                   pop ebx
// 004bb7ec  32c0                 xor al, al
// 004bb7ee  c20800               ret 8
// 004bb7f1  0fb74108             movzx eax, word ptr [ecx + 8]
// 004bb7f5  85c0                 test eax, eax
// 004bb7f7  7e24                 jle 0x4bb81d
// 004bb7f9  8b892c020000         mov ecx, dword ptr [ecx + 0x22c]
// 004bb7ff  be08000000           mov esi, 8
// 004bb804  803900               cmp byte ptr [ecx], 0
// 004bb807  7409                 je 0x4bb812
// 004bb809  39b148080000         cmp dword ptr [ecx + 0x848], esi
// 004bb80f  7501                 jne 0x4bb812
// 004bb811  42                   inc edx
// 004bb812  81c150080000         add ecx, 0x850
// 004bb818  83e801               sub eax, 1
// 004bb81b  75e7                 jne 0x4bb804
// 004bb81d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004bb821  5f                   pop edi
// 004bb822  5e                   pop esi
// 004bb823  668911               mov word ptr [ecx], dx
// 004bb826  5b                   pop ebx
// 004bb827  32c0                 xor al, al
// 004bb829  c20800               ret 8
// 004bb82c  8b442408             mov eax, dword ptr [esp + 8]
// 004bb830  33d2                 xor edx, edx
// 004bb832  668910               mov word ptr [eax], dx
// 004bb835  32c0                 xor al, al
// 004bb837  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?GetConnectionList@RakPeer@@UBE_NPAUSystemAddress@@PAG@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
