// from server: 100% by auto
// roc 2010-06 00843560  unit: UtagACCEL::?$CArray  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00843560
//
// 00843560  56                   push esi
// 00843561  8bf1                 mov esi, ecx
// 00843563  837e1000             cmp dword ptr [esi + 0x10], 0
// 00843567  57                   push edi
// 00843568  7537                 jne 0x8435a1
// 0084356a  8b4618               mov eax, dword ptr [esi + 0x18]
// 0084356d  6a10                 push 0x10
// 0084356f  50                   push eax
// 00843570  8d4e14               lea ecx, [esi + 0x14]
// 00843573  51                   push ecx
// 00843574  e8af4ff6ff           call 0x7a8528
// 00843579  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0084357c  8bd1                 mov edx, ecx
// 0084357e  83c004               add eax, 4
// 00843581  c1e204               shl edx, 4
// 00843584  83c1ff               add ecx, -1
// 00843587  8d4410f0             lea eax, [eax + edx - 0x10]
// 0084358b  7814                 js 0x8435a1
// 0084358d  8d4900               lea ecx, [ecx]
// 00843590  8b5610               mov edx, dword ptr [esi + 0x10]
// 00843593  895008               mov dword ptr [eax + 8], edx
// 00843596  894610               mov dword ptr [esi + 0x10], eax
// 00843599  49                   dec ecx
// 0084359a  83e810               sub eax, 0x10
// 0084359d  85c9                 test ecx, ecx
// 0084359f  7def                 jge 0x843590
// 008435a1  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008435a4  85ff                 test edi, edi
// 008435a6  7505                 jne 0x8435ad
// 008435a8  e89f46f6ff           call 0x7a7c4c
// 008435ad  8b4f08               mov ecx, dword ptr [edi + 8]
// 008435b0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008435b4  33c0                 xor eax, eax
// 008435b6  8907                 mov dword ptr [edi], eax
// 008435b8  894704               mov dword ptr [edi + 4], eax
// 008435bb  89470c               mov dword ptr [edi + 0xc], eax
// 008435be  894f08               mov dword ptr [edi + 8], ecx
// 008435c1  8b4610               mov eax, dword ptr [esi + 0x10]
// 008435c4  8b4808               mov ecx, dword ptr [eax + 8]
// 008435c7  ff460c               inc dword ptr [esi + 0xc]
// 008435ca  894e10               mov dword ptr [esi + 0x10], ecx
// 008435cd  8d4f04               lea ecx, [edi + 4]
// 008435d0  8917                 mov dword ptr [edi], edx
// 008435d2  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 008435d8  8bc7                 mov eax, edi
// 008435da  5f                   pop edi
// 008435db  5e                   pop esi
// 008435dc  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTMDIWndTab.cpp (function ?NewAssoc@?$CMap@PAUHWND__@@PAU1@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@AAV23@@@IAEPAVCAssoc@1@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTMDIWndTab.cpp
