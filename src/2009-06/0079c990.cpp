// from server: 100% by auto
// roc 2009-06 0079c990  unit: CXTPControlGallery  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079c990
//
// 0079c990  56                   push esi
// 0079c991  8d442408             lea eax, [esp + 8]
// 0079c995  50                   push eax
// 0079c996  8bf1                 mov esi, ecx
// 0079c998  e83342fcff           call 0x760bd0
// 0079c99d  85c0                 test eax, eax
// 0079c99f  7530                 jne 0x79c9d1
// 0079c9a1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079c9a5  8b542408             mov edx, dword ptr [esp + 8]
// 0079c9a9  51                   push ecx
// 0079c9aa  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0079c9ae  83ec10               sub esp, 0x10
// 0079c9b1  8bc4                 mov eax, esp
// 0079c9b3  8910                 mov dword ptr [eax], edx
// 0079c9b5  8b542424             mov edx, dword ptr [esp + 0x24]
// 0079c9b9  894804               mov dword ptr [eax + 4], ecx
// 0079c9bc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0079c9c0  895008               mov dword ptr [eax + 8], edx
// 0079c9c3  89480c               mov dword ptr [eax + 0xc], ecx
// 0079c9c6  8bce                 mov ecx, esi
// 0079c9c8  e88333f8ff           call 0x71fd50
// 0079c9cd  5e                   pop esi
// 0079c9ce  c21400               ret 0x14
// 0079c9d1  686c218f00           push 0x8f216c
// 0079c9d6  ff15d8e98900         call dword ptr [0x89e9d8]
// 0079c9dc  8b542418             mov edx, dword ptr [esp + 0x18]
// 0079c9e0  8902                 mov dword ptr [edx], eax
// 0079c9e2  33c0                 xor eax, eax
// 0079c9e4  5e                   pop esi
// 0079c9e5  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleDefaultAction@CXTPControlGallery@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
