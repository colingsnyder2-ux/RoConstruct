// from server: 100% by auto
// roc 2010-06 0083dc10  unit: XTPPaintThemes::CXTPOfficeTheme  size: 513 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083dc10
//
// 0083dc10  83ec20               sub esp, 0x20
// 0083dc13  53                   push ebx
// 0083dc14  55                   push ebp
// 0083dc15  56                   push esi
// 0083dc16  57                   push edi
// 0083dc17  6a1e                 push 0x1e
// 0083dc19  8bd9                 mov ebx, ecx
// 0083dc1b  e8f0f4f6ff           call 0x7ad110
// 0083dc20  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0083dc24  50                   push eax
// 0083dc25  8d44243c             lea eax, [esp + 0x3c]
// 0083dc29  50                   push eax
// 0083dc2a  8bcd                 mov ecx, ebp
// 0083dc2c  e80dabf6ff           call 0x7a873e
// 0083dc31  8b742440             mov esi, dword ptr [esp + 0x40]
// 0083dc35  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0083dc39  8d0431               lea eax, [ecx + esi]
// 0083dc3c  99                   cdq 
// 0083dc3d  2bc2                 sub eax, edx
// 0083dc3f  d1f8                 sar eax, 1
// 0083dc41  837c244802           cmp dword ptr [esp + 0x48], 2
// 0083dc46  0f858e000000         jne 0x83dcda
// 0083dc4c  8d70f8               lea esi, [eax - 8]
// 0083dc4f  8d7808               lea edi, [eax + 8]
// 0083dc52  3bf7                 cmp esi, edi
// 0083dc54  0f8dad010000         jge 0x83de07
// 0083dc5a  8d9b00000000         lea ebx, [ebx]
// 0083dc60  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0083dc64  8d4804               lea ecx, [eax + 4]
// 0083dc67  8d5601               lea edx, [esi + 1]
// 0083dc6a  89542410             mov dword ptr [esp + 0x10], edx
// 0083dc6e  894c2414             mov dword ptr [esp + 0x14], ecx
// 0083dc72  8d5603               lea edx, [esi + 3]
// 0083dc75  83c006               add eax, 6
// 0083dc78  6a05                 push 5
// 0083dc7a  8bcb                 mov ecx, ebx
// 0083dc7c  8954241c             mov dword ptr [esp + 0x1c], edx
// 0083dc80  89442420             mov dword ptr [esp + 0x20], eax
// 0083dc84  e887f4f6ff           call 0x7ad110
// 0083dc89  50                   push eax
// 0083dc8a  8d442414             lea eax, [esp + 0x14]
// 0083dc8e  50                   push eax
// 0083dc8f  8bcd                 mov ecx, ebp
// 0083dc91  e8a8aaf6ff           call 0x7a873e
// 0083dc96  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0083dc9a  8d4803               lea ecx, [eax + 3]
// 0083dc9d  894c2424             mov dword ptr [esp + 0x24], ecx
// 0083dca1  8d5602               lea edx, [esi + 2]
// 0083dca4  83c005               add eax, 5
// 0083dca7  6a26                 push 0x26
// 0083dca9  8bcb                 mov ecx, ebx
// 0083dcab  89742424             mov dword ptr [esp + 0x24], esi
// 0083dcaf  8954242c             mov dword ptr [esp + 0x2c], edx
// 0083dcb3  89442430             mov dword ptr [esp + 0x30], eax
// 0083dcb7  e854f4f6ff           call 0x7ad110
// 0083dcbc  50                   push eax
// 0083dcbd  8d442424             lea eax, [esp + 0x24]
// 0083dcc1  50                   push eax
// 0083dcc2  8bcd                 mov ecx, ebp
// 0083dcc4  e875aaf6ff           call 0x7a873e
// 0083dcc9  83c604               add esi, 4
// 0083dccc  3bf7                 cmp esi, edi
// 0083dcce  7c90                 jl 0x83dc60
// 0083dcd0  5f                   pop edi
// 0083dcd1  5e                   pop esi
// 0083dcd2  5d                   pop ebp
// 0083dcd3  5b                   pop ebx
// 0083dcd4  83c420               add esp, 0x20
// 0083dcd7  c21800               ret 0x18
// 0083dcda  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0083dcde  83c7fc               add edi, -4
// 0083dce1  83c6fc               add esi, -4
// 0083dce4  8d4701               lea eax, [edi + 1]
// 0083dce7  8d4e01               lea ecx, [esi + 1]
// 0083dcea  89442424             mov dword ptr [esp + 0x24], eax
// 0083dcee  894c2420             mov dword ptr [esp + 0x20], ecx
// 0083dcf2  8d5603               lea edx, [esi + 3]
// 0083dcf5  8d4703               lea eax, [edi + 3]
// 0083dcf8  6a05                 push 5
// 0083dcfa  8bcb                 mov ecx, ebx
// 0083dcfc  8954242c             mov dword ptr [esp + 0x2c], edx
// 0083dd00  89442430             mov dword ptr [esp + 0x30], eax
// 0083dd04  e807f4f6ff           call 0x7ad110
// 0083dd09  50                   push eax
// 0083dd0a  8d442424             lea eax, [esp + 0x24]
// 0083dd0e  50                   push eax
// 0083dd0f  8bcd                 mov ecx, ebp
// 0083dd11  e828aaf6ff           call 0x7a873e
// 0083dd16  8d4e02               lea ecx, [esi + 2]
// 0083dd19  894c2428             mov dword ptr [esp + 0x28], ecx
// 0083dd1d  8d4702               lea eax, [edi + 2]
// 0083dd20  6a26                 push 0x26
// 0083dd22  8bcb                 mov ecx, ebx
// 0083dd24  89742424             mov dword ptr [esp + 0x24], esi
// 0083dd28  897c2428             mov dword ptr [esp + 0x28], edi
// 0083dd2c  89442430             mov dword ptr [esp + 0x30], eax
// 0083dd30  e8dbf3f6ff           call 0x7ad110
// 0083dd35  50                   push eax
// 0083dd36  8d542424             lea edx, [esp + 0x24]
// 0083dd3a  52                   push edx
// 0083dd3b  8bcd                 mov ecx, ebp
// 0083dd3d  e8fca9f6ff           call 0x7a873e
// 0083dd42  83ee04               sub esi, 4
// 0083dd45  8d4601               lea eax, [esi + 1]
// 0083dd48  89442420             mov dword ptr [esp + 0x20], eax
// 0083dd4c  8d4701               lea eax, [edi + 1]
// 0083dd4f  8d4e03               lea ecx, [esi + 3]
// 0083dd52  89442424             mov dword ptr [esp + 0x24], eax
// 0083dd56  894c2428             mov dword ptr [esp + 0x28], ecx
// 0083dd5a  8d4703               lea eax, [edi + 3]
// 0083dd5d  6a05                 push 5
// 0083dd5f  8bcb                 mov ecx, ebx
// 0083dd61  89442430             mov dword ptr [esp + 0x30], eax
// 0083dd65  e8a6f3f6ff           call 0x7ad110
// 0083dd6a  50                   push eax
// 0083dd6b  8d542424             lea edx, [esp + 0x24]
// 0083dd6f  52                   push edx
// 0083dd70  8bcd                 mov ecx, ebp
// 0083dd72  e8c7a9f6ff           call 0x7a873e
// 0083dd77  8d4602               lea eax, [esi + 2]
// 0083dd7a  89442428             mov dword ptr [esp + 0x28], eax
// 0083dd7e  8d4702               lea eax, [edi + 2]
// 0083dd81  6a26                 push 0x26
// 0083dd83  8bcb                 mov ecx, ebx
// 0083dd85  89742424             mov dword ptr [esp + 0x24], esi
// 0083dd89  897c2428             mov dword ptr [esp + 0x28], edi
// 0083dd8d  89442430             mov dword ptr [esp + 0x30], eax
// 0083dd91  e87af3f6ff           call 0x7ad110
// 0083dd96  50                   push eax
// 0083dd97  8d4c2424             lea ecx, [esp + 0x24]
// 0083dd9b  51                   push ecx
// 0083dd9c  8bcd                 mov ecx, ebp
// 0083dd9e  e89ba9f6ff           call 0x7a873e
// 0083dda3  83c604               add esi, 4
// 0083dda6  83ef04               sub edi, 4
// 0083dda9  8d5601               lea edx, [esi + 1]
// 0083ddac  8d4e03               lea ecx, [esi + 3]
// 0083ddaf  89542420             mov dword ptr [esp + 0x20], edx
// 0083ddb3  8d4701               lea eax, [edi + 1]
// 0083ddb6  894c2428             mov dword ptr [esp + 0x28], ecx
// 0083ddba  8d5703               lea edx, [edi + 3]
// 0083ddbd  6a05                 push 5
// 0083ddbf  8bcb                 mov ecx, ebx
// 0083ddc1  89442428             mov dword ptr [esp + 0x28], eax
// 0083ddc5  89542430             mov dword ptr [esp + 0x30], edx
// 0083ddc9  e842f3f6ff           call 0x7ad110
// 0083ddce  50                   push eax
// 0083ddcf  8d442424             lea eax, [esp + 0x24]
// 0083ddd3  50                   push eax
// 0083ddd4  8bcd                 mov ecx, ebp
// 0083ddd6  e863a9f6ff           call 0x7a873e
// 0083dddb  89742420             mov dword ptr [esp + 0x20], esi
// 0083dddf  897c2424             mov dword ptr [esp + 0x24], edi
// 0083dde3  83c602               add esi, 2
// 0083dde6  83c702               add edi, 2
// 0083dde9  6a26                 push 0x26
// 0083ddeb  8bcb                 mov ecx, ebx
// 0083dded  8974242c             mov dword ptr [esp + 0x2c], esi
// 0083ddf1  897c2430             mov dword ptr [esp + 0x30], edi
// 0083ddf5  e816f3f6ff           call 0x7ad110
// 0083ddfa  50                   push eax
// 0083ddfb  8d4c2424             lea ecx, [esp + 0x24]
// 0083ddff  51                   push ecx
// 0083de00  8bcd                 mov ecx, ebp
// 0083de02  e837a9f6ff           call 0x7a873e
// 0083de07  5f                   pop edi
// 0083de08  5e                   pop esi
// 0083de09  5d                   pop ebp
// 0083de0a  5b                   pop ebx
// 0083de0b  83c420               add esp, 0x20
// 0083de0e  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupResizeGripper@CXTPOfficeTheme@@UAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
