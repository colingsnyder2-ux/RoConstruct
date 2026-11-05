// from server: 100% by auto
// roc 2010-06 007e94e0  unit: CXTPControls  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e94e0
//
// 007e94e0  8b442404             mov eax, dword ptr [esp + 4]
// 007e94e4  85c0                 test eax, eax
// 007e94e6  7514                 jne 0x7e94fc
// 007e94e8  50                   push eax
// 007e94e9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007e94ec  50                   push eax
// 007e94ed  ff15f0b99e00         call dword ptr [0x9eb9f0]
// 007e94f3  89442404             mov dword ptr [esp + 4], eax
// 007e94f7  e96ee7fbff           jmp 0x7a7c6a
// 007e94fc  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e94ff  50                   push eax
// 007e9500  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007e9503  50                   push eax
// 007e9504  ff15f0b99e00         call dword ptr [0x9eb9f0]
// 007e950a  89442404             mov dword ptr [esp + 4], eax
// 007e950e  e957e7fbff           jmp 0x7a7c6a
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
