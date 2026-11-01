// from server: 100% by auto
// roc 2009-12 00871990  unit: CXTPRibbonTheme  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871990
//
// 00871990  83ec30               sub esp, 0x30
// 00871993  53                   push ebx
// 00871994  55                   push ebp
// 00871995  56                   push esi
// 00871996  57                   push edi
// 00871997  68a00fa000           push 0xa00fa0
// 0087199c  8bf9                 mov edi, ecx
// 0087199e  e85dd30000           call 0x87ed00
// 008719a3  8be8                 mov ebp, eax
// 008719a5  33db                 xor ebx, ebx
// 008719a7  3beb                 cmp ebp, ebx
// 008719a9  753b                 jne 0x8719e6
// 008719ab  8b442458             mov eax, dword ptr [esp + 0x58]
// 008719af  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 008719b3  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 008719b7  50                   push eax
// 008719b8  83ec10               sub esp, 0x10
// 008719bb  8bc4                 mov eax, esp
// 008719bd  8908                 mov dword ptr [eax], ecx
// 008719bf  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 008719c3  895004               mov dword ptr [eax + 4], edx
// 008719c6  8b542468             mov edx, dword ptr [esp + 0x68]
// 008719ca  894808               mov dword ptr [eax + 8], ecx
// 008719cd  89500c               mov dword ptr [eax + 0xc], edx
// 008719d0  8b442458             mov eax, dword ptr [esp + 0x58]
// 008719d4  50                   push eax
// 008719d5  8bcf                 mov ecx, edi
// 008719d7  e8b48c0100           call 0x88a690
// 008719dc  5f                   pop edi
// 008719dd  5e                   pop esi
// 008719de  5d                   pop ebp
// 008719df  5b                   pop ebx
// 008719e0  83c430               add esp, 0x30
// 008719e3  c21800               ret 0x18
// 008719e6  be01000000           mov esi, 1
// 008719eb  56                   push esi
// 008719ec  53                   push ebx
// 008719ed  8d4c2438             lea ecx, [esp + 0x38]
// 008719f1  51                   push ecx
// 008719f2  8bcd                 mov ecx, ebp
// 008719f4  8974241c             mov dword ptr [esp + 0x1c], esi
// 008719f8  89742420             mov dword ptr [esp + 0x20], esi
// 008719fc  89742424             mov dword ptr [esp + 0x24], esi
// 00871a00  89742428             mov dword ptr [esp + 0x28], esi
// 00871a04  e8b7ee0600           call 0x8e08c0
// 00871a09  68ff00ff00           push 0xff00ff
// 00871a0e  8d542414             lea edx, [esp + 0x14]
// 00871a12  52                   push edx
// 00871a13  8b10                 mov edx, dword ptr [eax]
// 00871a15  83ec10               sub esp, 0x10
// 00871a18  8bcc                 mov ecx, esp
// 00871a1a  8911                 mov dword ptr [ecx], edx
// 00871a1c  8b5004               mov edx, dword ptr [eax + 4]
// 00871a1f  895104               mov dword ptr [ecx + 4], edx
// 00871a22  8b5008               mov edx, dword ptr [eax + 8]
// 00871a25  8b400c               mov eax, dword ptr [eax + 0xc]
// 00871a28  895108               mov dword ptr [ecx + 8], edx
// 00871a2b  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 00871a2f  89410c               mov dword ptr [ecx + 0xc], eax
// 00871a32  8d4c2460             lea ecx, [esp + 0x60]
// 00871a36  51                   push ecx
// 00871a37  52                   push edx
// 00871a38  8bcd                 mov ecx, ebp
// 00871a3a  e8c1f30600           call 0x8e0e00
// 00871a3f  837c245802           cmp dword ptr [esp + 0x58], 2
// 00871a44  8bcf                 mov ecx, edi
// 00871a46  0f85b8000000         jne 0x871b04
// 00871a4c  68840fa000           push 0xa00f84
// 00871a51  e8aad20000           call 0x87ed00
// 00871a56  56                   push esi
// 00871a57  8be8                 mov ebp, eax
// 00871a59  53                   push ebx
// 00871a5a  8d442418             lea eax, [esp + 0x18]
// 00871a5e  50                   push eax
// 00871a5f  8bcd                 mov ecx, ebp
// 00871a61  e85aee0600           call 0x8e08c0
// 00871a66  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00871a6a  8b542448             mov edx, dword ptr [esp + 0x48]
// 00871a6e  8b742418             mov esi, dword ptr [esp + 0x18]
// 00871a72  2b742410             sub esi, dword ptr [esp + 0x10]
// 00871a76  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00871a7a  8d040a               lea eax, [edx + ecx]
// 00871a7d  2b7c2414             sub edi, dword ptr [esp + 0x14]
// 00871a81  99                   cdq 
// 00871a82  2bc2                 sub eax, edx
// 00871a84  8bc8                 mov ecx, eax
// 00871a86  8bc6                 mov eax, esi
// 00871a88  99                   cdq 
// 00871a89  2bc2                 sub eax, edx
// 00871a8b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00871a8f  d1f8                 sar eax, 1
// 00871a91  d1f9                 sar ecx, 1
// 00871a93  2bc8                 sub ecx, eax
// 00871a95  8b442414             mov eax, dword ptr [esp + 0x14]
// 00871a99  2bc2                 sub eax, edx
// 00871a9b  03442454             add eax, dword ptr [esp + 0x54]
// 00871a9f  68ff00ff00           push 0xff00ff
// 00871aa4  89442438             mov dword ptr [esp + 0x38], eax
// 00871aa8  03c7                 add eax, edi
// 00871aaa  89442440             mov dword ptr [esp + 0x40], eax
// 00871aae  894c2434             mov dword ptr [esp + 0x34], ecx
// 00871ab2  03ce                 add ecx, esi
// 00871ab4  8d442424             lea eax, [esp + 0x24]
// 00871ab8  50                   push eax
// 00871ab9  894c2440             mov dword ptr [esp + 0x40], ecx
// 00871abd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00871ac1  83ec10               sub esp, 0x10
// 00871ac4  8bc4                 mov eax, esp
// 00871ac6  8908                 mov dword ptr [eax], ecx
// 00871ac8  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00871acc  894804               mov dword ptr [eax + 4], ecx
// 00871acf  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00871ad3  894808               mov dword ptr [eax + 8], ecx
// 00871ad6  89500c               mov dword ptr [eax + 0xc], edx
// 00871ad9  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00871add  8d542448             lea edx, [esp + 0x48]
// 00871ae1  52                   push edx
// 00871ae2  8bcd                 mov ecx, ebp
// 00871ae4  50                   push eax
// 00871ae5  895c2440             mov dword ptr [esp + 0x40], ebx
// 00871ae9  895c2444             mov dword ptr [esp + 0x44], ebx
// 00871aed  895c2448             mov dword ptr [esp + 0x48], ebx
// 00871af1  895c244c             mov dword ptr [esp + 0x4c], ebx
// 00871af5  e806f30600           call 0x8e0e00
// 00871afa  5f                   pop edi
// 00871afb  5e                   pop esi
// 00871afc  5d                   pop ebp
// 00871afd  5b                   pop ebx
// 00871afe  83c430               add esp, 0x30
// 00871b01  c21800               ret 0x18
// 00871b04  68680fa000           push 0xa00f68
// 00871b09  e8f2d10000           call 0x87ed00
// 00871b0e  56                   push esi
// 00871b0f  53                   push ebx
// 00871b10  8d4c2418             lea ecx, [esp + 0x18]
// 00871b14  8bf8                 mov edi, eax
// 00871b16  51                   push ecx
// 00871b17  8bcf                 mov ecx, edi
// 00871b19  e8a2ed0600           call 0x8e08c0
// 00871b1e  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00871b22  8b442410             mov eax, dword ptr [esp + 0x10]
// 00871b26  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00871b2a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00871b2e  2bf1                 sub esi, ecx
// 00871b30  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 00871b34  8bd5                 mov edx, ebp
// 00871b36  034c2454             add ecx, dword ptr [esp + 0x54]
// 00871b3a  2bd0                 sub edx, eax
// 00871b3c  2bc5                 sub eax, ebp
// 00871b3e  03442450             add eax, dword ptr [esp + 0x50]
// 00871b42  68ff00ff00           push 0xff00ff
// 00871b47  89442424             mov dword ptr [esp + 0x24], eax
// 00871b4b  03c2                 add eax, edx
// 00871b4d  894c2428             mov dword ptr [esp + 0x28], ecx
// 00871b51  03ce                 add ecx, esi
// 00871b53  8d542434             lea edx, [esp + 0x34]
// 00871b57  52                   push edx
// 00871b58  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00871b5c  83ec10               sub esp, 0x10
// 00871b5f  894c2444             mov dword ptr [esp + 0x44], ecx
// 00871b63  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00871b67  89442440             mov dword ptr [esp + 0x40], eax
// 00871b6b  8bc4                 mov eax, esp
// 00871b6d  8908                 mov dword ptr [eax], ecx
// 00871b6f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00871b73  895004               mov dword ptr [eax + 4], edx
// 00871b76  896808               mov dword ptr [eax + 8], ebp
// 00871b79  89480c               mov dword ptr [eax + 0xc], ecx
// 00871b7c  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00871b80  8d542438             lea edx, [esp + 0x38]
// 00871b84  52                   push edx
// 00871b85  8bcf                 mov ecx, edi
// 00871b87  50                   push eax
// 00871b88  895c2450             mov dword ptr [esp + 0x50], ebx
// 00871b8c  895c2454             mov dword ptr [esp + 0x54], ebx
// 00871b90  895c2458             mov dword ptr [esp + 0x58], ebx
// 00871b94  895c245c             mov dword ptr [esp + 0x5c], ebx
// 00871b98  e863f20600           call 0x8e0e00
// 00871b9d  5f                   pop edi
// 00871b9e  5e                   pop esi
// 00871b9f  5d                   pop ebp
// 00871ba0  5b                   pop ebx
// 00871ba1  83c430               add esp, 0x30
// 00871ba4  c21800               ret 0x18
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawPopupResizeGripper@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
