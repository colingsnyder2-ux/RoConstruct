// from server: 100% by auto
// roc 2009-12 0084a2c0  unit: CXTPControlSelector  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084a2c0
//
// 0084a2c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084a2c4  56                   push esi
// 0084a2c5  8b742408             mov esi, dword ptr [esp + 8]
// 0084a2c9  8d4801               lea ecx, [eax + 1]
// 0084a2cc  51                   push ecx
// 0084a2cd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0084a2d1  8d5101               lea edx, [ecx + 1]
// 0084a2d4  52                   push edx
// 0084a2d5  50                   push eax
// 0084a2d6  51                   push ecx
// 0084a2d7  8bce                 mov ecx, esi
// 0084a2d9  e874c60d00           call 0x926952
// 0084a2de  8b442410             mov eax, dword ptr [esp + 0x10]
// 0084a2e2  8d4801               lea ecx, [eax + 1]
// 0084a2e5  51                   push ecx
// 0084a2e6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0084a2ea  51                   push ecx
// 0084a2eb  49                   dec ecx
// 0084a2ec  50                   push eax
// 0084a2ed  51                   push ecx
// 0084a2ee  8bce                 mov ecx, esi
// 0084a2f0  e85dc60d00           call 0x926952
// 0084a2f5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084a2f9  8b442418             mov eax, dword ptr [esp + 0x18]
// 0084a2fd  50                   push eax
// 0084a2fe  8d5101               lea edx, [ecx + 1]
// 0084a301  52                   push edx
// 0084a302  48                   dec eax
// 0084a303  50                   push eax
// 0084a304  51                   push ecx
// 0084a305  8bce                 mov ecx, esi
// 0084a307  e846c60d00           call 0x926952
// 0084a30c  8b442418             mov eax, dword ptr [esp + 0x18]
// 0084a310  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0084a314  50                   push eax
// 0084a315  51                   push ecx
// 0084a316  48                   dec eax
// 0084a317  49                   dec ecx
// 0084a318  50                   push eax
// 0084a319  51                   push ecx
// 0084a31a  8bce                 mov ecx, esi
// 0084a31c  e831c60d00           call 0x926952
// 0084a321  5e                   pop esi
// 0084a322  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?ExcludeCorners@CXTPOffice2003Theme@@QAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
