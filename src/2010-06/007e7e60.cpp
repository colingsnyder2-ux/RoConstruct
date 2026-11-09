// from server: 100% by auto
// roc 2010-06 007e7e60  unit: CRobloxTreeCtrl  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7e60
//
// 007e7e60  56                   push esi
// 007e7e61  8bf1                 mov esi, ecx
// 007e7e63  837e1000             cmp dword ptr [esi + 0x10], 0
// 007e7e67  57                   push edi
// 007e7e68  7537                 jne 0x7e7ea1
// 007e7e6a  8b4618               mov eax, dword ptr [esi + 0x18]
// 007e7e6d  6a50                 push 0x50
// 007e7e6f  50                   push eax
// 007e7e70  8d4e14               lea ecx, [esi + 0x14]
// 007e7e73  51                   push ecx
// 007e7e74  e8af06fcff           call 0x7a8528
// 007e7e79  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007e7e7c  8d1489               lea edx, [ecx + ecx*4]
// 007e7e7f  83c004               add eax, 4
// 007e7e82  c1e204               shl edx, 4
// 007e7e85  83c1ff               add ecx, -1
// 007e7e88  8d4410b0             lea eax, [eax + edx - 0x50]
// 007e7e8c  7813                 js 0x7e7ea1
// 007e7e8e  8bff                 mov edi, edi
// 007e7e90  8b5610               mov edx, dword ptr [esi + 0x10]
// 007e7e93  895048               mov dword ptr [eax + 0x48], edx
// 007e7e96  894610               mov dword ptr [esi + 0x10], eax
// 007e7e99  49                   dec ecx
// 007e7e9a  83e850               sub eax, 0x50
// 007e7e9d  85c9                 test ecx, ecx
// 007e7e9f  7def                 jge 0x7e7e90
// 007e7ea1  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007e7ea4  85ff                 test edi, edi
// 007e7ea6  7505                 jne 0x7e7ead
// 007e7ea8  e89ffdfbff           call 0x7a7c4c
// 007e7ead  53                   push ebx
// 007e7eae  8b5f48               mov ebx, dword ptr [edi + 0x48]
// 007e7eb1  6a50                 push 0x50
// 007e7eb3  6a00                 push 0
// 007e7eb5  57                   push edi
// 007e7eb6  e8290dfcff           call 0x7a8be4
// 007e7ebb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007e7ebf  895f48               mov dword ptr [edi + 0x48], ebx
// 007e7ec2  8b4610               mov eax, dword ptr [esi + 0x10]
// 007e7ec5  8b4848               mov ecx, dword ptr [eax + 0x48]
// 007e7ec8  ff460c               inc dword ptr [esi + 0xc]
// 007e7ecb  894e10               mov dword ptr [esi + 0x10], ecx
// 007e7ece  8d4704               lea eax, [edi + 4]
// 007e7ed1  6a3c                 push 0x3c
// 007e7ed3  83c9ff               or ecx, 0xffffffff
// 007e7ed6  8917                 mov dword ptr [edi], edx
// 007e7ed8  6a00                 push 0
// 007e7eda  50                   push eax
// 007e7edb  89483c               mov dword ptr [eax + 0x3c], ecx
// 007e7ede  894840               mov dword ptr [eax + 0x40], ecx
// 007e7ee1  e8fe0cfcff           call 0x7a8be4
// 007e7ee6  83c418               add esp, 0x18
// 007e7ee9  5b                   pop ebx
// 007e7eea  8bc7                 mov eax, edi
// 007e7eec  5f                   pop edi
// 007e7eed  5e                   pop esi
// 007e7eee  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?NewAssoc@?$CMap@PAXPAXUCLRFONT@CXTTreeBase@@AAU12@@@IAEPAVCAssoc@1@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
