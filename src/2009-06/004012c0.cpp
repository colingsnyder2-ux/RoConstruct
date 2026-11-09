// from server: 100% by auto
// roc 2009-06 004012c0  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004012c0
//
// 004012c0  8b442404             mov eax, dword ptr [esp + 4]
// 004012c4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004012c8  8ad0                 mov dl, al
// 004012ca  80e20f               and dl, 0xf
// 004012cd  80c241               add dl, 0x41
// 004012d0  8811                 mov byte ptr [ecx], dl
// 004012d2  8bd0                 mov edx, eax
// 004012d4  c1ea04               shr edx, 4
// 004012d7  80e20f               and dl, 0xf
// 004012da  80c241               add dl, 0x41
// 004012dd  885101               mov byte ptr [ecx + 1], dl
// 004012e0  8bd0                 mov edx, eax
// 004012e2  c1ea08               shr edx, 8
// 004012e5  80e20f               and dl, 0xf
// 004012e8  80c241               add dl, 0x41
// 004012eb  885102               mov byte ptr [ecx + 2], dl
// 004012ee  8bd0                 mov edx, eax
// 004012f0  c1ea0c               shr edx, 0xc
// 004012f3  80e20f               and dl, 0xf
// 004012f6  80c241               add dl, 0x41
// 004012f9  885103               mov byte ptr [ecx + 3], dl
// 004012fc  8bd0                 mov edx, eax
// 004012fe  c1ea10               shr edx, 0x10
// 00401301  80e20f               and dl, 0xf
// 00401304  80c241               add dl, 0x41
// 00401307  885104               mov byte ptr [ecx + 4], dl
// 0040130a  8bd0                 mov edx, eax
// 0040130c  c1ea14               shr edx, 0x14
// 0040130f  80e20f               and dl, 0xf
// 00401312  80c241               add dl, 0x41
// 00401315  885105               mov byte ptr [ecx + 5], dl
// 00401318  8bd0                 mov edx, eax
// 0040131a  c1ea18               shr edx, 0x18
// 0040131d  c1e81c               shr eax, 0x1c
// 00401320  80e20f               and dl, 0xf
// 00401323  240f                 and al, 0xf
// 00401325  80c241               add dl, 0x41
// 00401328  0441                 add al, 0x41
// 0040132a  885106               mov byte ptr [ecx + 6], dl
// 0040132d  884107               mov byte ptr [ecx + 7], al
// 00401330  c6410800             mov byte ptr [ecx + 8], 0
// 00401334  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@K@detail@boost@@YAXKPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
