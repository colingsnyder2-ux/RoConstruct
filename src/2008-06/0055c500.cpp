// from server: 100% by auto
// roc 2008-06 0055c500  unit: std::logic_error  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c500
//
// 0055c500  51                   push ecx
// 0055c501  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0055c505  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0055c509  c7042400000000       mov dword ptr [esp], 0
// 0055c510  7217                 jb 0x55c529
// 0055c512  8b4004               mov eax, dword ptr [eax + 4]
// 0055c515  56                   push esi
// 0055c516  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0055c51a  50                   push eax
// 0055c51b  56                   push esi
// 0055c51c  e85ff8ffff           call 0x55bd80
// 0055c521  83c408               add esp, 8
// 0055c524  8bc6                 mov eax, esi
// 0055c526  5e                   pop esi
// 0055c527  59                   pop ecx
// 0055c528  c3                   ret 
// 0055c529  56                   push esi
// 0055c52a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0055c52e  83c004               add eax, 4
// 0055c531  50                   push eax
// 0055c532  56                   push esi
// 0055c533  e848f8ffff           call 0x55bd80
// 0055c538  83c408               add esp, 8
// 0055c53b  8bc6                 mov eax, esi
// 0055c53d  5e                   pop esi
// 0055c53e  59                   pop ecx
// 0055c53f  c3                   ret 
// library boost-1.36.0/libs\iostreams\src\mapped_file.cpp (function ?system_failure@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@6@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/iostreams/src/mapped_file.cpp
