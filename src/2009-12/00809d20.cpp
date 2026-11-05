// from server: 100% by auto
// roc 2009-12 00809d20  unit: CXTPImageManagerResource::CBitmapDC  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809d20
//
// 00809d20  8b442420             mov eax, dword ptr [esp + 0x20]
// 00809d24  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00809d28  8b4904               mov ecx, dword ptr [ecx + 4]
// 00809d2b  50                   push eax
// 00809d2c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00809d30  52                   push edx
// 00809d31  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00809d35  50                   push eax
// 00809d36  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00809d3a  52                   push edx
// 00809d3b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00809d3f  50                   push eax
// 00809d40  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00809d44  52                   push edx
// 00809d45  50                   push eax
// 00809d46  51                   push ecx
// 00809d47  ff15fcca9800         call dword ptr [0x98cafc]
// 00809d4d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00809d51  0fbfd0               movsx edx, ax
// 00809d54  c1e810               shr eax, 0x10
// 00809d57  98                   cwde 
// 00809d58  894104               mov dword ptr [ecx + 4], eax
// 00809d5b  8911                 mov dword ptr [ecx], edx
// 00809d5d  8bc1                 mov eax, ecx
// 00809d5f  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?TabbedTextOutA@CDC@@UAE?AVCSize@@HHPBDHHPAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
