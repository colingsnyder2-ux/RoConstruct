// from server: 100% by auto
// roc 2010-06 00804240  unit: CXTPPropExchange  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00804240
//
// 00804240  8b442404             mov eax, dword ptr [esp + 4]
// 00804244  83ec10               sub esp, 0x10
// 00804247  53                   push ebx
// 00804248  55                   push ebp
// 00804249  56                   push esi
// 0080424a  8b30                 mov esi, dword ptr [eax]
// 0080424c  33ed                 xor ebp, ebp
// 0080424e  57                   push edi
// 0080424f  3bf5                 cmp esi, ebp
// 00804251  7506                 jne 0x804259
// 00804253  896c2410             mov dword ptr [esp + 0x10], ebp
// 00804257  eb1a                 jmp 0x804273
// 00804259  8bc6                 mov eax, esi
// 0080425b  8d5002               lea edx, [eax + 2]
// 0080425e  8bff                 mov edi, edi
// 00804260  668b08               mov cx, word ptr [eax]
// 00804263  83c002               add eax, 2
// 00804266  663bcd               cmp cx, bp
// 00804269  75f5                 jne 0x804260
// 0080426b  2bc2                 sub eax, edx
// 0080426d  d1f8                 sar eax, 1
// 0080426f  89442410             mov dword ptr [esp + 0x10], eax
// 00804273  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00804277  3bdd                 cmp ebx, ebp
// 00804279  0f841d010000         je 0x80439c
// 0080427f  8bc3                 mov eax, ebx
// 00804281  8d5002               lea edx, [eax + 2]
// 00804284  668b08               mov cx, word ptr [eax]
// 00804287  83c002               add eax, 2
// 0080428a  663bcd               cmp cx, bp
// 0080428d  75f5                 jne 0x804284
// 0080428f  2bc2                 sub eax, edx
// 00804291  d1f8                 sar eax, 1
// 00804293  8bf8                 mov edi, eax
// 00804295  897c2418             mov dword ptr [esp + 0x18], edi
// 00804299  0f84fd000000         je 0x80439c
// 0080429f  396c2410             cmp dword ptr [esp + 0x10], ebp
// 008042a3  0f84f3000000         je 0x80439c
// 008042a9  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008042ad  3bc5                 cmp eax, ebp
// 008042af  7506                 jne 0x8042b7
// 008042b1  896c2414             mov dword ptr [esp + 0x14], ebp
// 008042b5  eb1c                 jmp 0x8042d3
// 008042b7  8d5002               lea edx, [eax + 2]
// 008042ba  8d9b00000000         lea ebx, [ebx]
// 008042c0  668b08               mov cx, word ptr [eax]
// 008042c3  83c002               add eax, 2
// 008042c6  663bcd               cmp cx, bp
// 008042c9  75f5                 jne 0x8042c0
// 008042cb  2bc2                 sub eax, edx
// 008042cd  d1f8                 sar eax, 1
// 008042cf  89442414             mov dword ptr [esp + 0x14], eax
// 008042d3  53                   push ebx
// 008042d4  56                   push esi
// 008042d5  8b35dca99e00         mov esi, dword ptr [0x9ea9dc]
// 008042db  ffd6                 call esi
// 008042dd  83c408               add esp, 8
// 008042e0  85c0                 test eax, eax
// 008042e2  0f84aa000000         je 0x804392
// 008042e8  8d0c78               lea ecx, [eax + edi*2]
// 008042eb  53                   push ebx
// 008042ec  51                   push ecx
// 008042ed  45                   inc ebp
// 008042ee  ffd6                 call esi
// 008042f0  83c408               add esp, 8
// 008042f3  85c0                 test eax, eax
// 008042f5  75f1                 jne 0x8042e8
// 008042f7  896c241c             mov dword ptr [esp + 0x1c], ebp
// 008042fb  85ed                 test ebp, ebp
// 008042fd  0f8e8f000000         jle 0x804392
// 00804303  8b542424             mov edx, dword ptr [esp + 0x24]
// 00804307  8b02                 mov eax, dword ptr [edx]
// 00804309  53                   push ebx
// 0080430a  50                   push eax
// 0080430b  ffd6                 call esi
// 0080430d  8bf0                 mov esi, eax
// 0080430f  83c408               add esp, 8
// 00804312  85f6                 test esi, esi
// 00804314  747c                 je 0x804392
// 00804316  8b442414             mov eax, dword ptr [esp + 0x14]
// 0080431a  8d2c00               lea ebp, [eax + eax]
// 0080431d  2bc7                 sub eax, edi
// 0080431f  89442414             mov dword ptr [esp + 0x14], eax
// 00804323  eb0f                 jmp 0x804334
// 00804325  eb09                 jmp 0x804330
// 00804327  8da42400000000       lea esp, [esp]
// 0080432e  8bff                 mov edi, edi
// 00804330  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00804334  8b542424             mov edx, dword ptr [esp + 0x24]
// 00804338  8b442410             mov eax, dword ptr [esp + 0x10]
// 0080433c  8bce                 mov ecx, esi
// 0080433e  2b0a                 sub ecx, dword ptr [edx]
// 00804340  8d1c2e               lea ebx, [esi + ebp]
// 00804343  d1f9                 sar ecx, 1
// 00804345  2bc1                 sub eax, ecx
// 00804347  2bc7                 sub eax, edi
// 00804349  8d3c00               lea edi, [eax + eax]
// 0080434c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00804350  57                   push edi
// 00804351  8d0c46               lea ecx, [esi + eax*2]
// 00804354  51                   push ecx
// 00804355  57                   push edi
// 00804356  53                   push ebx
// 00804357  ff1580a89e00         call dword ptr [0x9ea880]
// 0080435d  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00804361  55                   push ebp
// 00804362  52                   push edx
// 00804363  55                   push ebp
// 00804364  56                   push esi
// 00804365  ff15c4a89e00         call dword ptr [0x9ea8c4]
// 0080436b  8b542448             mov edx, dword ptr [esp + 0x48]
// 0080436f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00804373  014c2430             add dword ptr [esp + 0x30], ecx
// 00804377  52                   push edx
// 00804378  33c0                 xor eax, eax
// 0080437a  53                   push ebx
// 0080437b  6689041f             mov word ptr [edi + ebx], ax
// 0080437f  ff15dca99e00         call dword ptr [0x9ea9dc]
// 00804385  8bf0                 mov esi, eax
// 00804387  83c428               add esp, 0x28
// 0080438a  85f6                 test esi, esi
// 0080438c  75a2                 jne 0x804330
// 0080438e  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00804392  5f                   pop edi
// 00804393  5e                   pop esi
// 00804394  8bc5                 mov eax, ebp
// 00804396  5d                   pop ebp
// 00804397  5b                   pop ebx
// 00804398  83c410               add esp, 0x10
// 0080439b  c3                   ret 
// 0080439c  5f                   pop edi
// 0080439d  5e                   pop esi
// 0080439e  5d                   pop ebp
// 0080439f  33c0                 xor eax, eax
// 008043a1  5b                   pop ebx
// 008043a2  83c410               add esp, 0x10
// 008043a5  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?REPLACEW_S@@YAHAAPA_WPB_W1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
