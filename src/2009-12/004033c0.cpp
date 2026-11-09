// from server: 100% by auto
// roc 2009-12 004033c0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004033c0
//
// 004033c0  51                   push ecx
// 004033c1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004033c5  6a00                 push 0
// 004033c7  6a00                 push 0
// 004033c9  6a00                 push 0
// 004033cb  6a00                 push 0
// 004033cd  6a00                 push 0
// 004033cf  6a00                 push 0
// 004033d1  6a00                 push 0
// 004033d3  8d44241c             lea eax, [esp + 0x1c]
// 004033d7  50                   push eax
// 004033d8  6a00                 push 0
// 004033da  6a00                 push 0
// 004033dc  6a00                 push 0
// 004033de  51                   push ecx
// 004033df  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004033e7  ff1518b09800         call dword ptr [0x98b018]
// 004033ed  85c0                 test eax, eax
// 004033ef  7406                 je 0x4033f7
// 004033f1  33c0                 xor eax, eax
// 004033f3  59                   pop ecx
// 004033f4  c20400               ret 4
// 004033f7  33d2                 xor edx, edx
// 004033f9  3b1424               cmp edx, dword ptr [esp]
// 004033fc  1bc0                 sbb eax, eax
// 004033fe  f7d8                 neg eax
// 00403400  59                   pop ecx
// 00403401  c20400               ret 4
// library atl-8.0/atl.cpp (function ?HasSubKeys@CRegParser@ATL@@IAEHPAUHKEY__@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
