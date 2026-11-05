// from server: 100% by auto
// roc 2009-12 006b1850  unit: RBX::DropperTool  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b1850
//
// 006b1850  51                   push ecx
// 006b1851  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b1855  83781810             cmp dword ptr [eax + 0x18], 0x10
// 006b1859  c7042400000000       mov dword ptr [esp], 0
// 006b1860  7217                 jb 0x6b1879
// 006b1862  8b4004               mov eax, dword ptr [eax + 4]
// 006b1865  56                   push esi
// 006b1866  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b186a  50                   push eax
// 006b186b  56                   push esi
// 006b186c  e83fffffff           call 0x6b17b0
// 006b1871  83c408               add esp, 8
// 006b1874  8bc6                 mov eax, esi
// 006b1876  5e                   pop esi
// 006b1877  59                   pop ecx
// 006b1878  c3                   ret 
// 006b1879  56                   push esi
// 006b187a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b187e  83c004               add eax, 4
// 006b1881  50                   push eax
// 006b1882  56                   push esi
// 006b1883  e828ffffff           call 0x6b17b0
// 006b1888  83c408               add esp, 8
// 006b188b  8bc6                 mov eax, esi
// 006b188d  5e                   pop esi
// 006b188e  59                   pop ecx
// 006b188f  c3                   ret 
// library boost-1.36.0/libs\iostreams\src\mapped_file.cpp (function ?system_failure@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@6@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/iostreams/src/mapped_file.cpp
