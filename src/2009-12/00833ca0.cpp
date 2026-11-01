// from server: 100% by auto
// roc 2009-12 00833ca0  unit: CRobloxTreeCtrl  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833ca0
//
// 00833ca0  56                   push esi
// 00833ca1  8bf1                 mov esi, ecx
// 00833ca3  837e1000             cmp dword ptr [esi + 0x10], 0
// 00833ca7  57                   push edi
// 00833ca8  7537                 jne 0x833ce1
// 00833caa  8b4618               mov eax, dword ptr [esi + 0x18]
// 00833cad  6a50                 push 0x50
// 00833caf  50                   push eax
// 00833cb0  8d4e14               lea ecx, [esi + 0x14]
// 00833cb3  51                   push ecx
// 00833cb4  e82f07fcff           call 0x7f43e8
// 00833cb9  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00833cbc  8d1489               lea edx, [ecx + ecx*4]
// 00833cbf  83c004               add eax, 4
// 00833cc2  c1e204               shl edx, 4
// 00833cc5  83c1ff               add ecx, -1
// 00833cc8  8d4410b0             lea eax, [eax + edx - 0x50]
// 00833ccc  7813                 js 0x833ce1
// 00833cce  8bff                 mov edi, edi
// 00833cd0  8b5610               mov edx, dword ptr [esi + 0x10]
// 00833cd3  895048               mov dword ptr [eax + 0x48], edx
// 00833cd6  894610               mov dword ptr [esi + 0x10], eax
// 00833cd9  49                   dec ecx
// 00833cda  83e850               sub eax, 0x50
// 00833cdd  85c9                 test ecx, ecx
// 00833cdf  7def                 jge 0x833cd0
// 00833ce1  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00833ce4  85ff                 test edi, edi
// 00833ce6  7505                 jne 0x833ced
// 00833ce8  e81ffefbff           call 0x7f3b0c
// 00833ced  53                   push ebx
// 00833cee  8b5f48               mov ebx, dword ptr [edi + 0x48]
// 00833cf1  6a50                 push 0x50
// 00833cf3  6a00                 push 0
// 00833cf5  57                   push edi
// 00833cf6  e8a90dfcff           call 0x7f4aa4
// 00833cfb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00833cff  895f48               mov dword ptr [edi + 0x48], ebx
// 00833d02  8b4610               mov eax, dword ptr [esi + 0x10]
// 00833d05  8b4848               mov ecx, dword ptr [eax + 0x48]
// 00833d08  ff460c               inc dword ptr [esi + 0xc]
// 00833d0b  894e10               mov dword ptr [esi + 0x10], ecx
// 00833d0e  8d4704               lea eax, [edi + 4]
// 00833d11  6a3c                 push 0x3c
// 00833d13  83c9ff               or ecx, 0xffffffff
// 00833d16  8917                 mov dword ptr [edi], edx
// 00833d18  6a00                 push 0
// 00833d1a  50                   push eax
// 00833d1b  89483c               mov dword ptr [eax + 0x3c], ecx
// 00833d1e  894840               mov dword ptr [eax + 0x40], ecx
// 00833d21  e87e0dfcff           call 0x7f4aa4
// 00833d26  83c418               add esp, 0x18
// 00833d29  5b                   pop ebx
// 00833d2a  8bc7                 mov eax, edi
// 00833d2c  5f                   pop edi
// 00833d2d  5e                   pop esi
// 00833d2e  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?NewAssoc@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@IAEPAVCAssoc@1@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
