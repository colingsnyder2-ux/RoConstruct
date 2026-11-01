// from server: 100% by auto
// roc 2009-12 00877910  unit: CXTPControlGallery  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00877910
//
// 00877910  56                   push esi
// 00877911  8d442408             lea eax, [esp + 8]
// 00877915  50                   push eax
// 00877916  8bf1                 mov esi, ecx
// 00877918  e88340fcff           call 0x83b9a0
// 0087791d  85c0                 test eax, eax
// 0087791f  7530                 jne 0x877951
// 00877921  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00877925  8b542408             mov edx, dword ptr [esp + 8]
// 00877929  51                   push ecx
// 0087792a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0087792e  83ec10               sub esp, 0x10
// 00877931  8bc4                 mov eax, esp
// 00877933  8910                 mov dword ptr [eax], edx
// 00877935  8b542424             mov edx, dword ptr [esp + 0x24]
// 00877939  894804               mov dword ptr [eax + 4], ecx
// 0087793c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00877940  895008               mov dword ptr [eax + 8], edx
// 00877943  89480c               mov dword ptr [eax + 0xc], ecx
// 00877946  8bce                 mov ecx, esi
// 00877948  e823eaf7ff           call 0x7f6370
// 0087794d  5e                   pop esi
// 0087794e  c21400               ret 0x14
// 00877951  68b8179f00           push 0x9f17b8
// 00877956  ff1550ba9800         call dword ptr [0x98ba50]
// 0087795c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00877960  8902                 mov dword ptr [edx], eax
// 00877962  33c0                 xor eax, eax
// 00877964  5e                   pop esi
// 00877965  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleDefaultAction@CXTPControlGallery@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
