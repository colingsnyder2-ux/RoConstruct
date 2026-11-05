// from server: 100% by auto
// roc 2008-06 006ba690  unit: CXTPImageManagerResource::CBitmapDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba690
//
// 006ba690  8b442408             mov eax, dword ptr [esp + 8]
// 006ba694  8b542404             mov edx, dword ptr [esp + 4]
// 006ba698  50                   push eax
// 006ba699  8b4104               mov eax, dword ptr [ecx + 4]
// 006ba69c  52                   push edx
// 006ba69d  50                   push eax
// 006ba69e  ff158c208000         call dword ptr [0x80208c]
// 006ba6a4  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?Polygon@CDC@@QAEHPBUtagPOINT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
