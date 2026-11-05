// from server: 100% by auto
// roc 2007-08 0066adb0  unit: CXTPToolBar::CControlButtonExpand  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0066adb0
//
// 0066adb0  8b442404             mov eax, dword ptr [esp + 4]
// 0066adb4  85c0                 test eax, eax
// 0066adb6  7514                 jne 0x66adcc
// 0066adb8  50                   push eax
// 0066adb9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0066adbc  50                   push eax
// 0066adbd  ff15acee7700         call dword ptr [0x77eeac]
// 0066adc3  89442404             mov dword ptr [esp + 4], eax
// 0066adc7  e9f453fcff           jmp 0x6301c0
// 0066adcc  8b4020               mov eax, dword ptr [eax + 0x20]
// 0066adcf  50                   push eax
// 0066add0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0066add3  50                   push eax
// 0066add4  ff15acee7700         call dword ptr [0x77eeac]
// 0066adda  89442404             mov dword ptr [esp + 4], eax
// 0066adde  e9dd53fcff           jmp 0x6301c0
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
