// from server: 100% by auto
// roc 2009-06 00732c70  unit: CXTPImageManagerResource::CBitmapDC  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732c70
//
// 00732c70  8b442420             mov eax, dword ptr [esp + 0x20]
// 00732c74  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00732c78  8b4904               mov ecx, dword ptr [ecx + 4]
// 00732c7b  50                   push eax
// 00732c7c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00732c80  52                   push edx
// 00732c81  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00732c85  50                   push eax
// 00732c86  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00732c8a  52                   push edx
// 00732c8b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00732c8f  50                   push eax
// 00732c90  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00732c94  52                   push edx
// 00732c95  50                   push eax
// 00732c96  51                   push ecx
// 00732c97  ff1510ef8900         call dword ptr [0x89ef10]
// 00732c9d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00732ca1  0fbfd0               movsx edx, ax
// 00732ca4  c1e810               shr eax, 0x10
// 00732ca7  98                   cwde 
// 00732ca8  894104               mov dword ptr [ecx + 4], eax
// 00732cab  8911                 mov dword ptr [ecx], edx
// 00732cad  8bc1                 mov eax, ecx
// 00732caf  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?TabbedTextOutA@CDC@@UAE?AVCSize@@HHPBDHHPAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
