// from server: 100% by auto
// roc 2007-08 006801a0  unit: CXTPBufferDC  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006801a0
//
// 006801a0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006801a4  8b542418             mov edx, dword ptr [esp + 0x18]
// 006801a8  8b4904               mov ecx, dword ptr [ecx + 4]
// 006801ab  50                   push eax
// 006801ac  8b442418             mov eax, dword ptr [esp + 0x18]
// 006801b0  52                   push edx
// 006801b1  8b542418             mov edx, dword ptr [esp + 0x18]
// 006801b5  50                   push eax
// 006801b6  8b442418             mov eax, dword ptr [esp + 0x18]
// 006801ba  52                   push edx
// 006801bb  8b542418             mov edx, dword ptr [esp + 0x18]
// 006801bf  50                   push eax
// 006801c0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006801c4  52                   push edx
// 006801c5  50                   push eax
// 006801c6  51                   push ecx
// 006801c7  ff15bcd07700         call dword ptr [0x77d0bc]
// 006801cd  c21c00               ret 0x1c
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ExtTextOutA@CDC@@UAEHHHIPBUtagRECT@@PBDIPAH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
