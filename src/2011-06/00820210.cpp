// from server: 100% by auto
// roc 2011-06 00820210  unit: CXTPImageManagerResource::CBitmapDC  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820210
//
// 00820210  8b442420             mov eax, dword ptr [esp + 0x20]
// 00820214  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00820218  8b4904               mov ecx, dword ptr [ecx + 4]
// 0082021b  50                   push eax
// 0082021c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00820220  52                   push edx
// 00820221  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00820225  50                   push eax
// 00820226  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0082022a  52                   push edx
// 0082022b  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0082022f  50                   push eax
// 00820230  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00820234  52                   push edx
// 00820235  50                   push eax
// 00820236  51                   push ecx
// 00820237  ff15e01aa400         call dword ptr [0xa41ae0]
// 0082023d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00820241  0fbfd0               movsx edx, ax
// 00820244  c1e810               shr eax, 0x10
// 00820247  98                   cwde 
// 00820248  894104               mov dword ptr [ecx + 4], eax
// 0082024b  8911                 mov dword ptr [ecx], edx
// 0082024d  8bc1                 mov eax, ecx
// 0082024f  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?TabbedTextOutA@CDC@@UAE?AVCSize@@HHPBDHHPAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
