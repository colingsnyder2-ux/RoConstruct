// from server: 100% by auto
// roc 2011-06 0087fbf0  unit: CXTPResourceManager  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087fbf0
//
// 0087fbf0  51                   push ecx
// 0087fbf1  53                   push ebx
// 0087fbf2  55                   push ebp
// 0087fbf3  894c2408             mov dword ptr [esp + 8], ecx
// 0087fbf7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0087fbfb  57                   push edi
// 0087fbfc  ff155c27a400         call dword ptr [0xa4275c]
// 0087fc02  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0087fc06  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0087fc0a  8bc3                 mov eax, ebx
// 0087fc0c  c1e804               shr eax, 4
// 0087fc0f  40                   inc eax
// 0087fc10  0fb7c8               movzx ecx, ax
// 0087fc13  6a06                 push 6
// 0087fc15  51                   push ecx
// 0087fc16  55                   push ebp
// 0087fc17  ff153803a400         call dword ptr [0xa40338]
// 0087fc1d  8bf8                 mov edi, eax
// 0087fc1f  85ff                 test edi, edi
// 0087fc21  7509                 jne 0x87fc2c
// 0087fc23  5f                   pop edi
// 0087fc24  5d                   pop ebp
// 0087fc25  33c0                 xor eax, eax
// 0087fc27  5b                   pop ebx
// 0087fc28  59                   pop ecx
// 0087fc29  c20c00               ret 0xc
// 0087fc2c  57                   push edi
// 0087fc2d  55                   push ebp
// 0087fc2e  ff153c03a400         call dword ptr [0xa4033c]
// 0087fc34  85c0                 test eax, eax
// 0087fc36  74eb                 je 0x87fc23
// 0087fc38  56                   push esi
// 0087fc39  50                   push eax
// 0087fc3a  ff15d001a400         call dword ptr [0xa401d0]
// 0087fc40  8bf0                 mov esi, eax
// 0087fc42  85f6                 test esi, esi
// 0087fc44  742a                 je 0x87fc70
// 0087fc46  57                   push edi
// 0087fc47  55                   push ebp
// 0087fc48  ff154003a400         call dword ptr [0xa40340]
// 0087fc4e  03c6                 add eax, esi
// 0087fc50  83e30f               and ebx, 0xf
// 0087fc53  7610                 jbe 0x87fc65
// 0087fc55  3bf0                 cmp esi, eax
// 0087fc57  7317                 jae 0x87fc70
// 0087fc59  83eb01               sub ebx, 1
// 0087fc5c  0fb716               movzx edx, word ptr [esi]
// 0087fc5f  8d745602             lea esi, [esi + edx*2 + 2]
// 0087fc63  75f0                 jne 0x87fc55
// 0087fc65  3bf0                 cmp esi, eax
// 0087fc67  7307                 jae 0x87fc70
// 0087fc69  0fb72e               movzx ebp, word ptr [esi]
// 0087fc6c  85ed                 test ebp, ebp
// 0087fc6e  750a                 jne 0x87fc7a
// 0087fc70  5e                   pop esi
// 0087fc71  5f                   pop edi
// 0087fc72  5d                   pop ebp
// 0087fc73  33c0                 xor eax, eax
// 0087fc75  5b                   pop ebx
// 0087fc76  59                   pop ecx
// 0087fc77  c20c00               ret 0xc
// 0087fc7a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0087fc7e  8b400c               mov eax, dword ptr [eax + 0xc]
// 0087fc81  85c0                 test eax, eax
// 0087fc83  7405                 je 0x87fc8a
// 0087fc85  8b5804               mov ebx, dword ptr [eax + 4]
// 0087fc88  eb02                 jmp 0x87fc8c
// 0087fc8a  33db                 xor ebx, ebx
// 0087fc8c  6a00                 push 0
// 0087fc8e  6a00                 push 0
// 0087fc90  6a00                 push 0
// 0087fc92  6a00                 push 0
// 0087fc94  55                   push ebp
// 0087fc95  8d7e02               lea edi, [esi + 2]
// 0087fc98  57                   push edi
// 0087fc99  6a00                 push 0
// 0087fc9b  53                   push ebx
// 0087fc9c  ff158c03a400         call dword ptr [0xa4038c]
// 0087fca2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0087fca6  8bf0                 mov esi, eax
// 0087fca8  56                   push esi
// 0087fca9  ff15101fa400         call dword ptr [0xa41f10]
// 0087fcaf  6a00                 push 0
// 0087fcb1  6a00                 push 0
// 0087fcb3  56                   push esi
// 0087fcb4  50                   push eax
// 0087fcb5  55                   push ebp
// 0087fcb6  57                   push edi
// 0087fcb7  6a00                 push 0
// 0087fcb9  53                   push ebx
// 0087fcba  ff158c03a400         call dword ptr [0xa4038c]
// 0087fcc0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0087fcc4  56                   push esi
// 0087fcc5  ff15e423a400         call dword ptr [0xa423e4]
// 0087fccb  8bc6                 mov eax, esi
// 0087fccd  5e                   pop esi
// 0087fcce  5f                   pop edi
// 0087fccf  5d                   pop ebp
// 0087fcd0  5b                   pop ebx
// 0087fcd1  59                   pop ecx
// 0087fcd2  c20c00               ret 0xc
// library xtp-15.2.1-shared-mfc/Source\Common\XTPResourceManager.cpp (function ?LoadLocaleString@CXTPResourceManager@@QBEHPAUHINSTANCE__@@IAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPResourceManager.cpp
