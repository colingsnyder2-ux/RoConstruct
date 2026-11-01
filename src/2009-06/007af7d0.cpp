// from server: 100% by auto
// roc 2009-06 007af7d0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 513 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007af7d0
//
// 007af7d0  83ec20               sub esp, 0x20
// 007af7d3  53                   push ebx
// 007af7d4  55                   push ebp
// 007af7d5  56                   push esi
// 007af7d6  57                   push edi
// 007af7d7  6a1e                 push 0x1e
// 007af7d9  8bd9                 mov ebx, ecx
// 007af7db  e8a02ff7ff           call 0x722780
// 007af7e0  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 007af7e4  50                   push eax
// 007af7e5  8d44243c             lea eax, [esp + 0x3c]
// 007af7e9  50                   push eax
// 007af7ea  8bcd                 mov ecx, ebp
// 007af7ec  e8df9ff6ff           call 0x7197d0
// 007af7f1  8b742440             mov esi, dword ptr [esp + 0x40]
// 007af7f5  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007af7f9  8d0431               lea eax, [ecx + esi]
// 007af7fc  99                   cdq 
// 007af7fd  2bc2                 sub eax, edx
// 007af7ff  d1f8                 sar eax, 1
// 007af801  837c244802           cmp dword ptr [esp + 0x48], 2
// 007af806  0f858e000000         jne 0x7af89a
// 007af80c  8d70f8               lea esi, [eax - 8]
// 007af80f  8d7808               lea edi, [eax + 8]
// 007af812  3bf7                 cmp esi, edi
// 007af814  0f8dad010000         jge 0x7af9c7
// 007af81a  8d9b00000000         lea ebx, [ebx]
// 007af820  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007af824  8d4804               lea ecx, [eax + 4]
// 007af827  8d5601               lea edx, [esi + 1]
// 007af82a  89542410             mov dword ptr [esp + 0x10], edx
// 007af82e  894c2414             mov dword ptr [esp + 0x14], ecx
// 007af832  8d5603               lea edx, [esi + 3]
// 007af835  83c006               add eax, 6
// 007af838  6a05                 push 5
// 007af83a  8bcb                 mov ecx, ebx
// 007af83c  8954241c             mov dword ptr [esp + 0x1c], edx
// 007af840  89442420             mov dword ptr [esp + 0x20], eax
// 007af844  e8372ff7ff           call 0x722780
// 007af849  50                   push eax
// 007af84a  8d442414             lea eax, [esp + 0x14]
// 007af84e  50                   push eax
// 007af84f  8bcd                 mov ecx, ebp
// 007af851  e87a9ff6ff           call 0x7197d0
// 007af856  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007af85a  8d4803               lea ecx, [eax + 3]
// 007af85d  894c2424             mov dword ptr [esp + 0x24], ecx
// 007af861  8d5602               lea edx, [esi + 2]
// 007af864  83c005               add eax, 5
// 007af867  6a26                 push 0x26
// 007af869  8bcb                 mov ecx, ebx
// 007af86b  89742424             mov dword ptr [esp + 0x24], esi
// 007af86f  8954242c             mov dword ptr [esp + 0x2c], edx
// 007af873  89442430             mov dword ptr [esp + 0x30], eax
// 007af877  e8042ff7ff           call 0x722780
// 007af87c  50                   push eax
// 007af87d  8d442424             lea eax, [esp + 0x24]
// 007af881  50                   push eax
// 007af882  8bcd                 mov ecx, ebp
// 007af884  e8479ff6ff           call 0x7197d0
// 007af889  83c604               add esi, 4
// 007af88c  3bf7                 cmp esi, edi
// 007af88e  7c90                 jl 0x7af820
// 007af890  5f                   pop edi
// 007af891  5e                   pop esi
// 007af892  5d                   pop ebp
// 007af893  5b                   pop ebx
// 007af894  83c420               add esp, 0x20
// 007af897  c21800               ret 0x18
// 007af89a  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 007af89e  83c7fc               add edi, -4
// 007af8a1  83c6fc               add esi, -4
// 007af8a4  8d4701               lea eax, [edi + 1]
// 007af8a7  8d4e01               lea ecx, [esi + 1]
// 007af8aa  89442424             mov dword ptr [esp + 0x24], eax
// 007af8ae  894c2420             mov dword ptr [esp + 0x20], ecx
// 007af8b2  8d5603               lea edx, [esi + 3]
// 007af8b5  8d4703               lea eax, [edi + 3]
// 007af8b8  6a05                 push 5
// 007af8ba  8bcb                 mov ecx, ebx
// 007af8bc  8954242c             mov dword ptr [esp + 0x2c], edx
// 007af8c0  89442430             mov dword ptr [esp + 0x30], eax
// 007af8c4  e8b72ef7ff           call 0x722780
// 007af8c9  50                   push eax
// 007af8ca  8d442424             lea eax, [esp + 0x24]
// 007af8ce  50                   push eax
// 007af8cf  8bcd                 mov ecx, ebp
// 007af8d1  e8fa9ef6ff           call 0x7197d0
// 007af8d6  8d4e02               lea ecx, [esi + 2]
// 007af8d9  894c2428             mov dword ptr [esp + 0x28], ecx
// 007af8dd  8d4702               lea eax, [edi + 2]
// 007af8e0  6a26                 push 0x26
// 007af8e2  8bcb                 mov ecx, ebx
// 007af8e4  89742424             mov dword ptr [esp + 0x24], esi
// 007af8e8  897c2428             mov dword ptr [esp + 0x28], edi
// 007af8ec  89442430             mov dword ptr [esp + 0x30], eax
// 007af8f0  e88b2ef7ff           call 0x722780
// 007af8f5  50                   push eax
// 007af8f6  8d542424             lea edx, [esp + 0x24]
// 007af8fa  52                   push edx
// 007af8fb  8bcd                 mov ecx, ebp
// 007af8fd  e8ce9ef6ff           call 0x7197d0
// 007af902  83ee04               sub esi, 4
// 007af905  8d4601               lea eax, [esi + 1]
// 007af908  89442420             mov dword ptr [esp + 0x20], eax
// 007af90c  8d4701               lea eax, [edi + 1]
// 007af90f  8d4e03               lea ecx, [esi + 3]
// 007af912  89442424             mov dword ptr [esp + 0x24], eax
// 007af916  894c2428             mov dword ptr [esp + 0x28], ecx
// 007af91a  8d4703               lea eax, [edi + 3]
// 007af91d  6a05                 push 5
// 007af91f  8bcb                 mov ecx, ebx
// 007af921  89442430             mov dword ptr [esp + 0x30], eax
// 007af925  e8562ef7ff           call 0x722780
// 007af92a  50                   push eax
// 007af92b  8d542424             lea edx, [esp + 0x24]
// 007af92f  52                   push edx
// 007af930  8bcd                 mov ecx, ebp
// 007af932  e8999ef6ff           call 0x7197d0
// 007af937  8d4602               lea eax, [esi + 2]
// 007af93a  89442428             mov dword ptr [esp + 0x28], eax
// 007af93e  8d4702               lea eax, [edi + 2]
// 007af941  6a26                 push 0x26
// 007af943  8bcb                 mov ecx, ebx
// 007af945  89742424             mov dword ptr [esp + 0x24], esi
// 007af949  897c2428             mov dword ptr [esp + 0x28], edi
// 007af94d  89442430             mov dword ptr [esp + 0x30], eax
// 007af951  e82a2ef7ff           call 0x722780
// 007af956  50                   push eax
// 007af957  8d4c2424             lea ecx, [esp + 0x24]
// 007af95b  51                   push ecx
// 007af95c  8bcd                 mov ecx, ebp
// 007af95e  e86d9ef6ff           call 0x7197d0
// 007af963  83c604               add esi, 4
// 007af966  83ef04               sub edi, 4
// 007af969  8d5601               lea edx, [esi + 1]
// 007af96c  8d4e03               lea ecx, [esi + 3]
// 007af96f  89542420             mov dword ptr [esp + 0x20], edx
// 007af973  8d4701               lea eax, [edi + 1]
// 007af976  894c2428             mov dword ptr [esp + 0x28], ecx
// 007af97a  8d5703               lea edx, [edi + 3]
// 007af97d  6a05                 push 5
// 007af97f  8bcb                 mov ecx, ebx
// 007af981  89442428             mov dword ptr [esp + 0x28], eax
// 007af985  89542430             mov dword ptr [esp + 0x30], edx
// 007af989  e8f22df7ff           call 0x722780
// 007af98e  50                   push eax
// 007af98f  8d442424             lea eax, [esp + 0x24]
// 007af993  50                   push eax
// 007af994  8bcd                 mov ecx, ebp
// 007af996  e8359ef6ff           call 0x7197d0
// 007af99b  89742420             mov dword ptr [esp + 0x20], esi
// 007af99f  897c2424             mov dword ptr [esp + 0x24], edi
// 007af9a3  83c602               add esi, 2
// 007af9a6  83c702               add edi, 2
// 007af9a9  6a26                 push 0x26
// 007af9ab  8bcb                 mov ecx, ebx
// 007af9ad  8974242c             mov dword ptr [esp + 0x2c], esi
// 007af9b1  897c2430             mov dword ptr [esp + 0x30], edi
// 007af9b5  e8c62df7ff           call 0x722780
// 007af9ba  50                   push eax
// 007af9bb  8d4c2424             lea ecx, [esp + 0x24]
// 007af9bf  51                   push ecx
// 007af9c0  8bcd                 mov ecx, ebp
// 007af9c2  e8099ef6ff           call 0x7197d0
// 007af9c7  5f                   pop edi
// 007af9c8  5e                   pop esi
// 007af9c9  5d                   pop ebp
// 007af9ca  5b                   pop ebx
// 007af9cb  83c420               add esp, 0x20
// 007af9ce  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupResizeGripper@CXTPOfficeTheme@@UAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
