// from server: 100% by auto
// roc 2012-06 0047af40  unit: VCWorkspace::?$CComObject  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047af40
//
// 0047af40  51                   push ecx
// 0047af41  8bc1                 mov eax, ecx
// 0047af43  8b4804               mov ecx, dword ptr [eax + 4]
// 0047af46  8b00                 mov eax, dword ptr [eax]
// 0047af48  8b11                 mov edx, dword ptr [ecx]
// 0047af4a  8b5208               mov edx, dword ptr [edx + 8]
// 0047af4d  56                   push esi
// 0047af4e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0047af52  50                   push eax
// 0047af53  56                   push esi
// 0047af54  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0047af5c  ffd2                 call edx
// 0047af5e  8bc6                 mov eax, esi
// 0047af60  5e                   pop esi
// 0047af61  59                   pop ecx
// 0047af62  c20400               ret 4
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ?message@error_code@system@boost@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
