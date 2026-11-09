// from server: 100% by auto
// roc 2009-06 0075a4a0  unit: CXTPControls  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a4a0
//
// 0075a4a0  8b442404             mov eax, dword ptr [esp + 4]
// 0075a4a4  85c0                 test eax, eax
// 0075a4a6  7514                 jne 0x75a4bc
// 0075a4a8  50                   push eax
// 0075a4a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0075a4ac  50                   push eax
// 0075a4ad  ff15a0ec8900         call dword ptr [0x89eca0]
// 0075a4b3  89442404             mov dword ptr [esp + 4], eax
// 0075a4b7  e946e8fbff           jmp 0x718d02
// 0075a4bc  8b4020               mov eax, dword ptr [eax + 0x20]
// 0075a4bf  50                   push eax
// 0075a4c0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0075a4c3  50                   push eax
// 0075a4c4  ff15a0ec8900         call dword ptr [0x89eca0]
// 0075a4ca  89442404             mov dword ptr [esp + 4], eax
// 0075a4ce  e92fe8fbff           jmp 0x718d02
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
