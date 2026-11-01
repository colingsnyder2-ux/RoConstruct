// from server: 100% by auto
// roc 2011-06 0085f720  unit: CXTPPropExchange  size: 358 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f720
//
// 0085f720  8b442404             mov eax, dword ptr [esp + 4]
// 0085f724  83ec10               sub esp, 0x10
// 0085f727  53                   push ebx
// 0085f728  55                   push ebp
// 0085f729  56                   push esi
// 0085f72a  8b30                 mov esi, dword ptr [eax]
// 0085f72c  33ed                 xor ebp, ebp
// 0085f72e  57                   push edi
// 0085f72f  3bf5                 cmp esi, ebp
// 0085f731  7506                 jne 0x85f739
// 0085f733  896c2410             mov dword ptr [esp + 0x10], ebp
// 0085f737  eb1a                 jmp 0x85f753
// 0085f739  8bc6                 mov eax, esi
// 0085f73b  8d5002               lea edx, [eax + 2]
// 0085f73e  8bff                 mov edi, edi
// 0085f740  668b08               mov cx, word ptr [eax]
// 0085f743  83c002               add eax, 2
// 0085f746  663bcd               cmp cx, bp
// 0085f749  75f5                 jne 0x85f740
// 0085f74b  2bc2                 sub eax, edx
// 0085f74d  d1f8                 sar eax, 1
// 0085f74f  89442410             mov dword ptr [esp + 0x10], eax
// 0085f753  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0085f757  3bdd                 cmp ebx, ebp
// 0085f759  0f841d010000         je 0x85f87c
// 0085f75f  8bc3                 mov eax, ebx
// 0085f761  8d5002               lea edx, [eax + 2]
// 0085f764  668b08               mov cx, word ptr [eax]
// 0085f767  83c002               add eax, 2
// 0085f76a  663bcd               cmp cx, bp
// 0085f76d  75f5                 jne 0x85f764
// 0085f76f  2bc2                 sub eax, edx
// 0085f771  d1f8                 sar eax, 1
// 0085f773  8bf8                 mov edi, eax
// 0085f775  897c2418             mov dword ptr [esp + 0x18], edi
// 0085f779  0f84fd000000         je 0x85f87c
// 0085f77f  396c2410             cmp dword ptr [esp + 0x10], ebp
// 0085f783  0f84f3000000         je 0x85f87c
// 0085f789  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0085f78d  3bc5                 cmp eax, ebp
// 0085f78f  7506                 jne 0x85f797
// 0085f791  896c2414             mov dword ptr [esp + 0x14], ebp
// 0085f795  eb1c                 jmp 0x85f7b3
// 0085f797  8d5002               lea edx, [eax + 2]
// 0085f79a  8d9b00000000         lea ebx, [ebx]
// 0085f7a0  668b08               mov cx, word ptr [eax]
// 0085f7a3  83c002               add eax, 2
// 0085f7a6  663bcd               cmp cx, bp
// 0085f7a9  75f5                 jne 0x85f7a0
// 0085f7ab  2bc2                 sub eax, edx
// 0085f7ad  d1f8                 sar eax, 1
// 0085f7af  89442414             mov dword ptr [esp + 0x14], eax
// 0085f7b3  53                   push ebx
// 0085f7b4  56                   push esi
// 0085f7b5  8b35e407a400         mov esi, dword ptr [0xa407e4]
// 0085f7bb  ffd6                 call esi
// 0085f7bd  83c408               add esp, 8
// 0085f7c0  85c0                 test eax, eax
// 0085f7c2  0f84aa000000         je 0x85f872
// 0085f7c8  8d0c78               lea ecx, [eax + edi*2]
// 0085f7cb  53                   push ebx
// 0085f7cc  51                   push ecx
// 0085f7cd  45                   inc ebp
// 0085f7ce  ffd6                 call esi
// 0085f7d0  83c408               add esp, 8
// 0085f7d3  85c0                 test eax, eax
// 0085f7d5  75f1                 jne 0x85f7c8
// 0085f7d7  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0085f7db  85ed                 test ebp, ebp
// 0085f7dd  0f8e8f000000         jle 0x85f872
// 0085f7e3  8b542424             mov edx, dword ptr [esp + 0x24]
// 0085f7e7  8b02                 mov eax, dword ptr [edx]
// 0085f7e9  53                   push ebx
// 0085f7ea  50                   push eax
// 0085f7eb  ffd6                 call esi
// 0085f7ed  8bf0                 mov esi, eax
// 0085f7ef  83c408               add esp, 8
// 0085f7f2  85f6                 test esi, esi
// 0085f7f4  747c                 je 0x85f872
// 0085f7f6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0085f7fa  8d2c00               lea ebp, [eax + eax]
// 0085f7fd  2bc7                 sub eax, edi
// 0085f7ff  89442414             mov dword ptr [esp + 0x14], eax
// 0085f803  eb0f                 jmp 0x85f814
// 0085f805  eb09                 jmp 0x85f810
// 0085f807  8da42400000000       lea esp, [esp]
// 0085f80e  8bff                 mov edi, edi
// 0085f810  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0085f814  8b542424             mov edx, dword ptr [esp + 0x24]
// 0085f818  8b442410             mov eax, dword ptr [esp + 0x10]
// 0085f81c  8bce                 mov ecx, esi
// 0085f81e  2b0a                 sub ecx, dword ptr [edx]
// 0085f820  8d1c2e               lea ebx, [esi + ebp]
// 0085f823  d1f9                 sar ecx, 1
// 0085f825  2bc1                 sub eax, ecx
// 0085f827  2bc7                 sub eax, edi
// 0085f829  8d3c00               lea edi, [eax + eax]
// 0085f82c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0085f830  57                   push edi
// 0085f831  8d0c46               lea ecx, [esi + eax*2]
// 0085f834  51                   push ecx
// 0085f835  57                   push edi
// 0085f836  53                   push ebx
// 0085f837  ff15fc09a400         call dword ptr [0xa409fc]
// 0085f83d  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0085f841  55                   push ebp
// 0085f842  52                   push edx
// 0085f843  55                   push ebp
// 0085f844  56                   push esi
// 0085f845  ff153c0aa400         call dword ptr [0xa40a3c]
// 0085f84b  8b542448             mov edx, dword ptr [esp + 0x48]
// 0085f84f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0085f853  014c2430             add dword ptr [esp + 0x30], ecx
// 0085f857  52                   push edx
// 0085f858  33c0                 xor eax, eax
// 0085f85a  53                   push ebx
// 0085f85b  6689041f             mov word ptr [edi + ebx], ax
// 0085f85f  ff15e407a400         call dword ptr [0xa407e4]
// 0085f865  8bf0                 mov esi, eax
// 0085f867  83c428               add esp, 0x28
// 0085f86a  85f6                 test esi, esi
// 0085f86c  75a2                 jne 0x85f810
// 0085f86e  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0085f872  5f                   pop edi
// 0085f873  5e                   pop esi
// 0085f874  8bc5                 mov eax, ebp
// 0085f876  5d                   pop ebp
// 0085f877  5b                   pop ebx
// 0085f878  83c410               add esp, 0x10
// 0085f87b  c3                   ret 
// 0085f87c  5f                   pop edi
// 0085f87d  5e                   pop esi
// 0085f87e  5d                   pop ebp
// 0085f87f  33c0                 xor eax, eax
// 0085f881  5b                   pop ebx
// 0085f882  83c410               add esp, 0x10
// 0085f885  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?REPLACEW_S@@YAHAAPA_WPB_W1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
