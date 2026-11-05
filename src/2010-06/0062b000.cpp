// from server: 100% by auto
// roc 2010-06 0062b000  unit: CPropGrid::UpdateItemsJob  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062b000
//
// 0062b000  51                   push ecx
// 0062b001  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0062b005  83781810             cmp dword ptr [eax + 0x18], 0x10
// 0062b009  c7042400000000       mov dword ptr [esp], 0
// 0062b010  7217                 jb 0x62b029
// 0062b012  8b4004               mov eax, dword ptr [eax + 4]
// 0062b015  56                   push esi
// 0062b016  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0062b01a  50                   push eax
// 0062b01b  56                   push esi
// 0062b01c  e8cffeffff           call 0x62aef0
// 0062b021  83c408               add esp, 8
// 0062b024  8bc6                 mov eax, esi
// 0062b026  5e                   pop esi
// 0062b027  59                   pop ecx
// 0062b028  c3                   ret 
// 0062b029  56                   push esi
// 0062b02a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0062b02e  83c004               add eax, 4
// 0062b031  50                   push eax
// 0062b032  56                   push esi
// 0062b033  e8b8feffff           call 0x62aef0
// 0062b038  83c408               add esp, 8
// 0062b03b  8bc6                 mov eax, esi
// 0062b03d  5e                   pop esi
// 0062b03e  59                   pop ecx
// 0062b03f  c3                   ret 
// library boost-1.36.0/libs\iostreams\src\mapped_file.cpp (function ?system_failure@detail@iostreams@boost@@YA?AVfailure@ios_base@std@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@6@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/iostreams/src/mapped_file.cpp
