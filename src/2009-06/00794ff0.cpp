// from server: 100% by auto
// roc 2009-06 00794ff0  unit: CXTPRibbonTheme  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00794ff0
//
// 00794ff0  83ec30               sub esp, 0x30
// 00794ff3  53                   push ebx
// 00794ff4  55                   push ebp
// 00794ff5  56                   push esi
// 00794ff6  57                   push edi
// 00794ff7  68c0039000           push 0x9003c0
// 00794ffc  8bf9                 mov edi, ecx
// 00794ffe  e8bded0000           call 0x7a3dc0
// 00795003  8be8                 mov ebp, eax
// 00795005  33db                 xor ebx, ebx
// 00795007  3beb                 cmp ebp, ebx
// 00795009  753b                 jne 0x795046
// 0079500b  8b442458             mov eax, dword ptr [esp + 0x58]
// 0079500f  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00795013  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 00795017  50                   push eax
// 00795018  83ec10               sub esp, 0x10
// 0079501b  8bc4                 mov eax, esp
// 0079501d  8908                 mov dword ptr [eax], ecx
// 0079501f  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00795023  895004               mov dword ptr [eax + 4], edx
// 00795026  8b542468             mov edx, dword ptr [esp + 0x68]
// 0079502a  894808               mov dword ptr [eax + 8], ecx
// 0079502d  89500c               mov dword ptr [eax + 0xc], edx
// 00795030  8b442458             mov eax, dword ptr [esp + 0x58]
// 00795034  50                   push eax
// 00795035  8bcf                 mov ecx, edi
// 00795037  e894a70100           call 0x7af7d0
// 0079503c  5f                   pop edi
// 0079503d  5e                   pop esi
// 0079503e  5d                   pop ebp
// 0079503f  5b                   pop ebx
// 00795040  83c430               add esp, 0x30
// 00795043  c21800               ret 0x18
// 00795046  be01000000           mov esi, 1
// 0079504b  56                   push esi
// 0079504c  53                   push ebx
// 0079504d  8d4c2438             lea ecx, [esp + 0x38]
// 00795051  51                   push ecx
// 00795052  8bcd                 mov ecx, ebp
// 00795054  8974241c             mov dword ptr [esp + 0x1c], esi
// 00795058  89742420             mov dword ptr [esp + 0x20], esi
// 0079505c  89742424             mov dword ptr [esp + 0x24], esi
// 00795060  89742428             mov dword ptr [esp + 0x28], esi
// 00795064  e8570d0700           call 0x805dc0
// 00795069  68ff00ff00           push 0xff00ff
// 0079506e  8d542414             lea edx, [esp + 0x14]
// 00795072  52                   push edx
// 00795073  8b10                 mov edx, dword ptr [eax]
// 00795075  83ec10               sub esp, 0x10
// 00795078  8bcc                 mov ecx, esp
// 0079507a  8911                 mov dword ptr [ecx], edx
// 0079507c  8b5004               mov edx, dword ptr [eax + 4]
// 0079507f  895104               mov dword ptr [ecx + 4], edx
// 00795082  8b5008               mov edx, dword ptr [eax + 8]
// 00795085  8b400c               mov eax, dword ptr [eax + 0xc]
// 00795088  895108               mov dword ptr [ecx + 8], edx
// 0079508b  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0079508f  89410c               mov dword ptr [ecx + 0xc], eax
// 00795092  8d4c2460             lea ecx, [esp + 0x60]
// 00795096  51                   push ecx
// 00795097  52                   push edx
// 00795098  8bcd                 mov ecx, ebp
// 0079509a  e861120700           call 0x806300
// 0079509f  837c245802           cmp dword ptr [esp + 0x58], 2
// 007950a4  8bcf                 mov ecx, edi
// 007950a6  0f85b8000000         jne 0x795164
// 007950ac  68a4039000           push 0x9003a4
// 007950b1  e80aed0000           call 0x7a3dc0
// 007950b6  56                   push esi
// 007950b7  8be8                 mov ebp, eax
// 007950b9  53                   push ebx
// 007950ba  8d442418             lea eax, [esp + 0x18]
// 007950be  50                   push eax
// 007950bf  8bcd                 mov ecx, ebp
// 007950c1  e8fa0c0700           call 0x805dc0
// 007950c6  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 007950ca  8b542448             mov edx, dword ptr [esp + 0x48]
// 007950ce  8b742418             mov esi, dword ptr [esp + 0x18]
// 007950d2  2b742410             sub esi, dword ptr [esp + 0x10]
// 007950d6  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007950da  8d040a               lea eax, [edx + ecx]
// 007950dd  2b7c2414             sub edi, dword ptr [esp + 0x14]
// 007950e1  99                   cdq 
// 007950e2  2bc2                 sub eax, edx
// 007950e4  8bc8                 mov ecx, eax
// 007950e6  8bc6                 mov eax, esi
// 007950e8  99                   cdq 
// 007950e9  2bc2                 sub eax, edx
// 007950eb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007950ef  d1f8                 sar eax, 1
// 007950f1  d1f9                 sar ecx, 1
// 007950f3  2bc8                 sub ecx, eax
// 007950f5  8b442414             mov eax, dword ptr [esp + 0x14]
// 007950f9  2bc2                 sub eax, edx
// 007950fb  03442454             add eax, dword ptr [esp + 0x54]
// 007950ff  68ff00ff00           push 0xff00ff
// 00795104  89442438             mov dword ptr [esp + 0x38], eax
// 00795108  03c7                 add eax, edi
// 0079510a  89442440             mov dword ptr [esp + 0x40], eax
// 0079510e  894c2434             mov dword ptr [esp + 0x34], ecx
// 00795112  03ce                 add ecx, esi
// 00795114  8d442424             lea eax, [esp + 0x24]
// 00795118  50                   push eax
// 00795119  894c2440             mov dword ptr [esp + 0x40], ecx
// 0079511d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00795121  83ec10               sub esp, 0x10
// 00795124  8bc4                 mov eax, esp
// 00795126  8908                 mov dword ptr [eax], ecx
// 00795128  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0079512c  894804               mov dword ptr [eax + 4], ecx
// 0079512f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00795133  894808               mov dword ptr [eax + 8], ecx
// 00795136  89500c               mov dword ptr [eax + 0xc], edx
// 00795139  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0079513d  8d542448             lea edx, [esp + 0x48]
// 00795141  52                   push edx
// 00795142  8bcd                 mov ecx, ebp
// 00795144  50                   push eax
// 00795145  895c2440             mov dword ptr [esp + 0x40], ebx
// 00795149  895c2444             mov dword ptr [esp + 0x44], ebx
// 0079514d  895c2448             mov dword ptr [esp + 0x48], ebx
// 00795151  895c244c             mov dword ptr [esp + 0x4c], ebx
// 00795155  e8a6110700           call 0x806300
// 0079515a  5f                   pop edi
// 0079515b  5e                   pop esi
// 0079515c  5d                   pop ebp
// 0079515d  5b                   pop ebx
// 0079515e  83c430               add esp, 0x30
// 00795161  c21800               ret 0x18
// 00795164  6888039000           push 0x900388
// 00795169  e852ec0000           call 0x7a3dc0
// 0079516e  56                   push esi
// 0079516f  53                   push ebx
// 00795170  8d4c2418             lea ecx, [esp + 0x18]
// 00795174  8bf8                 mov edi, eax
// 00795176  51                   push ecx
// 00795177  8bcf                 mov ecx, edi
// 00795179  e8420c0700           call 0x805dc0
// 0079517e  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00795182  8b442410             mov eax, dword ptr [esp + 0x10]
// 00795186  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0079518a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0079518e  2bf1                 sub esi, ecx
// 00795190  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 00795194  8bd5                 mov edx, ebp
// 00795196  034c2454             add ecx, dword ptr [esp + 0x54]
// 0079519a  2bd0                 sub edx, eax
// 0079519c  2bc5                 sub eax, ebp
// 0079519e  03442450             add eax, dword ptr [esp + 0x50]
// 007951a2  68ff00ff00           push 0xff00ff
// 007951a7  89442424             mov dword ptr [esp + 0x24], eax
// 007951ab  03c2                 add eax, edx
// 007951ad  894c2428             mov dword ptr [esp + 0x28], ecx
// 007951b1  03ce                 add ecx, esi
// 007951b3  8d542434             lea edx, [esp + 0x34]
// 007951b7  52                   push edx
// 007951b8  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007951bc  83ec10               sub esp, 0x10
// 007951bf  894c2444             mov dword ptr [esp + 0x44], ecx
// 007951c3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007951c7  89442440             mov dword ptr [esp + 0x40], eax
// 007951cb  8bc4                 mov eax, esp
// 007951cd  8908                 mov dword ptr [eax], ecx
// 007951cf  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007951d3  895004               mov dword ptr [eax + 4], edx
// 007951d6  896808               mov dword ptr [eax + 8], ebp
// 007951d9  89480c               mov dword ptr [eax + 0xc], ecx
// 007951dc  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 007951e0  8d542438             lea edx, [esp + 0x38]
// 007951e4  52                   push edx
// 007951e5  8bcf                 mov ecx, edi
// 007951e7  50                   push eax
// 007951e8  895c2450             mov dword ptr [esp + 0x50], ebx
// 007951ec  895c2454             mov dword ptr [esp + 0x54], ebx
// 007951f0  895c2458             mov dword ptr [esp + 0x58], ebx
// 007951f4  895c245c             mov dword ptr [esp + 0x5c], ebx
// 007951f8  e803110700           call 0x806300
// 007951fd  5f                   pop edi
// 007951fe  5e                   pop esi
// 007951ff  5d                   pop ebp
// 00795200  5b                   pop ebx
// 00795201  83c430               add esp, 0x30
// 00795204  c21800               ret 0x18
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawPopupResizeGripper@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
