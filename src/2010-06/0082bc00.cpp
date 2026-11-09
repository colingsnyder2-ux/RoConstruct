// from server: 100% by auto
// roc 2010-06 0082bc00  unit: XTPPaintThemes::CXTPDefaultTheme  size: 490 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082bc00
//
// 0082bc00  8b442408             mov eax, dword ptr [esp + 8]
// 0082bc04  83ec20               sub esp, 0x20
// 0082bc07  53                   push ebx
// 0082bc08  55                   push ebp
// 0082bc09  56                   push esi
// 0082bc0a  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0082bc0e  03c6                 add eax, esi
// 0082bc10  99                   cdq 
// 0082bc11  2bc2                 sub eax, edx
// 0082bc13  d1f8                 sar eax, 1
// 0082bc15  837c244402           cmp dword ptr [esp + 0x44], 2
// 0082bc1a  57                   push edi
// 0082bc1b  8bd9                 mov ebx, ecx
// 0082bc1d  0f858c000000         jne 0x82bcaf
// 0082bc23  8d70f8               lea esi, [eax - 8]
// 0082bc26  8d6808               lea ebp, [eax + 8]
// 0082bc29  3bf5                 cmp esi, ebp
// 0082bc2b  0f8daf010000         jge 0x82bde0
// 0082bc31  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0082bc35  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0082bc39  8d4e01               lea ecx, [esi + 1]
// 0082bc3c  894c2410             mov dword ptr [esp + 0x10], ecx
// 0082bc40  8d5004               lea edx, [eax + 4]
// 0082bc43  8d4e03               lea ecx, [esi + 3]
// 0082bc46  894c2418             mov dword ptr [esp + 0x18], ecx
// 0082bc4a  83c006               add eax, 6
// 0082bc4d  6a05                 push 5
// 0082bc4f  8bcb                 mov ecx, ebx
// 0082bc51  89542418             mov dword ptr [esp + 0x18], edx
// 0082bc55  89442420             mov dword ptr [esp + 0x20], eax
// 0082bc59  e8b214f8ff           call 0x7ad110
// 0082bc5e  50                   push eax
// 0082bc5f  8d542414             lea edx, [esp + 0x14]
// 0082bc63  52                   push edx
// 0082bc64  8bcf                 mov ecx, edi
// 0082bc66  e8d3caf7ff           call 0x7a873e
// 0082bc6b  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0082bc6f  8d4803               lea ecx, [eax + 3]
// 0082bc72  894c2424             mov dword ptr [esp + 0x24], ecx
// 0082bc76  8d5602               lea edx, [esi + 2]
// 0082bc79  83c005               add eax, 5
// 0082bc7c  6a26                 push 0x26
// 0082bc7e  8bcb                 mov ecx, ebx
// 0082bc80  89742424             mov dword ptr [esp + 0x24], esi
// 0082bc84  8954242c             mov dword ptr [esp + 0x2c], edx
// 0082bc88  89442430             mov dword ptr [esp + 0x30], eax
// 0082bc8c  e87f14f8ff           call 0x7ad110
// 0082bc91  50                   push eax
// 0082bc92  8d442424             lea eax, [esp + 0x24]
// 0082bc96  50                   push eax
// 0082bc97  8bcf                 mov ecx, edi
// 0082bc99  e8a0caf7ff           call 0x7a873e
// 0082bc9e  83c604               add esi, 4
// 0082bca1  3bf5                 cmp esi, ebp
// 0082bca3  7c90                 jl 0x82bc35
// 0082bca5  5f                   pop edi
// 0082bca6  5e                   pop esi
// 0082bca7  5d                   pop ebp
// 0082bca8  5b                   pop ebx
// 0082bca9  83c420               add esp, 0x20
// 0082bcac  c21800               ret 0x18
// 0082bcaf  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0082bcb3  83c7fc               add edi, -4
// 0082bcb6  83c6fc               add esi, -4
// 0082bcb9  8d4701               lea eax, [edi + 1]
// 0082bcbc  8d4e01               lea ecx, [esi + 1]
// 0082bcbf  89442424             mov dword ptr [esp + 0x24], eax
// 0082bcc3  894c2420             mov dword ptr [esp + 0x20], ecx
// 0082bcc7  8d5603               lea edx, [esi + 3]
// 0082bcca  8d4703               lea eax, [edi + 3]
// 0082bccd  6a05                 push 5
// 0082bccf  8bcb                 mov ecx, ebx
// 0082bcd1  8954242c             mov dword ptr [esp + 0x2c], edx
// 0082bcd5  89442430             mov dword ptr [esp + 0x30], eax
// 0082bcd9  e83214f8ff           call 0x7ad110
// 0082bcde  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0082bce2  50                   push eax
// 0082bce3  8d442424             lea eax, [esp + 0x24]
// 0082bce7  50                   push eax
// 0082bce8  8bcd                 mov ecx, ebp
// 0082bcea  e84fcaf7ff           call 0x7a873e
// 0082bcef  8d4e02               lea ecx, [esi + 2]
// 0082bcf2  894c2428             mov dword ptr [esp + 0x28], ecx
// 0082bcf6  8d4702               lea eax, [edi + 2]
// 0082bcf9  6a26                 push 0x26
// 0082bcfb  8bcb                 mov ecx, ebx
// 0082bcfd  89742424             mov dword ptr [esp + 0x24], esi
// 0082bd01  897c2428             mov dword ptr [esp + 0x28], edi
// 0082bd05  89442430             mov dword ptr [esp + 0x30], eax
// 0082bd09  e80214f8ff           call 0x7ad110
// 0082bd0e  50                   push eax
// 0082bd0f  8d542424             lea edx, [esp + 0x24]
// 0082bd13  52                   push edx
// 0082bd14  8bcd                 mov ecx, ebp
// 0082bd16  e823caf7ff           call 0x7a873e
// 0082bd1b  83ee04               sub esi, 4
// 0082bd1e  8d4601               lea eax, [esi + 1]
// 0082bd21  89442420             mov dword ptr [esp + 0x20], eax
// 0082bd25  8d4701               lea eax, [edi + 1]
// 0082bd28  8d4e03               lea ecx, [esi + 3]
// 0082bd2b  89442424             mov dword ptr [esp + 0x24], eax
// 0082bd2f  894c2428             mov dword ptr [esp + 0x28], ecx
// 0082bd33  8d4703               lea eax, [edi + 3]
// 0082bd36  6a05                 push 5
// 0082bd38  8bcb                 mov ecx, ebx
// 0082bd3a  89442430             mov dword ptr [esp + 0x30], eax
// 0082bd3e  e8cd13f8ff           call 0x7ad110
// 0082bd43  50                   push eax
// 0082bd44  8d542424             lea edx, [esp + 0x24]
// 0082bd48  52                   push edx
// 0082bd49  8bcd                 mov ecx, ebp
// 0082bd4b  e8eec9f7ff           call 0x7a873e
// 0082bd50  8d4602               lea eax, [esi + 2]
// 0082bd53  89442428             mov dword ptr [esp + 0x28], eax
// 0082bd57  8d4702               lea eax, [edi + 2]
// 0082bd5a  6a26                 push 0x26
// 0082bd5c  8bcb                 mov ecx, ebx
// 0082bd5e  89742424             mov dword ptr [esp + 0x24], esi
// 0082bd62  897c2428             mov dword ptr [esp + 0x28], edi
// 0082bd66  89442430             mov dword ptr [esp + 0x30], eax
// 0082bd6a  e8a113f8ff           call 0x7ad110
// 0082bd6f  50                   push eax
// 0082bd70  8d4c2424             lea ecx, [esp + 0x24]
// 0082bd74  51                   push ecx
// 0082bd75  8bcd                 mov ecx, ebp
// 0082bd77  e8c2c9f7ff           call 0x7a873e
// 0082bd7c  83c604               add esi, 4
// 0082bd7f  83ef04               sub edi, 4
// 0082bd82  8d5601               lea edx, [esi + 1]
// 0082bd85  8d4e03               lea ecx, [esi + 3]
// 0082bd88  89542420             mov dword ptr [esp + 0x20], edx
// 0082bd8c  8d4701               lea eax, [edi + 1]
// 0082bd8f  894c2428             mov dword ptr [esp + 0x28], ecx
// 0082bd93  8d5703               lea edx, [edi + 3]
// 0082bd96  6a05                 push 5
// 0082bd98  8bcb                 mov ecx, ebx
// 0082bd9a  89442428             mov dword ptr [esp + 0x28], eax
// 0082bd9e  89542430             mov dword ptr [esp + 0x30], edx
// 0082bda2  e86913f8ff           call 0x7ad110
// 0082bda7  50                   push eax
// 0082bda8  8d442424             lea eax, [esp + 0x24]
// 0082bdac  50                   push eax
// 0082bdad  8bcd                 mov ecx, ebp
// 0082bdaf  e88ac9f7ff           call 0x7a873e
// 0082bdb4  89742420             mov dword ptr [esp + 0x20], esi
// 0082bdb8  897c2424             mov dword ptr [esp + 0x24], edi
// 0082bdbc  83c602               add esi, 2
// 0082bdbf  83c702               add edi, 2
// 0082bdc2  6a26                 push 0x26
// 0082bdc4  8bcb                 mov ecx, ebx
// 0082bdc6  8974242c             mov dword ptr [esp + 0x2c], esi
// 0082bdca  897c2430             mov dword ptr [esp + 0x30], edi
// 0082bdce  e83d13f8ff           call 0x7ad110
// 0082bdd3  50                   push eax
// 0082bdd4  8d4c2424             lea ecx, [esp + 0x24]
// 0082bdd8  51                   push ecx
// 0082bdd9  8bcd                 mov ecx, ebp
// 0082bddb  e85ec9f7ff           call 0x7a873e
// 0082bde0  5f                   pop edi
// 0082bde1  5e                   pop esi
// 0082bde2  5d                   pop ebp
// 0082bde3  5b                   pop ebx
// 0082bde4  83c420               add esp, 0x20
// 0082bde7  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawPopupResizeGripper@CXTPDefaultTheme@@UAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
