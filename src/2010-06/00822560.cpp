// from server: 100% by auto
// roc 2010-06 00822560  unit: CXTPResourceManager  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822560
//
// 00822560  51                   push ecx
// 00822561  53                   push ebx
// 00822562  55                   push ebp
// 00822563  894c2408             mov dword ptr [esp + 8], ecx
// 00822567  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0082256b  57                   push edi
// 0082256c  ff1588c69e00         call dword ptr [0x9ec688]
// 00822572  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00822576  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0082257a  8bc3                 mov eax, ebx
// 0082257c  c1e804               shr eax, 4
// 0082257f  40                   inc eax
// 00822580  0fb7c8               movzx ecx, ax
// 00822583  6a06                 push 6
// 00822585  51                   push ecx
// 00822586  55                   push ebp
// 00822587  ff155ca39e00         call dword ptr [0x9ea35c]
// 0082258d  8bf8                 mov edi, eax
// 0082258f  85ff                 test edi, edi
// 00822591  7509                 jne 0x82259c
// 00822593  5f                   pop edi
// 00822594  5d                   pop ebp
// 00822595  33c0                 xor eax, eax
// 00822597  5b                   pop ebx
// 00822598  59                   pop ecx
// 00822599  c20c00               ret 0xc
// 0082259c  57                   push edi
// 0082259d  55                   push ebp
// 0082259e  ff1560a39e00         call dword ptr [0x9ea360]
// 008225a4  85c0                 test eax, eax
// 008225a6  74eb                 je 0x822593
// 008225a8  56                   push esi
// 008225a9  50                   push eax
// 008225aa  ff15eca29e00         call dword ptr [0x9ea2ec]
// 008225b0  8bf0                 mov esi, eax
// 008225b2  85f6                 test esi, esi
// 008225b4  742a                 je 0x8225e0
// 008225b6  57                   push edi
// 008225b7  55                   push ebp
// 008225b8  ff1564a39e00         call dword ptr [0x9ea364]
// 008225be  03c6                 add eax, esi
// 008225c0  83e30f               and ebx, 0xf
// 008225c3  7610                 jbe 0x8225d5
// 008225c5  3bf0                 cmp esi, eax
// 008225c7  7317                 jae 0x8225e0
// 008225c9  83eb01               sub ebx, 1
// 008225cc  0fb716               movzx edx, word ptr [esi]
// 008225cf  8d745602             lea esi, [esi + edx*2 + 2]
// 008225d3  75f0                 jne 0x8225c5
// 008225d5  3bf0                 cmp esi, eax
// 008225d7  7307                 jae 0x8225e0
// 008225d9  0fb72e               movzx ebp, word ptr [esi]
// 008225dc  85ed                 test ebp, ebp
// 008225de  750a                 jne 0x8225ea
// 008225e0  5e                   pop esi
// 008225e1  5f                   pop edi
// 008225e2  5d                   pop ebp
// 008225e3  33c0                 xor eax, eax
// 008225e5  5b                   pop ebx
// 008225e6  59                   pop ecx
// 008225e7  c20c00               ret 0xc
// 008225ea  8b442410             mov eax, dword ptr [esp + 0x10]
// 008225ee  8b400c               mov eax, dword ptr [eax + 0xc]
// 008225f1  85c0                 test eax, eax
// 008225f3  7405                 je 0x8225fa
// 008225f5  8b5804               mov ebx, dword ptr [eax + 4]
// 008225f8  eb02                 jmp 0x8225fc
// 008225fa  33db                 xor ebx, ebx
// 008225fc  6a00                 push 0
// 008225fe  6a00                 push 0
// 00822600  6a00                 push 0
// 00822602  6a00                 push 0
// 00822604  55                   push ebp
// 00822605  8d7e02               lea edi, [esi + 2]
// 00822608  57                   push edi
// 00822609  6a00                 push 0
// 0082260b  53                   push ebx
// 0082260c  ff15aca39e00         call dword ptr [0x9ea3ac]
// 00822612  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00822616  8bf0                 mov esi, eax
// 00822618  56                   push esi
// 00822619  ff1554bf9e00         call dword ptr [0x9ebf54]
// 0082261f  6a00                 push 0
// 00822621  6a00                 push 0
// 00822623  56                   push esi
// 00822624  50                   push eax
// 00822625  55                   push ebp
// 00822626  57                   push edi
// 00822627  6a00                 push 0
// 00822629  53                   push ebx
// 0082262a  ff15aca39e00         call dword ptr [0x9ea3ac]
// 00822630  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00822634  56                   push esi
// 00822635  ff1500c49e00         call dword ptr [0x9ec400]
// 0082263b  8bc6                 mov eax, esi
// 0082263d  5e                   pop esi
// 0082263e  5f                   pop edi
// 0082263f  5d                   pop ebp
// 00822640  5b                   pop ebx
// 00822641  59                   pop ecx
// 00822642  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Common\XTPResourceManager.cpp (function ?LoadLocaleString@CXTPResourceManager@@QBEHPAUHINSTANCE__@@IAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPResourceManager.cpp
