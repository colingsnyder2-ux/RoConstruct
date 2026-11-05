// from server: 100% by auto
// roc 2007-03 00632b90  unit: seg_00630000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632b90
//
// 00632b90  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00632b94  8b4908               mov ecx, dword ptr [ecx + 8]
// 00632b97  83ec08               sub esp, 8
// 00632b9a  8d0424               lea eax, [esp]
// 00632b9d  50                   push eax
// 00632b9e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00632ba2  52                   push edx
// 00632ba3  50                   push eax
// 00632ba4  51                   push ecx
// 00632ba5  ff15bcd07700         call dword ptr [0x77d0bc]
// 00632bab  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00632baf  8b1424               mov edx, dword ptr [esp]
// 00632bb2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00632bb6  8910                 mov dword ptr [eax], edx
// 00632bb8  894804               mov dword ptr [eax + 4], ecx
// 00632bbb  83c408               add esp, 8
// 00632bbe  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dcmeta.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dcmeta.cpp
