// from server: 100% by auto
// roc 2009-06 004036f0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004036f0
//
// 004036f0  51                   push ecx
// 004036f1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004036f5  6a00                 push 0
// 004036f7  6a00                 push 0
// 004036f9  6a00                 push 0
// 004036fb  6a00                 push 0
// 004036fd  6a00                 push 0
// 004036ff  6a00                 push 0
// 00403701  6a00                 push 0
// 00403703  8d44241c             lea eax, [esp + 0x1c]
// 00403707  50                   push eax
// 00403708  6a00                 push 0
// 0040370a  6a00                 push 0
// 0040370c  6a00                 push 0
// 0040370e  51                   push ecx
// 0040370f  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00403717  ff1518e08900         call dword ptr [0x89e018]
// 0040371d  85c0                 test eax, eax
// 0040371f  7406                 je 0x403727
// 00403721  33c0                 xor eax, eax
// 00403723  59                   pop ecx
// 00403724  c20400               ret 4
// 00403727  33d2                 xor edx, edx
// 00403729  3b1424               cmp edx, dword ptr [esp]
// 0040372c  1bc0                 sbb eax, eax
// 0040372e  f7d8                 neg eax
// 00403730  59                   pop ecx
// 00403731  c20400               ret 4
// library atl-8.0/atl.cpp (function ?HasSubKeys@CRegParser@ATL@@IAEHPAUHKEY__@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
