// from server: 100% by auto
// roc 2009-06 00709790  unit: boost::detail::thread_data_base  size: 496 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00709790
//
// 00709790  83ec20               sub esp, 0x20
// 00709793  56                   push esi
// 00709794  8b742428             mov esi, dword ptr [esp + 0x28]
// 00709798  807e1000             cmp byte ptr [esi + 0x10], 0
// 0070979c  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007097a4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007097ac  743b                 je 0x7097e9
// 007097ae  ff1518e28900         call dword ptr [0x89e218]
// 007097b4  2b06                 sub eax, dword ptr [esi]
// 007097b6  8b4e08               mov ecx, dword ptr [esi + 8]
// 007097b9  8b760c               mov esi, dword ptr [esi + 0xc]
// 007097bc  33d2                 xor edx, edx
// 007097be  2bc8                 sub ecx, eax
// 007097c0  1bf2                 sbb esi, edx
// 007097c2  0f88a7010000         js 0x70996f
// 007097c8  7f08                 jg 0x7097d2
// 007097ca  85c9                 test ecx, ecx
// 007097cc  0f869d010000         jbe 0x70996f
// 007097d2  6aff                 push -1
// 007097d4  68f0d8ffff           push 0xffffd8f0
// 007097d9  56                   push esi
// 007097da  51                   push ecx
// 007097db  e860040100           call 0x719c40
// 007097e0  8bf0                 mov esi, eax
// 007097e2  8bca                 mov ecx, edx
// 007097e4  5e                   pop esi
// 007097e5  83c420               add esp, 0x20
// 007097e8  c3                   ret 
// 007097e9  33c0                 xor eax, eax
// 007097eb  8d4c2428             lea ecx, [esp + 0x28]
// 007097ef  83c618               add esi, 0x18
// 007097f2  51                   push ecx
// 007097f3  8bce                 mov ecx, esi
// 007097f5  6689442418           mov word ptr [esp + 0x18], ax
// 007097fa  8944241a             mov dword ptr [esp + 0x1a], eax
// 007097fe  8944241e             mov dword ptr [esp + 0x1e], eax
// 00709802  89442422             mov dword ptr [esp + 0x22], eax
// 00709806  6689442426           mov word ptr [esp + 0x26], ax
// 0070980b  e8a0fcffff           call 0x7094b0
// 00709810  8b542428             mov edx, dword ptr [esp + 0x28]
// 00709814  52                   push edx
// 00709815  8d442408             lea eax, [esp + 8]
// 00709819  50                   push eax
// 0070981a  e861fbffff           call 0x709380
// 0070981f  668b4c240c           mov cx, word ptr [esp + 0xc]
// 00709824  83c408               add esp, 8
// 00709827  8d542428             lea edx, [esp + 0x28]
// 0070982b  66894c2414           mov word ptr [esp + 0x14], cx
// 00709830  52                   push edx
// 00709831  8bce                 mov ecx, esi
// 00709833  e878fcffff           call 0x7094b0
// 00709838  8b442428             mov eax, dword ptr [esp + 0x28]
// 0070983c  50                   push eax
// 0070983d  8d4c2408             lea ecx, [esp + 8]
// 00709841  51                   push ecx
// 00709842  e839fbffff           call 0x709380
// 00709847  668b54240e           mov dx, word ptr [esp + 0xe]
// 0070984c  83c408               add esp, 8
// 0070984f  8d442428             lea eax, [esp + 0x28]
// 00709853  50                   push eax
// 00709854  8bce                 mov ecx, esi
// 00709856  668954241a           mov word ptr [esp + 0x1a], dx
// 0070985b  e850fcffff           call 0x7094b0
// 00709860  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00709864  51                   push ecx
// 00709865  8d542408             lea edx, [esp + 8]
// 00709869  52                   push edx
// 0070986a  e811fbffff           call 0x709380
// 0070986f  668b442410           mov ax, word ptr [esp + 0x10]
// 00709874  8d4c240c             lea ecx, [esp + 0xc]
// 00709878  56                   push esi
// 00709879  51                   push ecx
// 0070987a  668944242a           mov word ptr [esp + 0x2a], ax
// 0070987f  e8acf6ffff           call 0x708f30
// 00709884  8b542418             mov edx, dword ptr [esp + 0x18]
// 00709888  8b442414             mov eax, dword ptr [esp + 0x14]
// 0070988c  83c410               add esp, 0x10
// 0070988f  6a00                 push 0
// 00709891  6800a493d6           push 0xd693a400
// 00709896  52                   push edx
// 00709897  50                   push eax
// 00709898  e8d3040100           call 0x719d70
// 0070989d  8d4c2404             lea ecx, [esp + 4]
// 007098a1  56                   push esi
// 007098a2  51                   push ecx
// 007098a3  6689442424           mov word ptr [esp + 0x24], ax
// 007098a8  e883f6ffff           call 0x708f30
// 007098ad  8b542410             mov edx, dword ptr [esp + 0x10]
// 007098b1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007098b5  83c408               add esp, 8
// 007098b8  6a00                 push 0
// 007098ba  6800879303           push 0x3938700
// 007098bf  52                   push edx
// 007098c0  50                   push eax
// 007098c1  e8aa040100           call 0x719d70
// 007098c6  6a00                 push 0
// 007098c8  6a3c                 push 0x3c
// 007098ca  52                   push edx
// 007098cb  50                   push eax
// 007098cc  e8df0b0100           call 0x71a4b0
// 007098d1  8d4c2404             lea ecx, [esp + 4]
// 007098d5  56                   push esi
// 007098d6  51                   push ecx
// 007098d7  6689442426           mov word ptr [esp + 0x26], ax
// 007098dc  e84ff6ffff           call 0x708f30
// 007098e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007098e5  83c408               add esp, 8
// 007098e8  6a00                 push 0
// 007098ea  6840420f00           push 0xf4240
// 007098ef  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007098f3  52                   push edx
// 007098f4  50                   push eax
// 007098f5  e876040100           call 0x719d70
// 007098fa  6a00                 push 0
// 007098fc  6a3c                 push 0x3c
// 007098fe  52                   push edx
// 007098ff  50                   push eax
// 00709900  e8ab0b0100           call 0x71a4b0
// 00709905  8d4c240c             lea ecx, [esp + 0xc]
// 00709909  51                   push ecx
// 0070990a  8d542418             lea edx, [esp + 0x18]
// 0070990e  52                   push edx
// 0070990f  6689442428           mov word ptr [esp + 0x28], ax
// 00709914  ff1514e38900         call dword ptr [0x89e314]
// 0070991a  85c0                 test eax, eax
// 0070991c  750d                 jne 0x70992b
// 0070991e  33f6                 xor esi, esi
// 00709920  33c9                 xor ecx, ecx
// 00709922  8bc6                 mov eax, esi
// 00709924  8bd1                 mov edx, ecx
// 00709926  5e                   pop esi
// 00709927  83c420               add esp, 0x20
// 0070992a  c3                   ret 
// 0070992b  8d442404             lea eax, [esp + 4]
// 0070992f  56                   push esi
// 00709930  50                   push eax
// 00709931  e8faf5ffff           call 0x708f30
// 00709936  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0070993a  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0070993e  83c408               add esp, 8
// 00709941  6a00                 push 0
// 00709943  6840420f00           push 0xf4240
// 00709948  51                   push ecx
// 00709949  52                   push edx
// 0070994a  e8610b0100           call 0x71a4b0
// 0070994f  6a00                 push 0
// 00709951  6a0a                 push 0xa
// 00709953  52                   push edx
// 00709954  50                   push eax
// 00709955  e8e6020100           call 0x719c40
// 0070995a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0070995e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00709962  03f0                 add esi, eax
// 00709964  13ca                 adc ecx, edx
// 00709966  8bc6                 mov eax, esi
// 00709968  8bd1                 mov edx, ecx
// 0070996a  5e                   pop esi
// 0070996b  83c420               add esp, 0x20
// 0070996e  c3                   ret 
// 0070996f  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00709973  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00709977  8bc6                 mov eax, esi
// 00709979  8bd1                 mov edx, ecx
// 0070997b  5e                   pop esi
// 0070997c  83c420               add esp, 0x20
// 0070997f  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?get_due_time@?A0x1a561512@this_thread@boost@@YA?AT_LARGE_INTEGER@@ABUtimeout@detail@3@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
