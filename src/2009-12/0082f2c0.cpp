// from server: 100% by auto
// roc 2009-12 0082f2c0  unit: CXTPReportSelectedRows  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f2c0
//
// 0082f2c0  8b442404             mov eax, dword ptr [esp + 4]
// 0082f2c4  85c0                 test eax, eax
// 0082f2c6  7417                 je 0x82f2df
// 0082f2c8  6a0c                 push 0xc
// 0082f2ca  50                   push eax
// 0082f2cb  ff1564b19800         call dword ptr [0x98b164]
// 0082f2d1  48                   dec eax
// 0082f2d2  b907000000           mov ecx, 7
// 0082f2d7  3bc8                 cmp ecx, eax
// 0082f2d9  1bc0                 sbb eax, eax
// 0082f2db  40                   inc eax
// 0082f2dc  c20400               ret 4
// 0082f2df  53                   push ebx
// 0082f2e0  8b1de4cb9800         mov ebx, dword ptr [0x98cbe4]
// 0082f2e6  56                   push esi
// 0082f2e7  ffd3                 call ebx
// 0082f2e9  50                   push eax
// 0082f2ea  ff15e0cb9800         call dword ptr [0x98cbe0]
// 0082f2f0  8bf0                 mov esi, eax
// 0082f2f2  85f6                 test esi, esi
// 0082f2f4  7427                 je 0x82f31d
// 0082f2f6  57                   push edi
// 0082f2f7  6a0c                 push 0xc
// 0082f2f9  56                   push esi
// 0082f2fa  ff1564b19800         call dword ptr [0x98b164]
// 0082f300  56                   push esi
// 0082f301  8bf8                 mov edi, eax
// 0082f303  ffd3                 call ebx
// 0082f305  50                   push eax
// 0082f306  ff15d8cb9800         call dword ptr [0x98cbd8]
// 0082f30c  4f                   dec edi
// 0082f30d  ba07000000           mov edx, 7
// 0082f312  3bd7                 cmp edx, edi
// 0082f314  5f                   pop edi
// 0082f315  1bc0                 sbb eax, eax
// 0082f317  5e                   pop esi
// 0082f318  40                   inc eax
// 0082f319  5b                   pop ebx
// 0082f31a  c20400               ret 4
// 0082f31d  5e                   pop esi
// 0082f31e  33c0                 xor eax, eax
// 0082f320  5b                   pop ebx
// 0082f321  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?IsLowResolution@CXTPColorManager@@QAEHPAUHDC__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
