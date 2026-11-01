// from server: 100% by auto
// roc 2009-12 00831890  unit: CXTTreeBase  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831890
//
// 00831890  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00831893  8b442404             mov eax, dword ptr [esp + 4]
// 00831897  895048               mov dword ptr [eax + 0x48], edx
// 0083189a  83410cff             add dword ptr [ecx + 0xc], -1
// 0083189e  894110               mov dword ptr [ecx + 0x10], eax
// 008318a1  7505                 jne 0x8318a8
// 008318a3  e898ffffff           call 0x831840
// 008318a8  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?FreeAssoc@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@IAEXPAVCAssoc@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
