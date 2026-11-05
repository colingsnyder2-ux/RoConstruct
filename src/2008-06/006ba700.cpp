// from server: 100% by auto
// roc 2008-06 006ba700  unit: CXTPImageManagerResource::CBitmapDC  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba700
//
// 006ba700  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ba704  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ba708  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ba70b  50                   push eax
// 006ba70c  8b442418             mov eax, dword ptr [esp + 0x18]
// 006ba710  52                   push edx
// 006ba711  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ba715  50                   push eax
// 006ba716  8b442418             mov eax, dword ptr [esp + 0x18]
// 006ba71a  52                   push edx
// 006ba71b  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ba71f  50                   push eax
// 006ba720  8b442418             mov eax, dword ptr [esp + 0x18]
// 006ba724  52                   push edx
// 006ba725  50                   push eax
// 006ba726  51                   push ecx
// 006ba727  ff1544218000         call dword ptr [0x802144]
// 006ba72d  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ExtTextOutA@CDC@@UAEHHHIPBUtagRECT@@PBDIPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
