// from server: 100% by auto
// roc 2010-06 0082c8c0  unit: CXTPRibbonTheme  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082c8c0
//
// 0082c8c0  83ec30               sub esp, 0x30
// 0082c8c3  53                   push ebx
// 0082c8c4  55                   push ebp
// 0082c8c5  56                   push esi
// 0082c8c6  57                   push edi
// 0082c8c7  68e458a600           push 0xa658e4
// 0082c8cc  8bf9                 mov edi, ecx
// 0082c8ce  e82d590000           call 0x832200
// 0082c8d3  8be8                 mov ebp, eax
// 0082c8d5  33db                 xor ebx, ebx
// 0082c8d7  3beb                 cmp ebp, ebx
// 0082c8d9  753b                 jne 0x82c916
// 0082c8db  8b442458             mov eax, dword ptr [esp + 0x58]
// 0082c8df  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0082c8e3  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0082c8e7  50                   push eax
// 0082c8e8  83ec10               sub esp, 0x10
// 0082c8eb  8bc4                 mov eax, esp
// 0082c8ed  8908                 mov dword ptr [eax], ecx
// 0082c8ef  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0082c8f3  895004               mov dword ptr [eax + 4], edx
// 0082c8f6  8b542468             mov edx, dword ptr [esp + 0x68]
// 0082c8fa  894808               mov dword ptr [eax + 8], ecx
// 0082c8fd  89500c               mov dword ptr [eax + 0xc], edx
// 0082c900  8b442458             mov eax, dword ptr [esp + 0x58]
// 0082c904  50                   push eax
// 0082c905  8bcf                 mov ecx, edi
// 0082c907  e804130100           call 0x83dc10
// 0082c90c  5f                   pop edi
// 0082c90d  5e                   pop esi
// 0082c90e  5d                   pop ebp
// 0082c90f  5b                   pop ebx
// 0082c910  83c430               add esp, 0x30
// 0082c913  c21800               ret 0x18
// 0082c916  be01000000           mov esi, 1
// 0082c91b  56                   push esi
// 0082c91c  53                   push ebx
// 0082c91d  8d4c2438             lea ecx, [esp + 0x38]
// 0082c921  51                   push ecx
// 0082c922  8bcd                 mov ecx, ebp
// 0082c924  8974241c             mov dword ptr [esp + 0x1c], esi
// 0082c928  89742420             mov dword ptr [esp + 0x20], esi
// 0082c92c  89742424             mov dword ptr [esp + 0x24], esi
// 0082c930  89742428             mov dword ptr [esp + 0x28], esi
// 0082c934  e8f7810600           call 0x894b30
// 0082c939  68ff00ff00           push 0xff00ff
// 0082c93e  8d542414             lea edx, [esp + 0x14]
// 0082c942  52                   push edx
// 0082c943  8b10                 mov edx, dword ptr [eax]
// 0082c945  83ec10               sub esp, 0x10
// 0082c948  8bcc                 mov ecx, esp
// 0082c94a  8911                 mov dword ptr [ecx], edx
// 0082c94c  8b5004               mov edx, dword ptr [eax + 4]
// 0082c94f  895104               mov dword ptr [ecx + 4], edx
// 0082c952  8b5008               mov edx, dword ptr [eax + 8]
// 0082c955  8b400c               mov eax, dword ptr [eax + 0xc]
// 0082c958  895108               mov dword ptr [ecx + 8], edx
// 0082c95b  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0082c95f  89410c               mov dword ptr [ecx + 0xc], eax
// 0082c962  8d4c2460             lea ecx, [esp + 0x60]
// 0082c966  51                   push ecx
// 0082c967  52                   push edx
// 0082c968  8bcd                 mov ecx, ebp
// 0082c96a  e801870600           call 0x895070
// 0082c96f  837c245802           cmp dword ptr [esp + 0x58], 2
// 0082c974  8bcf                 mov ecx, edi
// 0082c976  0f85b8000000         jne 0x82ca34
// 0082c97c  68c858a600           push 0xa658c8
// 0082c981  e87a580000           call 0x832200
// 0082c986  56                   push esi
// 0082c987  8be8                 mov ebp, eax
// 0082c989  53                   push ebx
// 0082c98a  8d442418             lea eax, [esp + 0x18]
// 0082c98e  50                   push eax
// 0082c98f  8bcd                 mov ecx, ebp
// 0082c991  e89a810600           call 0x894b30
// 0082c996  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0082c99a  8b542448             mov edx, dword ptr [esp + 0x48]
// 0082c99e  8b742418             mov esi, dword ptr [esp + 0x18]
// 0082c9a2  2b742410             sub esi, dword ptr [esp + 0x10]
// 0082c9a6  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0082c9aa  8d040a               lea eax, [edx + ecx]
// 0082c9ad  2b7c2414             sub edi, dword ptr [esp + 0x14]
// 0082c9b1  99                   cdq 
// 0082c9b2  2bc2                 sub eax, edx
// 0082c9b4  8bc8                 mov ecx, eax
// 0082c9b6  8bc6                 mov eax, esi
// 0082c9b8  99                   cdq 
// 0082c9b9  2bc2                 sub eax, edx
// 0082c9bb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0082c9bf  d1f8                 sar eax, 1
// 0082c9c1  d1f9                 sar ecx, 1
// 0082c9c3  2bc8                 sub ecx, eax
// 0082c9c5  8b442414             mov eax, dword ptr [esp + 0x14]
// 0082c9c9  2bc2                 sub eax, edx
// 0082c9cb  03442454             add eax, dword ptr [esp + 0x54]
// 0082c9cf  68ff00ff00           push 0xff00ff
// 0082c9d4  89442438             mov dword ptr [esp + 0x38], eax
// 0082c9d8  03c7                 add eax, edi
// 0082c9da  89442440             mov dword ptr [esp + 0x40], eax
// 0082c9de  894c2434             mov dword ptr [esp + 0x34], ecx
// 0082c9e2  03ce                 add ecx, esi
// 0082c9e4  8d442424             lea eax, [esp + 0x24]
// 0082c9e8  50                   push eax
// 0082c9e9  894c2440             mov dword ptr [esp + 0x40], ecx
// 0082c9ed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0082c9f1  83ec10               sub esp, 0x10
// 0082c9f4  8bc4                 mov eax, esp
// 0082c9f6  8908                 mov dword ptr [eax], ecx
// 0082c9f8  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0082c9fc  894804               mov dword ptr [eax + 4], ecx
// 0082c9ff  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0082ca03  894808               mov dword ptr [eax + 8], ecx
// 0082ca06  89500c               mov dword ptr [eax + 0xc], edx
// 0082ca09  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0082ca0d  8d542448             lea edx, [esp + 0x48]
// 0082ca11  52                   push edx
// 0082ca12  8bcd                 mov ecx, ebp
// 0082ca14  50                   push eax
// 0082ca15  895c2440             mov dword ptr [esp + 0x40], ebx
// 0082ca19  895c2444             mov dword ptr [esp + 0x44], ebx
// 0082ca1d  895c2448             mov dword ptr [esp + 0x48], ebx
// 0082ca21  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0082ca25  e846860600           call 0x895070
// 0082ca2a  5f                   pop edi
// 0082ca2b  5e                   pop esi
// 0082ca2c  5d                   pop ebp
// 0082ca2d  5b                   pop ebx
// 0082ca2e  83c430               add esp, 0x30
// 0082ca31  c21800               ret 0x18
// 0082ca34  68ac58a600           push 0xa658ac
// 0082ca39  e8c2570000           call 0x832200
// 0082ca3e  56                   push esi
// 0082ca3f  53                   push ebx
// 0082ca40  8d4c2418             lea ecx, [esp + 0x18]
// 0082ca44  8bf8                 mov edi, eax
// 0082ca46  51                   push ecx
// 0082ca47  8bcf                 mov ecx, edi
// 0082ca49  e8e2800600           call 0x894b30
// 0082ca4e  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0082ca52  8b442410             mov eax, dword ptr [esp + 0x10]
// 0082ca56  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0082ca5a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0082ca5e  2bf1                 sub esi, ecx
// 0082ca60  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 0082ca64  8bd5                 mov edx, ebp
// 0082ca66  034c2454             add ecx, dword ptr [esp + 0x54]
// 0082ca6a  2bd0                 sub edx, eax
// 0082ca6c  2bc5                 sub eax, ebp
// 0082ca6e  03442450             add eax, dword ptr [esp + 0x50]
// 0082ca72  68ff00ff00           push 0xff00ff
// 0082ca77  89442424             mov dword ptr [esp + 0x24], eax
// 0082ca7b  03c2                 add eax, edx
// 0082ca7d  894c2428             mov dword ptr [esp + 0x28], ecx
// 0082ca81  03ce                 add ecx, esi
// 0082ca83  8d542434             lea edx, [esp + 0x34]
// 0082ca87  52                   push edx
// 0082ca88  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0082ca8c  83ec10               sub esp, 0x10
// 0082ca8f  894c2444             mov dword ptr [esp + 0x44], ecx
// 0082ca93  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0082ca97  89442440             mov dword ptr [esp + 0x40], eax
// 0082ca9b  8bc4                 mov eax, esp
// 0082ca9d  8908                 mov dword ptr [eax], ecx
// 0082ca9f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0082caa3  895004               mov dword ptr [eax + 4], edx
// 0082caa6  896808               mov dword ptr [eax + 8], ebp
// 0082caa9  89480c               mov dword ptr [eax + 0xc], ecx
// 0082caac  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0082cab0  8d542438             lea edx, [esp + 0x38]
// 0082cab4  52                   push edx
// 0082cab5  8bcf                 mov ecx, edi
// 0082cab7  50                   push eax
// 0082cab8  895c2450             mov dword ptr [esp + 0x50], ebx
// 0082cabc  895c2454             mov dword ptr [esp + 0x54], ebx
// 0082cac0  895c2458             mov dword ptr [esp + 0x58], ebx
// 0082cac4  895c245c             mov dword ptr [esp + 0x5c], ebx
// 0082cac8  e8a3850600           call 0x895070
// 0082cacd  5f                   pop edi
// 0082cace  5e                   pop esi
// 0082cacf  5d                   pop ebp
// 0082cad0  5b                   pop ebx
// 0082cad1  83c430               add esp, 0x30
// 0082cad4  c21800               ret 0x18
// library xtp-13.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawPopupResizeGripper@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonTheme.cpp
