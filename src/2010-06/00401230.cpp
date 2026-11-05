// from server: 100% by auto
// roc 2010-06 00401230  unit: CAboutRobloxDialog  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401230
//
// 00401230  8b442404             mov eax, dword ptr [esp + 4]
// 00401234  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401238  8ad0                 mov dl, al
// 0040123a  80e20f               and dl, 0xf
// 0040123d  80c241               add dl, 0x41
// 00401240  8811                 mov byte ptr [ecx], dl
// 00401242  8bd0                 mov edx, eax
// 00401244  c1fa04               sar edx, 4
// 00401247  80e20f               and dl, 0xf
// 0040124a  80c241               add dl, 0x41
// 0040124d  885101               mov byte ptr [ecx + 1], dl
// 00401250  8bd0                 mov edx, eax
// 00401252  c1fa08               sar edx, 8
// 00401255  80e20f               and dl, 0xf
// 00401258  80c241               add dl, 0x41
// 0040125b  885102               mov byte ptr [ecx + 2], dl
// 0040125e  8bd0                 mov edx, eax
// 00401260  c1fa0c               sar edx, 0xc
// 00401263  80e20f               and dl, 0xf
// 00401266  80c241               add dl, 0x41
// 00401269  885103               mov byte ptr [ecx + 3], dl
// 0040126c  8bd0                 mov edx, eax
// 0040126e  c1fa10               sar edx, 0x10
// 00401271  80e20f               and dl, 0xf
// 00401274  80c241               add dl, 0x41
// 00401277  885104               mov byte ptr [ecx + 4], dl
// 0040127a  8bd0                 mov edx, eax
// 0040127c  c1fa14               sar edx, 0x14
// 0040127f  80e20f               and dl, 0xf
// 00401282  80c241               add dl, 0x41
// 00401285  885105               mov byte ptr [ecx + 5], dl
// 00401288  8bd0                 mov edx, eax
// 0040128a  c1fa18               sar edx, 0x18
// 0040128d  c1f81c               sar eax, 0x1c
// 00401290  80e20f               and dl, 0xf
// 00401293  240f                 and al, 0xf
// 00401295  80c241               add dl, 0x41
// 00401298  0441                 add al, 0x41
// 0040129a  885106               mov byte ptr [ecx + 6], dl
// 0040129d  884107               mov byte ptr [ecx + 7], al
// 004012a0  c6410800             mov byte ptr [ecx + 8], 0
// 004012a4  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??$int_to_string@H@detail@boost@@YAXHPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
