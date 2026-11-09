// from server: 100% by auto
// roc 2009-06 00732c40  unit: CXTPImageManagerResource::CBitmapDC  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732c40
//
// 00732c40  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00732c44  8b542418             mov edx, dword ptr [esp + 0x18]
// 00732c48  8b4904               mov ecx, dword ptr [ecx + 4]
// 00732c4b  50                   push eax
// 00732c4c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00732c50  52                   push edx
// 00732c51  8b542418             mov edx, dword ptr [esp + 0x18]
// 00732c55  50                   push eax
// 00732c56  8b442418             mov eax, dword ptr [esp + 0x18]
// 00732c5a  52                   push edx
// 00732c5b  8b542418             mov edx, dword ptr [esp + 0x18]
// 00732c5f  50                   push eax
// 00732c60  8b442418             mov eax, dword ptr [esp + 0x18]
// 00732c64  52                   push edx
// 00732c65  50                   push eax
// 00732c66  51                   push ecx
// 00732c67  ff1554e18900         call dword ptr [0x89e154]
// 00732c6d  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ExtTextOutA@CDC@@UAEHHHIPBUtagRECT@@PBDIPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
