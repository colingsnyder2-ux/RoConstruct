// from server: 100% by auto
// roc 2011-06 0084ad00  unit: CXTPControls  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0084ad00
//
// 0084ad00  8b442404             mov eax, dword ptr [esp + 4]
// 0084ad04  85c0                 test eax, eax
// 0084ad06  7514                 jne 0x84ad1c
// 0084ad08  50                   push eax
// 0084ad09  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0084ad0c  50                   push eax
// 0084ad0d  ff15a01aa400         call dword ptr [0xa41aa0]
// 0084ad13  89442404             mov dword ptr [esp + 4], eax
// 0084ad17  e90cf6fbff           jmp 0x80a328
// 0084ad1c  8b4020               mov eax, dword ptr [eax + 0x20]
// 0084ad1f  50                   push eax
// 0084ad20  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0084ad23  50                   push eax
// 0084ad24  ff15a01aa400         call dword ptr [0xa41aa0]
// 0084ad2a  89442404             mov dword ptr [esp + 4], eax
// 0084ad2e  e9f5f5fbff           jmp 0x80a328
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
