// from server: 100% by auto
// roc 2009-06 00762be0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00762be0
//
// 00762be0  53                   push ebx
// 00762be1  56                   push esi
// 00762be2  57                   push edi
// 00762be3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00762be7  57                   push edi
// 00762be8  e8a9960e00           call 0x84c296
// 00762bed  e84e850300           call 0x79b140
// 00762bf2  8bd8                 mov ebx, eax
// 00762bf4  8b33                 mov esi, dword ptr [ebx]
// 00762bf6  8bcf                 mov ecx, edi
// 00762bf8  83c61c               add esi, 0x1c
// 00762bfb  e890960e00           call 0x84c290
// 00762c00  8b400c               mov eax, dword ptr [eax + 0xc]
// 00762c03  8b16                 mov edx, dword ptr [esi]
// 00762c05  50                   push eax
// 00762c06  8bcb                 mov ecx, ebx
// 00762c08  ffd2                 call edx
// 00762c0a  8bf0                 mov esi, eax
// 00762c0c  85f6                 test esi, esi
// 00762c0e  7417                 je 0x762c27
// 00762c10  8bcf                 mov ecx, edi
// 00762c12  e879960e00           call 0x84c290
// 00762c17  8bcf                 mov ecx, edi
// 00762c19  89700c               mov dword ptr [eax + 0xc], esi
// 00762c1c  e86f960e00           call 0x84c290
// 00762c21  83c004               add eax, 4
// 00762c24  830801               or dword ptr [eax], 1
// 00762c27  5f                   pop edi
// 00762c28  5e                   pop esi
// 00762c29  5b                   pop ebx
// 00762c2a  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorDialog.cpp (function ?AddPage@CXTPColorDialog@@IAEXPAVCPropertyPage@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorDialog.cpp
