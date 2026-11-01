// from server: 100% by auto
// roc 2007-03 0062fad0  unit: seg_00620000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062fad0
//
// 0062fad0  8b442404             mov eax, dword ptr [esp + 4]
// 0062fad4  8b5004               mov edx, dword ptr [eax + 4]
// 0062fad7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0062fada  52                   push edx
// 0062fadb  50                   push eax
// 0062fadc  ff150cee7700         call dword ptr [0x77ee0c]
// 0062fae2  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
