// from server: 100% by auto
// roc 2010-06 004012b0  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004012b0
//
// 004012b0  8b442404             mov eax, dword ptr [esp + 4]
// 004012b4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004012b8  8ad0                 mov dl, al
// 004012ba  80e20f               and dl, 0xf
// 004012bd  80c241               add dl, 0x41
// 004012c0  8811                 mov byte ptr [ecx], dl
// 004012c2  8bd0                 mov edx, eax
// 004012c4  c1ea04               shr edx, 4
// 004012c7  80e20f               and dl, 0xf
// 004012ca  80c241               add dl, 0x41
// 004012cd  885101               mov byte ptr [ecx + 1], dl
// 004012d0  8bd0                 mov edx, eax
// 004012d2  c1ea08               shr edx, 8
// 004012d5  80e20f               and dl, 0xf
// 004012d8  80c241               add dl, 0x41
// 004012db  885102               mov byte ptr [ecx + 2], dl
// 004012de  8bd0                 mov edx, eax
// 004012e0  c1ea0c               shr edx, 0xc
// 004012e3  80e20f               and dl, 0xf
// 004012e6  80c241               add dl, 0x41
// 004012e9  885103               mov byte ptr [ecx + 3], dl
// 004012ec  8bd0                 mov edx, eax
// 004012ee  c1ea10               shr edx, 0x10
// 004012f1  80e20f               and dl, 0xf
// 004012f4  80c241               add dl, 0x41
// 004012f7  885104               mov byte ptr [ecx + 4], dl
// 004012fa  8bd0                 mov edx, eax
// 004012fc  c1ea14               shr edx, 0x14
// 004012ff  80e20f               and dl, 0xf
// 00401302  80c241               add dl, 0x41
// 00401305  885105               mov byte ptr [ecx + 5], dl
// 00401308  8bd0                 mov edx, eax
// 0040130a  c1ea18               shr edx, 0x18
// 0040130d  c1e81c               shr eax, 0x1c
// 00401310  80e20f               and dl, 0xf
// 00401313  240f                 and al, 0xf
// 00401315  80c241               add dl, 0x41
// 00401318  0441                 add al, 0x41
// 0040131a  885106               mov byte ptr [ecx + 6], dl
// 0040131d  884107               mov byte ptr [ecx + 7], al
// 00401320  c6410800             mov byte ptr [ecx + 8], 0
// 00401324  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@K@detail@boost@@YAXKPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
