// from server: 100% by auto
// roc 2009-06 007569e0  unit: CXTTreeBase  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007569e0
//
// 007569e0  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007569e3  8b442404             mov eax, dword ptr [esp + 4]
// 007569e7  895048               mov dword ptr [eax + 0x48], edx
// 007569ea  83410cff             add dword ptr [ecx + 0xc], -1
// 007569ee  894110               mov dword ptr [ecx + 0x10], eax
// 007569f1  7505                 jne 0x7569f8
// 007569f3  e898ffffff           call 0x756990
// 007569f8  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?FreeAssoc@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
