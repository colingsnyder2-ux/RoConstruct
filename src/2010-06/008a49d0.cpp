// from server: 100% by auto
// roc 2010-06 008a49d0  unit: CXTPRibbonControlTab  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a49d0
//
// 008a49d0  56                   push esi
// 008a49d1  8d442408             lea eax, [esp + 8]
// 008a49d5  50                   push eax
// 008a49d6  8bf1                 mov esi, ecx
// 008a49d8  e813b1f4ff           call 0x7efaf0
// 008a49dd  85c0                 test eax, eax
// 008a49df  7530                 jne 0x8a4a11
// 008a49e1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008a49e5  8b542408             mov edx, dword ptr [esp + 8]
// 008a49e9  51                   push ecx
// 008a49ea  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008a49ee  83ec10               sub esp, 0x10
// 008a49f1  8bc4                 mov eax, esp
// 008a49f3  8910                 mov dword ptr [eax], edx
// 008a49f5  8b542424             mov edx, dword ptr [esp + 0x24]
// 008a49f9  894804               mov dword ptr [eax + 4], ecx
// 008a49fc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008a4a00  895008               mov dword ptr [eax + 8], edx
// 008a4a03  89480c               mov dword ptr [eax + 0xc], ecx
// 008a4a06  8bce                 mov ecx, esi
// 008a4a08  e8a35af0ff           call 0x7aa4b0
// 008a4a0d  5e                   pop esi
// 008a4a0e  c21400               ret 0x14
// 008a4a11  68941aa600           push 0xa61a94
// 008a4a16  ff1580aa9e00         call dword ptr [0x9eaa80]
// 008a4a1c  8b542418             mov edx, dword ptr [esp + 0x18]
// 008a4a20  8902                 mov dword ptr [edx], eax
// 008a4a22  33c0                 xor eax, eax
// 008a4a24  5e                   pop esi
// 008a4a25  c21400               ret 0x14
// library xtp-13.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleDefaultAction@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
