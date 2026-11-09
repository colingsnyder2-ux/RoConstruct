// from server: 100% by auto
// roc 2011-06 008201e0  unit: CXTPImageManagerResource::CBitmapDC  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008201e0
//
// 008201e0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008201e4  8b542418             mov edx, dword ptr [esp + 0x18]
// 008201e8  8b4904               mov ecx, dword ptr [ecx + 4]
// 008201eb  50                   push eax
// 008201ec  8b442418             mov eax, dword ptr [esp + 0x18]
// 008201f0  52                   push edx
// 008201f1  8b542418             mov edx, dword ptr [esp + 0x18]
// 008201f5  50                   push eax
// 008201f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 008201fa  52                   push edx
// 008201fb  8b542418             mov edx, dword ptr [esp + 0x18]
// 008201ff  50                   push eax
// 00820200  8b442418             mov eax, dword ptr [esp + 0x18]
// 00820204  52                   push edx
// 00820205  50                   push eax
// 00820206  51                   push ecx
// 00820207  ff153c01a400         call dword ptr [0xa4013c]
// 0082020d  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ExtTextOutA@CDC@@UAEHHHIPBUtagRECT@@PBDIPAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
