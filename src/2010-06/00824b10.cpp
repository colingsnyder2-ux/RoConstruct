// from server: 100% by auto
// roc 2010-06 00824b10  unit: CXTPControlGallery  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00824b10
//
// 00824b10  56                   push esi
// 00824b11  8d442408             lea eax, [esp + 8]
// 00824b15  50                   push eax
// 00824b16  8bf1                 mov esi, ecx
// 00824b18  e8d3affcff           call 0x7efaf0
// 00824b1d  85c0                 test eax, eax
// 00824b1f  7530                 jne 0x824b51
// 00824b21  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00824b25  8b542408             mov edx, dword ptr [esp + 8]
// 00824b29  51                   push ecx
// 00824b2a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00824b2e  83ec10               sub esp, 0x10
// 00824b31  8bc4                 mov eax, esp
// 00824b33  8910                 mov dword ptr [eax], edx
// 00824b35  8b542424             mov edx, dword ptr [esp + 0x24]
// 00824b39  894804               mov dword ptr [eax + 4], ecx
// 00824b3c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00824b40  895008               mov dword ptr [eax + 8], edx
// 00824b43  89480c               mov dword ptr [eax + 0xc], ecx
// 00824b46  8bce                 mov ecx, esi
// 00824b48  e86359f8ff           call 0x7aa4b0
// 00824b4d  5e                   pop esi
// 00824b4e  c21400               ret 0x14
// 00824b51  68a85aa500           push 0xa55aa8
// 00824b56  ff1580aa9e00         call dword ptr [0x9eaa80]
// 00824b5c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00824b60  8902                 mov dword ptr [edx], eax
// 00824b62  33c0                 xor eax, eax
// 00824b64  5e                   pop esi
// 00824b65  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleDefaultAction@CXTPControlGallery@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlGallery.cpp
