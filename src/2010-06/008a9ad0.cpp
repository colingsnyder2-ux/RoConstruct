// from server: 100% by auto
// roc 2010-06 008a9ad0  unit: CXTButtonThemeOffice2003  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a9ad0
//
// 008a9ad0  56                   push esi
// 008a9ad1  8bf1                 mov esi, ecx
// 008a9ad3  8b4604               mov eax, dword ptr [esi + 4]
// 008a9ad6  85c0                 test eax, eax
// 008a9ad8  7414                 je 0x8a9aee
// 008a9ada  50                   push eax
// 008a9adb  ff1584bb9e00         call dword ptr [0x9ebb84]
// 008a9ae1  8b442408             mov eax, dword ptr [esp + 8]
// 008a9ae5  894604               mov dword ptr [esi + 4], eax
// 008a9ae8  8bc6                 mov eax, esi
// 008a9aea  5e                   pop esi
// 008a9aeb  c20400               ret 4
// 008a9aee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008a9af2  894e04               mov dword ptr [esi + 4], ecx
// 008a9af5  8bc6                 mov eax, esi
// 008a9af7  5e                   pop esi
// 008a9af8  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTUtil.cpp (function ??4CXTIconHandle@@QAEAAV0@PAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTUtil.cpp
