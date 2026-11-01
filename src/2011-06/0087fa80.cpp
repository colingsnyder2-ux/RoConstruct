// from server: 100% by auto
// roc 2011-06 0087fa80  unit: CXTPResourceManager  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087fa80
//
// 0087fa80  51                   push ecx
// 0087fa81  8b542408             mov edx, dword ptr [esp + 8]
// 0087fa85  890c24               mov dword ptr [esp], ecx
// 0087fa88  85d2                 test edx, edx
// 0087fa8a  0f844b010000         je 0x87fbdb
// 0087fa90  8b4204               mov eax, dword ptr [edx + 4]
// 0087fa93  85c0                 test eax, eax
// 0087fa95  0f8440010000         je 0x87fbdb
// 0087fa9b  83790c00             cmp dword ptr [ecx + 0xc], 0
// 0087fa9f  751a                 jne 0x87fabb
// 0087faa1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0087faa5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0087faa9  50                   push eax
// 0087faaa  8b442410             mov eax, dword ptr [esp + 0x10]
// 0087faae  51                   push ecx
// 0087faaf  50                   push eax
// 0087fab0  8bca                 mov ecx, edx
// 0087fab2  e861ce1400           call 0x9cc918
// 0087fab7  59                   pop ecx
// 0087fab8  c21000               ret 0x10
// 0087fabb  53                   push ebx
// 0087fabc  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0087fac0  55                   push ebp
// 0087fac1  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0087fac5  56                   push esi
// 0087fac6  57                   push edi
// 0087fac7  53                   push ebx
// 0087fac8  6a00                 push 0
// 0087faca  6a00                 push 0
// 0087facc  55                   push ebp
// 0087facd  50                   push eax
// 0087face  ff15641aa400         call dword ptr [0xa41a64]
// 0087fad4  8bf0                 mov esi, eax
// 0087fad6  85f6                 test esi, esi
// 0087fad8  0f8ee9000000         jle 0x87fbc7
// 0087fade  e8dd15fdff           call 0x8510c0
// 0087fae3  8bc8                 mov ecx, eax
// 0087fae5  e83616fdff           call 0x851120
// 0087faea  84c0                 test al, al
// 0087faec  0f84a0000000         je 0x87fb92
// 0087faf2  33c9                 xor ecx, ecx
// 0087faf4  8d6e01               lea ebp, [esi + 1]
// 0087faf7  8bc5                 mov eax, ebp
// 0087faf9  ba02000000           mov edx, 2
// 0087fafe  f7e2                 mul edx
// 0087fb00  0f90c1               seto cl
// 0087fb03  f7d9                 neg ecx
// 0087fb05  0bc8                 or ecx, eax
// 0087fb07  51                   push ecx
// 0087fb08  e833a8f8ff           call 0x80a340
// 0087fb0d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0087fb11  8b5104               mov edx, dword ptr [ecx + 4]
// 0087fb14  83c404               add esp, 4
// 0087fb17  53                   push ebx
// 0087fb18  55                   push ebp
// 0087fb19  8bf8                 mov edi, eax
// 0087fb1b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0087fb1f  57                   push edi
// 0087fb20  50                   push eax
// 0087fb21  52                   push edx
// 0087fb22  ff15681aa400         call dword ptr [0xa41a68]
// 0087fb28  8b442410             mov eax, dword ptr [esp + 0x10]
// 0087fb2c  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0087fb2f  8b5104               mov edx, dword ptr [ecx + 4]
// 0087fb32  6a00                 push 0
// 0087fb34  6a00                 push 0
// 0087fb36  6a00                 push 0
// 0087fb38  6a00                 push 0
// 0087fb3a  56                   push esi
// 0087fb3b  57                   push edi
// 0087fb3c  6a00                 push 0
// 0087fb3e  52                   push edx
// 0087fb3f  ff158c03a400         call dword ptr [0xa4038c]
// 0087fb45  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0087fb49  8bd8                 mov ebx, eax
// 0087fb4b  53                   push ebx
// 0087fb4c  ff15101fa400         call dword ptr [0xa41f10]
// 0087fb52  6a00                 push 0
// 0087fb54  6a00                 push 0
// 0087fb56  53                   push ebx
// 0087fb57  8be8                 mov ebp, eax
// 0087fb59  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0087fb5d  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0087fb60  8b5104               mov edx, dword ptr [ecx + 4]
// 0087fb63  55                   push ebp
// 0087fb64  56                   push esi
// 0087fb65  57                   push edi
// 0087fb66  6a00                 push 0
// 0087fb68  52                   push edx
// 0087fb69  ff158c03a400         call dword ptr [0xa4038c]
// 0087fb6f  57                   push edi
// 0087fb70  c6042b00             mov byte ptr [ebx + ebp], 0
// 0087fb74  e88ba7f8ff           call 0x80a304
// 0087fb79  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0087fb7d  83c404               add esp, 4
// 0087fb80  6aff                 push -1
// 0087fb82  ff15e423a400         call dword ptr [0xa423e4]
// 0087fb88  5f                   pop edi
// 0087fb89  8bc6                 mov eax, esi
// 0087fb8b  5e                   pop esi
// 0087fb8c  5d                   pop ebp
// 0087fb8d  5b                   pop ebx
// 0087fb8e  59                   pop ecx
// 0087fb8f  c21000               ret 0x10
// 0087fb92  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0087fb96  56                   push esi
// 0087fb97  8bcf                 mov ecx, edi
// 0087fb99  ff15101fa400         call dword ptr [0xa41f10]
// 0087fb9f  8b542418             mov edx, dword ptr [esp + 0x18]
// 0087fba3  53                   push ebx
// 0087fba4  8d4e01               lea ecx, [esi + 1]
// 0087fba7  51                   push ecx
// 0087fba8  50                   push eax
// 0087fba9  8b4204               mov eax, dword ptr [edx + 4]
// 0087fbac  55                   push ebp
// 0087fbad  50                   push eax
// 0087fbae  ff15641aa400         call dword ptr [0xa41a64]
// 0087fbb4  56                   push esi
// 0087fbb5  8bcf                 mov ecx, edi
// 0087fbb7  ff15e423a400         call dword ptr [0xa423e4]
// 0087fbbd  5f                   pop edi
// 0087fbbe  8bc6                 mov eax, esi
// 0087fbc0  5e                   pop esi
// 0087fbc1  5d                   pop ebp
// 0087fbc2  5b                   pop ebx
// 0087fbc3  59                   pop ecx
// 0087fbc4  c21000               ret 0x10
// 0087fbc7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0087fbcb  ff155c27a400         call dword ptr [0xa4275c]
// 0087fbd1  5f                   pop edi
// 0087fbd2  8bc6                 mov eax, esi
// 0087fbd4  5e                   pop esi
// 0087fbd5  5d                   pop ebp
// 0087fbd6  5b                   pop ebx
// 0087fbd7  59                   pop ecx
// 0087fbd8  c21000               ret 0x10
// 0087fbdb  33c0                 xor eax, eax
// 0087fbdd  59                   pop ecx
// 0087fbde  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\Common\XTPResourceManager.cpp (function ?GetMenuLocaleString@CXTPResourceManager@@QBEHPAVCMenu@@IAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPResourceManager.cpp
