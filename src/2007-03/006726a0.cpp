// from server: 100% by auto
// roc 2007-03 006726a0  unit: seg_00670000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006726a0
//
// 006726a0  56                   push esi
// 006726a1  8bf1                 mov esi, ecx
// 006726a3  e8d8ffffff           call 0x672680
// 006726a8  8b442408             mov eax, dword ptr [esp + 8]
// 006726ac  89463c               mov dword ptr [esi + 0x3c], eax
// 006726af  5e                   pop esi
// 006726b0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetOriginalControls@CXTPControls@@QAEXPAVCXTPOriginalControls@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
