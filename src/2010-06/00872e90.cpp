// from server: 100% by auto
// roc 2010-06 00872e90  unit: CXTPDockingPaneContext  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00872e90
//
// 00872e90  56                   push esi
// 00872e91  8bf1                 mov esi, ecx
// 00872e93  837e1000             cmp dword ptr [esi + 0x10], 0
// 00872e97  7538                 jne 0x872ed1
// 00872e99  8b4618               mov eax, dword ptr [esi + 0x18]
// 00872e9c  6a10                 push 0x10
// 00872e9e  50                   push eax
// 00872e9f  8d4e14               lea ecx, [esi + 0x14]
// 00872ea2  51                   push ecx
// 00872ea3  e88056f3ff           call 0x7a8528
// 00872ea8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00872eab  8bd1                 mov edx, ecx
// 00872ead  83c004               add eax, 4
// 00872eb0  c1e204               shl edx, 4
// 00872eb3  83c1ff               add ecx, -1
// 00872eb6  8d4410f0             lea eax, [eax + edx - 0x10]
// 00872eba  7815                 js 0x872ed1
// 00872ebc  8d642400             lea esp, [esp]
// 00872ec0  8b5610               mov edx, dword ptr [esi + 0x10]
// 00872ec3  895008               mov dword ptr [eax + 8], edx
// 00872ec6  894610               mov dword ptr [esi + 0x10], eax
// 00872ec9  49                   dec ecx
// 00872eca  83e810               sub eax, 0x10
// 00872ecd  85c9                 test ecx, ecx
// 00872ecf  7def                 jge 0x872ec0
// 00872ed1  8b4610               mov eax, dword ptr [esi + 0x10]
// 00872ed4  85c0                 test eax, eax
// 00872ed6  7505                 jne 0x872edd
// 00872ed8  e86f4df3ff           call 0x7a7c4c
// 00872edd  8b5008               mov edx, dword ptr [eax + 8]
// 00872ee0  33c9                 xor ecx, ecx
// 00872ee2  8908                 mov dword ptr [eax], ecx
// 00872ee4  894804               mov dword ptr [eax + 4], ecx
// 00872ee7  89480c               mov dword ptr [eax + 0xc], ecx
// 00872eea  895008               mov dword ptr [eax + 8], edx
// 00872eed  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00872ef0  8b5108               mov edx, dword ptr [ecx + 8]
// 00872ef3  ff460c               inc dword ptr [esi + 0xc]
// 00872ef6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00872efa  895610               mov dword ptr [esi + 0x10], edx
// 00872efd  8908                 mov dword ptr [eax], ecx
// 00872eff  5e                   pop esi
// 00872f00  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?NewAssoc@?$CMap@PAUHICON__@@PAU1@HH@@IAEPAVCAssoc@1@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
