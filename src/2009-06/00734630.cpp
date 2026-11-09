// from server: 100% by auto
// roc 2009-06 00734630  unit: CXTPImageManagerResource::CBitmapDC  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00734630
//
// 00734630  8b442404             mov eax, dword ptr [esp + 4]
// 00734634  56                   push esi
// 00734635  8b7108               mov esi, dword ptr [ecx + 8]
// 00734638  50                   push eax
// 00734639  56                   push esi
// 0073463a  e8e1e00100           call 0x752720
// 0073463f  8bc6                 mov eax, esi
// 00734641  5e                   pop esi
// 00734642  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?Add@CPtrArray@@QAEHPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
