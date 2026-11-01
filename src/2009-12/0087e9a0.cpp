// from server: 100% by auto
// roc 2009-12 0087e9a0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 490 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087e9a0
//
// 0087e9a0  8b442408             mov eax, dword ptr [esp + 8]
// 0087e9a4  83ec20               sub esp, 0x20
// 0087e9a7  53                   push ebx
// 0087e9a8  55                   push ebp
// 0087e9a9  56                   push esi
// 0087e9aa  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0087e9ae  03c6                 add eax, esi
// 0087e9b0  99                   cdq 
// 0087e9b1  2bc2                 sub eax, edx
// 0087e9b3  d1f8                 sar eax, 1
// 0087e9b5  837c244402           cmp dword ptr [esp + 0x44], 2
// 0087e9ba  57                   push edi
// 0087e9bb  8bd9                 mov ebx, ecx
// 0087e9bd  0f858c000000         jne 0x87ea4f
// 0087e9c3  8d70f8               lea esi, [eax - 8]
// 0087e9c6  8d6808               lea ebp, [eax + 8]
// 0087e9c9  3bf5                 cmp esi, ebp
// 0087e9cb  0f8daf010000         jge 0x87eb80
// 0087e9d1  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0087e9d5  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0087e9d9  8d4e01               lea ecx, [esi + 1]
// 0087e9dc  894c2410             mov dword ptr [esp + 0x10], ecx
// 0087e9e0  8d5004               lea edx, [eax + 4]
// 0087e9e3  8d4e03               lea ecx, [esi + 3]
// 0087e9e6  894c2418             mov dword ptr [esp + 0x18], ecx
// 0087e9ea  83c006               add eax, 6
// 0087e9ed  6a05                 push 5
// 0087e9ef  8bcb                 mov ecx, ebx
// 0087e9f1  89542418             mov dword ptr [esp + 0x18], edx
// 0087e9f5  89442420             mov dword ptr [esp + 0x20], eax
// 0087e9f9  e842ecf7ff           call 0x7fd640
// 0087e9fe  50                   push eax
// 0087e9ff  8d542414             lea edx, [esp + 0x14]
// 0087ea03  52                   push edx
// 0087ea04  8bcf                 mov ecx, edi
// 0087ea06  e8f35bf7ff           call 0x7f45fe
// 0087ea0b  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0087ea0f  8d4803               lea ecx, [eax + 3]
// 0087ea12  894c2424             mov dword ptr [esp + 0x24], ecx
// 0087ea16  8d5602               lea edx, [esi + 2]
// 0087ea19  83c005               add eax, 5
// 0087ea1c  6a26                 push 0x26
// 0087ea1e  8bcb                 mov ecx, ebx
// 0087ea20  89742424             mov dword ptr [esp + 0x24], esi
// 0087ea24  8954242c             mov dword ptr [esp + 0x2c], edx
// 0087ea28  89442430             mov dword ptr [esp + 0x30], eax
// 0087ea2c  e80fecf7ff           call 0x7fd640
// 0087ea31  50                   push eax
// 0087ea32  8d442424             lea eax, [esp + 0x24]
// 0087ea36  50                   push eax
// 0087ea37  8bcf                 mov ecx, edi
// 0087ea39  e8c05bf7ff           call 0x7f45fe
// 0087ea3e  83c604               add esi, 4
// 0087ea41  3bf5                 cmp esi, ebp
// 0087ea43  7c90                 jl 0x87e9d5
// 0087ea45  5f                   pop edi
// 0087ea46  5e                   pop esi
// 0087ea47  5d                   pop ebp
// 0087ea48  5b                   pop ebx
// 0087ea49  83c420               add esp, 0x20
// 0087ea4c  c21800               ret 0x18
// 0087ea4f  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0087ea53  83c7fc               add edi, -4
// 0087ea56  83c6fc               add esi, -4
// 0087ea59  8d4701               lea eax, [edi + 1]
// 0087ea5c  8d4e01               lea ecx, [esi + 1]
// 0087ea5f  89442424             mov dword ptr [esp + 0x24], eax
// 0087ea63  894c2420             mov dword ptr [esp + 0x20], ecx
// 0087ea67  8d5603               lea edx, [esi + 3]
// 0087ea6a  8d4703               lea eax, [edi + 3]
// 0087ea6d  6a05                 push 5
// 0087ea6f  8bcb                 mov ecx, ebx
// 0087ea71  8954242c             mov dword ptr [esp + 0x2c], edx
// 0087ea75  89442430             mov dword ptr [esp + 0x30], eax
// 0087ea79  e8c2ebf7ff           call 0x7fd640
// 0087ea7e  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0087ea82  50                   push eax
// 0087ea83  8d442424             lea eax, [esp + 0x24]
// 0087ea87  50                   push eax
// 0087ea88  8bcd                 mov ecx, ebp
// 0087ea8a  e86f5bf7ff           call 0x7f45fe
// 0087ea8f  8d4e02               lea ecx, [esi + 2]
// 0087ea92  894c2428             mov dword ptr [esp + 0x28], ecx
// 0087ea96  8d4702               lea eax, [edi + 2]
// 0087ea99  6a26                 push 0x26
// 0087ea9b  8bcb                 mov ecx, ebx
// 0087ea9d  89742424             mov dword ptr [esp + 0x24], esi
// 0087eaa1  897c2428             mov dword ptr [esp + 0x28], edi
// 0087eaa5  89442430             mov dword ptr [esp + 0x30], eax
// 0087eaa9  e892ebf7ff           call 0x7fd640
// 0087eaae  50                   push eax
// 0087eaaf  8d542424             lea edx, [esp + 0x24]
// 0087eab3  52                   push edx
// 0087eab4  8bcd                 mov ecx, ebp
// 0087eab6  e8435bf7ff           call 0x7f45fe
// 0087eabb  83ee04               sub esi, 4
// 0087eabe  8d4601               lea eax, [esi + 1]
// 0087eac1  89442420             mov dword ptr [esp + 0x20], eax
// 0087eac5  8d4701               lea eax, [edi + 1]
// 0087eac8  8d4e03               lea ecx, [esi + 3]
// 0087eacb  89442424             mov dword ptr [esp + 0x24], eax
// 0087eacf  894c2428             mov dword ptr [esp + 0x28], ecx
// 0087ead3  8d4703               lea eax, [edi + 3]
// 0087ead6  6a05                 push 5
// 0087ead8  8bcb                 mov ecx, ebx
// 0087eada  89442430             mov dword ptr [esp + 0x30], eax
// 0087eade  e85debf7ff           call 0x7fd640
// 0087eae3  50                   push eax
// 0087eae4  8d542424             lea edx, [esp + 0x24]
// 0087eae8  52                   push edx
// 0087eae9  8bcd                 mov ecx, ebp
// 0087eaeb  e80e5bf7ff           call 0x7f45fe
// 0087eaf0  8d4602               lea eax, [esi + 2]
// 0087eaf3  89442428             mov dword ptr [esp + 0x28], eax
// 0087eaf7  8d4702               lea eax, [edi + 2]
// 0087eafa  6a26                 push 0x26
// 0087eafc  8bcb                 mov ecx, ebx
// 0087eafe  89742424             mov dword ptr [esp + 0x24], esi
// 0087eb02  897c2428             mov dword ptr [esp + 0x28], edi
// 0087eb06  89442430             mov dword ptr [esp + 0x30], eax
// 0087eb0a  e831ebf7ff           call 0x7fd640
// 0087eb0f  50                   push eax
// 0087eb10  8d4c2424             lea ecx, [esp + 0x24]
// 0087eb14  51                   push ecx
// 0087eb15  8bcd                 mov ecx, ebp
// 0087eb17  e8e25af7ff           call 0x7f45fe
// 0087eb1c  83c604               add esi, 4
// 0087eb1f  83ef04               sub edi, 4
// 0087eb22  8d5601               lea edx, [esi + 1]
// 0087eb25  8d4e03               lea ecx, [esi + 3]
// 0087eb28  89542420             mov dword ptr [esp + 0x20], edx
// 0087eb2c  8d4701               lea eax, [edi + 1]
// 0087eb2f  894c2428             mov dword ptr [esp + 0x28], ecx
// 0087eb33  8d5703               lea edx, [edi + 3]
// 0087eb36  6a05                 push 5
// 0087eb38  8bcb                 mov ecx, ebx
// 0087eb3a  89442428             mov dword ptr [esp + 0x28], eax
// 0087eb3e  89542430             mov dword ptr [esp + 0x30], edx
// 0087eb42  e8f9eaf7ff           call 0x7fd640
// 0087eb47  50                   push eax
// 0087eb48  8d442424             lea eax, [esp + 0x24]
// 0087eb4c  50                   push eax
// 0087eb4d  8bcd                 mov ecx, ebp
// 0087eb4f  e8aa5af7ff           call 0x7f45fe
// 0087eb54  89742420             mov dword ptr [esp + 0x20], esi
// 0087eb58  897c2424             mov dword ptr [esp + 0x24], edi
// 0087eb5c  83c602               add esi, 2
// 0087eb5f  83c702               add edi, 2
// 0087eb62  6a26                 push 0x26
// 0087eb64  8bcb                 mov ecx, ebx
// 0087eb66  8974242c             mov dword ptr [esp + 0x2c], esi
// 0087eb6a  897c2430             mov dword ptr [esp + 0x30], edi
// 0087eb6e  e8cdeaf7ff           call 0x7fd640
// 0087eb73  50                   push eax
// 0087eb74  8d4c2424             lea ecx, [esp + 0x24]
// 0087eb78  51                   push ecx
// 0087eb79  8bcd                 mov ecx, ebp
// 0087eb7b  e87e5af7ff           call 0x7f45fe
// 0087eb80  5f                   pop edi
// 0087eb81  5e                   pop esi
// 0087eb82  5d                   pop ebp
// 0087eb83  5b                   pop ebx
// 0087eb84  83c420               add esp, 0x20
// 0087eb87  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawPopupResizeGripper@CXTPDefaultTheme@@UAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
