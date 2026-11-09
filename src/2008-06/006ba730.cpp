// from server: 100% by auto
// roc 2008-06 006ba730  unit: CXTPImageManagerResource::CBitmapDC  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba730
//
// 006ba730  8b442420             mov eax, dword ptr [esp + 0x20]
// 006ba734  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006ba738  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ba73b  50                   push eax
// 006ba73c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ba740  52                   push edx
// 006ba741  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006ba745  50                   push eax
// 006ba746  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ba74a  52                   push edx
// 006ba74b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006ba74f  50                   push eax
// 006ba750  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006ba754  52                   push edx
// 006ba755  50                   push eax
// 006ba756  51                   push ecx
// 006ba757  ff157c2b8000         call dword ptr [0x802b7c]
// 006ba75d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006ba761  0fbfd0               movsx edx, ax
// 006ba764  c1e810               shr eax, 0x10
// 006ba767  98                   cwde 
// 006ba768  894104               mov dword ptr [ecx + 4], eax
// 006ba76b  8911                 mov dword ptr [ecx], edx
// 006ba76d  8bc1                 mov eax, ecx
// 006ba76f  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?TabbedTextOutA@CDC@@UAE?AVCSize@@HHPBDHHPAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
