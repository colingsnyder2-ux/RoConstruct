// from server: 100% by auto
// roc 2009-12 00814ea0  unit: CXTPCommandBarKeyboardTip  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814ea0
//
// 00814ea0  8b442404             mov eax, dword ptr [esp + 4]
// 00814ea4  894154               mov dword ptr [ecx + 0x54], eax
// 00814ea7  e854f8ffff           call 0x814700
// 00814eac  8bc8                 mov ecx, eax
// 00814eae  e85d7affff           call 0x80c910
// 00814eb3  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?SetImageManager@CXTPCommandBars@@QAEXPAVCXTPImageManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
