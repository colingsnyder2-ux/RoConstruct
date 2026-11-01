// from server: 100% by auto
// roc 2007-08 00683be0  unit: CXTPPropertyGrid  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00683be0
//
// 00683be0  83ec10               sub esp, 0x10
// 00683be3  56                   push esi
// 00683be4  8bf1                 mov esi, ecx
// 00683be6  85f6                 test esi, esi
// 00683be8  742e                 je 0x683c18
// 00683bea  837e2000             cmp dword ptr [esi + 0x20], 0
// 00683bee  7428                 je 0x683c18
// 00683bf0  56                   push esi
// 00683bf1  8d4c2408             lea ecx, [esp + 8]
// 00683bf5  e806c4ffff           call 0x680000
// 00683bfa  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00683bfe  2b4c2408             sub ecx, dword ptr [esp + 8]
// 00683c02  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00683c06  2b542404             sub edx, dword ptr [esp + 4]
// 00683c0a  8b06                 mov eax, dword ptr [esi]
// 00683c0c  8b8050010000         mov eax, dword ptr [eax + 0x150]
// 00683c12  51                   push ecx
// 00683c13  52                   push edx
// 00683c14  8bce                 mov ecx, esi
// 00683c16  ffd0                 call eax
// 00683c18  5e                   pop esi
// 00683c19  83c410               add esp, 0x10
// 00683c1c  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?Reposition@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
