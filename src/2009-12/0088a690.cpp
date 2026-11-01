// from server: 100% by auto
// roc 2009-12 0088a690  unit: XTPPaintThemes::CXTPOfficeTheme  size: 513 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088a690
//
// 0088a690  83ec20               sub esp, 0x20
// 0088a693  53                   push ebx
// 0088a694  55                   push ebp
// 0088a695  56                   push esi
// 0088a696  57                   push edi
// 0088a697  6a1e                 push 0x1e
// 0088a699  8bd9                 mov ebx, ecx
// 0088a69b  e8a02ff7ff           call 0x7fd640
// 0088a6a0  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0088a6a4  50                   push eax
// 0088a6a5  8d44243c             lea eax, [esp + 0x3c]
// 0088a6a9  50                   push eax
// 0088a6aa  8bcd                 mov ecx, ebp
// 0088a6ac  e84d9ff6ff           call 0x7f45fe
// 0088a6b1  8b742440             mov esi, dword ptr [esp + 0x40]
// 0088a6b5  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0088a6b9  8d0431               lea eax, [ecx + esi]
// 0088a6bc  99                   cdq 
// 0088a6bd  2bc2                 sub eax, edx
// 0088a6bf  d1f8                 sar eax, 1
// 0088a6c1  837c244802           cmp dword ptr [esp + 0x48], 2
// 0088a6c6  0f858e000000         jne 0x88a75a
// 0088a6cc  8d70f8               lea esi, [eax - 8]
// 0088a6cf  8d7808               lea edi, [eax + 8]
// 0088a6d2  3bf7                 cmp esi, edi
// 0088a6d4  0f8dad010000         jge 0x88a887
// 0088a6da  8d9b00000000         lea ebx, [ebx]
// 0088a6e0  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0088a6e4  8d4804               lea ecx, [eax + 4]
// 0088a6e7  8d5601               lea edx, [esi + 1]
// 0088a6ea  89542410             mov dword ptr [esp + 0x10], edx
// 0088a6ee  894c2414             mov dword ptr [esp + 0x14], ecx
// 0088a6f2  8d5603               lea edx, [esi + 3]
// 0088a6f5  83c006               add eax, 6
// 0088a6f8  6a05                 push 5
// 0088a6fa  8bcb                 mov ecx, ebx
// 0088a6fc  8954241c             mov dword ptr [esp + 0x1c], edx
// 0088a700  89442420             mov dword ptr [esp + 0x20], eax
// 0088a704  e8372ff7ff           call 0x7fd640
// 0088a709  50                   push eax
// 0088a70a  8d442414             lea eax, [esp + 0x14]
// 0088a70e  50                   push eax
// 0088a70f  8bcd                 mov ecx, ebp
// 0088a711  e8e89ef6ff           call 0x7f45fe
// 0088a716  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0088a71a  8d4803               lea ecx, [eax + 3]
// 0088a71d  894c2424             mov dword ptr [esp + 0x24], ecx
// 0088a721  8d5602               lea edx, [esi + 2]
// 0088a724  83c005               add eax, 5
// 0088a727  6a26                 push 0x26
// 0088a729  8bcb                 mov ecx, ebx
// 0088a72b  89742424             mov dword ptr [esp + 0x24], esi
// 0088a72f  8954242c             mov dword ptr [esp + 0x2c], edx
// 0088a733  89442430             mov dword ptr [esp + 0x30], eax
// 0088a737  e8042ff7ff           call 0x7fd640
// 0088a73c  50                   push eax
// 0088a73d  8d442424             lea eax, [esp + 0x24]
// 0088a741  50                   push eax
// 0088a742  8bcd                 mov ecx, ebp
// 0088a744  e8b59ef6ff           call 0x7f45fe
// 0088a749  83c604               add esi, 4
// 0088a74c  3bf7                 cmp esi, edi
// 0088a74e  7c90                 jl 0x88a6e0
// 0088a750  5f                   pop edi
// 0088a751  5e                   pop esi
// 0088a752  5d                   pop ebp
// 0088a753  5b                   pop ebx
// 0088a754  83c420               add esp, 0x20
// 0088a757  c21800               ret 0x18
// 0088a75a  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0088a75e  83c7fc               add edi, -4
// 0088a761  83c6fc               add esi, -4
// 0088a764  8d4701               lea eax, [edi + 1]
// 0088a767  8d4e01               lea ecx, [esi + 1]
// 0088a76a  89442424             mov dword ptr [esp + 0x24], eax
// 0088a76e  894c2420             mov dword ptr [esp + 0x20], ecx
// 0088a772  8d5603               lea edx, [esi + 3]
// 0088a775  8d4703               lea eax, [edi + 3]
// 0088a778  6a05                 push 5
// 0088a77a  8bcb                 mov ecx, ebx
// 0088a77c  8954242c             mov dword ptr [esp + 0x2c], edx
// 0088a780  89442430             mov dword ptr [esp + 0x30], eax
// 0088a784  e8b72ef7ff           call 0x7fd640
// 0088a789  50                   push eax
// 0088a78a  8d442424             lea eax, [esp + 0x24]
// 0088a78e  50                   push eax
// 0088a78f  8bcd                 mov ecx, ebp
// 0088a791  e8689ef6ff           call 0x7f45fe
// 0088a796  8d4e02               lea ecx, [esi + 2]
// 0088a799  894c2428             mov dword ptr [esp + 0x28], ecx
// 0088a79d  8d4702               lea eax, [edi + 2]
// 0088a7a0  6a26                 push 0x26
// 0088a7a2  8bcb                 mov ecx, ebx
// 0088a7a4  89742424             mov dword ptr [esp + 0x24], esi
// 0088a7a8  897c2428             mov dword ptr [esp + 0x28], edi
// 0088a7ac  89442430             mov dword ptr [esp + 0x30], eax
// 0088a7b0  e88b2ef7ff           call 0x7fd640
// 0088a7b5  50                   push eax
// 0088a7b6  8d542424             lea edx, [esp + 0x24]
// 0088a7ba  52                   push edx
// 0088a7bb  8bcd                 mov ecx, ebp
// 0088a7bd  e83c9ef6ff           call 0x7f45fe
// 0088a7c2  83ee04               sub esi, 4
// 0088a7c5  8d4601               lea eax, [esi + 1]
// 0088a7c8  89442420             mov dword ptr [esp + 0x20], eax
// 0088a7cc  8d4701               lea eax, [edi + 1]
// 0088a7cf  8d4e03               lea ecx, [esi + 3]
// 0088a7d2  89442424             mov dword ptr [esp + 0x24], eax
// 0088a7d6  894c2428             mov dword ptr [esp + 0x28], ecx
// 0088a7da  8d4703               lea eax, [edi + 3]
// 0088a7dd  6a05                 push 5
// 0088a7df  8bcb                 mov ecx, ebx
// 0088a7e1  89442430             mov dword ptr [esp + 0x30], eax
// 0088a7e5  e8562ef7ff           call 0x7fd640
// 0088a7ea  50                   push eax
// 0088a7eb  8d542424             lea edx, [esp + 0x24]
// 0088a7ef  52                   push edx
// 0088a7f0  8bcd                 mov ecx, ebp
// 0088a7f2  e8079ef6ff           call 0x7f45fe
// 0088a7f7  8d4602               lea eax, [esi + 2]
// 0088a7fa  89442428             mov dword ptr [esp + 0x28], eax
// 0088a7fe  8d4702               lea eax, [edi + 2]
// 0088a801  6a26                 push 0x26
// 0088a803  8bcb                 mov ecx, ebx
// 0088a805  89742424             mov dword ptr [esp + 0x24], esi
// 0088a809  897c2428             mov dword ptr [esp + 0x28], edi
// 0088a80d  89442430             mov dword ptr [esp + 0x30], eax
// 0088a811  e82a2ef7ff           call 0x7fd640
// 0088a816  50                   push eax
// 0088a817  8d4c2424             lea ecx, [esp + 0x24]
// 0088a81b  51                   push ecx
// 0088a81c  8bcd                 mov ecx, ebp
// 0088a81e  e8db9df6ff           call 0x7f45fe
// 0088a823  83c604               add esi, 4
// 0088a826  83ef04               sub edi, 4
// 0088a829  8d5601               lea edx, [esi + 1]
// 0088a82c  8d4e03               lea ecx, [esi + 3]
// 0088a82f  89542420             mov dword ptr [esp + 0x20], edx
// 0088a833  8d4701               lea eax, [edi + 1]
// 0088a836  894c2428             mov dword ptr [esp + 0x28], ecx
// 0088a83a  8d5703               lea edx, [edi + 3]
// 0088a83d  6a05                 push 5
// 0088a83f  8bcb                 mov ecx, ebx
// 0088a841  89442428             mov dword ptr [esp + 0x28], eax
// 0088a845  89542430             mov dword ptr [esp + 0x30], edx
// 0088a849  e8f22df7ff           call 0x7fd640
// 0088a84e  50                   push eax
// 0088a84f  8d442424             lea eax, [esp + 0x24]
// 0088a853  50                   push eax
// 0088a854  8bcd                 mov ecx, ebp
// 0088a856  e8a39df6ff           call 0x7f45fe
// 0088a85b  89742420             mov dword ptr [esp + 0x20], esi
// 0088a85f  897c2424             mov dword ptr [esp + 0x24], edi
// 0088a863  83c602               add esi, 2
// 0088a866  83c702               add edi, 2
// 0088a869  6a26                 push 0x26
// 0088a86b  8bcb                 mov ecx, ebx
// 0088a86d  8974242c             mov dword ptr [esp + 0x2c], esi
// 0088a871  897c2430             mov dword ptr [esp + 0x30], edi
// 0088a875  e8c62df7ff           call 0x7fd640
// 0088a87a  50                   push eax
// 0088a87b  8d4c2424             lea ecx, [esp + 0x24]
// 0088a87f  51                   push ecx
// 0088a880  8bcd                 mov ecx, ebp
// 0088a882  e8779df6ff           call 0x7f45fe
// 0088a887  5f                   pop edi
// 0088a888  5e                   pop esi
// 0088a889  5d                   pop ebp
// 0088a88a  5b                   pop ebx
// 0088a88b  83c420               add esp, 0x20
// 0088a88e  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupResizeGripper@CXTPOfficeTheme@@UAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
