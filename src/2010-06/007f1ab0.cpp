// from server: 100% by auto
// roc 2010-06 007f1ab0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f1ab0
//
// 007f1ab0  53                   push ebx
// 007f1ab1  56                   push esi
// 007f1ab2  57                   push edi
// 007f1ab3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007f1ab7  57                   push edi
// 007f1ab8  e881b61800           call 0x97d13e
// 007f1abd  e8ee0d0300           call 0x8228b0
// 007f1ac2  8bd8                 mov ebx, eax
// 007f1ac4  8b33                 mov esi, dword ptr [ebx]
// 007f1ac6  8bcf                 mov ecx, edi
// 007f1ac8  83c61c               add esi, 0x1c
// 007f1acb  e868b61800           call 0x97d138
// 007f1ad0  8b400c               mov eax, dword ptr [eax + 0xc]
// 007f1ad3  8b16                 mov edx, dword ptr [esi]
// 007f1ad5  50                   push eax
// 007f1ad6  8bcb                 mov ecx, ebx
// 007f1ad8  ffd2                 call edx
// 007f1ada  8bf0                 mov esi, eax
// 007f1adc  85f6                 test esi, esi
// 007f1ade  7417                 je 0x7f1af7
// 007f1ae0  8bcf                 mov ecx, edi
// 007f1ae2  e851b61800           call 0x97d138
// 007f1ae7  8bcf                 mov ecx, edi
// 007f1ae9  89700c               mov dword ptr [eax + 0xc], esi
// 007f1aec  e847b61800           call 0x97d138
// 007f1af1  83c004               add eax, 4
// 007f1af4  830801               or dword ptr [eax], 1
// 007f1af7  5f                   pop edi
// 007f1af8  5e                   pop esi
// 007f1af9  5b                   pop ebx
// 007f1afa  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorDialog.cpp (function ?AddPage@CXTColorDialog@@IAEXPAVCPropertyPage@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorDialog.cpp
