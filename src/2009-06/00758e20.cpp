// from server: 100% by auto
// roc 2009-06 00758e20  unit: CRobloxTreeCtrl  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758e20
//
// 00758e20  56                   push esi
// 00758e21  8bf1                 mov esi, ecx
// 00758e23  837e1000             cmp dword ptr [esi + 0x10], 0
// 00758e27  57                   push edi
// 00758e28  7537                 jne 0x758e61
// 00758e2a  8b4618               mov eax, dword ptr [esi + 0x18]
// 00758e2d  6a50                 push 0x50
// 00758e2f  50                   push eax
// 00758e30  8d4e14               lea ecx, [esi + 0x14]
// 00758e33  51                   push ecx
// 00758e34  e88107fcff           call 0x7195ba
// 00758e39  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00758e3c  8d1489               lea edx, [ecx + ecx*4]
// 00758e3f  83c004               add eax, 4
// 00758e42  c1e204               shl edx, 4
// 00758e45  83c1ff               add ecx, -1
// 00758e48  8d4410b0             lea eax, [eax + edx - 0x50]
// 00758e4c  7813                 js 0x758e61
// 00758e4e  8bff                 mov edi, edi
// 00758e50  8b5610               mov edx, dword ptr [esi + 0x10]
// 00758e53  895048               mov dword ptr [eax + 0x48], edx
// 00758e56  894610               mov dword ptr [esi + 0x10], eax
// 00758e59  49                   dec ecx
// 00758e5a  83e850               sub eax, 0x50
// 00758e5d  85c9                 test ecx, ecx
// 00758e5f  7def                 jge 0x758e50
// 00758e61  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00758e64  85ff                 test edi, edi
// 00758e66  7505                 jne 0x758e6d
// 00758e68  e877fefbff           call 0x718ce4
// 00758e6d  53                   push ebx
// 00758e6e  8b5f48               mov ebx, dword ptr [edi + 0x48]
// 00758e71  6a50                 push 0x50
// 00758e73  6a00                 push 0
// 00758e75  57                   push edi
// 00758e76  e8f90dfcff           call 0x719c74
// 00758e7b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00758e7f  895f48               mov dword ptr [edi + 0x48], ebx
// 00758e82  8b4610               mov eax, dword ptr [esi + 0x10]
// 00758e85  8b4848               mov ecx, dword ptr [eax + 0x48]
// 00758e88  ff460c               inc dword ptr [esi + 0xc]
// 00758e8b  894e10               mov dword ptr [esi + 0x10], ecx
// 00758e8e  8d4704               lea eax, [edi + 4]
// 00758e91  6a3c                 push 0x3c
// 00758e93  83c9ff               or ecx, 0xffffffff
// 00758e96  8917                 mov dword ptr [edi], edx
// 00758e98  6a00                 push 0
// 00758e9a  50                   push eax
// 00758e9b  89483c               mov dword ptr [eax + 0x3c], ecx
// 00758e9e  894840               mov dword ptr [eax + 0x40], ecx
// 00758ea1  e8ce0dfcff           call 0x719c74
// 00758ea6  83c418               add esp, 0x18
// 00758ea9  5b                   pop ebx
// 00758eaa  8bc7                 mov eax, edi
// 00758eac  5f                   pop edi
// 00758ead  5e                   pop esi
// 00758eae  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?NewAssoc@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@IAEPAVCAssoc@1@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
