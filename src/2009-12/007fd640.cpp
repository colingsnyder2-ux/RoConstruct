// from server: 100% by auto
// roc 2009-12 007fd640  unit: CXTPControlComboBoxAutoCompleteWnd  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd640
//
// 007fd640  8b442404             mov eax, dword ptr [esp + 4]
// 007fd644  83f83e               cmp eax, 0x3e
// 007fd647  771a                 ja 0x7fd663
// 007fd649  8d0440               lea eax, [eax + eax*2]
// 007fd64c  8d848164010000       lea eax, [ecx + eax*4 + 0x164]
// 007fd653  8b4808               mov ecx, dword ptr [eax + 8]
// 007fd656  83f9ff               cmp ecx, -1
// 007fd659  7506                 jne 0x7fd661
// 007fd65b  8b4004               mov eax, dword ptr [eax + 4]
// 007fd65e  c20400               ret 4
// 007fd661  8bc1                 mov eax, ecx
// 007fd663  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GetXtremeColor@CXTPPaintManager@@QAEKI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
