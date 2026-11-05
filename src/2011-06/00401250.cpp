// from server: 100% by auto
// roc 2011-06 00401250  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401250
//
// 00401250  8b442404             mov eax, dword ptr [esp + 4]
// 00401254  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401258  8ad0                 mov dl, al
// 0040125a  80e20f               and dl, 0xf
// 0040125d  80c241               add dl, 0x41
// 00401260  8811                 mov byte ptr [ecx], dl
// 00401262  8bd0                 mov edx, eax
// 00401264  c1ea04               shr edx, 4
// 00401267  80e20f               and dl, 0xf
// 0040126a  80c241               add dl, 0x41
// 0040126d  885101               mov byte ptr [ecx + 1], dl
// 00401270  8bd0                 mov edx, eax
// 00401272  c1ea08               shr edx, 8
// 00401275  80e20f               and dl, 0xf
// 00401278  80c241               add dl, 0x41
// 0040127b  885102               mov byte ptr [ecx + 2], dl
// 0040127e  8bd0                 mov edx, eax
// 00401280  c1ea0c               shr edx, 0xc
// 00401283  80e20f               and dl, 0xf
// 00401286  80c241               add dl, 0x41
// 00401289  885103               mov byte ptr [ecx + 3], dl
// 0040128c  8bd0                 mov edx, eax
// 0040128e  c1ea10               shr edx, 0x10
// 00401291  80e20f               and dl, 0xf
// 00401294  80c241               add dl, 0x41
// 00401297  885104               mov byte ptr [ecx + 4], dl
// 0040129a  8bd0                 mov edx, eax
// 0040129c  c1ea14               shr edx, 0x14
// 0040129f  80e20f               and dl, 0xf
// 004012a2  80c241               add dl, 0x41
// 004012a5  885105               mov byte ptr [ecx + 5], dl
// 004012a8  8bd0                 mov edx, eax
// 004012aa  c1ea18               shr edx, 0x18
// 004012ad  c1e81c               shr eax, 0x1c
// 004012b0  80e20f               and dl, 0xf
// 004012b3  240f                 and al, 0xf
// 004012b5  80c241               add dl, 0x41
// 004012b8  0441                 add al, 0x41
// 004012ba  885106               mov byte ptr [ecx + 6], dl
// 004012bd  884107               mov byte ptr [ecx + 7], al
// 004012c0  c6410800             mov byte ptr [ecx + 8], 0
// 004012c4  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@K@detail@boost@@YAXKPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
