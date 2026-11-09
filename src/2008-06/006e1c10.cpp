// from server: 100% by auto
// roc 2008-06 006e1c10  unit: CXTPControls  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006e1c10
//
// 006e1c10  8b442404             mov eax, dword ptr [esp + 4]
// 006e1c14  85c0                 test eax, eax
// 006e1c16  7514                 jne 0x6e1c2c
// 006e1c18  50                   push eax
// 006e1c19  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006e1c1c  50                   push eax
// 006e1c1d  ff15b82b8000         call dword ptr [0x802bb8]
// 006e1c23  89442404             mov dword ptr [esp + 4], eax
// 006e1c27  e9b2effbff           jmp 0x6a0bde
// 006e1c2c  8b4020               mov eax, dword ptr [eax + 0x20]
// 006e1c2f  50                   push eax
// 006e1c30  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006e1c33  50                   push eax
// 006e1c34  ff15b82b8000         call dword ptr [0x802bb8]
// 006e1c3a  89442404             mov dword ptr [esp + 4], eax
// 006e1c3e  e99beffbff           jmp 0x6a0bde
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
