// from server: 100% by auto
// roc 2007-03 00651460  unit: seg_00650000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651460
//
// 00651460  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00651463  8b442404             mov eax, dword ptr [esp + 4]
// 00651467  895048               mov dword ptr [eax + 0x48], edx
// 0065146a  83410cff             add dword ptr [ecx + 0xc], -1
// 0065146e  894110               mov dword ptr [ecx + 0x10], eax
// 00651471  7505                 jne 0x651478
// 00651473  e898ffffff           call 0x651410
// 00651478  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?FreeAssoc@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
