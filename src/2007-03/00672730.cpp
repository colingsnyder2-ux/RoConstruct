// from server: 100% by auto
// roc 2007-03 00672730  unit: seg_00670000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00672730
//
// 00672730  83792c00             cmp dword ptr [ecx + 0x2c], 0
// 00672734  8b442404             mov eax, dword ptr [esp + 4]
// 00672738  894120               mov dword ptr [ecx + 0x20], eax
// 0067273b  7e07                 jle 0x672744
// 0067273d  8b11                 mov edx, dword ptr [ecx]
// 0067273f  8b426c               mov eax, dword ptr [edx + 0x6c]
// 00672742  ffd0                 call eax
// 00672744  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?SetParent@CXTPControls@@QAEXPAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
