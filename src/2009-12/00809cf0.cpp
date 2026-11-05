// from server: 100% by auto
// roc 2009-12 00809cf0  unit: CXTPImageManagerResource::CBitmapDC  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809cf0
//
// 00809cf0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00809cf4  8b542418             mov edx, dword ptr [esp + 0x18]
// 00809cf8  8b4904               mov ecx, dword ptr [ecx + 4]
// 00809cfb  50                   push eax
// 00809cfc  8b442418             mov eax, dword ptr [esp + 0x18]
// 00809d00  52                   push edx
// 00809d01  8b542418             mov edx, dword ptr [esp + 0x18]
// 00809d05  50                   push eax
// 00809d06  8b442418             mov eax, dword ptr [esp + 0x18]
// 00809d0a  52                   push edx
// 00809d0b  8b542418             mov edx, dword ptr [esp + 0x18]
// 00809d0f  50                   push eax
// 00809d10  8b442418             mov eax, dword ptr [esp + 0x18]
// 00809d14  52                   push edx
// 00809d15  50                   push eax
// 00809d16  51                   push ecx
// 00809d17  ff1568b19800         call dword ptr [0x98b168]
// 00809d1d  c21c00               ret 0x1c
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ExtTextOutA@CDC@@UAEHHHIPBUtagRECT@@PBDIPAH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
