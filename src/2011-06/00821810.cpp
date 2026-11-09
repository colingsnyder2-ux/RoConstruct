// from server: 100% by auto
// roc 2011-06 00821810  unit: CXTPImageManagerResource::CBitmapDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00821810
//
// 00821810  8b442404             mov eax, dword ptr [esp + 4]
// 00821814  56                   push esi
// 00821815  8b7108               mov esi, dword ptr [ecx + 8]
// 00821818  50                   push eax
// 00821819  56                   push esi
// 0082181a  e871d40100           call 0x83ec90
// 0082181f  8bc6                 mov eax, esi
// 00821821  5e                   pop esi
// 00821822  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?Add@CPtrArray@@QAEHPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
