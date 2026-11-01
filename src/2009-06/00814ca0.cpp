// from server: 100% by auto
// roc 2009-06 00814ca0  unit: CXTPRibbonControlTab  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00814ca0
//
// 00814ca0  56                   push esi
// 00814ca1  8d442408             lea eax, [esp + 8]
// 00814ca5  50                   push eax
// 00814ca6  8bf1                 mov esi, ecx
// 00814ca8  e823bff4ff           call 0x760bd0
// 00814cad  85c0                 test eax, eax
// 00814caf  7530                 jne 0x814ce1
// 00814cb1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00814cb5  8b542408             mov edx, dword ptr [esp + 8]
// 00814cb9  51                   push ecx
// 00814cba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00814cbe  83ec10               sub esp, 0x10
// 00814cc1  8bc4                 mov eax, esp
// 00814cc3  8910                 mov dword ptr [eax], edx
// 00814cc5  8b542424             mov edx, dword ptr [esp + 0x24]
// 00814cc9  894804               mov dword ptr [eax + 4], ecx
// 00814ccc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00814cd0  895008               mov dword ptr [eax + 8], edx
// 00814cd3  89480c               mov dword ptr [eax + 0xc], ecx
// 00814cd6  8bce                 mov ecx, esi
// 00814cd8  e873b0f0ff           call 0x71fd50
// 00814cdd  5e                   pop esi
// 00814cde  c21400               ret 0x14
// 00814ce1  682cd38f00           push 0x8fd32c
// 00814ce6  ff15d8e98900         call dword ptr [0x89e9d8]
// 00814cec  8b542418             mov edx, dword ptr [esp + 0x18]
// 00814cf0  8902                 mov dword ptr [edx], eax
// 00814cf2  33c0                 xor eax, eax
// 00814cf4  5e                   pop esi
// 00814cf5  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonControlTab.cpp (function ?GetAccessibleDefaultAction@CXTPRibbonControlTab@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonControlTab.cpp
