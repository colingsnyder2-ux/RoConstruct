// from server: 100% by auto
// roc 2007-03 0065c530  unit: seg_00650000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065c530
//
// 0065c530  56                   push esi
// 0065c531  8bf1                 mov esi, ecx
// 0065c533  e8f0e80d00           call 0x73ae28
// 0065c538  33c0                 xor eax, eax
// 0065c53a  894664               mov dword ptr [esi + 0x64], eax
// 0065c53d  894668               mov dword ptr [esi + 0x68], eax
// 0065c540  894660               mov dword ptr [esi + 0x60], eax
// 0065c543  89465c               mov dword ptr [esi + 0x5c], eax
// 0065c546  c70634857c00         mov dword ptr [esi], 0x7c8534
// 0065c54c  8bc6                 mov eax, esi
// 0065c54e  5e                   pop esi
// 0065c54f  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ??0CXTPPropertyGridToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
