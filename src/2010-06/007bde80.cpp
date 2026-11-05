// from server: 100% by auto
// roc 2010-06 007bde80  unit: CXTPImageManagerResource::CBitmapDC  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bde80
//
// 007bde80  8b442420             mov eax, dword ptr [esp + 0x20]
// 007bde84  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007bde88  8b4904               mov ecx, dword ptr [ecx + 4]
// 007bde8b  50                   push eax
// 007bde8c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bde90  52                   push edx
// 007bde91  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007bde95  50                   push eax
// 007bde96  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bde9a  52                   push edx
// 007bde9b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007bde9f  50                   push eax
// 007bdea0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bdea4  52                   push edx
// 007bdea5  50                   push eax
// 007bdea6  51                   push ecx
// 007bdea7  ff15b0b99e00         call dword ptr [0x9eb9b0]
// 007bdead  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007bdeb1  0fbfd0               movsx edx, ax
// 007bdeb4  c1e810               shr eax, 0x10
// 007bdeb7  98                   cwde 
// 007bdeb8  894104               mov dword ptr [ecx + 4], eax
// 007bdebb  8911                 mov dword ptr [ecx], edx
// 007bdebd  8bc1                 mov eax, ecx
// 007bdebf  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?TabbedTextOutA@CDC@@UAE?AVCSize@@HHPBDHHPAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
