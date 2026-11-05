// from server: 100% by auto
// roc 2012-06 004011c0  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004011c0
//
// 004011c0  8b442404             mov eax, dword ptr [esp + 4]
// 004011c4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004011c8  8ad0                 mov dl, al
// 004011ca  80e20f               and dl, 0xf
// 004011cd  80c241               add dl, 0x41
// 004011d0  8811                 mov byte ptr [ecx], dl
// 004011d2  8bd0                 mov edx, eax
// 004011d4  c1fa04               sar edx, 4
// 004011d7  80e20f               and dl, 0xf
// 004011da  80c241               add dl, 0x41
// 004011dd  885101               mov byte ptr [ecx + 1], dl
// 004011e0  8bd0                 mov edx, eax
// 004011e2  c1fa08               sar edx, 8
// 004011e5  80e20f               and dl, 0xf
// 004011e8  80c241               add dl, 0x41
// 004011eb  885102               mov byte ptr [ecx + 2], dl
// 004011ee  8bd0                 mov edx, eax
// 004011f0  c1fa0c               sar edx, 0xc
// 004011f3  80e20f               and dl, 0xf
// 004011f6  80c241               add dl, 0x41
// 004011f9  885103               mov byte ptr [ecx + 3], dl
// 004011fc  8bd0                 mov edx, eax
// 004011fe  c1fa10               sar edx, 0x10
// 00401201  80e20f               and dl, 0xf
// 00401204  80c241               add dl, 0x41
// 00401207  885104               mov byte ptr [ecx + 4], dl
// 0040120a  8bd0                 mov edx, eax
// 0040120c  c1fa14               sar edx, 0x14
// 0040120f  80e20f               and dl, 0xf
// 00401212  80c241               add dl, 0x41
// 00401215  885105               mov byte ptr [ecx + 5], dl
// 00401218  8bd0                 mov edx, eax
// 0040121a  c1fa18               sar edx, 0x18
// 0040121d  c1f81c               sar eax, 0x1c
// 00401220  80e20f               and dl, 0xf
// 00401223  240f                 and al, 0xf
// 00401225  80c241               add dl, 0x41
// 00401228  0441                 add al, 0x41
// 0040122a  885106               mov byte ptr [ecx + 6], dl
// 0040122d  884107               mov byte ptr [ecx + 7], al
// 00401230  c6410800             mov byte ptr [ecx + 8], 0
// 00401234  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@H@detail@boost@@YAXHPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
