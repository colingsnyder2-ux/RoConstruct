// from server: 100% by auto
// roc 2007-03 0069fac0  unit: seg_00690000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0069fac0
//
// 0069fac0  56                   push esi
// 0069fac1  8d442408             lea eax, [esp + 8]
// 0069fac5  50                   push eax
// 0069fac6  8bf1                 mov esi, ecx
// 0069fac8  e8e364feff           call 0x685fb0
// 0069facd  85c0                 test eax, eax
// 0069facf  7530                 jne 0x69fb01
// 0069fad1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0069fad5  8b542408             mov edx, dword ptr [esp + 8]
// 0069fad9  51                   push ecx
// 0069fada  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0069fade  83ec10               sub esp, 0x10
// 0069fae1  8bc4                 mov eax, esp
// 0069fae3  8910                 mov dword ptr [eax], edx
// 0069fae5  8b542424             mov edx, dword ptr [esp + 0x24]
// 0069fae9  894804               mov dword ptr [eax + 4], ecx
// 0069faec  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0069faf0  895008               mov dword ptr [eax + 8], edx
// 0069faf3  89480c               mov dword ptr [eax + 0xc], ecx
// 0069faf6  8bce                 mov ecx, esi
// 0069faf8  e8b3fef8ff           call 0x62f9b0
// 0069fafd  5e                   pop esi
// 0069fafe  c21400               ret 0x14
// 0069fb01  68903b7c00           push 0x7c3b90
// 0069fb06  ff15ccea7700         call dword ptr [0x77eacc]
// 0069fb0c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069fb10  8902                 mov dword ptr [edx], eax
// 0069fb12  33c0                 xor eax, eax
// 0069fb14  5e                   pop esi
// 0069fb15  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPControlGallery.cpp (function ?GetAccessibleDefaultAction@CXTPControlGallery@@MAEJUtagVARIANT@@PAPA_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlGallery.cpp
