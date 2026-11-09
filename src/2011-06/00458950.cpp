// from server: 100% by auto
// roc 2011-06 00458950  unit: RBX::Stats::H::?$TypedStatsItem  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00458950
//
// 00458950  51                   push ecx
// 00458951  56                   push esi
// 00458952  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00458956  8b4608               mov eax, dword ptr [esi + 8]
// 00458959  c744240400000000     mov dword ptr [esp + 4], 0
// 00458961  85c0                 test eax, eax
// 00458963  7505                 jne 0x45896a
// 00458965  5e                   pop esi
// 00458966  59                   pop ecx
// 00458967  c20c00               ret 0xc
// 0045896a  8b560c               mov edx, dword ptr [esi + 0xc]
// 0045896d  57                   push edi
// 0045896e  8d4c2408             lea ecx, [esp + 8]
// 00458972  51                   push ecx
// 00458973  68e0bca500           push 0xa5bce0
// 00458978  52                   push edx
// 00458979  ffd0                 call eax
// 0045897b  8bf8                 mov edi, eax
// 0045897d  85ff                 test edi, edi
// 0045897f  7c1e                 jl 0x45899f
// 00458981  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00458985  8b542414             mov edx, dword ptr [esp + 0x14]
// 00458989  8d4614               lea eax, [esi + 0x14]
// 0045898c  50                   push eax
// 0045898d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00458991  51                   push ecx
// 00458992  8b0e                 mov ecx, dword ptr [esi]
// 00458994  52                   push edx
// 00458995  50                   push eax
// 00458996  51                   push ecx
// 00458997  ff159830a400         call dword ptr [0xa43098]
// 0045899d  8bf8                 mov edi, eax
// 0045899f  8b442408             mov eax, dword ptr [esp + 8]
// 004589a3  85c0                 test eax, eax
// 004589a5  7408                 je 0x4589af
// 004589a7  8b10                 mov edx, dword ptr [eax]
// 004589a9  50                   push eax
// 004589aa  8b4208               mov eax, dword ptr [edx + 8]
// 004589ad  ffd0                 call eax
// 004589af  8bc7                 mov eax, edi
// 004589b1  5f                   pop edi
// 004589b2  5e                   pop esi
// 004589b3  59                   pop ecx
// 004589b4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function ?RegisterClassObject@_ATL_OBJMAP_ENTRY30@ATL@@QAGJKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
