// from server: 100% by auto
// roc 2007-08 0040a770  unit: RBX::VDebugSettings::?$FactoryProduct::Creator  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a770
//
// 0040a770  8b442404             mov eax, dword ptr [esp + 4]
// 0040a774  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040a777  6a00                 push 0
// 0040a779  50                   push eax
// 0040a77a  6882010000           push 0x182
// 0040a77f  51                   push ecx
// 0040a780  ff15d8ec7700         call dword ptr [0x77ecd8]
// 0040a786  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\winctrl2.cpp (function ?DeleteString@CListBox@@QAEHI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl2.cpp
