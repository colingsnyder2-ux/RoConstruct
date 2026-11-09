// from server: 100% by auto
// roc 2011-06 00653c10  unit: CPropGrid::UpdateItemsJob  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00653c10
//
// 00653c10  51                   push ecx
// 00653c11  8bc1                 mov eax, ecx
// 00653c13  8b4804               mov ecx, dword ptr [eax + 4]
// 00653c16  8b00                 mov eax, dword ptr [eax]
// 00653c18  8b11                 mov edx, dword ptr [ecx]
// 00653c1a  8b5208               mov edx, dword ptr [edx + 8]
// 00653c1d  56                   push esi
// 00653c1e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00653c22  50                   push eax
// 00653c23  56                   push esi
// 00653c24  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00653c2c  ffd2                 call edx
// 00653c2e  8bc6                 mov eax, esi
// 00653c30  5e                   pop esi
// 00653c31  59                   pop ecx
// 00653c32  c20400               ret 4
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ?message@error_code@system@boost@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
