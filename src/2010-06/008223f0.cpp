// from server: 100% by auto
// roc 2010-06 008223f0  unit: CXTPResourceManager  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008223f0
//
// 008223f0  51                   push ecx
// 008223f1  8b542408             mov edx, dword ptr [esp + 8]
// 008223f5  890c24               mov dword ptr [esp], ecx
// 008223f8  85d2                 test edx, edx
// 008223fa  0f844b010000         je 0x82254b
// 00822400  8b4204               mov eax, dword ptr [edx + 4]
// 00822403  85c0                 test eax, eax
// 00822405  0f8440010000         je 0x82254b
// 0082240b  83790c00             cmp dword ptr [ecx + 0xc], 0
// 0082240f  751a                 jne 0x82242b
// 00822411  8b442414             mov eax, dword ptr [esp + 0x14]
// 00822415  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00822419  50                   push eax
// 0082241a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0082241e  51                   push ecx
// 0082241f  50                   push eax
// 00822420  8bca                 mov ecx, edx
// 00822422  e8e1ac1500           call 0x97d108
// 00822427  59                   pop ecx
// 00822428  c21000               ret 0x10
// 0082242b  53                   push ebx
// 0082242c  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00822430  55                   push ebp
// 00822431  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00822435  56                   push esi
// 00822436  57                   push edi
// 00822437  53                   push ebx
// 00822438  6a00                 push 0
// 0082243a  6a00                 push 0
// 0082243c  55                   push ebp
// 0082243d  50                   push eax
// 0082243e  ff153cba9e00         call dword ptr [0x9eba3c]
// 00822444  8bf0                 mov esi, eax
// 00822446  85f6                 test esi, esi
// 00822448  0f8ee9000000         jle 0x822537
// 0082244e  e81dd4fcff           call 0x7ef870
// 00822453  8bc8                 mov ecx, eax
// 00822455  e876d4fcff           call 0x7ef8d0
// 0082245a  84c0                 test al, al
// 0082245c  0f84a0000000         je 0x822502
// 00822462  33c9                 xor ecx, ecx
// 00822464  8d6e01               lea ebp, [esi + 1]
// 00822467  8bc5                 mov eax, ebp
// 00822469  ba02000000           mov edx, 2
// 0082246e  f7e2                 mul edx
// 00822470  0f90c1               seto cl
// 00822473  f7d9                 neg ecx
// 00822475  0bc8                 or ecx, eax
// 00822477  51                   push ecx
// 00822478  e80558f8ff           call 0x7a7c82
// 0082247d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00822481  8b5104               mov edx, dword ptr [ecx + 4]
// 00822484  83c404               add esp, 4
// 00822487  53                   push ebx
// 00822488  55                   push ebp
// 00822489  8bf8                 mov edi, eax
// 0082248b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0082248f  57                   push edi
// 00822490  50                   push eax
// 00822491  52                   push edx
// 00822492  ff1538ba9e00         call dword ptr [0x9eba38]
// 00822498  8b442410             mov eax, dword ptr [esp + 0x10]
// 0082249c  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0082249f  8b5104               mov edx, dword ptr [ecx + 4]
// 008224a2  6a00                 push 0
// 008224a4  6a00                 push 0
// 008224a6  6a00                 push 0
// 008224a8  6a00                 push 0
// 008224aa  56                   push esi
// 008224ab  57                   push edi
// 008224ac  6a00                 push 0
// 008224ae  52                   push edx
// 008224af  ff15aca39e00         call dword ptr [0x9ea3ac]
// 008224b5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008224b9  8bd8                 mov ebx, eax
// 008224bb  53                   push ebx
// 008224bc  ff1554bf9e00         call dword ptr [0x9ebf54]
// 008224c2  6a00                 push 0
// 008224c4  6a00                 push 0
// 008224c6  53                   push ebx
// 008224c7  8be8                 mov ebp, eax
// 008224c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008224cd  8b480c               mov ecx, dword ptr [eax + 0xc]
// 008224d0  8b5104               mov edx, dword ptr [ecx + 4]
// 008224d3  55                   push ebp
// 008224d4  56                   push esi
// 008224d5  57                   push edi
// 008224d6  6a00                 push 0
// 008224d8  52                   push edx
// 008224d9  ff15aca39e00         call dword ptr [0x9ea3ac]
// 008224df  57                   push edi
// 008224e0  c6042b00             mov byte ptr [ebx + ebp], 0
// 008224e4  e85d57f8ff           call 0x7a7c46
// 008224e9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008224ed  83c404               add esp, 4
// 008224f0  6aff                 push -1
// 008224f2  ff1500c49e00         call dword ptr [0x9ec400]
// 008224f8  5f                   pop edi
// 008224f9  8bc6                 mov eax, esi
// 008224fb  5e                   pop esi
// 008224fc  5d                   pop ebp
// 008224fd  5b                   pop ebx
// 008224fe  59                   pop ecx
// 008224ff  c21000               ret 0x10
// 00822502  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00822506  56                   push esi
// 00822507  8bcf                 mov ecx, edi
// 00822509  ff1554bf9e00         call dword ptr [0x9ebf54]
// 0082250f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00822513  53                   push ebx
// 00822514  8d4e01               lea ecx, [esi + 1]
// 00822517  51                   push ecx
// 00822518  50                   push eax
// 00822519  8b4204               mov eax, dword ptr [edx + 4]
// 0082251c  55                   push ebp
// 0082251d  50                   push eax
// 0082251e  ff153cba9e00         call dword ptr [0x9eba3c]
// 00822524  56                   push esi
// 00822525  8bcf                 mov ecx, edi
// 00822527  ff1500c49e00         call dword ptr [0x9ec400]
// 0082252d  5f                   pop edi
// 0082252e  8bc6                 mov eax, esi
// 00822530  5e                   pop esi
// 00822531  5d                   pop ebp
// 00822532  5b                   pop ebx
// 00822533  59                   pop ecx
// 00822534  c21000               ret 0x10
// 00822537  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0082253b  ff1588c69e00         call dword ptr [0x9ec688]
// 00822541  5f                   pop edi
// 00822542  8bc6                 mov eax, esi
// 00822544  5e                   pop esi
// 00822545  5d                   pop ebp
// 00822546  5b                   pop ebx
// 00822547  59                   pop ecx
// 00822548  c21000               ret 0x10
// 0082254b  33c0                 xor eax, eax
// 0082254d  59                   pop ecx
// 0082254e  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\Common\XTPResourceManager.cpp (function ?GetMenuLocaleString@CXTPResourceManager@@QBEHPAVCMenu@@IAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPResourceManager.cpp
