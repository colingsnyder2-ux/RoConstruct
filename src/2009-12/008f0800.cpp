// from server: 100% by auto
// roc 2009-12 008f0800  unit: CXTPRibbonControlTab  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f0800
//
// 008f0800  56                   push esi
// 008f0801  8d442408             lea eax, [esp + 8]
// 008f0805  50                   push eax
// 008f0806  8bf1                 mov esi, ecx
// 008f0808  e893b1f4ff           call 0x83b9a0
// 008f080d  85c0                 test eax, eax
// 008f080f  7530                 jne 0x8f0841
// 008f0811  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008f0815  8b542408             mov edx, dword ptr [esp + 8]
// 008f0819  51                   push ecx
// 008f081a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f081e  83ec10               sub esp, 0x10
// 008f0821  8bc4                 mov eax, esp
// 008f0823  8910                 mov dword ptr [eax], edx
// 008f0825  8b542424             mov edx, dword ptr [esp + 0x24]
// 008f0829  894804               mov dword ptr [eax + 4], ecx
// 008f082c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008f0830  895008               mov dword ptr [eax + 8], edx
// 008f0833  89480c               mov dword ptr [eax + 0xc], ecx
// 008f0836  8bce                 mov ecx, esi
// 008f0838  e8335bf0ff           call 0x7f6370
// 008f083d  5e                   pop esi
// 008f083e  c21400               ret 0x14
// 008f0841  68d4d79f00           push 0x9fd7d4
// 008f0846  ff1550ba9800         call dword ptr [0x98ba50]
// 008f084c  8b542418             mov edx, dword ptr [esp + 0x18]
// 008f0850  8902                 mov dword ptr [edx], eax
// 008f0852  33c0                 xor eax, eax
// 008f0854  5e                   pop esi
// 008f0855  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleDefaultAction@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
