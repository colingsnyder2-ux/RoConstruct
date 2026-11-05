// from server: 100% by auto
// roc 2010-06 00403410  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403410
//
// 00403410  51                   push ecx
// 00403411  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00403415  6a00                 push 0
// 00403417  6a00                 push 0
// 00403419  6a00                 push 0
// 0040341b  6a00                 push 0
// 0040341d  6a00                 push 0
// 0040341f  6a00                 push 0
// 00403421  6a00                 push 0
// 00403423  8d44241c             lea eax, [esp + 0x1c]
// 00403427  50                   push eax
// 00403428  6a00                 push 0
// 0040342a  6a00                 push 0
// 0040342c  6a00                 push 0
// 0040342e  51                   push ecx
// 0040342f  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00403437  ff1520a09e00         call dword ptr [0x9ea020]
// 0040343d  85c0                 test eax, eax
// 0040343f  7406                 je 0x403447
// 00403441  33c0                 xor eax, eax
// 00403443  59                   pop ecx
// 00403444  c20400               ret 4
// 00403447  33d2                 xor edx, edx
// 00403449  3b1424               cmp edx, dword ptr [esp]
// 0040344c  1bc0                 sbb eax, eax
// 0040344e  f7d8                 neg eax
// 00403450  59                   pop ecx
// 00403451  c20400               ret 4
// library atl-8.0/atl.cpp (function ?HasSubKeys@CRegParser@ATL@@IAEHPAUHKEY__@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
