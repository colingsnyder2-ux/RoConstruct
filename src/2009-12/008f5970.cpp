// from server: 100% by auto
// roc 2009-12 008f5970  unit: CXTButtonThemeOffice2003  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f5970
//
// 008f5970  56                   push esi
// 008f5971  8bf1                 mov esi, ecx
// 008f5973  8b4604               mov eax, dword ptr [esi + 4]
// 008f5976  85c0                 test eax, eax
// 008f5978  7414                 je 0x8f598e
// 008f597a  50                   push eax
// 008f597b  ff15f8c99800         call dword ptr [0x98c9f8]
// 008f5981  8b442408             mov eax, dword ptr [esp + 8]
// 008f5985  894604               mov dword ptr [esi + 4], eax
// 008f5988  8bc6                 mov eax, esi
// 008f598a  5e                   pop esi
// 008f598b  c20400               ret 4
// 008f598e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008f5992  894e04               mov dword ptr [esi + 4], ecx
// 008f5995  8bc6                 mov eax, esi
// 008f5997  5e                   pop esi
// 008f5998  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Util\XTPUtil.cpp (function ??4CXTPIconHandle@@QAEAAV0@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPUtil.cpp
