// from server: 100% by auto
// roc 2011-06 008bf310  unit: CXTPReportSelectedRows::USELECTED_BLOCK::?$CArray  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bf310
//
// 008bf310  56                   push esi
// 008bf311  8bf1                 mov esi, ecx
// 008bf313  837e1000             cmp dword ptr [esi + 0x10], 0
// 008bf317  7538                 jne 0x8bf351
// 008bf319  8b4618               mov eax, dword ptr [esi + 0x18]
// 008bf31c  6a10                 push 0x10
// 008bf31e  50                   push eax
// 008bf31f  8d4e14               lea ecx, [esi + 0x14]
// 008bf322  51                   push ecx
// 008bf323  e8c4b8f4ff           call 0x80abec
// 008bf328  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008bf32b  8bd1                 mov edx, ecx
// 008bf32d  83c004               add eax, 4
// 008bf330  c1e204               shl edx, 4
// 008bf333  83c1ff               add ecx, -1
// 008bf336  8d4410f0             lea eax, [eax + edx - 0x10]
// 008bf33a  7815                 js 0x8bf351
// 008bf33c  8d642400             lea esp, [esp]
// 008bf340  8b5610               mov edx, dword ptr [esi + 0x10]
// 008bf343  895008               mov dword ptr [eax + 8], edx
// 008bf346  894610               mov dword ptr [esi + 0x10], eax
// 008bf349  49                   dec ecx
// 008bf34a  83e810               sub eax, 0x10
// 008bf34d  85c9                 test ecx, ecx
// 008bf34f  7def                 jge 0x8bf340
// 008bf351  8b4610               mov eax, dword ptr [esi + 0x10]
// 008bf354  85c0                 test eax, eax
// 008bf356  7505                 jne 0x8bf35d
// 008bf358  e8adaff4ff           call 0x80a30a
// 008bf35d  8b5008               mov edx, dword ptr [eax + 8]
// 008bf360  33c9                 xor ecx, ecx
// 008bf362  8908                 mov dword ptr [eax], ecx
// 008bf364  894804               mov dword ptr [eax + 4], ecx
// 008bf367  89480c               mov dword ptr [eax + 0xc], ecx
// 008bf36a  895008               mov dword ptr [eax + 8], edx
// 008bf36d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008bf370  8b5108               mov edx, dword ptr [ecx + 8]
// 008bf373  ff460c               inc dword ptr [esi + 0xc]
// 008bf376  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008bf37a  895610               mov dword ptr [esi + 0x10], edx
// 008bf37d  8908                 mov dword ptr [eax], ecx
// 008bf37f  5e                   pop esi
// 008bf380  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?NewAssoc@?$CMap@PAUHICON__@@PAU1@HH@@IAEPAVCAssoc@1@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
