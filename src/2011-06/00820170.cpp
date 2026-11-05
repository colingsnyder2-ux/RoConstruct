// from server: 100% by auto
// roc 2011-06 00820170  unit: CXTPImageManagerResource::CBitmapDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820170
//
// 00820170  8b442408             mov eax, dword ptr [esp + 8]
// 00820174  8b542404             mov edx, dword ptr [esp + 4]
// 00820178  50                   push eax
// 00820179  8b4104               mov eax, dword ptr [ecx + 4]
// 0082017c  52                   push edx
// 0082017d  50                   push eax
// 0082017e  ff15ec00a400         call dword ptr [0xa400ec]
// 00820184  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ?Polygon@CDC@@QAEHPBUtagPOINT@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
