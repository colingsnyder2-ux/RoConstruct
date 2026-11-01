// from server: 100% by auto
// roc 2011-06 008a0720  unit: UtagACCEL::?$CArray  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a0720
//
// 008a0720  56                   push esi
// 008a0721  8bf1                 mov esi, ecx
// 008a0723  837e1000             cmp dword ptr [esi + 0x10], 0
// 008a0727  57                   push edi
// 008a0728  7537                 jne 0x8a0761
// 008a072a  8b4618               mov eax, dword ptr [esi + 0x18]
// 008a072d  6a10                 push 0x10
// 008a072f  50                   push eax
// 008a0730  8d4e14               lea ecx, [esi + 0x14]
// 008a0733  51                   push ecx
// 008a0734  e8b3a4f6ff           call 0x80abec
// 008a0739  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008a073c  8bd1                 mov edx, ecx
// 008a073e  83c004               add eax, 4
// 008a0741  c1e204               shl edx, 4
// 008a0744  83c1ff               add ecx, -1
// 008a0747  8d4410f0             lea eax, [eax + edx - 0x10]
// 008a074b  7814                 js 0x8a0761
// 008a074d  8d4900               lea ecx, [ecx]
// 008a0750  8b5610               mov edx, dword ptr [esi + 0x10]
// 008a0753  895008               mov dword ptr [eax + 8], edx
// 008a0756  894610               mov dword ptr [esi + 0x10], eax
// 008a0759  49                   dec ecx
// 008a075a  83e810               sub eax, 0x10
// 008a075d  85c9                 test ecx, ecx
// 008a075f  7def                 jge 0x8a0750
// 008a0761  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008a0764  85ff                 test edi, edi
// 008a0766  7505                 jne 0x8a076d
// 008a0768  e89d9bf6ff           call 0x80a30a
// 008a076d  8b4f08               mov ecx, dword ptr [edi + 8]
// 008a0770  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008a0774  33c0                 xor eax, eax
// 008a0776  8907                 mov dword ptr [edi], eax
// 008a0778  894704               mov dword ptr [edi + 4], eax
// 008a077b  89470c               mov dword ptr [edi + 0xc], eax
// 008a077e  894f08               mov dword ptr [edi + 8], ecx
// 008a0781  8b4610               mov eax, dword ptr [esi + 0x10]
// 008a0784  8b4808               mov ecx, dword ptr [eax + 8]
// 008a0787  ff460c               inc dword ptr [esi + 0xc]
// 008a078a  894e10               mov dword ptr [esi + 0x10], ecx
// 008a078d  8d4f04               lea ecx, [edi + 4]
// 008a0790  8917                 mov dword ptr [edi], edx
// 008a0792  ff15b42da400         call dword ptr [0xa42db4]
// 008a0798  8bc7                 mov eax, edi
// 008a079a  5f                   pop edi
// 008a079b  5e                   pop esi
// 008a079c  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Common\XTPResourceImage.cpp (function ?NewAssoc@?$CMap@IIV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V12@@@IAEPAVCAssoc@1@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPResourceImage.cpp
