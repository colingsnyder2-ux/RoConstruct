// from server: 100% by auto
// roc 2009-06 005d94a0  unit: VAuthoringSettings::?$BoundPropGetSet  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d94a0
//
// 005d94a0  51                   push ecx
// 005d94a1  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005d94a5  83781810             cmp dword ptr [eax + 0x18], 0x10
// 005d94a9  c7042400000000       mov dword ptr [esp], 0
// 005d94b0  7217                 jb 0x5d94c9
// 005d94b2  8b4004               mov eax, dword ptr [eax + 4]
// 005d94b5  56                   push esi
// 005d94b6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d94ba  50                   push eax
// 005d94bb  56                   push esi
// 005d94bc  e8cff7ffff           call 0x5d8c90
// 005d94c1  83c408               add esp, 8
// 005d94c4  8bc6                 mov eax, esi
// 005d94c6  5e                   pop esi
// 005d94c7  59                   pop ecx
// 005d94c8  c3                   ret 
// 005d94c9  56                   push esi
// 005d94ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d94ce  83c004               add eax, 4
// 005d94d1  50                   push eax
// 005d94d2  56                   push esi
// 005d94d3  e8b8f7ffff           call 0x5d8c90
// 005d94d8  83c408               add esp, 8
// 005d94db  8bc6                 mov eax, esi
// 005d94dd  5e                   pop esi
// 005d94de  59                   pop ecx
// 005d94df  c3                   ret 
// library boost-1.36.0/libs\iostreams\src\mapped_file.cpp (function ?system_failure@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@6@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/iostreams/src/mapped_file.cpp
