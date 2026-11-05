// from server: 100% by auto
// roc 2010-06 007bde50  unit: CXTPImageManagerResource::CBitmapDC  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bde50
//
// 007bde50  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bde54  8b542418             mov edx, dword ptr [esp + 0x18]
// 007bde58  8b4904               mov ecx, dword ptr [ecx + 4]
// 007bde5b  50                   push eax
// 007bde5c  8b442418             mov eax, dword ptr [esp + 0x18]
// 007bde60  52                   push edx
// 007bde61  8b542418             mov edx, dword ptr [esp + 0x18]
// 007bde65  50                   push eax
// 007bde66  8b442418             mov eax, dword ptr [esp + 0x18]
// 007bde6a  52                   push edx
// 007bde6b  8b542418             mov edx, dword ptr [esp + 0x18]
// 007bde6f  50                   push eax
// 007bde70  8b442418             mov eax, dword ptr [esp + 0x18]
// 007bde74  52                   push edx
// 007bde75  50                   push eax
// 007bde76  51                   push ecx
// 007bde77  ff15b8a09e00         call dword ptr [0x9ea0b8]
// 007bde7d  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ExtTextOutA@CDC@@UAEHHHIPBUtagRECT@@PBDIPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
