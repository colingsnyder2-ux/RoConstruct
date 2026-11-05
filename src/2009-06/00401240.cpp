// from server: 100% by auto
// roc 2009-06 00401240  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401240
//
// 00401240  8b442404             mov eax, dword ptr [esp + 4]
// 00401244  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401248  8ad0                 mov dl, al
// 0040124a  80e20f               and dl, 0xf
// 0040124d  80c241               add dl, 0x41
// 00401250  8811                 mov byte ptr [ecx], dl
// 00401252  8bd0                 mov edx, eax
// 00401254  c1fa04               sar edx, 4
// 00401257  80e20f               and dl, 0xf
// 0040125a  80c241               add dl, 0x41
// 0040125d  885101               mov byte ptr [ecx + 1], dl
// 00401260  8bd0                 mov edx, eax
// 00401262  c1fa08               sar edx, 8
// 00401265  80e20f               and dl, 0xf
// 00401268  80c241               add dl, 0x41
// 0040126b  885102               mov byte ptr [ecx + 2], dl
// 0040126e  8bd0                 mov edx, eax
// 00401270  c1fa0c               sar edx, 0xc
// 00401273  80e20f               and dl, 0xf
// 00401276  80c241               add dl, 0x41
// 00401279  885103               mov byte ptr [ecx + 3], dl
// 0040127c  8bd0                 mov edx, eax
// 0040127e  c1fa10               sar edx, 0x10
// 00401281  80e20f               and dl, 0xf
// 00401284  80c241               add dl, 0x41
// 00401287  885104               mov byte ptr [ecx + 4], dl
// 0040128a  8bd0                 mov edx, eax
// 0040128c  c1fa14               sar edx, 0x14
// 0040128f  80e20f               and dl, 0xf
// 00401292  80c241               add dl, 0x41
// 00401295  885105               mov byte ptr [ecx + 5], dl
// 00401298  8bd0                 mov edx, eax
// 0040129a  c1fa18               sar edx, 0x18
// 0040129d  c1f81c               sar eax, 0x1c
// 004012a0  80e20f               and dl, 0xf
// 004012a3  240f                 and al, 0xf
// 004012a5  80c241               add dl, 0x41
// 004012a8  0441                 add al, 0x41
// 004012aa  885106               mov byte ptr [ecx + 6], dl
// 004012ad  884107               mov byte ptr [ecx + 7], al
// 004012b0  c6410800             mov byte ptr [ecx + 8], 0
// 004012b4  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@H@detail@boost@@YAXHPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
