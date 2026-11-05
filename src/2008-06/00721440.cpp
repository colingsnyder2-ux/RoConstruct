// from server: 100% by auto
// roc 2008-06 00721440  unit: CXTPMenuBar  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00721440
//
// 00721440  56                   push esi
// 00721441  8bf1                 mov esi, ecx
// 00721443  837e1000             cmp dword ptr [esi + 0x10], 0
// 00721447  7538                 jne 0x721481
// 00721449  8b4618               mov eax, dword ptr [esi + 0x18]
// 0072144c  6a10                 push 0x10
// 0072144e  50                   push eax
// 0072144f  8d4e14               lea ecx, [esi + 0x14]
// 00721452  51                   push ecx
// 00721453  e8e4fcf7ff           call 0x6a113c
// 00721458  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0072145b  8bd1                 mov edx, ecx
// 0072145d  83c004               add eax, 4
// 00721460  c1e204               shl edx, 4
// 00721463  83c1ff               add ecx, -1
// 00721466  8d4410f0             lea eax, [eax + edx - 0x10]
// 0072146a  7815                 js 0x721481
// 0072146c  8d642400             lea esp, [esp]
// 00721470  8b5610               mov edx, dword ptr [esi + 0x10]
// 00721473  895008               mov dword ptr [eax + 8], edx
// 00721476  894610               mov dword ptr [esi + 0x10], eax
// 00721479  49                   dec ecx
// 0072147a  83e810               sub eax, 0x10
// 0072147d  85c9                 test ecx, ecx
// 0072147f  7def                 jge 0x721470
// 00721481  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721484  85c0                 test eax, eax
// 00721486  7505                 jne 0x72148d
// 00721488  e8b7f4f7ff           call 0x6a0944
// 0072148d  8b5008               mov edx, dword ptr [eax + 8]
// 00721490  33c9                 xor ecx, ecx
// 00721492  8908                 mov dword ptr [eax], ecx
// 00721494  894804               mov dword ptr [eax + 4], ecx
// 00721497  89480c               mov dword ptr [eax + 0xc], ecx
// 0072149a  895008               mov dword ptr [eax + 8], edx
// 0072149d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007214a0  8b5108               mov edx, dword ptr [ecx + 8]
// 007214a3  ff460c               inc dword ptr [esi + 0xc]
// 007214a6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007214aa  895610               mov dword ptr [esi + 0x10], edx
// 007214ad  8908                 mov dword ptr [eax], ecx
// 007214af  5e                   pop esi
// 007214b0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?NewAssoc@?$CMap@PAUHICON__@@PAU1@HH@@IAEPAVCAssoc@1@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
