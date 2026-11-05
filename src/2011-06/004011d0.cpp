// from server: 100% by auto
// roc 2011-06 004011d0  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004011d0
//
// 004011d0  8b442404             mov eax, dword ptr [esp + 4]
// 004011d4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004011d8  8ad0                 mov dl, al
// 004011da  80e20f               and dl, 0xf
// 004011dd  80c241               add dl, 0x41
// 004011e0  8811                 mov byte ptr [ecx], dl
// 004011e2  8bd0                 mov edx, eax
// 004011e4  c1fa04               sar edx, 4
// 004011e7  80e20f               and dl, 0xf
// 004011ea  80c241               add dl, 0x41
// 004011ed  885101               mov byte ptr [ecx + 1], dl
// 004011f0  8bd0                 mov edx, eax
// 004011f2  c1fa08               sar edx, 8
// 004011f5  80e20f               and dl, 0xf
// 004011f8  80c241               add dl, 0x41
// 004011fb  885102               mov byte ptr [ecx + 2], dl
// 004011fe  8bd0                 mov edx, eax
// 00401200  c1fa0c               sar edx, 0xc
// 00401203  80e20f               and dl, 0xf
// 00401206  80c241               add dl, 0x41
// 00401209  885103               mov byte ptr [ecx + 3], dl
// 0040120c  8bd0                 mov edx, eax
// 0040120e  c1fa10               sar edx, 0x10
// 00401211  80e20f               and dl, 0xf
// 00401214  80c241               add dl, 0x41
// 00401217  885104               mov byte ptr [ecx + 4], dl
// 0040121a  8bd0                 mov edx, eax
// 0040121c  c1fa14               sar edx, 0x14
// 0040121f  80e20f               and dl, 0xf
// 00401222  80c241               add dl, 0x41
// 00401225  885105               mov byte ptr [ecx + 5], dl
// 00401228  8bd0                 mov edx, eax
// 0040122a  c1fa18               sar edx, 0x18
// 0040122d  c1f81c               sar eax, 0x1c
// 00401230  80e20f               and dl, 0xf
// 00401233  240f                 and al, 0xf
// 00401235  80c241               add dl, 0x41
// 00401238  0441                 add al, 0x41
// 0040123a  885106               mov byte ptr [ecx + 6], dl
// 0040123d  884107               mov byte ptr [ecx + 7], al
// 00401240  c6410800             mov byte ptr [ecx + 8], 0
// 00401244  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@H@detail@boost@@YAXHPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
