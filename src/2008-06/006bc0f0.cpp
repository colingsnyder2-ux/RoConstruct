// from server: 100% by auto
// roc 2008-06 006bc0f0  unit: CXTPImageManagerResource::CBitmapDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006bc0f0
//
// 006bc0f0  8b442404             mov eax, dword ptr [esp + 4]
// 006bc0f4  56                   push esi
// 006bc0f5  8b7108               mov esi, dword ptr [ecx + 8]
// 006bc0f8  50                   push eax
// 006bc0f9  56                   push esi
// 006bc0fa  e821220500           call 0x70e320
// 006bc0ff  8bc6                 mov eax, esi
// 006bc101  5e                   pop esi
// 006bc102  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?Add@CPtrArray@@QAEHPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
