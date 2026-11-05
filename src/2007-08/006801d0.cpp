// from server: 100% by auto
// roc 2007-08 006801d0  unit: CXTPBufferDC  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006801d0
//
// 006801d0  8b442420             mov eax, dword ptr [esp + 0x20]
// 006801d4  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006801d8  8b4904               mov ecx, dword ptr [ecx + 4]
// 006801db  50                   push eax
// 006801dc  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006801e0  52                   push edx
// 006801e1  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006801e5  50                   push eax
// 006801e6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006801ea  52                   push edx
// 006801eb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006801ef  50                   push eax
// 006801f0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006801f4  52                   push edx
// 006801f5  50                   push eax
// 006801f6  51                   push ecx
// 006801f7  ff15d0ee7700         call dword ptr [0x77eed0]
// 006801fd  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00680201  0fbfd0               movsx edx, ax
// 00680204  c1e810               shr eax, 0x10
// 00680207  0fbfc0               movsx eax, ax
// 0068020a  894104               mov dword ptr [ecx + 4], eax
// 0068020d  8911                 mov dword ptr [ecx], edx
// 0068020f  8bc1                 mov eax, ecx
// 00680211  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?TabbedTextOutA@CDC@@UAE?AVCSize@@HHPBDHHPAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
