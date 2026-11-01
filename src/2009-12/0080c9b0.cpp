// from server: 100% by auto
// roc 2009-12 0080c9b0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c9b0
//
// 0080c9b0  56                   push esi
// 0080c9b1  8bf1                 mov esi, ecx
// 0080c9b3  837e1000             cmp dword ptr [esi + 0x10], 0
// 0080c9b7  7538                 jne 0x80c9f1
// 0080c9b9  8b4618               mov eax, dword ptr [esi + 0x18]
// 0080c9bc  6a10                 push 0x10
// 0080c9be  50                   push eax
// 0080c9bf  8d4e14               lea ecx, [esi + 0x14]
// 0080c9c2  51                   push ecx
// 0080c9c3  e8207afeff           call 0x7f43e8
// 0080c9c8  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0080c9cb  8bd1                 mov edx, ecx
// 0080c9cd  83c004               add eax, 4
// 0080c9d0  c1e204               shl edx, 4
// 0080c9d3  83c1ff               add ecx, -1
// 0080c9d6  8d4410f0             lea eax, [eax + edx - 0x10]
// 0080c9da  7815                 js 0x80c9f1
// 0080c9dc  8d642400             lea esp, [esp]
// 0080c9e0  8b5610               mov edx, dword ptr [esi + 0x10]
// 0080c9e3  895008               mov dword ptr [eax + 8], edx
// 0080c9e6  894610               mov dword ptr [esi + 0x10], eax
// 0080c9e9  49                   dec ecx
// 0080c9ea  83e810               sub eax, 0x10
// 0080c9ed  85c9                 test ecx, ecx
// 0080c9ef  7def                 jge 0x80c9e0
// 0080c9f1  8b4610               mov eax, dword ptr [esi + 0x10]
// 0080c9f4  85c0                 test eax, eax
// 0080c9f6  7505                 jne 0x80c9fd
// 0080c9f8  e80f71feff           call 0x7f3b0c
// 0080c9fd  8b5008               mov edx, dword ptr [eax + 8]
// 0080ca00  33c9                 xor ecx, ecx
// 0080ca02  8908                 mov dword ptr [eax], ecx
// 0080ca04  894804               mov dword ptr [eax + 4], ecx
// 0080ca07  89480c               mov dword ptr [eax + 0xc], ecx
// 0080ca0a  895008               mov dword ptr [eax + 8], edx
// 0080ca0d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0080ca10  8b5108               mov edx, dword ptr [ecx + 8]
// 0080ca13  ff460c               inc dword ptr [esi + 0xc]
// 0080ca16  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080ca1a  895610               mov dword ptr [esi + 0x10], edx
// 0080ca1d  8908                 mov dword ptr [eax], ecx
// 0080ca1f  5e                   pop esi
// 0080ca20  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?NewAssoc@?$CMap@PAUHICON__@@PAU1@HH@@IAEPAVCAssoc@1@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
